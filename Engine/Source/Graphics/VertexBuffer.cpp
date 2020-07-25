#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(unsigned int t_size, const void* t_data)
{
	/* Generates the vertex buffer object */
	glGenBuffers(1, &m_rendererID);

	/* Binds the vertex buffer */
	glBindBuffer(GL_ARRAY_BUFFER, m_rendererID);

	/* Creates and initializes a buffer object's data store */
	glBufferData(GL_ARRAY_BUFFER, t_size, t_data, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &m_rendererID);
}

void VertexBuffer::bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_rendererID);
}

void VertexBuffer::unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}