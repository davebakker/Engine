#include "VertexBuffer.h"

void VertexBuffer::initialize()
{
	/* Generates a buffer object */
	glGenBuffers(1, &m_buffer);

	/* Binds the buffer object */
	glBindBuffer(GL_ARRAY_BUFFER, m_buffer);

	/* Creates and initializes a buffer object's data store */
	glBufferData(GL_ARRAY_BUFFER, sizeof(m_vertices), m_vertices, GL_STATIC_DRAW);

	/* Enables the vertex attribute array */
	glEnableVertexAttribArray(0);

	/* Defines an array of generic vertex attribute data */
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (const void*) 0);
}

void VertexBuffer::draw()
{
	/* Draws the vertex buffer */
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

