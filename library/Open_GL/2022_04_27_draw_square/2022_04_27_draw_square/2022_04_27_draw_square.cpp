// 2022_04_27_draw_square.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <GL/glut.h>


void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT); //화면 clear
	glBegin(GL_POLYGON); //그래픽 object를 선언 
		glVertex3f(-0.5, -0.5, 0.0);
		glVertex3f(0.5, -0.5, 0.0);
		glVertex3f(0.5, 0.5, 0.0);
		glVertex3f(-0.5, 0.5, 0.0);
		//좌표 지정 
	glEnd(); //그래픽 object 내용 마무리 
	glFlush(); //버퍼에 있는 내용 그리도록함 
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv); //glut 라이브러리 초기화
	glutCreateWindow("OpenGL_drawing_example"); //윈도우 생성 
	glutDisplayFunc(MyDisplay); //display 함수 지정 
	glutMainLoop(); //메인루프 돌입 
	return 0;
}

