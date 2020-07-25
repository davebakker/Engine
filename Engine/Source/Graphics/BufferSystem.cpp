#include "BufferSystem.h"

BufferSystem::BufferSystem()
{
	/* Generates the vertex array object */
	glGenVertexArrays(1, &m_vertexArray);

	/* Binds the vertex array */
	glBindVertexArray(m_vertexArray);

	/* Enables the vertex attribute array */
	glEnableVertexAttribArray(0);

	/* Defines an array of generic vertex attribute data */
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (const void*) 0);

	/* Unbinds the vertex array, buffers and program */
	glBindVertexArray(0);
	glUseProgram(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

BufferSystem::~BufferSystem() {}

void BufferSystem::draw()
{
	/* Binds the vertex array */
	glBindVertexArray(m_vertexArray);

	/* Binds the index buffer */
	m_indexBuffer.bind();

	/* Draws the vertex buffer */
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
}

