#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Context
{
public:
	Context(int width, int height);
	~Context();

	bool ShouldClose() const;
	void ProcessInput() const;
	void SwapBuffers() const;
	void PollEvents() const;
private:
	GLFWwindow* window;
};