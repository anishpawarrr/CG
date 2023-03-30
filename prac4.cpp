# include<GL/freeglut.h>
# include<GL/gl.h>
#include<math.h>
#define xsize 1000
#define ysize 1000
void renderFunctionline(int xi, int yi, int xf, int yf){
	//int xi = 1;
	//int yi = 1;
	//int xf = 100;
	//int yf = 100;
	//glClearColor(1.0, 1.0, 1.0, 0.0);
	//glClear(GL_COLOR_BUFFER_BIT);
	//gluOrtho2D(0,1000,0,1000);
	int x = xi, y = yi;
	int dx = xf-xi;
	int dy = yf-yi;
	dx = abs(dx);
	dy = abs(dy);
	int xch =1, ych = 1;
	if(xi>xf){
		xch = -1*xch;
	}
	if(yi>yf){
		ych = -1*ych;
	}
	glColor3f(0.0,0.0,0.0);
	if(dx==0){
		glBegin(GL_POINTS);
			for(int i=0;i<dy;i++){
				glVertex2i(x,y);
				y = y + ych;
			}
		glEnd();
		//glFlush();
		//return;
	}else if(dy==0){
		glBegin(GL_POINTS);
			for(int i=0;i<dx;i++){
				glVertex2i(x,y);
				x = x + xch;
			}
		glEnd();
		//glFlush();
		//return;
	}else{
		glBegin(GL_POINTS);
			glVertex2i(x,y);
		if(dx>dy){
			int p = 2*dy-dx;
			for(int i=0;i<dx;i++){
				if(p>0){
					y = y + ych;
					p = p + 2*(dy-dx);
				}else{
					p = p + 2*dx;
				}
				x = x + xch;
				glVertex2i(x,y);
			}
		glEnd();
		//glFlush();
			//return;
		}else{
			int p = 2*dx-dy;
			for(int i=0;i<dy;i++){
				if(p>0){
					x = x + xch;
					p = p + 2*(dx-dy);
				}else{
					p = p + 2*dx;
				}
				y = y + ych;
				glVertex2i(x,y);
			}
		glEnd();
		//glFlush();
			//return;
		}
	}
	return;
}
void renderFunctionrec(int x0,int y0,int x1,int y1,int x2,int y2,int x3,int y3, int rects){
	renderFunctionline(x0,y0,x1,y1);
	renderFunctionline(x0,y0,x3,y3);
	renderFunctionline(x3,y3,x2,y2);
	renderFunctionline(x1,y1,x2,y2);
	int xt0 = x0,yt0 = y0,xt1 = x1,yt1 = y1,xt2 = x2,yt2 = y2,xt3 = x3,yt3 = y3;
	x0 = (xt0+xt3)/2;
	x1 = (xt0+xt1)/2;
	x2 = (xt1+xt2)/2;
	x3 = (xt2+xt3)/2;
	y0 = (yt0+yt3)/2;
	y1 = (yt0+yt1)/2;
	y2 = (yt1+yt2)/2;
	y3 = (yt2+yt3)/2;
	if(rects--){
		renderFunctionrec(x0,y0,x1,y1,x2,y2,x3,y3,rects);
	}
	return;
	
}

void shapefunc(int x0,int y0,int x1,int y1,int x2,int y2,int x3,int y3,int num){
	int ch = 50;
	int p0x,p0y,p1x,p1y,p2x,p2y,p3x,p3y,p4x,p4y,p5x,p5y;
		p0x = (x0+x1)/2;
		p0y = (y0+y1)/2;
		p1x = (x1+x2)/2;
		p1y = (3*y2+y1)/4;
		p5x = (x0+x3)/2;
		p5y = (3*y3+y0)/4;
		p3x = (x1+x0)/2;
		p3y = (3*y2+y1)/4;
		p2x = (3*x2+x3)/4;
		p2y = (y3+y2)/2;
		p4x = (3*x3+x2)/4;
		p4y = (y3+y2)/2;
		renderFunctionline(p0x,p0y,p1x,p1y);
		renderFunctionline(p1x,p1y,p2x,p2y);
		renderFunctionline(p2x,p2y,p3x,p3y);
		renderFunctionline(p3x,p3y,p4x,p4y);
		renderFunctionline(p4x,p4y,p5x,p5y);
		renderFunctionline(p5x,p5y,p0x,p0y);
	if(num--){
		shapefunc(x0+ch,y0+ch,x1-ch,y1+ch,x2-ch,y2-ch,x3+ch,y3-ch,num);
	}
	return;
	
}

void renderFunction(){ 
	int x0 = 0,y0 = 0;
	int x1 = xsize,y1 = 0;
	int x2 = xsize,y2 = ysize;
	int x3 = 0,y3 = ysize;
//	renderFunctionline(x0,y0,x1,y1);
//	renderFunctionline(x0,y0,x3,y3);
//	renderFunctionline(x3,y3,x2,y2);
//	renderFunctionline(x1,y1,x2,y2);
//	x0 = (x0+x3)/2;
//	x1 = (x0+x1)/2;
//	x2 = (x1+x2)/2;
//	x3 = (x2+x3)/2;
	shapefunc(x0,y0,x1,y1,x2,y2,x3,y3,10);
	renderFunctionrec(x0,y0,x1,y1,x2,y2,x3,y3,20);


	glFlush();
//	renderFunction();

	//int x1,x2,x3,x4,y1,y2,y3,y4;
	                                                                         
	
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(xsize,ysize);
    glutInitWindowPosition(0,0);
    glutCreateWindow("BREN_recursion");
    glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(0,1000,0,1000);
    glutDisplayFunc(renderFunction);
    glutMainLoop(); 


	return 0;
}
