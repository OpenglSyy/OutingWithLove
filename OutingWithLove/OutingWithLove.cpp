#include"stdafx.h"

void worldInit(void){
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	glDepthRange(0.0, 1.0);

}

void drawGround(){
	int actorGroundColors[][3]{
		{ 128, 64, 0 },
		{ 128, 64, 0 },
		{ 128, 64, 0 },
		{ 128, 64, 0 }

	};
	int actorGroundVertexs[][3]{
		//顺时针
		{ -200, -50, 0 },//-x,-y front
		{ -100, 50, 0 },//right front
		{ 100, 50, 0 },//left middle
		{ 200, -50, 0 }//right middle
	};
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	//glColor3i(255, 0, 0);
	//重置当前指定的矩阵为单位矩阵,当您调用glLoadIdentity()之后，您实际上将当前点移到了屏幕中心，
	//X坐标轴从左至右，Y坐标轴从下至上，Z坐标轴从里至外。
	glBegin(GL_QUADS);
	for (int i = 0; i < 4; i++)
	{
		//glColor3i(actorGroundColors[i][0], actorGroundColors[i][1], actorGroundColors[i][2]);
		glColor3i(2147483647, 0, 0);
		glVertex3i(actorGroundVertexs[i][0], actorGroundVertexs[i][1], actorGroundVertexs[i][2]);
	}
	glEnd();
	glPopMatrix();
	glutSwapBuffers();
}
void myReshape(int width, int height){
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-200,200,-200,200,-200,200);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(400, 400);
	glutCreateWindow("OutingWithLove");


	worldInit();
	glutReshapeFunc(myReshape);
	glutDisplayFunc(&drawGround);
	glutMainLoop();


	return 0;
}

