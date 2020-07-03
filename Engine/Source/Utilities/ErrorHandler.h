#pragma once

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <iostream>

#define ASSERT(x) if (!(x)) __debugbreak();
#define ErrorCall(x) errorHandler.clearError(); x; ASSERT(errorHandler.checkError(#x, __FILE__, __LINE__));

class ErrorHandler
{
public:
	static void clearError();
	static bool checkError(const char* t_function, const char* t_file, int t_line);
};

/* NOTE: to debug a function: include this script (with class), use the function 'ErrorCall' with the function in question as a parameter */
