#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h> //Linkt die vom user verwendeten Grafik treiber bibliotek ins programm
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include "Defines.h"
#include "VertexBuffer.h"
#include "Pyramiede.h"

#include <windows.h>
#include <fstream>


#include <chrono>
#include <thread>

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
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);//Insgesamt buffer g??e pro pixel
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);//Double buffer anschalten


	window = SDL_CreateWindow("C++ Fenstername", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
	SDL_GLContext glContext = SDL_GL_CreateContext(window);//Speichert dne Status (glBegin);

	GLenum err=glewInit(); //glew Inizialisieren
	if (err != GLEW_OK) {
		std::cout << "Error: " << glewGetErrorString(err) << "\n";
		std::cin.get();
		return -1;
	}

	std::cout << "OpenGl Version: " << glGetString(GL_VERSION) << "\n";

	Vertex verticies[] = {    
		Vertex (- 0.5f ,-0.8f, 0.0f),
		Vertex (0.0f, 0.5f, 0.0f),
		Vertex (0.5f, -0.5f, 0.0f)
	};
	uint32_t numVertices = 3; //Die l?nge des arrays mitf?hren weil c keine l?nge von arrays speichert.

	VertexBuffer vertexBuffer(verticies, numVertices);
	vertexBuffer.unbind();

	Pyramiede pyramiede(Vertex(-0.3f, -0.3f, 0.3f), Vertex(0.3f, -0.3f, -0.3f), Vertex(0.0f, -0.3f, -0.3f), Vertex(0.0f, 0.3f, 0.0f));

	
	bool close = false;
	while (!close)
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		//Zeichenbereich

		//vertexBuffer.bind();
		//glDrawArrays(GL_TRIANGLES, 0, numVertices);
		//vertexBuffer.unbind();

		if (GetKeyState(VK_NUMPAD8) & 0x80)
		{
			pyramiede.skalieren(1.01f);
		}
		if (GetKeyState(VK_NUMPAD2) & 0x80)
		{
			pyramiede.skalieren(0.99f);
		}

		if (GetKeyState(VK_NUMPAD4) & 0x80)
		{
			pyramiede.drehen(-0.01f);
		}
		if (GetKeyState(VK_NUMPAD6) & 0x80)
		{
			pyramiede.drehen(0.01f);
		}

		if (GetKeyState(VK_UP) & 0x80)
		{
			pyramiede.verschieben(0,0.01f,0);
		}
		if (GetKeyState(VK_DOWN) & 0x80)
		{
			pyramiede.verschieben(0, -0.01f, 0);
		}
		if (GetKeyState(VK_RIGHT) & 0x80)
		{
			pyramiede.verschieben(0.01f, 0, 0);
		}
		if (GetKeyState(VK_LEFT) & 0x80)
		{
			pyramiede.verschieben(-0.01f, 0, 0);
		}

		pyramiede.draw();
		
		
		
		

	




		SDL_GL_SwapWindow(window); // DoubleBuffering (Zwischenspeichern von 2 Frames um instand laden von Frame zu erm?glichen


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