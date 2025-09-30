#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

uniform mat4 u_ModelMatrix;
uniform mat4 u_ViewMatrix;
uniform mat4 u_ProjectMatrix;

out vec2 vTexCoord;

void main()
{
   vec4 res = u_ProjectMatrix * u_ViewMatrix * u_ModelMatrix * vec4(aPos, 1.0);
   gl_Position = res;
   vTexCoord = aTexCoord;
}