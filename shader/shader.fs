#version 330 core

out vec4 FragColor;
in vec3 ourColor;

// uniform vec4 vertexColor;
void main ()
{
	//FragColor = vertexColor;
	FragColor = vec4(ourColor, 1.0f);
}