#pragma once

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"

class BufferSystem
{
	float m_vertices[16] =
	{
		-0.5f, -0.5f, 0.0f, 0.0f,
		 0.5f, -0.5f, 1.0f, 0.0f,
		 0.5f,  0.5f, 1.0f, 1.0f,
		-0.5f,  0.5f, 0.0f, 1.0f
	};

	unsigned int m_indices[6] =
	{
		0, 1, 2, 
		2, 3, 0
	};

private:
	const VertexBuffer& m_vertexBuffer = VertexBuffer(sizeof(m_vertices), m_vertices);
	const IndexBuffer& m_indexBuffer = IndexBuffer(sizeof(m_indices), m_indices);
	const VertexArray& m_vertexArray = VertexArray();

public:
	BufferSystem();
	~BufferSystem();

	void draw();
};