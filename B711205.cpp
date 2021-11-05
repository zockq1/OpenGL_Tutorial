#include "pch.h"
#include "B711205.h"

void B711205::DrawXYZ() {//�� �׸���
	glDisable(GL_LIGHTING);//������ Ű�� xyz�� ������ ȸ���� �Ǿ Light ����, ���п��� Normal�� ��� �׷� �� �����ϴ�.

	glBegin(GL_LINE_LOOP);//X��
	glColor3f(0, 1, 0);
	glVertex3f(10, 0, 0);
	glVertex3f(-10, 0, 0);
	glEnd();

	glBegin(GL_LINE_LOOP);//Y��
	glColor3f(1, 0, 0);
	glVertex3f(0, 10, 0);
	glVertex3f(0, -10, 0);
	glEnd();

	glBegin(GL_LINE_LOOP);//Z��
	glColor3f(0, 0, 1);
	glVertex3f(0, 0, 10);
	glVertex3f(0, 0, -10);
	glEnd();
}

void B711205::DrawCube() {//������ü �׸���
	glBegin(GL_TRIANGLE_FAN); //+X�� ���� ��
	glNormal3f(1, 0, 0);

	glColor3f(0.4, 0.7, 1);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);

	glEnd();

	glBegin(GL_TRIANGLE_FAN); //-X�� ���� ��
	glNormal3f(-1, 0, 0);

	glColor3f(0.4, 0.7, 1);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);

	glEnd();

	glBegin(GL_TRIANGLE_FAN); //+Y�� ���� ��
	glNormal3f(0, 1, 0);

	glColor3f(0.4, 0.7, 1);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);

	glEnd();

	glBegin(GL_TRIANGLE_FAN); //+Y�� ���� ��
	glNormal3f(0, -1, 0);

	glColor3f(0.4, 0.7, 1);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);

	glEnd();


	glBegin(GL_TRIANGLE_FAN); //+Z�� ���� ��
	glNormal3f(0, 0, 1);

	glColor3f(0.4, 0.7, 1);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);

	glEnd();

	glBegin(GL_TRIANGLE_FAN); //-Z�� ���� ��
	glNormal3f(0, 0, -1);

	glColor3f(0.4, 0.7, 1);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);

	glEnd();
}

void B711205::SetLight() {
	glEnable(GL_LIGHTING);
	
	glEnable(GL_LIGHT0); //������ ����(Ambient)
	GLfloat amb_color[] = { 0.5, 0.5, 0.5, 1.0 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, amb_color);


	glEnable(GL_LIGHT1); //�ʱ� ��ġ (3.0, 3.0, 6.0, 1.0)���� ���۵Ǵ� ����(Diffuse)
	GLfloat dif_pos[] = { 3.0, 3.0, 6.0, 1.0 };
	GLfloat dif_color[] = { 1.0, 1.0, 1.0, 1.0 };
	glLightfv(GL_LIGHT1, GL_POSITION, dif_pos);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, dif_color);



	GLfloat mat_color[] = { 0.10, 0.50, 0.80, 1.0 }; //cube�� ����
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_color);
	
}

void B711205::SetSpotLight() {
	glEnable(GL_LIGHTING);

	glEnable(GL_LIGHT2); //Spot light ����
	GLfloat spot_pos[] = { 1.0, 2.0, 3.0, 1.0 };
	GLfloat amb_color[] = { 0.5, 0.5, 0.5, 1.0 };
	GLfloat dif_color[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat spot_direction[] = { -1.0, -2.0, -3.0, 1.0 };
	glLightfv(GL_LIGHT2, GL_AMBIENT, amb_color);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, dif_color);
	glLightfv(GL_LIGHT2, GL_POSITION, spot_pos);
	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 10.0);
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spot_direction);



	GLfloat mat_color[] = { 0.10, 0.50, 0.80, 1.0 }; //cube�� ����
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_color);

}