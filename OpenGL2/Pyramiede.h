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

	void drehen (float gradY) {

		float x, y, z;
		
		//point a
		x = a.getX();
		y = a.getY();
		z = a.getZ();
		a.setX(x * cos(gradY) + z * sin(gradY));
		a.setZ(z * cos(gradY) + x * -sin(gradY));


        //point b
		x = b.getX();
		y = b.getY();
		z = b.getZ();
		b.setX(x * cos(gradY) + z * sin(gradY));
		b.setZ(z * cos(gradY) + x * -sin(gradY));

		//point c
		x = c.getX();
		y = c.getY();
		z = c.getZ();
		c.setX(x * cos(gradY) + z * sin(gradY));
		c.setZ(z * cos(gradY) + x * -sin(gradY));

		//point s
		x = s.getX();
		y = s.getY();
		z = s.getZ();
		s.setX(x * cos(gradY) + z * sin(gradY));
		s.setZ(z * cos(gradY) + x * -sin(gradY));


		std::cout << "x:" << a.getX() << "\ty: " << a.getZ() << "\n";
		init();
	}


	//c.setX(c.getX()* cos(gradY) + c.getY() * -sin(gradY));
	//c.setY(c.getX()* sin(gradY) + c.getY() * cos(gradY));

	void skalieren(float x) {
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
	}


	void verschieben(float x, float y, float z) {
		a.setX(a.getX() + x);
		a.setY(a.getY() + y);
		a.setZ(a.getZ() + z);

		b.setX(b.getX() + x);
		b.setY(b.getY() + y);
		b.setZ(b.getZ() + z);

		c.setX(c.getX() + x);
		c.setY(c.getY() + y);
		c.setZ(c.getZ() + z);

		s.setX(s.getX() + x);
		s.setY(s.getY() + y);
		s.setZ(s.getZ() + z);
		init();
	}


};
