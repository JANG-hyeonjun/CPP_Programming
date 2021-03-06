// 2022_04_23_매뉴콜백.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <gl/glut.h>

GLboolean IsSphere = true;

void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.0, 0.5);
	if (IsSphere)
	{
		glutWireSphere(0.2, 15, 15);
	}
	else
	{
		glutWireTorus(0.1, 0.3, 40, 20);
	}
	glFlush();
}

void MyMainMenu(int entryID)
{
	if (entryID == 1)
	{
		IsSphere = true;
	}
	else if (entryID == 2)
	{
		IsSphere = false;
	}
	else
	{
		exit(0);
	}
	glutPostRedisplay();
}

int main(int argc,char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowPosition(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Example Programmming");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
	glutAddMenuEntry("Draw Sphere", 1);
	glutAddMenuEntry("Draw Torus", 2);
	glutAddMenuEntry("EXIT", 3);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutDisplayFunc(MyDisplay);
	glutMainLoop();

	return 0;
}