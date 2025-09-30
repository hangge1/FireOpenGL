#version 330 core

uniform sampler2D u_Texture;

in vec2 vTexCoord;
out vec4 FragColor;

void main()
{
   //FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);

   FragColor = texture(u_Texture, vTexCoord);
}