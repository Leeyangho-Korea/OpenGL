#include <gl/glut.h>  // OpenGL 및 GLUT 라이브러리 포함
#include <iostream>
using namespace std;

void myinit(void)
{
	glClearColor(0.7, 0.8, 0.7, 0.0);  // 배경색 설정
	glMatrixMode(GL_PROJECTION);  // 행렬 모드를 설정하여 투영 변환을 수행
	glLoadIdentity();  // 현재 행렬을 초기화
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);  // 2D 좌표를 설정
}

void setPixel(GLint x, GLint y)
{
	glBegin(GL_POINTS);  // 점 그리기 시작
	glVertex2i(x, y);  // 정수 좌표 (x, y)에 점 그리기
	glEnd();  // 점 그리기 종료
}

void ellipseMidPoint()
{
	glColor3ub(rand() % 255, rand() % 255, rand() % 255);  // 랜덤한 색상으로 설정
	int rx = 100, ry = 120;  // 타원의 x축 반지름과 y축 반지름 설정
	int xCenter = 320, yCenter = 240;  // 타원의 중심 좌표 설정
	float x = 0;
	float y = ry;
	float p1 = ry * ry - (rx * rx) * ry + (rx * rx) * (0.25);  // 결정 변수 p1 초기화
	float dx = 2 * (ry * ry) * x;
	float dy = 2 * (rx * rx) * y;

	// 타원을 그리는 반복문
	while (dx < dy)
	{
		// 타원을 그리는 점들을 설정
		setPixel(xCenter + x, yCenter + y);
		setPixel(xCenter - x, yCenter + y);
		setPixel(xCenter + x, yCenter - y);
		setPixel(xCenter - x, yCenter - y);
		if (p1 < 0)
		{
			x = x + 1;
			dx = 2 * (ry * ry) * x;
			p1 = p1 + dx + (ry * ry);
		}
		else
		{
			x = x + 1;
			y = y - 1;
			dx = 2 * (ry * ry) * x;
			dy = 2 * (rx * rx) * y;
			p1 = p1 + dx - dy + (ry * ry);
		}
	}
	glFlush();  // 그리기 명령을 실행
	float p2 = (ry * ry) * (x + 0.5) * (x + 0.5) + (rx * rx) * (y - 1) * (y - 1) - (rx * rx) * (ry * ry);
	glColor3ub(rand() % 255, rand() % 255, rand() % 255);  // 랜덤한 색상으로 설정
	// 타원을 그리는 반복문
	while (y > 0)
	{
		// 타원을 그리는 점들을 설정
		setPixel(xCenter + x, yCenter + y);
		setPixel(xCenter - x, yCenter + y);
		setPixel(xCenter + x, yCenter - y);
		setPixel(xCenter - x, yCenter - y);
		if (p2 > 0)
		{
			x = x;
			y = y - 1;
			dy = 2 * (rx * rx) * y;
			p2 = p2 - dy + (rx * rx);
		}
		else
		{
			x = x + 1;
			y = y - 1;
			dx = dx + 2 * (ry * ry);
			dy = dy - 2 * (rx * rx);
			p2 = p2 + dx - dy + (rx * rx);
		}
	}
	glFlush();  // 그리기 명령
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);  // 프레임 버퍼를 지우고 배경색으로 채움
	glColor3f(1.0, 0.0, 0.0);  // 선 및 다각형의 색상을 빨간색으로 설정
	glPointSize(2.0);  // 점의 크기를 설정
	ellipseMidPoint();  // 원을 그리는 함수 호출
	glFlush();  // 그리기 명령
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);  // GLUT 라이브러리 초기화
	glutInitWindowSize(640, 480);  // 윈도우의 초기 크기 설정
	glutInitWindowPosition(10, 10);  // 윈도우의 초기 위치 설정
	glutCreateWindow("Leeyangho_DrawCircle");  // 윈도우 생성 및 제목 설정
	myinit();  // OpenGL 초기화 함수 호출
	glutDisplayFunc(display);  // 디스플레이 콜백 함수 설정
	glutMainLoop();  // GLUT 이벤트 함수( 무한 루프 )
	return 0;
}