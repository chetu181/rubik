#include<windows.h>
#include <GL/glut.h>

int C[6][9];

void setcol(int cc)
{
    switch(cc)
    {
        case 0:glColor3f(1.0,1.0,1.0);break;
        case 1:glColor3f(0.0,0.0,1.0);break;
        case 2:glColor3f(1.0,1.0,0.0);break;
        case 3:glColor3f(0.0,1.0,0.0);break;
        case 4:glColor3f(1.0,0.0,0.0);break;
        case 5:glColor3f(1.0,0.5,0.0);break;
        case 6:glColor3f(0.0,0.0,0.0);break;
        default:break;
    }
}


void mycube(float siz,float x,float y,float z,int d,int f,int u,int b,int r,int l)
{
    siz/=2;
    glPushMatrix();
    glTranslatef(x,y,z);
    glBegin(GL_POLYGON);
    setcol(d);
        glVertex3f(  siz, -siz,  siz );
        glVertex3f(  siz, -siz, -siz );
        glVertex3f( -siz, -siz, -siz );
        glVertex3f( -siz, -siz,  siz );
    glEnd();

    glBegin(GL_POLYGON);
    setcol(b);
        glVertex3f(  siz,  siz,  siz );
        glVertex3f(  siz, -siz,  siz );
        glVertex3f( -siz, -siz,  siz );
        glVertex3f( -siz,  siz,  siz );
    glEnd();

    glBegin(GL_POLYGON);
    setcol(u);
        glVertex3f(  siz,  siz,  siz );
        glVertex3f(  siz,  siz, -siz );
        glVertex3f( -siz,  siz, -siz );
        glVertex3f( -siz,  siz,  siz );
    glEnd();

    glBegin(GL_POLYGON);
    setcol(f);
        glVertex3f(  siz,  siz,  -siz );
        glVertex3f(  siz, -siz,  -siz );
        glVertex3f( -siz, -siz,  -siz );
        glVertex3f( -siz,  siz,  -siz );
    glEnd();

    glBegin(GL_POLYGON);
    setcol(r);
        glVertex3f(  siz,  siz,  siz );
        glVertex3f(  siz, -siz,  siz );
        glVertex3f(  siz, -siz, -siz );
        glVertex3f(  siz,  siz, -siz );
    glEnd();

    glBegin(GL_POLYGON);
    setcol(l);
        glVertex3f( -siz,  siz,  siz );
        glVertex3f( -siz, -siz,  siz );
        glVertex3f( -siz, -siz, -siz );
        glVertex3f( -siz,  siz, -siz );
    glEnd();

    glPopMatrix();
}
//__________________________________________________________DISPLAY
void draw()
{
    int i,j,k;
    float siz=0.2,x,y,z;
    x=y=z=-siz-0.05;

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glRotatef(30,1.0,1.0,0.0);

    for(i=0;i<3;i++,x+=siz+0.05,y=-siz-0.05)
    for(j=0;j<3;j++,y+=siz+0.05,z=-siz-0.05)
    for(k=0;k<3;k++,z+=siz+0.05)
        mycube(siz,x,y,z,0,1,2,3,4,5);


    glutSwapBuffers();
}
//___________________________________________________________MAIN

int main(int argc,char** argv)
{
    int i,j;

    for(i=0;i<6;i++)
    for(j=0;j<9;j++)
        C[i][j]=i;

//---------------------------GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);

    glutCreateWindow("TEST");

 /*   glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0,1.0,-1.0,1.0,1.0,-1.0);
*/
    glEnable(GL_DEPTH_TEST);


    glutDisplayFunc(draw);


    glutMainLoop();
    return 0;
}
