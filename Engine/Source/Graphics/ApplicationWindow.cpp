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
	glClearColor(0.94, 0.97f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void ApplicationWindow::input()
{
	/* Receives input events */
	glfwSetKeyCallback(m_window, key_callback);
}

void ApplicationWindow::key_callback(GLFWwindow* t_window, int t_key, int t_scancode, int t_action, int t_mods)
{
	if (t_key == GLFW_KEY_ESCAPE && t_action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(t_window, GLFW_TRUE);
	}
}
