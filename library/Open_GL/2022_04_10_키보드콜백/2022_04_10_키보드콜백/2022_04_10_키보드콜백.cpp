// 2022_4_10_drawSquare2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
//#include <GL/GL.h>
//#include <GL/GLU.h>
#include <GL/glut.h>


void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
		glVertex3f(-0.5, -0.5, 0.0);
		glVertex3f(0.5, -0.5, 0.0);
		glVertex3f(0.5, 0.5, 0.0);
		glVertex3f(-0.5, 0.5, 0.0);
	glEnd();
	glFlush();
}

void MyKeyboard(unsigned char KeyPressed, int X, int Y)
{
	switch (KeyPressed)
	{
		case 'Q':
			exit(0);
			break;
		case 'q':
			exit(0);
			break;
		case 27:
			exit(0);
			break;
	}
}

int main(int argc, char* argv)
{
	glutInit(&argc, &argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	
	glutCreateWindow("OpenGL Sample drawing");
	
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); //어떻게 보면 view volume즉 가시화 부피를 결정하는 것이다,
	
	glutDisplayFunc(MyDisplay);
	glutKeyboardFunc(MyKeyboard);
	
	glutMainLoop();
	return 0;
}


