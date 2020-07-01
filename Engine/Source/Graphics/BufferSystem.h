#pragma once

#include "GL/glew.h"
#include "GLFW/glfw3.h"

class BufferSystem
{
private:
	unsigned int m_vertexBuffer;
	unsigned int m_indexBuffer;

	float m_vertices[12] =
	{
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f
	};

	unsigned int m_indices[6] =
	{
		0, 1, 2, 
		2, 3, 0
	};

public:
	void initialize();
	void draw();
};