#include "BufferSystem.h"

BufferSystem::BufferSystem()
{
	BufferLayout layout;
	layout.push<float>(2);
	layout.push<float>(2);

	m_vertexArray.addBuffer(m_vertexBuffer, layout);

	/* Unbinds the vertex array, buffers and program */
	glBindVertexArray(0);
	glUseProgram(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	
	/* Enables blending */
	glEnable(GL_BLEND);

	/* Defines the blending of alpha pixels */
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

BufferSystem::~BufferSystem() {}

void BufferSystem::draw()
{
	/* Binds the vertex array */
	m_vertexArray.bind();

	/* Binds the index buffer */
	m_indexBuffer.bind();

	/* Draws the vertex buffer */
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
}

