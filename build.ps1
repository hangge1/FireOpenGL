param(
    [ValidateSet("Debug", "Release")]
    [string]$BuildType = "Debug"
)

# 1. 初始化子模块
Write-Host "init Git submodule..." -ForegroundColor Cyan
git submodule update --init --recursive

# 2. 创建构建目录
$buildDir = "build/$BuildType"
if (-not (Test-Path $buildDir)) {
    New-Item -Path $buildDir -ItemType Directory -Force | Out-Null
}

# 3. 配置 CMake
Write-Host "config CMake ($BuildType mode)..." -ForegroundColor Cyan
$cmakeArgs = @(
    "-DCMAKE_BUILD_TYPE=$BuildType",
    "-DBUILD_TESTS=ON",
    "-S", ".",
    "-B", $buildDir
)

# 根据平台添加额外配置
if ($IsWindows) {
    $cmakeArgs += "-A", "x64"
}

cmake @cmakeArgs

# 4. 构建项目
Write-Host "build project..." -ForegroundColor Cyan
cmake --build $buildDir --config $BuildType

# 5. 运行测试
Write-Host "run test..." -ForegroundColor Cyan
ctest --test-dir $buildDir -C $BuildType --verbose