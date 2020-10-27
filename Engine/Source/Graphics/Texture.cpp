#include "Texture.h"

#include "../Vendor/STB/stb_image.h"

Texture::Texture(const std::string& t_path) : m_rendererID(0), m_filepath(t_path), m_localBuffer(nullptr), m_width(0), m_height(0), m_bitsPerPixel(0)
{
	/* Flips the texture vertically */
	stbi_set_flip_vertically_on_load(1);

	/* Sets the texture data in the local buffer */
	m_localBuffer = stbi_load(t_path.c_str(), &m_width, &m_height, &m_bitsPerPixel, 4);

	glGenTextures(1, & m_rendererID);
	glBindTexture(GL_TEXTURE_2D, m_rendererID);

	/* Sets the texture parameters */
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_localBuffer);
	glBindTexture(GL_TEXTURE_2D, 0);

	if (m_localBuffer) { stbi_image_free(m_localBuffer); }
}

Texture::~Texture()
{
	glDeleteTextures(1, &m_rendererID);
}

void Texture::bind(unsigned int t_slot) const
{
	glActiveTexture(GL_TEXTURE0 + t_slot);
	glBindTexture(GL_TEXTURE_2D, m_rendererID);
}

void Texture::unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}
