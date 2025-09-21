#include <gtest/gtest.h>

#include <Glad/gl.h>
#include <GLFW/glfw3.h>


class GlfwFixture : public ::testing::Test {
protected:
    void SetUp() override {
        ASSERT_EQ(glfwInit(), GLFW_TRUE);

		const char* p = nullptr;
		ASSERT_EQ(glfwGetError(&p), GLFW_NO_ERROR);

		int major{};
		int minor{};
		int revision{};
		glfwGetVersion(&major, &minor, &revision);
		ASSERT_TRUE(major == 3);
		ASSERT_TRUE(minor == 4);
		ASSERT_TRUE(revision == 0);
		ASSERT_EQ(glfwGetError(&p), GLFW_NO_ERROR);
    }

    void TearDown() override {
		glfwTerminate();
    }

    const char* p = nullptr;
};


TEST_F(GlfwFixture, CreateWindow) {
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    ASSERT_TRUE(window);
    ASSERT_EQ(glfwGetError(&p), GLFW_NO_ERROR);

    glfwMakeContextCurrent(window);
    ASSERT_EQ(glfwGetError(&p), GLFW_NO_ERROR);

    glfwDestroyWindow(window);
    ASSERT_EQ(glfwGetError(&p), GLFW_NO_ERROR);
}

TEST_F(GlfwFixture, GladLoadGL) {

	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	ASSERT_TRUE(window);

	glfwMakeContextCurrent(window);
	ASSERT_EQ(glfwGetError(&p), GLFW_NO_ERROR);

#ifdef GLAD_OPTION_GL_MX
	GladGLContext context = {};
#ifdef GLAD_OPTION_GL_LOADER
	int version = gladLoaderLoadGLContext(&context);
#else
	int version = gladLoadGLContext(&context, glfwGetProcAddress);
#endif
#else
#ifdef GLAD_OPTION_GL_LOADER
	int version = gladLoaderLoadGL();
#else
	int version = gladLoadGL(glfwGetProcAddress);
#endif
#endif

	ASSERT_TRUE(version != 0);

	int major = GLAD_VERSION_MAJOR(version);
	int minor = GLAD_VERSION_MINOR(version);

	ASSERT_TRUE(major == 4);
	ASSERT_TRUE(minor == 6);

	glfwDestroyWindow(window);
	ASSERT_EQ(glfwGetError(&p), GLFW_NO_ERROR);
}
