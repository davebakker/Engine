#pragma once

#include <iostream>

#include "VertexBuffer.h"
#include "BufferLayout.h"

class VertexArray
{
private:
	unsigned int m_rendererID;

public:
	VertexArray();
	~VertexArray();

public:
	void addBuffer(const VertexBuffer& t_vertexBuffer, const BufferLayout& t_layout) const;

	void bind() const;
	void unbind() const;

};
