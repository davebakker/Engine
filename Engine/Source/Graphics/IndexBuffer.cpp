#include "IndexBuffer.h"

IndexBuffer::IndexBuffer(unsigned int t_count, const unsigned int* t_data) 
	: m_count(t_count)
{
	/* Generates the vertex buffer object */
	glGenBuffers(1, &m_rendererID);

	/* Binds the vertex buffer */
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_rendererID);

	/* Creates and initializes a buffer object's data store */
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, t_count, t_data, GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(1, &m_rendererID);
}

void IndexBuffer::bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_rendererID);
}

void IndexBuffer::unbind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}