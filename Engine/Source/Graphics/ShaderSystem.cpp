#include "ShaderSystem.h"

ShaderSystem::ShaderSystem(const std::string& t_filepath) : m_filepath(t_filepath), m_shader(0)
{
	/* Converts the shader */
	shaderProgramSource source = convert(t_filepath);
	m_shader = create(source.vertexSource, source.fragmentSource);

	setUniform4f("uniformColor", 0.98f, 0.69f, 0.19f, 1.0f);
}

ShaderSystem::~ShaderSystem() 
{
	glDeleteProgram(m_shader);
}

void ShaderSystem::bind()const
{
	glUseProgram(m_shader);
}

void ShaderSystem::unbind() const
{
	glUseProgram(0);
}

int ShaderSystem::getUniform(const std::string& t_name)
{
	/* Checks if the uniform cache consists an uniform */
	if (m_uniformCache.find(t_name) != m_uniformCache.end()) { return m_uniformCache[t_name]; }

	/* Receives the location of the shader variable */
	int location = glGetUniformLocation(m_shader, t_name.c_str());
	if (location == -1) { std::cout << "ERROR: uniform " << t_name << " does not exist." << std::endl; }

	m_uniformCache[t_name] = location;
	return location;
}

void ShaderSystem::setUniform1i(const std::string& t_name, int t_value)
{
	/* Writes the data to the shader variable */
	glUniform1i(getUniform(t_name), t_value);
}

void ShaderSystem::setUniform1f(const std::string& t_name, float t_value)
{
	/* Writes the data to the shader variable */
	glUniform1f(getUniform(t_name), t_value);
}

void ShaderSystem::setUniform4f(const std::string& t_name, float t_value0, float t_value1, float t_value2, float t_value3)
{
	/* Writes the data to the shader variable */
	glUniform4f(getUniform(t_name), t_value0, t_value1, t_value2, t_value3);
}

unsigned int ShaderSystem::create(const std::string& t_vertexShader, const std::string& t_fragmentShader)
{
	/* Sets the program and shaders */
	unsigned int program = glCreateProgram();
	unsigned int vertexShader = compile(GL_VERTEX_SHADER, t_vertexShader);
	unsigned int fragmentShader = compile(GL_FRAGMENT_SHADER, t_fragmentShader);

	/* Attaches the shader(s) to the program */
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);

	/* Links the program */
	glLinkProgram(program);

	/* Validates the program */
	glValidateProgram(program);

	/* Deletes the shader(s) */
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	return program;
}

unsigned int ShaderSystem::compile(unsigned int t_type, const std::string& t_source)
{
	/* Creates the shader object */
	unsigned int shader = glCreateShader(t_type);

	/* Pointer to the beginning of the data (as a raw string)*/
	const char* source = t_source.c_str();

	/* Replaces the source code in the shader */
	glShaderSource(shader, 1, &source, nullptr);

	/* Compiles the shader */
	glCompileShader(shader);

	int result;

	/* Return the parameter from the shader */
	glGetShaderiv(shader, GL_COMPILE_STATUS, &result);

	if (!result)
	{
		shaderError(shader);
		return 0;
	}

	return shader;
}

shaderProgramSource ShaderSystem::convert(const std::string& t_filepath)
{
	/* Sets stream to read from file */
	std::ifstream stream(t_filepath);

	enum class shaderType
	{
		NONE = -1,
		VERTEX = 0,
		FRAGMENT = 1,
	};

	std::string line;
	std::stringstream stringstream[2];

	/* Sets the shader type by default to none (null) */
	shaderType type = shaderType::NONE;

	/* Goes through the stream line by line */
	while (getline(stream, line))
	{
		/* Checks for the existence of the given strings */
		if (line.find("#shader") != std::string::npos)
		{
			if (line.find("vertex") != std::string::npos)
			{
				type = shaderType::VERTEX;
			}
			else if (line.find("fragment") != std::string::npos)
			{
				type = shaderType::FRAGMENT;
			}
		}
		else
		{
			/* Adds the string to the stringstream with the given shader index (type) */
			stringstream[(int)type] << line << '\n';
		}
	}

	/* Returns the shader code */
	return { stringstream[0].str(), stringstream[1].str() };
}

void ShaderSystem::shaderError(unsigned int t_shader)
{
	int length;

	/* Return the parameter from the shader */
	glGetShaderiv(t_shader, GL_INFO_LOG_LENGTH, &length);

	/* Creates a char array which is allocated on the stack dynamically */
	char* message = (char*)_malloca(length * sizeof(char));

	/* Returns the information log of the shader */
	glGetShaderInfoLog(t_shader, length, &length, message);

	std::cout << "Failed to compile the shader" << std::endl;
	std::cout << message << std::endl;

	/* Deletes the shader */
	glDeleteShader(t_shader);
}