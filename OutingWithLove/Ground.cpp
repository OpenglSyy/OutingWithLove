#include "stdafx.h"
#include"ColorUtil.h"
#include"Colors.h"

void drawGround(){
	ColorUtil *cu = new ColorUtil();
	Colors    *colors = new Colors();
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
		glColor3f(cu->rgbIntToFloat(colors->groundbrown[0]), cu->rgbIntToFloat(colors->groundbrown[1]), cu->rgbIntToFloat(colors->groundbrown[2]));
		glVertex3i(actorGroundVertexs[i][0], actorGroundVertexs[i][1], actorGroundVertexs[i][2]);
	}
	delete cu;
	delete colors;
	glEnd();
	glPopMatrix();
	glutSwapBuffers();
}