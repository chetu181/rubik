#include<windows.h>
#include <GL/glut.h>

int C[6][10];

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
        case 6:glColor3f(0.1,0.0,0.0);break;
        default:break;
    }
}


void mycube(int pic,float siz,float x,float y,float z,int d,int f,int u,int b,int r,int l)
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
    float siz=0.2,x,y,z,sp=0.02;
    x=siz+sp;

    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glRotatef(30,1.0,0.0,0.0);
    glRotatef(45,0.0,1.0,0.0);

        mycube(1,siz, x, x, x,  6       ,6      ,C[2][3],C[3][9],C[4][3],6);
        mycube(2,siz, x, x, 0,  6       ,6      ,C[2][6],6      ,C[4][2],6);
        mycube(3,siz, x, x,-x,  6       ,C[1][3],C[2][9],6      ,C[4][1],6);

        mycube(1,siz, 0, x, x,  6       ,6      ,C[2][2],C[3][8],6      ,6);
        mycube(2,siz, 0, x, 0,  6       ,6      ,C[2][5],6      ,6      ,6);
        mycube(3,siz, 0, x,-x,  6       ,C[1][2],C[2][8],6      ,6      ,6);

        mycube(1,siz, -x, x, x, 6       ,6      ,C[2][1],C[3][7],6      ,C[5][3]);
        mycube(2,siz, -x, x, 0, 6       ,6      ,C[2][4],6      ,6      ,C[5][2]);
        mycube(3,siz, -x, x,-x, 6       ,C[1][1],C[2][7],6      ,6      ,C[5][1]);
        //_____MIDDLE_LAYER
        mycube(1,siz, x, 0, x,  6       ,6      ,6      ,C[3][6],C[4][6],6);
        mycube(2,siz, x, 0, 0,  6       ,6      ,6      ,6      ,C[4][5],6);
        mycube(3,siz, x, 0,-x,  6       ,C[1][6],6      ,6      ,C[4][4],6);

        mycube(1,siz, 0, 0, x,  6       ,6      ,6      ,C[3][5],6      ,6);
        //mycube(2,siz, 0, 0, 0,6       ,6      ,6      ,6      ,6      ,6);
        mycube(3,siz, 0, 0,-x,  6       ,C[1][5],6      ,6      ,6      ,6);

        mycube(1,siz, -x, 0, x, 6       ,6      ,6      ,C[3][4],6      ,C[5][6]);
        mycube(2,siz, -x, 0, 0, 6       ,6      ,6      ,6      ,6      ,C[5][5]);
        mycube(3,siz, -x, 0,-x, 6       ,C[1][4],6      ,6      ,6      ,C[5][4]);
        //_________BOTTOM LATER____
        mycube(1,siz, x, -x, x, C[0][9] ,6      ,6      ,C[3][3],C[4][9],6);
        mycube(2,siz, x, -x, 0, C[0][6]  ,6      ,6      ,6      ,C[4][8],6);
        mycube(3,siz, x, -x,-x, C[0][3]  ,C[1][9],6      ,6      ,C[4][7],6);

        mycube(1,siz, 0, -x, x, C[0][8]  ,6      ,6      ,C[3][2],6      ,6);
        mycube(2,siz, 0, -x, 0, C[0][5]  ,6      ,6      ,6      ,6      ,6);
        mycube(3,siz, 0, -x,-x, C[0][2]  ,C[1][8],6      ,6      ,6      ,6);

        mycube(1,siz, -x, -x, x,C[0][7]  ,6      ,6      ,C[3][1],6      ,C[5][9]);
        mycube(2,siz, -x, -x, 0,C[0][4]  ,6      ,6      ,6      ,6      ,C[5][8]);
        mycube(3,siz, -x, -x,-x,C[0][1]  ,C[1][7],6      ,6      ,6      ,C[5][7]);

    glutSwapBuffers();
}
//___________________________________________________________MAIN

int main(int argc,char** argv)
{
    int i,j;

    for(i=0;i<6;i++)
    for(j=0;j<10;j++)
        C[i][j]=i;

//---------------------------GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("TEST");

    glClearColor(0.2,0.6,0.5,0.1);
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
