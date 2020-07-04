#pragma once

#include <iostream>
#include <GLFW/glfw3.h>

class ApplicationWindow
{
private:
	const char* m_engineVersion;

	int m_windowWidth;
	int m_windowHeight;

	bool m_fullscreen;

	GLFWwindow* m_window;

	const int m_backgroundColor[4] = { 203, 43, 68, 255 };

private:
	void initialize();
	static void keyCallback(GLFWwindow* t_window, int t_key, int t_scancode, int t_action, int t_mods);

public:
	void update();
	void clear();
	bool closed();
	void input();

public:
	ApplicationWindow(const char* t_engineVersion, int t_windowWidth, int t_windowHeight, bool t_fullscreen);
	~ApplicationWindow();
};
