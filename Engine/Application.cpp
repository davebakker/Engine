/* Copyright © 2020 Dave Bakker. All rights reserved. */

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Source/Graphics/ApplicationWindow.h"

#include "Source/Graphics/BufferSystem.h"
#include "Source/Graphics/ShaderSystem.h"
#include "Source/Graphics/Texture.h"

const char* engineVersion = "v0.0.12";

const int windowWidth = 1280;
const int windowHeight = 720;

const bool fullscreen = false;

int main()
{
	/* Initialization of the GLFW library */
	if (!glfwInit()) {  std::cout << "Failed initialization of the GLFW library" << std::endl; return -1;	} 
	else			 {  std::cout << "Successful initialization of the GLFW library" << std::endl;			}

	/* Initializationn of the window */
	ApplicationWindow window(engineVersion, windowWidth, windowHeight, fullscreen);

	/* Initialization of the GLEW library */
	GLenum error = glewInit();
	if (GLEW_OK != error)	{ fprintf(stderr, "Error: %s\n", glewGetErrorString(error)); }
	else					{ std::cout << "Successful initialization of the GLEW library" << std::endl; }

	/* Initialization of the buffers */
	BufferSystem bufferSystem;

	/* Initialization of the shaders */
	ShaderSystem shaderSystem("Source/Shaders/Template.shader");
	shaderSystem.bind();
	shaderSystem.setUniform4f("uniformColor", 0.98f, 0.69f, 0.19f, 1.0f);

	/* Initialization of the texture */
	Texture texture("Source/Textures/Texture.png");
	texture.bind();
	shaderSystem.setUniform1i("uniformTexture", 0);
	shaderSystem.unbind();

	/* Application loop */
	while (!window.closed())
	{
		window.clear();

		shaderSystem.bind();
		shaderSystem.setUniform4f("uniformColor", 0.98f, 0.69f, 0.19f, 1.0f);

		bufferSystem.draw();

		window.update();
		window.input();
	}

	return 0;
}