#pragma once

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

struct shaderProgramSource
{
	std::string vertexSource;
	std::string fragmentSource;
};

class ShaderSystem
{
private:
	static void shaderError(unsigned int t_shader);
	static void setup(unsigned int t_shader, const GLchar* t_name, float t_red, float t_green, float t_blue, float t_alpha);

private:
	unsigned int m_shader;

public:
	void initialize();
	void draw();

public:
	static unsigned int create(const std::string& t_vertexShader, const std::string& t_fragmentShader);
	static unsigned int compile(unsigned int t_type, const std::string& t_source);

public:
	static shaderProgramSource convert(const std::string& t_filepath);
};