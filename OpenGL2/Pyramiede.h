#pragma once
#include "Defines.h"
#include "VertexBuffer.h"
class Pyramiede {
private:
	Vertex boden[3];
	Vertex seite1[3];
	Vertex seite2[3];
	Vertex seite3[3];
	int numVertices = 3;

	Vertex a, b, c, s;

	void init() {
		boden[0] = a;
		boden[1] = b;
		boden[2] = c;

		seite1[0] = c;
		seite1[1] = a;
		seite1[2] = s;

		seite2[0] = a;
		seite2[1] = b;
		seite2[2] = s;

		seite3[0] = b;
		seite3[1] = c;
		seite3[2] = s;
	}

public:
	Pyramiede(Vertex a, Vertex b, Vertex c, Vertex s) {
		this->a = a;
		this->b = b;
		this->c = c;
		this->s = s;
	}

	void draw() {
		init();
		VertexBuffer bodenVertex(boden, numVertices);
		VertexBuffer seite1Vertex(seite1, numVertices);
		VertexBuffer seite2Vertex(seite2, numVertices);
		VertexBuffer seite3Vertex(seite3, numVertices);

		bodenVertex.bind();
		glDrawArrays(GL_TRIANGLES, 0, numVertices);
		
		seite1Vertex.bind();
		glDrawArrays(GL_TRIANGLES, 0, numVertices);

		seite2Vertex.bind();
		glDrawArrays(GL_TRIANGLES, 0, numVertices);

		seite3Vertex.bind();
		glDrawArrays(GL_TRIANGLES, 0, numVertices);
		seite3Vertex.unbind();
	}

	void drehen (int gradZ) {
		a.setX(a.getX() * cos(gradZ) + a.getY()* sin(gradZ));
		a.setY(-a.getX() * sin(gradZ) + a.getY() * cos(gradZ));
		b.setX(b.getX() * cos(gradZ) + b.getY() * sin(gradZ));
		b.setY(-b.getX() * sin(gradZ) + b.getY() * cos(gradZ));
		c.setX(c.getX() * cos(gradZ) + c.getY() * sin(gradZ));
		c.setY(-c.getX() * sin(gradZ) + c.getY() * cos(gradZ));
		init();
	}

	bool skalieren(float x) {
//		if (a.getX() * x <= 1.0f && a.getX() * x >= 0.0f &&
//			a.getY() * x <= 1.0f && a.getY() * x >= 0.0f &&
//			a.getZ() * x <= 1.0f && a.getZ() * x >= 0.0f &&
//			b.getX() * x <= 1.0f && b.getX() * x >= 0.0f &&
//			b.getY() * x <= 1.0f && b.getY() * x >= 0.0f &&
//			b.getZ() * x <= 1.0f && b.getZ() * x >= 0.0f &&
//			c.getX() * x <= 1.0f && c.getX() * x >= 0.0f &&
//			c.getY() * x <= 1.0f && c.getY() * x >= 0.0f &&
//			c.getZ() * x <= 1.0f && c.getZ() * x >= 0.0f &&
//			s.getX() * x <= 1.0f && s.getX() * x >= 0.0f &&
//			s.getY() * x <= 1.0f && s.getY() * x >= 0.0f &&
//			s.getZ() * x <= 1.0f && s.getZ() * x >= 0.0f) {

			a.setX(a.getX() * x);
			a.setY(a.getY() * x);
			a.setZ(a.getZ() * x);

			b.setX(b.getX() * x);
			b.setY(b.getY() * x);
			b.setZ(b.getZ() * x);

			c.setX(c.getX() * x);
			c.setY(c.getY() * x);
			c.setZ(c.getZ() * x);

			s.setX(s.getX() * x);
			s.setY(s.getY() * x);
			s.setZ(s.getZ() * x);
			init();
			return true;
//		}
//		return false;
	}
};
