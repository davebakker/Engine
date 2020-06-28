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

public:
	static unsigned int create(const std::string& t_vertexShader, const std::string& t_fragmentShader);
	static unsigned int compile(unsigned int t_type, const std::string& t_source);

public:
	static shaderProgramSource convert(const std::string& t_filepath);
};
