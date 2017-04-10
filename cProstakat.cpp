#include "cProstokat.h"
#include <GL/freeglut.h>
#include <GL/gl.h>

cProstokat::cProstokat(){
	h = 0.1; w = 0.2;
}
/**************************/
cProstokat::cProstokat(float _h, float _w)
{
	w = _w; h = _h; 
	setGeometria(x, y, -(w / 2), -(h / 2),  (w / 2),  (h / 2));
}
/**************************/
void cProstokat::rysuj(){
	glPushMatrix();
	glColor3f(R, G, B);
	glTranslatef(x, y, 0);
	glRotated(0, 1.0, 0.0, 0.0);
	glRotated(0, 0.0, 1.0, 0.0);
	glRotated(alpha, 0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	{
		glVertex3d(-w / 2, h / 2, 0);
		glVertex3d(w / 2, h / 2, 0);
		glVertex3d(w / 2, -h / 2, 0);
		glVertex3d(-w / 2, -h / 2, 0);
	}
	glEnd();
	glPopMatrix();
}
/****************************/
bool cProstokat::czy_kliknieto(float xf, float yf){
	if (fabs(xf - x) < w / 2 && fabs(yf - y) < h / 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}
/****************************/