/* Copyright © 2020 Dave Bakker. All rights reserved. */

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Source/Graphics/ApplicationWindow.h"
#include "Source/Graphics/VertexBuffer.h"

const char* engineVersion = "v0.0.5";

const int windowWidth = 1280;
const int windowHeight = 720;

const bool fullscreen = false;

/* Error event function */
static void errorCallback(int t_error, const char* t_description)
{
	fprintf(stderr, "Error: %s\n", t_description);
}

int main()
{
	/* Receives error events */
	glfwSetErrorCallback(errorCallback);

	/* Intilization of the GLFW library */
	if (!glfwInit()) 
	{ 
		std::cout << "Failed initialization of the GLFW library" << std::endl;
		return -1; 
	} 
	else 
	{ 
		std::cout << "Successful initialization of the GLFW library" << std::endl; 
	}

	/* Sets the amount frames to wait until swapping the buffers */
	//glfwSwapInterval(1);

	/* Intilization of the window */
	ApplicationWindow window(engineVersion, windowWidth, windowHeight, fullscreen);

	/* Intilization of the GLEW library */
	GLenum error = glewInit();

	if (GLEW_OK != error)
	{
		fprintf(stderr, "Error: %s\n", glewGetErrorString(error));
	}
	else
	{
		std::cout << "Successful initialization of the GLEW library" << std::endl;
	}

	VertexBuffer bufferObject;

	bufferObject.initialize();

	/* Application loop */
	while (!window.closed())
	{
		window.clear();

		bufferObject.draw();

		window.update();
		window.input();
	}

	return 0;
}