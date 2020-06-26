#include "VertexBuffer.h"

void VertexBuffer::initialize()
{
	/* Generates a buffer object */
	glGenBuffers(1, &m_buffer);

	/* Bind a named buffer object */
	glBindBuffer(GL_ARRAY_BUFFER, m_buffer);

	/* Creates and initializes a buffer object's data store */
	glBufferData(GL_ARRAY_BUFFER, sizeof(m_vertices), m_vertices, GL_STATIC_DRAW);
}

void VertexBuffer::draw()
{
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f( 0.0f,  0.5f);
	glVertex2f( 0.5f, -0.5f);
	glEnd();
}

