#pragma once

#include "GL/glew.h"
#include "GLFW/glfw3.h"

class VertexBuffer
{
private:
	unsigned int m_buffer;

	float m_vertices[9] = 
	{
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f
	};

public:
	void initialize();
	void draw();

};