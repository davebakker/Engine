#pragma once

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include <unordered_map>

struct shaderProgramSource
{
	std::string vertexSource;
	std::string fragmentSource;
};

class ShaderSystem
{
private:
	std::string m_filepath;
	unsigned int m_shader;
	std::unordered_map<std::string, int> m_uniformCache;

private:
	int getUniform(const std::string& t_location);

	static unsigned int create(const std::string& t_vertexShader, const std::string& t_fragmentShader);
	static unsigned int compile(unsigned int t_type, const std::string& t_source);
	static shaderProgramSource convert(const std::string& t_filepath);

	static void shaderError(unsigned int t_shader);

public:
	ShaderSystem(const std::string& t_filepath);
	~ShaderSystem();

public:
	void bind() const;
	void unbind() const;

	void setUniform1i(const std::string& t_name, int t_value);
	void setUniform1f(const std::string& t_name, float t_value);
	void setUniform4f(const std::string& t_name, float t_value0, float t_value1, float t_value2, float t_value3);
};