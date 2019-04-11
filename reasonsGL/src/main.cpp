#include <iostream>

#include "context\Context.h"
#include "shaders\Shader.h"
#include "elements\Triangle.h"

int main()
{
	Context context(800, 600);

	Shader shader("src/shaders/shader.vert", "src/shaders/shader.frag");

	float vertices1[] = {
		 0.5f, 0.9f, 0.0f,
		 0.8f, 0.5f, 0.0f,
		 0.2f, 0.5f, 0.0f
	};

	Triangle triangle1(vertices1);

	float vertices2[] = {
		-0.1f, -0.1f, 0.0f,
		-0.1f, -0.6f, 0.0f,
		-0.6f, -0.35f, 0.0f
	};

	Triangle triangle2(vertices2);

	while (!context.ShouldClose()) {
		context.ProcessInput();

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// draw our first triangle
		shader.use();
		triangle1.Draw();
		triangle2.Draw();

		context.SwapBuffers();
		context.PollEvents();
	}

	return 0;
}