#include "stdafx.h"
#include "Colors.h"
#include "ColorUtil.h"

#ifndef _Ground_
#define _Ground_

class Ground{
public:
	Ground(){}
	~Ground(){}

public :
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
			{ -400, -400, 0 },//-x,-y front
			{ -300, -200, 0 },//right front
			{ 300, -200, 0 },//left middle
			{ 400, -400, 0 }//right middle
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
		delete cu;//释放指针空间	
		delete colors;//释放指针空间
		glEnd();
		glPopMatrix();
		glutSwapBuffers();
	}
};
#endif
