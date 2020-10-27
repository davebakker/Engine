#include "VertexArray.h"

VertexArray::VertexArray()
{
	/* Generates the vertex array object */
	glGenVertexArrays(1, &m_rendererID);
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &m_rendererID);
}

void VertexArray::addBuffer(const VertexBuffer& t_vertexBuffer, const BufferLayout& t_layout) const
{
	/* Bind the vertex array */
	bind();

	/* Binds the vertex buffer */
	t_vertexBuffer.bind();

	/* Setup a layout */
	const auto& elements = t_layout.getElements();
	unsigned int offset = 0;

	for (unsigned int i = 0; i < elements.size(); i++)
	{
		const auto& element = elements[i];

		/* Enables the vertex attribute array */
		glEnableVertexAttribArray(i);

		/* Defines an array of generic vertex attribute data */
		glVertexAttribPointer(i, element.count, element.type, element.normalized, t_layout.getStride(), (const void*)offset);

		offset += element.count * BufferElement::getSizeOfType(element.type);
	}
}

void VertexArray::bind() const
{
	glBindVertexArray(m_rendererID);
}

void VertexArray::unbind() const
{
	glBindVertexArray(0);
}