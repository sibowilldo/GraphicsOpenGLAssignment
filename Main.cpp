#include <windows.h>
#include <WinUser.h>
#include <cstdlib>
#include <cstdio>
#include<cmath>
#include<GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <string>

GLfloat alpha = 0.0, theta = 0.0, axis_x = 0.0, axis_y = 0.0, Calpha = 360.0, C_hr_alpha = 360.0;
GLboolean bRotate = false, fRotate = true, cRotate = true, xz_rotate = false, l_on = true;
const int screenWidth = 1280, screenHeight = 720;
GLboolean amb = true, spec = true, dif = true;


bool l_on1 = true;
bool l_on2 = true;
bool l_on3 = false;


//cube(1, 0.7, 0.4);  Skin tone

double spt_cutoff = 400;

float rot = 0;

GLfloat eyeX = 0;
GLfloat eyeY = 10;
GLfloat eyeZ = 10;

GLfloat lookX = 0;
GLfloat lookY = 10;
GLfloat lookZ = 2;

static GLfloat baseVertexCube[8][3] =
{
    {0,0,0},
    {0,0,1},
    {0,1,0},
    {0,1,1},

    {1,0,0},
    {1,0,1},
    {1,1,0},
    {1,1,1}
};


static GLubyte quadIndices[6][4] =
{
   {0,2,6,4},
    {1,5,7,3},
    {0,4,5,1},
    {2,3,7,6},
    {0,1,3,2},
    {4,6,7,5}
};



static void setGLNormal3f
(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2, GLfloat x3, GLfloat y3, GLfloat z3)
{
    GLfloat Nx = (y2 - y1) * (z3 - z1) - (z2 - z1) * (y3 - y1);
    GLfloat Ny = (z2 - z1) * (x3 - x1) - (x2 - x1) * (z3 - z1);
    GLfloat Nz = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);

    glNormal3f(Nx, Ny, Nz);
}

void cube(GLfloat red, GLfloat green, GLfloat blue)
{
    GLfloat 
        ambience[] = { red * 0.3,green * 0.3,blue * 0.3,1 },
        lightDiffuse[] = { red, green, blue, 1 },
        specular[] = { 1, 1, 1, 1 }, 
        shininess[] = { 10 };

    glMaterialfv(GL_FRONT, GL_AMBIENT, ambience);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, lightDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

    glBegin(GL_QUADS);
    for (GLint i = 0; i < 6; i++)
    {
        setGLNormal3f(
            baseVertexCube[quadIndices[i][0]][0], baseVertexCube[quadIndices[i][0]][1], baseVertexCube[quadIndices[i][0]][2],
            baseVertexCube[quadIndices[i][1]][0], baseVertexCube[quadIndices[i][1]][1], baseVertexCube[quadIndices[i][1]][2],
            baseVertexCube[quadIndices[i][2]][0], baseVertexCube[quadIndices[i][2]][1], baseVertexCube[quadIndices[i][2]][2]);

        for (GLint j = 0; j < 4; j++)
        {
            glVertex3fv(&baseVertexCube[quadIndices[i][j]][0]);
        }
    }
    glEnd();
}


void desk()
{
    float length = .5;
    float height = 3;
    float width = .5;

    // Leg
    glPushMatrix();
    glScalef(6, 2.2,.2); // (x: width,y:height, z:thickness)
    glTranslatef(0, 0, 11.5);
    cube(.5, .5, .9);
    glPopMatrix();
    // leg base
    glPushMatrix();
    glScalef(6, .3, 1.5); //(x: length, y: height, z: width)
    glTranslatef(0, 0, 1.1);
    cube(.5, .5, .9);
    glPopMatrix();

    // Top
    glPushMatrix();
    glScalef(6, .3, 4.5); //(x: length, y: height, z: width)
    glTranslatef(0, 7.3, 0);
    cube(1, 1, 1);
    glPopMatrix();





}
void chair()
{
    float length = .4;
    float height = 1.5;
    float width = .35;


    glPushMatrix(); // Chair Leg Y 1
    glTranslatef(length / 2, 0, 0);
    glScalef(length / 1.8, height, width / 3);
    glTranslatef(1, 0, -3.4);
    cube(.6, .6, .6);
    glPopMatrix();

    glPushMatrix(); // Chair Leg Y 2
    glTranslatef(length / 2, 0, 0);
    glScalef(length / 1.8, height, width / 3);
    glTranslatef(7.2, 0, -3.4);
    cube(.6, .6, .6);
    glPopMatrix();

    glPushMatrix(); // Chair Leg X - side
    glTranslatef(length / 2, 0, 0);
    glScalef(length / 1.8, height / 6, width * 2.5);
    glTranslatef(1, 0, -1.4);
    cube(.6, .6, .6);
    glPopMatrix();

    glPushMatrix(); // Chair Leg X - side
    glTranslatef(length / 2, 0, 0);
    glScalef(length / 1.8, height / 6, width * 2.5);
    glTranslatef(7.2, 0, -1.4);
    cube(.6, .6, .6);
    glPopMatrix();

    glPushMatrix(); // Chair Leg X - center
    glTranslatef(length / 2, 0, 0);
    glScalef(length * 4, height / 6, width/1.5);
    glTranslatef(.15, 0, -5.3);
    cube(.6, .6, .6);
    glPopMatrix();

    glPushMatrix(); // Chair Base
    glTranslatef(length / 2, 0, 0);
    glScalef(length * 4, height / 6, width * 4);
    glTranslatef(0.15, 6, -1.2);
    cube(.2,.2,.2);
    glPopMatrix();

    glPushMatrix(); // Chair Back Rest
    glTranslatef(length / 2, 0, 0);
    glScalef(length * 4, height * 1.2, width / 2);
    glTranslatef(.15, 1, -9.6);
    cube(0.8, 0.8, 0.8);
    glPopMatrix();

    glPushMatrix(); // Chair Head Rest
    glTranslatef(length / 2, 0, 0);
    glScalef(length*1.2, height/2, width / 2);
    glTranslatef(1.6, 4.8, -9.6);
    cube(.5, .5, .9);
    glPopMatrix();

}

void deskChairGrouping()
{
    glPushMatrix();
    desk();
    glPopMatrix();

    glPushMatrix();
    chair();
    glPopMatrix();

}


void renderDeskChairGroupSet()
{
    glPushMatrix();
    glTranslatef(8, 0, -2);
    glRotatef(-90,0,1,0);
    deskChairGrouping();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-4, 0, -2);
    glRotatef(-90,0,1,0);
    deskChairGrouping();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(8, 0, -10);
    glRotatef(-90,0,1,0);
    deskChairGrouping();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-4, 0, -10);
    glRotatef(-90,0,1,0);
    deskChairGrouping();
    glPopMatrix();
}


void fan_face()
{
    glPushMatrix();
    glScalef(2, .5, 1.8);
    glTranslatef(-0.4, 19, -.4);
    cube(1.000, 1.000, 1.000);
    glPopMatrix();


}

void stand()
{
    glPushMatrix();
    glScalef(.5, 5, .5);
    glTranslatef(0, 2, 0);
    cube(0.392, 0.584, 0.929);
    glPopMatrix();
}

void leg()
{
    glPushMatrix();
    glScalef(5, 0.07, 1.8);
    glTranslatef(0, 140, -0.3);
    cube(0.392, 0.584, 0.929);
    glPopMatrix();
}


void fan_set()
{
    glPushMatrix();
    glPushMatrix();
    fan_face();
    glPopMatrix();



    glPushMatrix();
    leg();
    glPopMatrix();

    glPushMatrix();

    glTranslatef(-5, 0.0, 0);
    leg();
    glPopMatrix();


    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    glTranslatef(-6, 0, 0);
    leg();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    glTranslatef(0, 0, 0);
    leg();
    glPopMatrix();
}

void fan()
{


    glPushMatrix();
    glRotatef(alpha, 0, .1, 0);
    fan_set();
    glPopMatrix();

    glPushMatrix();
    stand();
    glPopMatrix();

}
void fan_full_set()
{
    glPushMatrix();
    glTranslatef(7, 0, 0);
    fan();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-7, 0, 0);
    fan();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(7, 0, -9);
    fan();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-7, 0, -9);
    fan();
    glPopMatrix();


}
void almari()
{
    glPushMatrix();

    GLfloat almari_height = 12, almari_width = 6, almari_length = 3;


    glPushMatrix();
    glScalef(almari_width, almari_height, almari_length);
    glTranslatef(1, 0, 3.5);
    cube(1, 0.6, 0.2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4, 0, 4.1);
    glScalef(almari_width / 45, (almari_height - .5), almari_length / 5.5);
    glTranslatef(65, 0, 11.5);
    cube(1.000, 0.000, 1.000);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.5, 5, 4.5);
    glScalef(almari_width / 25, almari_height / 10, almari_length / 5.5);
    glTranslatef(28, 0, 10);
    cube(0, 0, 0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.6, 5, 4.5);
    glScalef(almari_width / 25, almari_height / 10, almari_length / 5.5);
    glTranslatef(44, 0, 10);
    cube(0, 0, 0);
    glPopMatrix();

    glPopMatrix();


}

void board()
{
    glPushMatrix();
    glScalef(10, 8, 0.1);
    glTranslatef(-1.2, .45, 130);
    cube(0, 0, 0);
    glPopMatrix();
}

void window()
{
    /*
    * Window 1
    */
    // Glass
    glPushMatrix();
    glScalef(0.1, 8, 15);
    glTranslatef(-140, .5, -1);
    cube(.5, .5, 1);
    glPopMatrix();


    glPushMatrix();
    glScalef(0.1, 8, 15);
    glTranslatef(-140, .5, -.0);
    cube(.5, .5, 1);
    glPopMatrix();

    // Top Frame
    glPushMatrix();
    glScalef(0.1, 0.1, -20);
    glTranslatef(-139, 120, -1);
    cube(0, 0, 0);
    glPopMatrix();

    // Top Frame
    glPushMatrix();
    glScalef(0.1, 0.1, 20);
    glTranslatef(-139, 120, -1);
    cube(0, 0, 0);
    glPopMatrix();

    //X Frame Top
    glPushMatrix();
    glScalef(0.1, 0.1, -15);
    glTranslatef(-139, 40, -1);
    cube(0, 0, 0);
    glPopMatrix();

    //X Frame Bottom
    glPushMatrix();
    glScalef(0.1, 0.1, 15);
    glTranslatef(-139, 40, -1);
    cube(0, 0, 0);
    glPopMatrix();


    //Y Frame 1  - From the Back
    glPushMatrix();
    glScalef(0.1, 8, .1);
    glTranslatef(-139, .5, -150);
    cube(0, 0, 0);
    glPopMatrix();

    //Y Frame 2
    glPushMatrix();
    glScalef(0.1, 8, .1);
    glTranslatef(-139, .5, -75);
    cube(0, 0, 0);
    glPopMatrix();

    //Y Frame 3
    glPushMatrix();
    glScalef(0.1, 8, .1);
    glTranslatef(-139, .5, 75);
    cube(0, 0, 0);
    glPopMatrix();

    //Y Frame 4
    glPushMatrix();
    glScalef(0.1, 8, .1);
    glTranslatef(-139, .5, 0);
    cube(0, 0, 0);
    glPopMatrix();

}

void windows()
{
    glPushMatrix();
    window();
    glPopMatrix();

    // Duplicate the windows to the opposite wall.
    glPushMatrix();
    glRotatef(180, 0, 1, 0);
    window();
    glPopMatrix();
}

void projector()
{
    glPushMatrix();
    glScalef(2, .7, 1.8);
    glTranslatef(-0.43, 15, -.4);
    cube(1, 0, 0);
    glPopMatrix();

    glPushMatrix();
    glScalef(.5, 3.4, .5);
    glTranslatef(0, 3.2, 0);
    cube(0.392, 0.3, 0.929);
    glPopMatrix();

    glPushMatrix();
    glScalef(.68, .68, .68);
    glTranslatef(0, 15.45, 1);
    cube(1, 0, 1);
    glPopMatrix();

    glPushMatrix();
    glScalef(.60, .60, .60);
    glTranslatef(0.05, 17.55, 1.4);
    cube(0, 0, 0);
    glPopMatrix();
}

void projector_board()
{
    glPushMatrix();
    glScalef(6, 6, 0.1);
    glTranslatef(-0.2, .8, 130);
    cube(1, 1, 1);
    glPopMatrix();

}
void AC()
{
    glPushMatrix();
    glScalef(6, 2, 2);
    cube(.8, .8, .8);
    glPopMatrix();
}

void aircons() {
    glPushMatrix();
    glTranslatef(6, 12, -15);
    AC();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-12.0, 12, -15);
    AC();
    glPopMatrix();
}
void ceilingLight()
{
    glPushMatrix();
    glScalef(1, .05, 1);
    glTranslatef(0, 115.55, 0);
    cube(1, 1, 1);
    glPopMatrix();
}
void ceilingLightSet()
{
    glPushMatrix();
    glScalef(1, 1, 1);
    glTranslatef(-12, 8.2, -12);
    ceilingLight();
    glPopMatrix();

    glPushMatrix();
    glScalef(1, 1, 1);
    glTranslatef(12, 8.2, -12);
    ceilingLight();
    glPopMatrix();

    glPushMatrix();
    glScalef(1, 1, 1);
    glTranslatef(-12, 8.2, 12);
    ceilingLight();
    glPopMatrix();

    glPushMatrix();
    glScalef(1, 1, 1);
    glTranslatef(12, 8.2, 12);
    ceilingLight();
    glPopMatrix();

    glPushMatrix();
    glScalef(1, 1, 1);
    glTranslatef(-5, 8.2, -5);
    ceilingLight();
    glPopMatrix();

    glPushMatrix();
    glScalef(1, 1, 1);
    glTranslatef(5, 8.2, -5);
    ceilingLight();
    glPopMatrix();

    glPushMatrix();
    glScalef(1, 1, 1);
    glTranslatef(-5, 8.2, 5);
    ceilingLight();
    glPopMatrix();

    glPushMatrix();
    glScalef(1, 1, 1);
    glTranslatef(5, 8.2, 5);
    ceilingLight();
    glPopMatrix();

}
void mainDoors()
{
    glPushMatrix(); // Exit Sign
    glScalef(1.8, 1.2, .18);
    glTranslatef(-.50, 9, -73);
    cube(1,0,0);
    glPopMatrix();

    // Door Frame
    glPushMatrix();
    glScalef(8, 10.2, .20);
    glTranslatef(-.5, 0, -75);
    cube(0,0,0);
    glPopMatrix();

    // Door R
    glPushMatrix();
    glScalef(3.8, 10, .199);
    glTranslatef(0, 0, -75);
    cube(0.6, 0.6, 0.6);
    glPopMatrix();

    // Handle
    glPushMatrix(); 
    glScalef(1.1, 1.6, .198);
    glTranslatef(-.50, 2.5, -73);
    cube(.1,.1,.1);
    glPopMatrix();

    // Door L
    glPushMatrix();
    glScalef(3.8, 10, .199);
    glTranslatef(-1.01, 0, -75);
    cube(0.6, 0.6, 0.6);
    glPopMatrix();

}

void floorWallsCeiling(float scale)
{
    // Floor
    glPushMatrix();
    glScalef(scale, 1, scale);
    glTranslatef(-0.5, -1, -0.5);
    cube(0.8, 0.8, 0.8);
    glPopMatrix();

    // Side Wall
    glPushMatrix();
    glTranslatef(scale / 2, scale / 4, 0);
    glScalef(1, scale / 2, scale);
    glTranslatef(-1, -0.5, -0.5);
    cube(.7, .7, .7);
    glPopMatrix();

    // Side Wall
    glPushMatrix();
    glTranslatef(-scale / 2 + 1, scale / 4, 0);
    glScalef(1, scale / 2, scale);
    glTranslatef(-1, -0.5, -0.5);
    cube(.7, .7, .7);
    glPopMatrix();

    // Front Wall
    glPushMatrix();
    glTranslatef(0, scale / 4, scale / 2);
    glScalef(scale, scale / 2, 1);
    glTranslatef(-0.5, -0.5, -1);
    cube(.3, .3, .9);
    glPopMatrix();

    // Back Wall
    glPushMatrix();
    glTranslatef(0, scale / 4, scale / 2);
    glScalef(scale, scale / 2, 1);
    glTranslatef(-0.5, -0.5, -31);
    cube(1.000, 0.855, 0.725);
    glPopMatrix();

    // Ceiling
    glPushMatrix();
    glTranslatef(0, scale / 2, 0);
    glScalef(scale, 1, scale);
    glTranslatef(-0.5, -1, -0.5);
    cube(1,1,1);
    glPopMatrix();
}


void light()
{


    GLfloat l_amb[] = { 0.2, 0.2, 0.2, 1.0 };
    GLfloat l_dif[] = { 0.961, 0.871, 0.702 };
    GLfloat l_spec[] = { 0.2,0.2,0.2,1 };
    GLfloat l_no[] = { 0, 0, 0, 1.0 };
    GLfloat l_pos1[] = { -20,20,20,1.0 };
    GLfloat l_pos2[] = { 44,30,-5,1.0 };
    GLfloat l_pos3[] = { 0,60,0,1.0 };



    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);

    if (l_on1)
    {
        if (amb == true)
        {
            glLightfv(GL_LIGHT0, GL_AMBIENT, l_amb);
        }
        else
        {
            glLightfv(GL_LIGHT0, GL_AMBIENT, l_no);
        }

        if (dif == true)
        {
            glLightfv(GL_LIGHT0, GL_DIFFUSE, l_dif);
        }
        else
        {
            glLightfv(GL_LIGHT0, GL_DIFFUSE, l_no);
        }
        if (spec == true)
        {
            glLightfv(GL_LIGHT0, GL_SPECULAR, l_spec);
        }
        else
        {
            glLightfv(GL_LIGHT0, GL_SPECULAR, l_no);
        }
    }
    else
    {
        glLightfv(GL_LIGHT0, GL_AMBIENT, l_no);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, l_no);
        glLightfv(GL_LIGHT0, GL_SPECULAR, l_no);

    }
    glLightfv(GL_LIGHT0, GL_POSITION, l_pos1);







    if (l_on2)
    {
        if (amb == true)
        {
            glLightfv(GL_LIGHT1, GL_AMBIENT, l_amb);
        }
        else
        {
            glLightfv(GL_LIGHT1, GL_AMBIENT, l_no);
        }

        if (dif == true)
        {
            glLightfv(GL_LIGHT1, GL_DIFFUSE, l_dif);
        }
        else
        {
            glLightfv(GL_LIGHT1, GL_DIFFUSE, l_no);
        }
        if (spec == true)
        {
            glLightfv(GL_LIGHT1, GL_SPECULAR, l_spec);
        }
        else
        {
            glLightfv(GL_LIGHT1, GL_SPECULAR, l_no);
        }
    }
    else
    {
        glLightfv(GL_LIGHT1, GL_AMBIENT, l_no);
        glLightfv(GL_LIGHT1, GL_DIFFUSE, l_no);
        glLightfv(GL_LIGHT1, GL_SPECULAR, l_no);

    }
    glLightfv(GL_LIGHT1, GL_POSITION, l_pos2);



    if (l_on3)
    {
        if (amb == true)
        {
            glLightfv(GL_LIGHT2, GL_AMBIENT, l_amb);
        }
        else
        {
            glLightfv(GL_LIGHT2, GL_AMBIENT, l_no);
        }

        if (dif == true)
        {
            glLightfv(GL_LIGHT2, GL_DIFFUSE, l_dif);
        }
        else
        {
            glLightfv(GL_LIGHT2, GL_DIFFUSE, l_no);
        }
        if (spec == true)
        {
            glLightfv(GL_LIGHT2, GL_SPECULAR, l_spec);
        }
        else
        {
            glLightfv(GL_LIGHT2, GL_SPECULAR, l_no);
        }

    }
    else
    {
        glLightfv(GL_LIGHT2, GL_AMBIENT, l_no);
        glLightfv(GL_LIGHT2, GL_DIFFUSE, l_no);
        glLightfv(GL_LIGHT2, GL_SPECULAR, l_no);
    }

    glLightfv(GL_LIGHT2, GL_POSITION, l_pos3);

    GLfloat spot_direction[] = { 0.0, -1.0, 0.0 };
    glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spot_direction);
    GLfloat spt_ct[] = { spt_cutoff };
    glLightfv(GL_LIGHT2, GL_SPOT_CUTOFF, spt_ct);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-3, 3, -3, 3, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eyeX, eyeY, eyeZ, lookX, lookY, lookZ, 0, 1, 0);


    glRotatef(rot, 0, 1, 0);
    light();
    //fan_full_set();
    renderDeskChairGroupSet();
    floorWallsCeiling(30);
    windows();
    board();
    //almari();
    //projector();
    aircons();
    //projector_board();
    ceilingLightSet();
    mainDoors();
    glFlush();
    glutSwapBuffers();
}

void myKeyboardFunc(unsigned char key, int x, int y)
{
    switch (key)
    {

    case 'd':
        rot++;
        break;

    case 'a':
        rot--;
        break;

    case 'w':
        eyeY++;
        break;

    case 's':
        eyeY--;
        break;

    case '+':
        eyeX = 0;
        eyeZ++; 
        lookZ++;
        break;

    case '-':
        eyeZ--;
        break;

    case '1':
        l_on1 = !l_on1;
        break;
    case '2':
        l_on2 = !l_on2;
        break;
    case '3':
        l_on3 = !l_on3;
        break;

    case '4':
        amb = ~amb;
        break;
    case '5':
        spec = ~spec;
        break;
    case '6':
        dif = ~dif;
        break;


    }
}


void animate()
{
    if (bRotate == true)
    {
        theta += 0.1;
        if (theta > 360.0)
            theta -= 360.0 * floor(theta / 360.0);
    }


    if (fRotate == true)
    {
        alpha += 0.8;
        if (alpha > 360.0)
            alpha -= 360.0 * floor(alpha / 360.0);
    }

    glutPostRedisplay();
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(0, 0);
    glutInitWindowSize(screenWidth, screenHeight);
    glutCreateWindow("DUT Computer Lab Envision 2030-20807042");

    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);

    glEnable(GL_LIGHTING);

    glutKeyboardFunc(myKeyboardFunc);
    glutDisplayFunc(display);
    glutIdleFunc(animate);

    glutMainLoop(); 

    return 0;
}
