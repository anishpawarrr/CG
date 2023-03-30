#include <GL/freeglut.h>
#include <GL/gl.h>

void renderFunction0()
{	
	float l = 1;
    glClearColor(0.5, 0.5, 0.5, 0.5);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0,1.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glBegin(GL_POLYGON);
        glVertex2f(0.0, 0.0);
        glVertex2f(-1*l, 0.0);
        glVertex2f(-1*l, l);
        glVertex2f(0.0, l);      
    glEnd();
    glColor3f(0.0, 0.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(0.0, 0.0);
        glVertex2f(l, 0.0);
        glVertex2f(l, l);
        glVertex2f(0.0, l);      
    glEnd();
    glColor3f(0.0, 0.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(0.0, 0.0);
        glVertex2f(-1*l, 0.0);
        glVertex2f(-1*l, -1*l);
    glBegin(GL_POLYGON);
        glVertex2f(0.0, 0.0);
        glVertex2f(l, 0.0);
        glVertex2f(l, -1*l);
        glVertex2f(0.0, -1*l);      
    glEnd();
    glFlush();
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Prac2");
    glutDisplayFunc(renderFunction0);
    glutMainLoop();    
    return 0;
}
        glVertex2f(0.0, -1*l);      
    glEnd();
    glColor3f(1.0, 1.0,1.0);
