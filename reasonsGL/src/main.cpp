#include <iostream>

#include "components\Context.h"

int main()
{
	Context context(800, 600);

	while (!context.ShouldClose()) {
		context.ProcessInput();

		context.SwapBuffers();
		context.PollEvents();
	}

	return 0;
}