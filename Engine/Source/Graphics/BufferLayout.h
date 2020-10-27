#pragma once

#include <vector>
#include <GL/glew.h>

struct BufferElement
{
public:
	unsigned int type;
	unsigned int count;
	unsigned char normalized;

	static unsigned int getSizeOfType(unsigned int t_type) 
	{ 
		switch (t_type)
		{
			case GL_FLOAT:			return 4;
			case GL_UNSIGNED_INT:	return 4;
			case GL_UNSIGNED_BYTE:	return 1;
		}

		return 0;
	}
};

class BufferLayout
{
private:
	std::vector<BufferElement> m_elements;
	unsigned int m_stride;

public:
	BufferLayout() : m_stride(0) {};

	template<typename T>
	void push(unsigned int t_count) { static_assert(false); }
	
	template<> void push<float>(unsigned int t_count) { m_elements.push_back({ GL_FLOAT, t_count, GL_FALSE }); m_stride +=  BufferElement::getSizeOfType(GL_FLOAT) * t_count; }
	template<> void push<unsigned int>(unsigned int t_count) { m_elements.push_back({ GL_UNSIGNED_INT, t_count, GL_FALSE }); m_stride += BufferElement::getSizeOfType(GL_UNSIGNED_INT) * t_count; }
	template<> void push<unsigned char>(unsigned int t_count) { m_elements.push_back({ GL_UNSIGNED_BYTE, t_count, GL_TRUE }); m_stride += BufferElement::getSizeOfType(GL_UNSIGNED_BYTE) * t_count; }

	inline const std::vector<BufferElement> getElements() const& { return m_elements; }
	inline unsigned int getStride() const { return m_stride; }
};
