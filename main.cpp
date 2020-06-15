#include <windows.h>
#include <gl/glut.h>
#include <cmath>
#define M_PI 3.14

void init(void)
{
	glClearColor(0.0,0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glLineWidth(2.0);
	glOrtho(-15.0, 15.0, -15.0, 15.0, -15.0, 15.0);
	glViewport(40, 400, 60, 300);
}

void spiral(int n_angle, float cx, float cy, float radius, float rotAngle)
{
    double angle , angleInc;
	int k;
	if(n_angle > 3)
    {
        angle = rotAngle * M_PI / 180;
        angleInc = 2 * M_PI /n_angle;
        glVertex2f(radius * cos(angle) + cx, radius * sin(angle)+cy);

        for(k = 0; k < n_angle; k++)
        {
            angle += angleInc;
            glVertex2f(radius * cos(angle) + cx, radius * sin(angle) + cy);
        }
	}
	else return;
}


void display(void)
{
	double angleInc = 2 * M_PI / 33, i;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_STRIP);
    for(i = 0; i < 10 ; i += angleInc)
    {
        glColor3f(0.7,(150+i)/255.0f,(50.6-i)/255.0f);
        spiral(6,0,0,i+0.25,180-i*6);
    }
	glEnd();
	glFlush();
	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500,400);
	glutInitWindowPosition(50 , 50);
	glutCreateWindow("Cahyo Nugroho - 672018039");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
