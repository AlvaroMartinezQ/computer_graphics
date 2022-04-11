#include <GL/glut.h>

static int year = 0, day = 0;

void dayAdd()
{
	day = (day + 10) % 360;
}

void daySubtract()
{
	day = (day - 10) % 360;
}

void yearAdd()
{
	year = (year + 5) % 360;
}

void yearSubtract()
{
	year = (year - 5) % 360;
}

void reshape(GLsizei w, GLsizei h)
{
	if (w == 0 || h == 0) return;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHT0);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef (0.0, 0.0, -5.0);
	
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(0.99, 0.55, 0.01);
	
	glPushMatrix();
		/* Dibuja el sol */
		glPushMatrix();
			glRotatef (90.0, 1.0, 0.0, 0.0); /* rotación para poner en vertical */
			glutSolidSphere (1.0, 20, 20);
		glPopMatrix();
		/* Situa el planeta */
		glTranslatef (2.5, 0.0, 0.0);
		glRotatef (90.0, 1.0, 0.0, 0.0); /* rotación para poner en vertical */
		/* Dibuja el planeta */
		glColor3f (0.0, 0.0, 1.0);
		glutWireSphere (0.4, 20, 20);
	glPopMatrix();
	
	glDisable(GL_COLOR_MATERIAL);
	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
		
	glFlush();
}

void init() 
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

/* Programa principal.
* Abre la ventana con el tamaño inicial, una barra de titulo,
* modo de pantalla RGBA, y maneja los eventos de entrada.
*/
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(20, 20);
	glutCreateWindow("Composición de transformaciones de modelado");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return(0);
}
