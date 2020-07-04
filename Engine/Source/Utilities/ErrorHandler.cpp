#include "ErrorHandler.h"

void ErrorHandler::clearError()
{
	/* Receives error information */
	while (!glGetError);
}

bool ErrorHandler::checkError(const char* t_function, const char* t_file, int t_line)
{
	/* Checks the error and transmits an error message */
	while (GLenum error = glGetError())
	{
		std::cout << "ERROR: " << error << " in function (" << t_function << ") in file (" << t_file << ") at line " << t_line << std::endl;
		return false;
	}

	return true;
}