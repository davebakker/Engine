#pragma once

#include "GL/glew.h"
#include "GLFW/glfw3.h"

class IndexBuffer
{
private:
	unsigned int m_rendererID;
	unsigned int m_count;

public:
	IndexBuffer(unsigned int t_count, const unsigned int* t_data);
	~IndexBuffer();

	void bind() const;
	void unbind() const;

	inline unsigned int GetCount() const { return m_count; }
};