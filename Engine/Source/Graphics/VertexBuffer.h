#pragma once

#include "GL/glew.h"
#include "GLFW/glfw3.h"

class VertexBuffer
{
private:
	unsigned int m_rendererID;

public:
	VertexBuffer(unsigned int t_size, const void* t_data);
	~VertexBuffer();

	void bind() const;
	void unbind() const;
};