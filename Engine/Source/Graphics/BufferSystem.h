#pragma once

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "VertexBuffer.h"
#include "IndexBuffer.h"

class BufferSystem
{
private:
	unsigned int m_vertexArray;

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

private:
	const VertexBuffer& m_vertexBuffer = VertexBuffer(sizeof(m_vertices), m_vertices);
	const IndexBuffer& m_indexBuffer = IndexBuffer(sizeof(m_indices), m_indices);

public:
	BufferSystem();
	~BufferSystem();

	void draw();
};