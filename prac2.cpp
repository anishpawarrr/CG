# include<GL/freeglut.h>
# include<GL/gl.h>
#include<cmath>


void dispoint(int x, int y){
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POINTS);
		glVertex2i(x,y);
	glEnd();
}

void dispointf(float x, float y){
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POINTS);
		glVertex2f(x,y);
	glEnd();
}


void disline(int x1, int y1, int x2, int y2){
	float dx = x2-x1;
	float dy = y2-y1;
	int steps;
	if(abs(dx)>abs(dy)){
		steps = abs(dx);
		if(steps<0){
			steps = steps*-1;
		}
	}else{
		steps = abs(dy);
		if(steps<0){
			steps = steps*-1;
		}
	}
	float xinc = dx/steps;
	float yinc = dy/steps;
	float x = (x1);
	float y = (y1);
	while(steps--){
		dispointf((x),(y));
		x = x + xinc;
		y = y + yinc;
	}
}
void renderFunction0()
{	
	//float l = 50;
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    //glColor3f(1.0, 1.0,1.0);
    gluOrtho2D(0,1000,0,1000);
    //glBegin(GL_POLYGON);
       // glVertex2f(0.0, 0.0);
       // glVertex2f(1*l, 0.0);
        //glVertex2f(1*l, l);
        //glVertex2f(0.0, l);      
   // glEnd();
   // glColor3f(1.0, 0.0,0.0);
   // glBegin(GL_LINES);
    //	glVertex2f(50,0);
    //	glVertex2f(100,50);
   // glEnd();
	glBegin(GL_POINTS);
		disline(0,0,50,50 );
	glEnd();
    glFlush();
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(1000,1000);
    glutInitWindowPosition(100,100);
    glutCreateWindow("BMW");
    glutDisplayFunc(renderFunction0);
    glutMainLoop(); 


	return 0;
}
