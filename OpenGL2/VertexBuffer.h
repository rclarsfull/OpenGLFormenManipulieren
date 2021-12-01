#pragma once
#include <GL/glew.h>
#include "Defines.h"

struct VertexBuffer {
	VertexBuffer(void* data, uint32_t numVertices) {
		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);

		glGenBuffers(1, &bufferId); // Erzeugt genau 1 Buffer auf der Gpu, die adresse wird in vertex buffer geschrieben
		glBindBuffer(GL_ARRAY_BUFFER, bufferId); //Buffer Binden und den typ übergeben (Auswählen von dem zu benutzenden buffer
		std::cout << "GPU Buffer erzeugt mit der ID: " << bufferId << "\n";
		glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * numVertices, data, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0); //Datenstrucktur an openGL übermitteln 0 weil nur 1 attribut (Vertex)
		glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(Vertex), 0); //Daten beschreiben 0=Welches attribut, 3=wieviele daten pro attribut, false=normaliesiern d.h specktrum anpassen, fröße des datentyps, offset bis ersten relevanten date d.h cod x
	}
	virtual ~VertexBuffer() {
		glDeleteBuffers(1, &bufferId);
	}

	void bind() {
		glBindVertexArray(vao);
		
		//glBindBuffer(GL_ARRAY_BUFFER, bufferId);
		//glEnableVertexAttribArray(0); //Datenstrucktur an openGL übermitteln 0 weil nur 1 attribut (Vertex)
		//glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(Vertex), 0); //Daten beschreiben 0=Welches attribut, 3=wieviele daten pro attribut, false=normaliesiern d.h specktrum anpassen, fröße des datentyps, offset bis ersten relevanten date d.h cod x
	}
	void unbind() {
		glBindVertexArray(0);
		//glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
private:
	GLuint bufferId;
	GLuint vao;
};

