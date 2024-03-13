#include <gl/glut.h>  // OpenGL �� GLUT ���̺귯�� ����
#include <iostream>
using namespace std;

void myinit(void)
{
	glClearColor(0.7, 0.8, 0.7, 0.0);  // ���� ����
	glMatrixMode(GL_PROJECTION);  // ��� ��带 �����Ͽ� ���� ��ȯ�� ����
	glLoadIdentity();  // ���� ����� �ʱ�ȭ
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);  // 2D ��ǥ�� ����
}

void setPixel(GLint x, GLint y)
{
	glBegin(GL_POINTS);  // �� �׸��� ����
	glVertex2i(x, y);  // ���� ��ǥ (x, y)�� �� �׸���
	glEnd();  // �� �׸��� ����
}

void ellipseMidPoint()
{
	glColor3ub(rand() % 255, rand() % 255, rand() % 255);  // ������ �������� ����
	int rx = 100, ry = 120;  // Ÿ���� x�� �������� y�� ������ ����
	int xCenter = 320, yCenter = 240;  // Ÿ���� �߽� ��ǥ ����
	float x = 0;
	float y = ry;
	float p1 = ry * ry - (rx * rx) * ry + (rx * rx) * (0.25);  // ���� ���� p1 �ʱ�ȭ
	float dx = 2 * (ry * ry) * x;
	float dy = 2 * (rx * rx) * y;

	// Ÿ���� �׸��� �ݺ���
	while (dx < dy)
	{
		// Ÿ���� �׸��� ������ ����
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
	glFlush();  // �׸��� ����� ����
	float p2 = (ry * ry) * (x + 0.5) * (x + 0.5) + (rx * rx) * (y - 1) * (y - 1) - (rx * rx) * (ry * ry);
	glColor3ub(rand() % 255, rand() % 255, rand() % 255);  // ������ �������� ����
	// Ÿ���� �׸��� �ݺ���
	while (y > 0)
	{
		// Ÿ���� �׸��� ������ ����
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
	glFlush();  // �׸��� ���
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);  // ������ ���۸� ����� �������� ä��
	glColor3f(1.0, 0.0, 0.0);  // �� �� �ٰ����� ������ ���������� ����
	glPointSize(2.0);  // ���� ũ�⸦ ����
	ellipseMidPoint();  // ���� �׸��� �Լ� ȣ��
	glFlush();  // �׸��� ���
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);  // GLUT ���̺귯�� �ʱ�ȭ
	glutInitWindowSize(640, 480);  // �������� �ʱ� ũ�� ����
	glutInitWindowPosition(10, 10);  // �������� �ʱ� ��ġ ����
	glutCreateWindow("Leeyangho_DrawCircle");  // ������ ���� �� ���� ����
	myinit();  // OpenGL �ʱ�ȭ �Լ� ȣ��
	glutDisplayFunc(display);  // ���÷��� �ݹ� �Լ� ����
	glutMainLoop();  // GLUT �̺�Ʈ �Լ�( ���� ���� )
	return 0;
}