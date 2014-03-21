#include <iostream>
#include <stdlib.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>

#include <GL/gl.h>
#include <GL/glu.h>

void msgBox(Uint32 type)
{
	SDL_ShowSimpleMessageBox(type, "This is a box", "This is a tinder box", NULL);
}

int main()
{
	std::cout << "Hello C++!" << std::endl;

	int sdlInitResult = SDL_Init(SDL_INIT_EVERYTHING);
	if(sdlInitResult == 0)
		std::cout << "It works!" << std::endl;
	else
		std::cout << "It failed " << sdlInitResult << std::endl
			<< "Reason: " << SDL_GetError() << std::endl;

	Uint32 ticks = SDL_GetTicks();
	std::cout << "Ticks: " << ticks << std::endl;

	char* basePath = SDL_GetPrefPath("everempire", "royal-hime");
	std::cout << "Game Dir: " << basePath << std::endl;

	SDL_Window* window = SDL_CreateWindow(
		"A Royal Window",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		800,
		600,
		SDL_WINDOW_FULLSCREEN | SDL_WINDOW_OPENGL
	);
	SDL_GL_CreateContext(window);

	// Game Loop
	bool running = true;
	SDL_Event event;

	while(true)
	{
		// Handle Messages
		SDL_PollEvent(&event);
		if(event.type == SDL_QuitEvent)
			break;

		// Render
		glClearColor(0.5, 0.5, 0.5, 0.5);
		SDL_GL_SwapWindow(window);

		glClearColor(0.5, 0.5, 0.5, 0.5);
		glBegin(GL_TRIANGLES);
		glColor3f(0.1, 0.2, 0.3);
		glVertex3f(0, 0, 0);
		glVertex3f(1, 0, 0);
		glVertex3f(0, 1, 0);
		glEnd();

		SDL_GL_SwapWindow(window);
	}
	SDL_Delay(3000);

	SDL_DestroyWindow(window);
	SDL_Quit();
}
