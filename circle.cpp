# include<GL/freeglut.h>
# include<GL/gl.h>
#include<math.h>
#include <iostream>
 
// Library effective with Windows
//#include <windows.h>
 
// Library effective with Linux
#include <unistd.h>

void plot(int x, int y){
	glBegin(GL_POINTS);
		glVertex2i(x,y);
		sleep(0.9999999999999);
	glEnd();
}

void circle(int xc, int yc, int r){
	int x = 0;
	int y = r;
	float decision = 5/4 - r;
	plot(x+xc,y+yc);
	while(x<y){
		if(decision<0){
			x++;
			decision+=2*x+1;
		}else{
			x++;
			y--;
			decision+=2*(x-y)+1;
		}
		plot(x+xc,y+yc);
		plot(y+xc,x+yc);
		plot(-x+xc,y+yc);
		plot(-y+xc,x+yc);
		plot(-y+xc,-x+yc);
		plot(-x+xc,-y+yc);
		plot(x+xc,-y+yc);
		plot(y+xc,-x+yc);
	}
	sleep(1);
	glFlush();
}


void renderFunction(){
	glColor3f (0.0, 1.0, 0.0);
	circle(0,-400,400);
	circle(0,400,400);
	circle(400,0,400);
	circle(-400,0,400);
	glColor3f (1.0, 0.0, 0.0);
	circle(200,200,400/pow(2,0.5));
	circle(-200,200,400/pow(2,0.5));
	circle(200,-200,400/pow(2,0.5));
	circle(-200,-200,400/pow(2,0.5));
	glColor3f (0.0, 0.0, 1.0);
	circle(0,0,800);
	glColor3f (1.0, 1.0, 1.0);
	circle(0,0,400*pow(2,0.5));
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(800,800);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Circle");
    glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(-900,900,-900,900);
	//glClear (GL_COLOR_BUFFER_BIT);
	//glColor3f (1.0, 0.0, 0.0);
	glPointSize(1.0);
    glutDisplayFunc(renderFunction);
    glutMainLoop(); 


	return 0;
}
