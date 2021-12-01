#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#define SDL_MAIN_HANDLED
#include <SDL.h>

#pragma comment(lib,"SDL2.lib")
#pragma comment(lib,"glew32s.lib")
#pragma comment(lib,"opengl32.lib")

int main(int argc, char** arbv) {

	SDL_Window* window;
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);//Rot kanalbreite 8 bit pro pixel
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);//Insgesamt buffer göße pro pixel
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);//Double buffer anschalten


	window = SDL_CreateWindow("C++ Fenstername", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
	SDL_GLContext glContext = SDL_GL_CreateContext(window);//Speichert dne Status (glBegin);
	
	bool close = false;
	while (!close)
	{
		glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		//Zeichenbereich

		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);//-1 - +1 open gl cordiaten;
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();





		SDL_GL_SwapWindow(window); // DoubleBuffering (Zwischenspeichern von 2 Frames um instand laden von Frame zu ermöglichen


		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT) {
				close = true;
			}

		}
	}


	return 0;
}