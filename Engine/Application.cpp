/* Copyright © 2020 Dave Bakker. All rights reserved. */

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Source/Graphics/ApplicationWindow.h"
#include "Source/Graphics/BufferSystem.h"
#include "Source/Graphics/ShaderSystem.h"

const char* engineVersion = "v0.0.10";

const int windowWidth = 1280;
const int windowHeight = 720;

const bool fullscreen = false;

int main()
{
	/* Intilization of the GLFW library */
	if (!glfwInit()) {  std::cout << "Failed initialization of the GLFW library" << std::endl; return -1;	} 
	else			 {  std::cout << "Successful initialization of the GLFW library" << std::endl;			}

	/* Intilization of the window */
	ApplicationWindow window(engineVersion, windowWidth, windowHeight, fullscreen);

	/* Intilization of the GLEW library */
	GLenum error = glewInit();
	if (GLEW_OK != error)	{ fprintf(stderr, "Error: %s\n", glewGetErrorString(error)); }
	else					{ std::cout << "Successful initialization of the GLEW library" << std::endl; }

	/* Intilization of the buffers */
	BufferSystem bufferSystem;
	bufferSystem.initialize();

	/* Intilization of the shaders */
	ShaderSystem shaderSystem;
	shaderSystem.initialize();

	/* Application loop */
	while (!window.closed())
	{
		window.clear();

		shaderSystem.draw();
		bufferSystem.draw();

		window.update();
		window.input();
	}

	return 0;
}