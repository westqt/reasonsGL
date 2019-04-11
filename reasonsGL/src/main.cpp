#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>


int main()
{
	int res = glfwInit();
	std::cout << res << std::endl;

	std::cin.get();

	return 0;
}