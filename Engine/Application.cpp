/* Copyright © 2020 Dave Bakker. All rights reserved. */

#include <iostream>

#include <GLFW/glfw3.h>
#include <GL/glew.h>

#include "Source/Graphics/ApplicationWindow.h"

const char* engineVersion = "v0.0.4";

const int windowWidth = 1280;
const int windowHeight = 720;

const bool fullscreen = false;

/* Error event function */
static void error_callback(int t_error, const char* t_description)
{
	fprintf(stderr, "Error: %s\n", t_description);
}

int main()
{
	/* Receives error events */
	glfwSetErrorCallback(error_callback);

	/* Intilization of the the library */
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

	ApplicationWindow window(engineVersion, windowWidth, windowHeight, fullscreen);

	while (!window.closed())
	{
		window.clear();
		window.update();
		window.input();
	}

	return 0;
}