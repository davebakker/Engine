#include "BufferSystem.h"

void BufferSystem::initialize()
{
	/* Generates the vertex buffer object */
	glGenBuffers(1, &m_vertexBuffer);

	/* Binds the buffer object */
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);

	/* Creates and initializes a buffer object's data store */
	glBufferData(GL_ARRAY_BUFFER, sizeof(m_vertices), m_vertices, GL_STATIC_DRAW);

	/* Enables the vertex attribute array */
	glEnableVertexAttribArray(0);

	/* Defines an array of generic vertex attribute data */
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (const void*) 0);

	/* Generates the index buffer object */
	glGenBuffers(1, &m_indexBuffer);

	/* Binds the buffer object */
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indexBuffer);

	/* Creates and initializes a buffer object's data store */
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(m_indices), m_indices, GL_STATIC_DRAW);
}

void BufferSystem::draw()
{
	/* Draws the vertex buffer */
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
}

