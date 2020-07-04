#include "ApplicationWindow.h"

ApplicationWindow::ApplicationWindow(const char* t_engineVersion, int t_windowWidth, int t_windowHeight, bool t_fullscreen) 
: m_engineVersion(t_engineVersion), m_windowWidth(t_windowWidth), m_windowHeight(t_windowHeight), m_fullscreen(t_fullscreen)
{
	initialize();
}

ApplicationWindow::~ApplicationWindow()
{
	/* Destroys the main window */
	glfwDestroyWindow(m_window);

	/* Destroys any remaining windows and releases futher resources allocated */
	glfwTerminate();
}

void ApplicationWindow::initialize()
{
	GLFWmonitor* monitor = glfwGetPrimaryMonitor();
	const GLFWvidmode* mode = glfwGetVideoMode(monitor);

	const int fullscreenWidth = mode->width;
	const int fullscreenHeight = mode->height;

	if (m_fullscreen)
	{
		/* Creates a fullscreen window */
		m_window = glfwCreateWindow(fullscreenWidth, fullscreenHeight, m_engineVersion, monitor, NULL);
	}
	else
	{
		/* Creates a window */
		m_window = glfwCreateWindow(m_windowWidth, m_windowHeight, m_engineVersion, NULL, NULL);
	}


	if (!m_window)
	{
		std::cout << "Failed to create a window" << std::endl;

		/* Destroys any remaining windows and releases futher resources allocated */
		glfwTerminate();

		return;
	}

	/* Makes the OpenGL API the current context */
	glfwMakeContextCurrent(m_window);

	/* Sets the amount of frames to wait until swapping the buffers */
	glfwSwapInterval(1);
}

void ApplicationWindow::update()
{
	/* Vice versa swaps the front (display) buffer with the back (render) buffer  */
	glfwSwapBuffers(m_window);

	/* Procceses events (only those that have already been received) */
	glfwPollEvents();
}

bool ApplicationWindow::closed()
{
	/* Calls functions until the window gets closed */
	return glfwWindowShouldClose(m_window);
}

void ApplicationWindow::clear()
{
	/* Rendering the background color */
	glClearColor((float)m_backgroundColor[0] / 255, (float)m_backgroundColor[1] / 255, (float)m_backgroundColor[2] / 255, (float)m_backgroundColor[3] / 255);
	glClear(GL_COLOR_BUFFER_BIT);
}

void ApplicationWindow::input()
{
	/* Receives input events */
	glfwSetKeyCallback(m_window, keyCallback);
}

void ApplicationWindow::keyCallback(GLFWwindow* t_window, int t_key, int t_scancode, int t_action, int t_mods)
{
	if (t_key == GLFW_KEY_ESCAPE && t_action == GLFW_PRESS)
	{
		/* Sets the window to be closed */
		glfwSetWindowShouldClose(t_window, GLFW_TRUE);
	}
}