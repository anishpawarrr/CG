#include <bits/stdc++.h>
#include <math.h>
# include<GL/freeglut.h>
# include<GL/gl.h>
#include <unistd.h>
 
using namespace std;

int xce, yce, Ra, ra, no;
void plot(int x, int y){
	glBegin(GL_POINTS);
		glVertex2i(x,y);
		for(int i=0;i<5;i++){
			sleep(0.9);
		}
		
	glEnd();
}

void circle(int xc, int yc, int r){
	int x = 0;
	int y = r;
	float p = 5/4 - r;
	plot(x+xc,y+yc);
	while(x<y){
		if(p<0){
			x++;
			p+=2*x+1;
		}else{
			x++;
			y--;
			p+=2*(x-y)+1;
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


void renderfunction(){
	glColor3f(1.0,0.0,0.0);
	circle(xce,yce,Ra);
	glColor3f(0.0,0.0,0.0);
	circle(xce,yce,int(Ra*0.9));
	Ra = Ra + ra;
	int x1 = Ra*0.259, y1 = Ra*0.966;
	int x2 = Ra*0.707, y2 = Ra*0.707;
	int x3 = Ra*0.966, y3 = Ra*0.259;
	glColor3f(1.0,0.0,1.0);
	circle(xce+x1,yce+y1,ra);
	circle(xce+x2,yce+y2,ra);
	circle(xce+x3,yce+y3,ra);
	
	circle(xce+x3,yce-y3,ra);
	circle(xce+x2,yce-y2,ra);
	circle(xce+x1,yce-y1,ra);
	
	circle(xce-x1,yce-y1,ra);
	circle(xce-x2,yce-y2,ra);
	circle(xce-x3,yce-y3,ra);
	
	circle(xce-x3,yce+y3,ra);
	circle(xce-x2,yce+y2,ra);
	circle(xce-x1,yce+y1,ra);

}

int main(int argc, char **argv){
	
	glutInit(&argc, argv);
   
    
	cout<<"Enter Radius of the circle\n";
	cin>>Ra;
	cout<<"Enter x-coordinate of centre of the circle\n";
	cin>>xce;
	cout<<"Enter y-coordinate of centre of the circle\n";
	cin>>yce;
	//cout<<"How many surrounding circles do you want?\n";
	//cin>>no;
	//float theta = 360/no;
	ra = Ra/2.88637;
	glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(800,800);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Circle");
	//float costheta = 
    glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(-1000,1000,-1000,1000);
	glPointSize(1.0);
    glutDisplayFunc(renderfunction);
    glutMainLoop(); 


	return 0;
	
	
}

