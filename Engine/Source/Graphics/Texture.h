#pragma once

#include <GL/glew.h>
#include <string>

class Texture
{
private:
	unsigned int m_rendererID;

	unsigned char* m_localBuffer;

	std::string m_filepath;

	int m_width, m_height, m_bitsPerPixel;

public:
	Texture(const std::string& t_path);
	~Texture();

	void bind(unsigned int t_slot = 0) const;
	void unbind();

	inline int getWidth() const { return m_width; }
	inline int getHeight() const { return m_height; }
};
