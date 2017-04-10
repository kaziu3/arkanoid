#include "scena.h"
#include <GL/freeglut.h>
#include <GL/gl.h>

cScena scena;

/***************/
void przerysuj()
{
	scena.rysuj();
}
/*******************/
cScena::cScena(){
	aktywny = -1;
}
/*******************/
void idle()
{
	scena.aktualizuj();
	glutPostRedisplay();
	Sleep(1);
}
/********************/
void cScena::aktualizuj()
{
	int czas = GetTickCount(); //zwraca czas w [ms]
	for (int i = 0; i< figury.size() - 1; i++)
		figury[i]->Aktualizuj(czas); //obliczanie nowych polozen
	//wykrywanie kolizji
	for (int i = 0; i< figury.size() - 1; i++)
	for (int j = i + 1; j<figury.size() - 1; j++)
	if (figury[i]->Kolizja(*figury[j])) //znajduje kolizje
	{
	// tu mozna zareagowac na kolizje np. usuwajac „zbity” obiekt itp...
	}
}
/*******************/
void cScena::rysuj(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	for (auto f = figury.begin(); f != figury.end(); f++)
	{
		(*f)->rysuj();
	}
	glPopMatrix();
	glutSwapBuffers();
}
/***************************************/
void cScena::init()
{
	cOkrag *okr = new cOkrag(0.05);
	okr->setPredkosc(0, -90);
	okr->setFizyka(8.91*1E-6, -90);
	okr->przesun(0, 0.2);
	figury.push_back(okr);
	cProstokat *pr0 = new cProstokat(0.2, 0.6);
	pr0->setPredkosc(0, 0);
	pr0->setFizyka(0, 0);
	pr0->przesun(0, -0.4);
	figury.push_back(pr0);
	cProstokat *pr1 = new cProstokat(0.6, 0.2);
	pr1->przesun(-0.4, -0.2);
	figury.push_back(pr1);
	cProstokat *pr2 = new cProstokat(0.6, 0.2);
	pr2->przesun(0.4, -0.2);
	figury.push_back(pr2);
}
/****************************************/
void cScena::inicjuj(){
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(800, 800);
	glutIdleFunc(idle);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);// | GLUT_DEPTH | GLUT_MULTISAMPLE);
	glutCreateWindow("Prostokaty");
	glClearColor(1, 1, 1, 1);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glutDisplayFunc(::przerysuj);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1, 1, -1, 1, -.1, .1);
	init();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

/*********************************************/