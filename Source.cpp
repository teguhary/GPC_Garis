#include <stdlib.h>
#include <GL\glut.h>
#include <cstdlib>
#include <iostream>


using namespace std;
void sumbu() {
	glPushMatrix();
	glBegin(GL_LINES);
	glVertex3f(0, 0, 0.0);
	glVertex3f(0, 1, 0.0);
	glVertex3f(0, 0, 0.0);
	glVertex3f(1, 0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glPopMatrix();
	glEnd();
	glFlush();
}
void Diagonal() {
	float a, b, c, d;
	cout << "Masukan X0 : "; cin >> a;
	cout << "Masukan Y0 : "; cin >> b;
	cout << "Masukan X1 : "; cin >> c;
	cout << "Masukan Y1 : "; cin >> d;
	glPushMatrix();
	glBegin(GL_LINES);
	glVertex3f(a + 0.5, b + 0.5, 0.0);
	glVertex3f(c + 0.5, d + 0.5, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glPopMatrix();
	glEnd();
	glFlush();
}
void Horizontal() {
	float c, d, y;
	cout << "Masukan X0 : "; cin >> c;
	cout << "Masukan X1 : "; cin >> d;
	cout << "Masukan Y : "; cin >> y;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	glVertex3f(c + 0.1, y + 0.1, 0.0);
	glVertex3f(d + 0.1, y + 0.1, 0.0);
	glEnd();
	glFlush();
}
void Vertikal() {
	float a, b, x;
	cout << "Masukan Y0 : "; cin >> a;
	cout << "Masukan Y1 : "; cin >> b;
	cout << "Masukan X : "; cin >> x;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	glVertex3f(x + 0.5, a + 0.5, 0.0);
	glVertex3f(x + 0.5, b + 0.5, 0.0);
	glEnd();
	glFlush();
}
void Initialize() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}
int main(int iArgc, char** cppArgv) {
menu:
	int a;
	cout << "--------MENU-------\n";
	cout << "1.Garis Vertikal\n";
	cout << "2.Garis Horizontal\n";
	cout << "3.Garis Diagonal\n";
	cout << "4.Exit\n";
	cout << "------------------ \n";
	cout << "Masukan pilihan anda : "; cin >> a;
	cout << "\n"; glutInit(&iArgc, cppArgv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(600, 200);
	glutCreateWindow("OPenGL with C++");
	Initialize();
	while (a <= 4) {
		switch (a) {
		case 1:
			glutDisplayFunc(Vertikal);
			glutMainLoop();
			return 0;
		case 2:
			glutDisplayFunc(Horizontal);
			glutMainLoop();
			return 0;
		case 3:
			glutDisplayFunc(Diagonal);
			glutMainLoop();
			return 0;
		default: cout << "anda salah memasukan"; goto menu;
		}
	}
}