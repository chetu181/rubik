
#include<windows.h>
#include <GL/glut.h>



void display();
void specialKeys();


double rotate_y=45;
double rotate_x=-45;
int kep=0;
int gi=40;


void drawbox(float x,float y,float z)
{
    //glPushMatrix();
glTranslatef( x,y,z );
      glBegin(GL_POLYGON);
     glColor3f(   1.0,  0.0,  0.0 );

    glVertex3f(  0.5, -0.5, -0.5 );
    glVertex3f(  0.5,  0.5, -0.5 );
    glVertex3f( -0.5,  0.5, -0.5 );
    glVertex3f( -0.5, -0.5, -0.5 );

  glEnd();


  glBegin(GL_POLYGON);
  glColor3f(   1.0,  0.3,  0.0 );
  glVertex3f(  0.5, -0.5, 0.5 );
  glVertex3f(  0.5,  0.5, 0.5 );
  glVertex3f( -0.5,  0.5, 0.5 );
  glVertex3f( -0.5, -0.5, 0.5 );
  glEnd();


  glBegin(GL_POLYGON);
    glColor3f(   0.0,  1.0,  0.0 );

  glVertex3f( 0.5, -0.5, -0.5 );
  glVertex3f( 0.5,  0.5, -0.5 );
  glVertex3f( 0.5,  0.5,  0.5 );
  glVertex3f( 0.5, -0.5,  0.5 );
  glEnd();


  glBegin(GL_POLYGON);
  glColor3f(   0.0,  0.0,  1.0 );

  glVertex3f( -0.5, -0.5,  0.5 );
  glVertex3f( -0.5,  0.5,  0.5 );
  glVertex3f( -0.5,  0.5, -0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();


  glBegin(GL_POLYGON);
    glColor3f( 1.0, 1.0, 0.0 );

  glVertex3f(  0.5,  0.5,  0.5 );
  glVertex3f(  0.5,  0.5, -0.5 );
  glVertex3f( -0.5,  0.5, -0.5 );
  glVertex3f( -0.5,  0.5,  0.5 );
  glEnd();


  glBegin(GL_POLYGON);
  glColor3f(   1.0,  1.0, 1.0 );

  glVertex3f(  0.5, -0.5, -0.5 );
  glVertex3f(  0.5, -0.5,  0.5 );
  glVertex3f( -0.5, -0.5,  0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();

//glPopMatrix();
}
void rubicx(float sp)
{
    //glScalef(0.3,0.3,0.3);
//glTranslatef(0.0,0.0,7.0);
      drawbox(-sp,-sp,-sp);
  drawbox(sp,0.0,0.0);
  drawbox(sp,0.0,0.0);
    drawbox(0.0,sp,0.0);
  drawbox(-sp,0.0,0.0);
  drawbox(-sp,0.0,0.0);
    drawbox(0.0,sp,0.0);
  drawbox(sp,0.0,0.0);
  drawbox(sp,0.0,0.0);

 drawbox(-2*sp,-2*sp,sp);
  drawbox(sp,0.0,0.0);
  drawbox(sp,0.0,0.0);
    drawbox(0.0,sp,0.0);
  drawbox(-sp,0.0,0.0);
  drawbox(-sp,0.0,0.0);
    drawbox(0.0,sp,0.0);
  drawbox(sp,0.0,0.0);
  drawbox(sp,0.0,0.0);

   drawbox(-2*sp,-2*sp,sp);
  drawbox(sp,0.0,0.0);
  drawbox(sp,0.0,0.0);
    drawbox(0.0,sp,0.0);
  drawbox(-sp,0.0,0.0);
  drawbox(-sp,0.0,0.0);
    drawbox(0.0,sp,0.0);
  drawbox(sp,0.0,0.0);
  drawbox(sp,0.0,0.0);

}




void display(){
int i,j,k;
float pos;



  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);


glLoadIdentity ();
//glMatrixMode(GL_MODELVIEW);
   // gluPerspective(45.0,1.0,0.2,10.0);

glOrtho(-1.0,1.0,-1.0,1.0,1.0,-1.0);

glRotatef( rotate_x, 1.0, 0.0, 0.0 );
  glRotatef( rotate_y, 0.0, 1.0, 0.0 );
   glScalef( 0.2, 0.2, 0.2 );


  //drawbox(3.0,0.0,0.0);
rubicx(1.5);
  kep=0;
  glFlush();
  glutSwapBuffers();



}
void tsd(int a)
{

    rotate_y += 3;
    gi++;
    if(gi<30)
    {
    glutPostRedisplay();
    glutTimerFunc(10,tsd,0);
    }
}

void specialKeys( int key, int x, int y ) {
int i=0;

  if (key == GLUT_KEY_RIGHT)
  {
      gi=0;
  glutTimerFunc(10,tsd,0);

  }

  else if (key == GLUT_KEY_LEFT)
    rotate_y -= 5;

  else if (key == GLUT_KEY_UP)
    rotate_x += 5;

  else if (key == GLUT_KEY_DOWN)
    rotate_x -= 5;
    kep=1;


  glutPostRedisplay();

}

//_______________________________________________________MAIN_______________________________________________
int main(int argc, char** argv){

  glutInit(&argc,argv);

  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
glutInitWindowSize (600, 600);
glutInitWindowPosition (0,0);

  glutCreateWindow("RUBIX CUBE");
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);



  glEnable(GL_DEPTH_TEST);


  glutDisplayFunc(display);
  glutSpecialFunc(specialKeys);

  glutMainLoop();

  return 0;

}
