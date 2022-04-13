// Librerias
#include <GL/glut.h>

// Variables
GLint ancho = 600;
GLint alto = 1000;

static int year = 0, day = 0;
static bool rotate = false;

// Funciones //
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
	if (w == 0 || h == 0)
		return;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_LIGHT0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);

	glEnable(GL_COLOR_MATERIAL);
	glColor3f(0.99, 0.55, 0.01);

	glPushMatrix(); // Sol color amarillo
    	// Sol
    	glPushMatrix();
    
    	glPushMatrix();
    	
            glRotatef(90, 1.0, 0.0, 0.0);
        	glutSolidSphere(1.0, 20, 20);
    	
        glPopMatrix();
    
    	glPushMatrix(); // Planeta verde
    	
        	glRotatef(year, 0.0, 0.0, 1.0);
        	glTranslatef(0.0, 1.5, 0.0);
        	glColor3f(0.0, 1.0, 0.0);
        	glutSolidSphere(0.35, 20, 20);
    	
        glPopMatrix();
    
    	glPushMatrix(); // Planeta y satelite color azul y rojo respectivamente
    	
            glRotatef(year, 0.0, 1.0, 0.0);
        	glTranslatef(3.5, 0.0, 0.0);
        	glRotatef(day, 0.0, 1.0, 0.0);
        	glColor3f(0.0, 0.0, 1.0);
        	glutWireSphere(0.4, 20, 20);
        
        	// Satelite del planeta
        	glTranslatef(1.0, 0.0, 0.0);
        	glRotatef(day, 0.0, 1.0, 0.0);
        	glColor3f(1.0, 0.0, 0.0);
        	glutWireSphere(0.2, 10, 5);
    	
        glPopMatrix();
	
    glPopMatrix();

	glDisable(GL_COLOR_MATERIAL);
	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	// glutSwapBuffers();
	glFlush();
	
	if (rotate) {
       yearAdd();
	   dayAdd();
    }
}

void initialize()
{
	glClearColor(1.f, 1.f, 1.f, 1.f);
}

void init()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glEnable(GL_LIGHTING);
	glShadeModel(GL_FLAT);
}

// Acciones de teclas
void specialKeyboard(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		dayAdd();
		break;
	case GLUT_KEY_DOWN:
		daySubtract();
		break;
	case GLUT_KEY_LEFT:
		yearSubtract();
		daySubtract();
		break;
	case GLUT_KEY_RIGHT:
		yearAdd();
		dayAdd();
		break;
	case GLUT_KEY_F1:
		rotate = true;
		// glutTimerFunc();
		break;
	case GLUT_KEY_F2:
		rotate = false;
		// glutTimerFunc();
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

// Timer
void timer (int i) {
     glutTimerFunc(100, timer, i);
     glutPostRedisplay();
}

/* Programa principal.
 * Abre la ventana con el tamanyo inicial, una barra de titulo,
 * modo de pantalla RGBA, y maneja los eventos de entrada.
 */
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(alto, ancho);
	glutInitWindowPosition(20, 20);
	glutCreateWindow("Practica OpenGL URJC - Sistema planetario");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutSpecialFunc(specialKeyboard);
	glEnable(GL_DEPTH_TEST);
	glutTimerFunc(1000, timer, 1);
	glutMainLoop();
	return (0);
}
