#include"stdafx.h"
#include"Ground.h"

void display(){
	Ground *grtound = new Ground();
	grtound->drawGround();
	delete grtound;
}

void worldInit(void){
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	glDepthRange(0.0, 1.0);
}

void myReshape(int width, int height){
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-400,400,-400,400,-400,400);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(800, 800);
	glutCreateWindow("OutingWithLove");

	worldInit();
	glutReshapeFunc(myReshape);
	glutDisplayFunc(&display);
	glutMainLoop();
	return 0;
}

