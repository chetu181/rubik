#include<windows.h>
#include <GL/glut.h>

int C[6][10];
int xro[28],yro[28],zro[28];

int done=0,di=1,rot=0,yes=1;
float ang=0.0;

void xrotation(int, int);
void yrotation(int, int);
void rmy(int,int,int,int,int);
void zrotation(int, int);
void rmz(int,int,int,int,int);
void fr(int);
void franti(int);
void yfinal(int);
void xfinal(int);
void zfinal(int);

int diry, layy,dirx,layx,dirz,layz;
//_______________________________________________
void keyb( unsigned char key, int x, int y )
 {
    if(yes)
    {


  switch(key)
  {
    case 'q':xfinal(1);yes=0;break;
    case 'w':xfinal(2);yes=0;break;
    case 'e':xfinal(3);yes=0;break;
    case 'r':xfinal(7);yes=0;break;
    case 't':xfinal(8);yes=0;break;
    case 'y':xfinal(9);yes=0;break;
    case 'a':yfinal(1);yes=0;break;
    case 's':yfinal(2);yes=0;break;
    case 'd':yfinal(3);yes=0;break;
    case 'f':yfinal(7);yes=0;break;
    case 'g':yfinal(8);yes=0;break;
    case 'h':yfinal(9);yes=0;break;
    case 'z':zfinal(1);yes=0;break;
    case 'x':zfinal(2);yes=0;break;
    case 'c':zfinal(3);yes=0;break;
    case 'v':zfinal(7);yes=0;break;
    case 'b':zfinal(8);yes=0;break;
    case 'n':zfinal(9);yes=0;break;
        default:break;
  }
    }
}

//_________________________________ANIMATION___
void anim(int t)
{
    glutPostRedisplay();
    glutTimerFunc(5,anim,1);
}

void yfinal(int com)
{

    int i;
    diry=di=2*(com/6)-1;
    layy=(com-1)%3+1;

    for(i=1;i<10;i++)
        yro[(layy-1)*9+i]=1;
    rot=1;
}
void xfinal(int com)
{
    dirx=di=2*(com/6)-1;
    layx=(com-1)%3+1;
        if(layx==1)
        {
            xro[7]=1;
            xro[8]=1;
            xro[9]=1;
            xro[16]=1;
            xro[17]=1;
            xro[18]=1;
            xro[25]=1;
            xro[26]=1;
            xro[27]=1;
        }
        if(layx==2)
        {
            xro[4]=1;
            xro[5]=1;
            xro[6]=1;
            xro[13]=1;
            xro[14]=1;
            xro[15]=1;
            xro[22]=1;
            xro[23]=1;
            xro[24]=1;
        }
        if(layx==3)
        {
            xro[1]=1;
            xro[2]=1;
            xro[3]=1;
            xro[10]=1;
            xro[11]=1;
            xro[12]=1;
            xro[19]=1;
            xro[20]=1;
            xro[21]=1;
        }

    rot=2;
}
void zfinal(int com)
{
    dirz=-1*(di=2*(com/6)-1);
    layz=(com-1)%3+1;
    if(layz==1)
        {
            zro[9]=1;
            zro[6]=1;
            zro[3]=1;
            zro[18]=1;
            zro[15]=1;
            zro[12]=1;
            zro[21]=1;
            zro[24]=1;
            zro[27]=1;
        }
        if(layz==2)
        {
            zro[2]=1;
            zro[5]=1;
            zro[8]=1;
            zro[11]=1;
            zro[14]=1;
            zro[17]=1;
            zro[20]=1;
            zro[23]=1;
            zro[26]=1;
        }
        if(layz==3)
        {
            zro[1]=1;
            zro[4]=1;
            zro[7]=1;
            zro[10]=1;
            zro[13]=1;
            zro[16]=1;
            zro[19]=1;
            zro[22]=1;
            zro[25]=1;
        }
    rot=3;
}

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
//_________________________________(SINGLE) CUBE
void mycube(int pic,float siz,float x,float y,float z,int d,int f,int u,int b,int r,int l)
{
    siz/=2;
    glPushMatrix();

    if(yro[pic])
        glRotatef(ang*di,0.0,1.0,0.0);
    if(xro[pic])
        glRotatef(ang*di,1.0,0.0,0.0);
    if(zro[pic])
        glRotatef(ang*di,0.0,0.0,1.0);
    //glScalef(ang/15,ang/15,ang/15);
    //glPopMatrix();
    //glPushMatrix();
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
//_________________________________RUBIK'S CUBE
void rubic(float siz,float x)
{
        mycube(1,siz, x, x, x,  6       ,6      ,C[2][3],C[3][9],C[4][3],6);
        mycube(2,siz, x, x, 0,  6       ,6      ,C[2][6],6      ,C[4][2],6);
        mycube(3,siz, x, x,-x,  6       ,C[1][3],C[2][9],6      ,C[4][1],6);

        mycube(4,siz, 0, x, x,  6       ,6      ,C[2][2],C[3][8],6      ,6);
        mycube(5,siz, 0, x, 0,  6       ,6      ,C[2][5],6      ,6      ,6);
        mycube(6,siz, 0, x,-x,  6       ,C[1][2],C[2][8],6      ,6      ,6);

        mycube(7,siz, -x, x, x, 6       ,6      ,C[2][1],C[3][7],6      ,C[5][3]);
        mycube(8,siz, -x, x, 0, 6       ,6      ,C[2][4],6      ,6      ,C[5][2]);
        mycube(9,siz, -x, x,-x, 6       ,C[1][1],C[2][7],6      ,6      ,C[5][1]);
        //_____MIDDLE_LAYER
        mycube(10,siz, x, 0, x,  6       ,6      ,6      ,C[3][6],C[4][6],6);
        mycube(11,siz, x, 0, 0,  6       ,6      ,6      ,6      ,C[4][5],6);
        mycube(12,siz, x, 0,-x,  6       ,C[1][6],6      ,6      ,C[4][4],6);

        mycube(13,siz, 0, 0, x,  6       ,6      ,6      ,C[3][5],6      ,6);
        //mycube(2,siz, 0, 0, 0,6       ,6      ,6      ,6      ,6      ,6);
        mycube(15,siz, 0, 0,-x,  6       ,C[1][5],6      ,6      ,6      ,6);

        mycube(16,siz, -x, 0, x, 6       ,6      ,6      ,C[3][4],6      ,C[5][6]);
        mycube(17,siz, -x, 0, 0, 6       ,6      ,6      ,6      ,6      ,C[5][5]);
        mycube(18,siz, -x, 0,-x, 6       ,C[1][4],6      ,6      ,6      ,C[5][4]);
        //_________BOTTOM LATER____
        mycube(19,siz, x, -x, x, C[0][9] ,6      ,6      ,C[3][3],C[4][9],6);
        mycube(20,siz, x, -x, 0, C[0][6]  ,6      ,6      ,6      ,C[4][8],6);
        mycube(21,siz, x, -x,-x, C[0][3]  ,C[1][9],6      ,6      ,C[4][7],6);

        mycube(22,siz, 0, -x, x, C[0][8]  ,6      ,6      ,C[3][2],6      ,6);
        mycube(23,siz, 0, -x, 0, C[0][5]  ,6      ,6      ,6      ,6      ,6);
        mycube(24,siz, 0, -x,-x, C[0][2]  ,C[1][8],6      ,6      ,6      ,6);

        mycube(25,siz, -x, -x, x,C[0][7]  ,6      ,6      ,C[3][1],6      ,C[5][9]);
        mycube(26,siz, -x, -x, 0,C[0][4]  ,6      ,6      ,6      ,6      ,C[5][8]);
        mycube(27,siz, -x, -x,-x,C[0][1]  ,C[1][7],6      ,6      ,6      ,C[5][7]);
}
//__________________________________________________________DISPLAY********************************OOOOOOOOOOOO
void draw()
{
     //xrotation(3,1);
     //yrotation(1,1);
     //xrotation(1,-1);
     //yrotation(1,-1);

    int i;
    float siz=0.2,x,sp=.02;
    x=siz+sp;
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glRotatef(-25,1.0,0.0,0.0);
    glRotatef(210,0.0,1.0,0.0);
    if(rot)
    {
        ang+=2;
        if(ang>90)
        {
            ang=0;
            for(i=0;i<28;i++)
            {
                xro[i]=0;
                yro[i]=0;
                zro[i]=0;
            }
            if(rot==1)
                yrotation(layy,diry);
            if(rot==2)
                xrotation(layx,dirx);
            if(rot==3)
                zrotation(layz,dirz);
            rot=0;
            yes=1;
        }
    }
    rubic(siz,x);

    glutSwapBuffers();
}
//___________________________________________________________MAIN

int main(int argc,char** argv)
{
    int i,j;

    for(i=0;i<6;i++)
    for(j=0;j<10;j++)
        C[i][j]=i;
    for(i=0;i<28;i++)
    {
        xro[i]=0;
        yro[i]=0;
        zro[i]=0;
    }


//---------------------------GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(700,700);
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
    glutKeyboardFunc(keyb);
    glutTimerFunc(100,anim,1);
    glutMainLoop();
    return 0;
}

//__________________________ALL ROTATIONS________________________NON_GLUT_____________________________________________________
void xrotation(int lay,int dir)  //lay can be 1,2,3;dir can be -1 or 1
{
    int i,j,temp,te1,te2,te3;
    if(dir==-1)
    {
        temp=lay;
        te1=C[0][lay];
        te2=C[0][lay+3];
        te3=C[0][lay+6];
        for(j=1;j<4;j++)
        for(i=0,lay=temp;i<3;i++,lay+=3)
            C[j-1][lay]=C[j][lay];
        lay=temp;
        C[3][lay]=te1;
        C[3][lay+3]=te2;
        C[3][lay+6]=te3;
        if(temp==3)
            franti(4);
        if(temp==1)
            franti(5);

    }
    else
    {
        temp=lay;
        te1=C[3][lay];
        te2=C[3][lay+3];
        te3=C[3][lay+6];
        for(j=3;j>0;j--)
        for(i=0,lay=temp;i<3;i++,lay+=3)
            C[j][lay]=C[j-1][lay];
        lay=temp;
        C[0][lay]=te1;
        C[0][lay+3]=te2;
        C[0][lay+6]=te3;
        if(temp==3)
            fr(4);
        if(temp==1)
            fr(5);
    }
}
void yrotation(int lay,int dir)
{
    if(lay==1)
    {
        rmy(1,3,9,1,dir);
        rmy(2,2,8,2,dir);
        rmy(3,1,7,3,dir);
        if(dir==1)
            fr(2);
        if(dir==-1)
            franti(2);
    }
    if(lay==2)
    {
        rmy(4,6,6,4,dir);
        rmy(5,5,5,5,dir);
        rmy(6,4,4,6,dir);
    }
    if(lay==3)
    {
        rmy(7,9,3,7,dir);
        rmy(8,8,2,8,dir);
        rmy(9,7,1,9,dir);
        if(dir)
            franti(0);
        else
            fr(0);
    }
}
void rmy(int fr,int le,int ba,int ri,int dir)
{
    int te;
    if(dir==1)
    {
        te=C[4][ri];
        C[4][ri]=C[3][ba];
        C[3][ba]=C[5][le];
        C[5][le]=C[1][fr];
        C[1][fr]=te;
    }
    else
    {
        te=C[4][ri];
        C[4][ri]=C[1][fr];
        C[1][fr]=C[5][le];
        C[5][le]=C[3][ba];
        C[3][ba]=te;

    }
}
void zrotation(int lay,int dir)
{
    if(lay==1)
    {
        rmz(7,1,3,7,dir);
        rmz(8,4,2,4,dir);
        rmz(9,7,1,1,dir);
        if(dir)
            fr(1);
        else
            franti(1);
    }
    if(lay==2)
    {
        rmz(4,2,6,8,dir);
        rmz(5,5,5,5,dir);
        rmz(6,8,4,2,dir);
    }
    if(lay==3)
    {
        rmz(1,3,9,9,dir);
        rmz(2,6,8,6,dir);
        rmz(3,9,7,3,dir);
        if(dir)
            franti(3);
        else
            fr(3);
    }
}
void rmz(int up,int ri,int dw,int le,int dir)
{
    int te;
    if(dir==1)
    {
        te=C[4][ri];
        C[4][ri]=C[2][up];
        C[2][up]=C[5][le];
        C[5][le]=C[0][dw];
        C[0][dw]=te;
    }
    else
    {
        te=C[4][ri];
        C[4][ri]=C[0][dw];
        C[0][dw]=C[5][le];
        C[5][le]=C[2][up];
        C[2][up]=te;

    }
}
void fr(int face)
{
    int temp;
    temp=C[face][2];
    C[face][2]=C[face][4];
    C[face][4]=C[face][8];
    C[face][8]=C[face][6];
    C[face][6]=temp;
    temp=C[face][1];
    C[face][1]=C[face][7];
    C[face][7]=C[face][9];
    C[face][9]=C[face][3];
    C[face][3]=temp;
}
void franti(int face)
{
    int temp;
    temp=C[face][2];
    C[face][2]=C[face][6];
    C[face][6]=C[face][8];
    C[face][8]=C[face][4];
    C[face][4]=temp;
    temp=C[face][1];
    C[face][1]=C[face][3];
    C[face][3]=C[face][9];
    C[face][9]=C[face][7];
    C[face][7]=temp;
}
