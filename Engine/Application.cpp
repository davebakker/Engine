/* Copyright © 2020 Dave Bakker. All rights reserved. */

#include <iostream>

#include <GLFW/glfw3.h>

const char* engineVersion = "v0.0.1";

const int windowWidth = 1280;
const int windowHeight = 720;

GLFWwindow* window;

/* Error event function */
static void error_callback(int t_error, const char* t_description)
{
	fprintf(stderr, "Error: %s\n", t_description);
}

/* Input event function */
static void key_callback(GLFWwindow* t_window, int t_key, int t_scancode, int t_action, int t_mods)
{
	if (t_key == GLFW_KEY_ESCAPE && t_action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(t_window, GLFW_TRUE);
	}
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

	/* Creates a window */
	window = glfwCreateWindow(windowWidth, windowHeight, engineVersion, NULL, NULL);

	if (!window) 
	{ 
		std::cout << "Failed to create a window" << std::endl;
		glfwTerminate();
		return -1; 
	}

	/* Receives input events */
	glfwSetKeyCallback(window, key_callback);

	/* Makes the OpenGL API the current context */
	glfwMakeContextCurrent(window);

	/* Sets the amount frames to wait until swapping the buffers */
	glfwSwapInterval(1);

	/* Calls functions until the window gets closed */
	while (!glfwWindowShouldClose(window))
	{
		int width, height;

		/*  */
		glfwGetFramebufferSize(window, &width, &height);

		/* Vice versa swaps the front (display) buffer with the back (render) buffer  */
		glfwSwapBuffers(window);

		/* Procceses events (only those that have already been received) */
		glfwPollEvents();
	}

	/* Destroys the main window */
	glfwDestroyWindow(window);

	/* Destroys any remaining windows and releases futher resources allocated */
	glfwTerminate();

	return 0;
}