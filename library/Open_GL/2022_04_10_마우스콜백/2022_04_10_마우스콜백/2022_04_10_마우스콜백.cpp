#include <GL/glut.h>

GLint TopLeft_X, TopLeft_Y, BottomRight_X, BottomRight_Y;

void MyDisplay()
{
	glViewport(0, 0, 300, 300);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
		glVertex3f(TopLeft_X / 300.0, (300.0 - TopLeft_Y) / 300.0, 0.0);
		glVertex3f(TopLeft_X / 300.0, (300.0 - BottomRight_Y) / 300.0, 0.0);
		glVertex3f(BottomRight_X / 300.0, (300.0 - BottomRight_Y) / 300.0, 0.0);
		glVertex3f(BottomRight_X / 300.0, (300.0 - TopLeft_Y) / 300.0, 0.0);
	glEnd();
	glFlush();
}

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y)
{
	if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN)
	{
		TopLeft_X = X;
		TopLeft_Y = Y;
	}
}

void MyMouseMove(GLint X, GLint Y)
{
	BottomRight_X = X;
	BottomRight_Y = Y;
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	
	glutCreateWindow("Open Gl Drawing Example");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
	
	glutDisplayFunc(MyDisplay);
	glutMouseFunc(MyMouseClick);
	glutMotionFunc(MyMouseMove);
	
	glutMainLoop();
	return 0;
}

