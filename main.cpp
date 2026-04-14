#include <GL/gl.h>
#include<stdio.h>
#include<math.h>
#include <GL/glut.h>


bool isNight = false;

void cloud(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{
    glBegin(GL_POLYGON);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.1416 / 180;
        float x = rx * cos(angle);
        float y = ry * sin(angle);
        glVertex2f((x + cx), (y + cy));
    }
    glEnd();
}


void init(void)
{
    if (isNight)
        glClearColor(0.0, 0.0, 0.1, 0.0);
    else
        glClearColor(0.0, 0.9, 0.9, 0.0);  // day

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}


float cx = -300;
float bx = -400;
float bx2 = 40;

void keyboard(unsigned char key, int x, int y)
{
    if (key == 'n' || key == 'N')
        isNight = true;

    if (key == 'd' || key == 'D')
        isNight = false;

    glutPostRedisplay();
}

void clouds()
{
    glPushMatrix();
    glTranslatef(cx, 0, 0);

    if (isNight)
        glColor3ub(140, 140, 140);
    else
        glColor3ub(255, 255, 255);


    // 1st cloud

    cloud(20, 30, 460, 460);
    cloud(15, 20, 445, 460);
    cloud(15, 20, 475, 460);


    // 2nd cloud

    cloud(20, 30, 390, 420);
    cloud(15, 20, 405, 420);
    cloud(15, 20, 375, 420);


    // 3rd cloud

    cloud(13, 17, 320, 385);
    cloud(7, 11, 309, 385);
    cloud(7, 11, 331, 385);



    glPopMatrix();
    cx += .008;
    if (cx > 200)
        cx = -500;



}
void smallBoat()
{
    glPushMatrix();

    glTranslatef(bx2, 205, 0);
    glScalef(0.35, 0.35, 1);

    if (isNight) glColor3ub(40, 40, 40);
    else glColor3ub(80, 80, 80);
    glBegin(GL_POLYGON);
    glVertex2d(325, 220);
    glVertex2d(400, 220);
    glVertex2d(425, 250);
    glVertex2d(300, 250);
    glEnd();

    if (isNight) glColor3ub(120, 90, 60);
    else glColor3ub(190, 150, 100);
    glBegin(GL_POLYGON);
    glVertex2d(325, 250);
    glVertex2d(400, 250);
    glVertex2d(390, 280);
    glVertex2d(335, 280);
    glEnd();

    if (isNight) glColor3ub(90, 60, 40);
    else glColor3ub(140, 100, 70);
    glBegin(GL_POLYGON);
    glVertex2d(360, 280);
    glVertex2d(370, 280);
    glVertex2d(370, 310);
    glVertex2d(360, 310);
    glEnd();

    if (isNight) glColor3ub(100, 80, 100);
    else glColor3ub(180, 140, 180);
    glBegin(GL_POLYGON);
    glVertex2d(335, 290);
    glVertex2d(390, 290);
    glVertex2d(390, 375);
    glVertex2d(335, 375);
    glEnd();

    glPopMatrix();

    bx2 += 0.007;
    if (bx2 > 400)
        bx2 = -200;
}
void boat()
{
    glPushMatrix();
    glTranslatef(bx, 0, 0);

    if (isNight) glColor3ub(20, 20, 20);
    else glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2d(325, 220);
    glVertex2d(400, 220);
    glVertex2d(425, 250);
    glVertex2d(300, 250);
    glEnd();

    if (isNight) glColor3ub(120, 80, 40);
    else glColor3ub(205, 133, 63);
    glBegin(GL_POLYGON);
    glVertex2d(325, 250);
    glVertex2d(400, 250);
    glVertex2d(390, 280);
    glVertex2d(335, 280);
    glEnd();

    if (isNight) glColor3ub(100, 60, 30);
    else glColor3ub(160, 82, 45);
    glBegin(GL_POLYGON);
    glVertex2d(360, 280);
    glVertex2d(370, 280);
    glVertex2d(370, 310);
    glVertex2d(360, 310);
    glEnd();

    if (isNight) glColor3ub(80, 0, 80);
    else glColor3ub(128, 0, 128);
    glBegin(GL_POLYGON);
    glVertex2d(335, 290);
    glVertex2d(390, 290);
    glVertex2d(390, 375);
    glVertex2d(335, 375);
    glEnd();

    glPopMatrix();

    bx += .02;
    if (bx > 220)
        bx = -500;
}

void drawCircleMidpoint(int xc, int yc, int r)
{
    int x = 0, y = r;
    int p = 1 - r;

    while (x <= y)
    {
        glBegin(GL_LINES);

        glVertex2i(xc - x, yc + y);
        glVertex2i(xc + x, yc + y);

        glVertex2i(xc - x, yc - y);
        glVertex2i(xc + x, yc - y);

        glVertex2i(xc - y, yc + x);
        glVertex2i(xc + y, yc + x);

        glVertex2i(xc - y, yc - x);
        glVertex2i(xc + y, yc - x);

        glEnd();

        if (p < 0)
            p += 2 * x + 3;
        else
        {
            p += 2 * (x - y) + 5;
            y--;
        }
        x++;
    }
}

void drawLineDDA(float x1, float y1, float x2, float y2)
{
    glPointSize(2);

    float dx = x2 - x1;
    float dy = y2 - y1;

    float steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);

    float xInc = dx / steps;
    float yInc = dy / steps;

    float x = x1;
    float y = y1;

    glBegin(GL_POINTS);
    for (int i = 0; i <= steps; i++)
    {
        glVertex2f(x, y);
        x += xInc;
        y += yInc;
    }
    glEnd();
}


void bambooWall(float startX, float endX, float y)
{
    // vertical bamboo sticks using DDA
    if (isNight)
        glColor3ub(120, 110, 80);
    else
        glColor3ub(194, 178, 128);

    for (float i = startX; i <= endX; i += 8)
    {
        // left line
        drawLineDDA(i, y, i, y + 40);

        // right line (thickness)
        drawLineDDA(i + 3, y, i + 3, y + 40);
    }

    // horizontal supports using DDA
    if (isNight)
        glColor3ub(100, 90, 60);
    else
        glColor3ub(160, 140, 90);


    drawLineDDA(startX, y + 10, endX, y + 10);
    drawLineDDA(startX, y + 13, endX, y + 13);

    drawLineDDA(startX, y + 25, endX, y + 25);
    drawLineDDA(startX, y + 28, endX, y + 28);
}


void stars()
{
    if (!isNight) return;

    glPointSize(2);
    glBegin(GL_POINTS);

    glColor3ub(255, 255, 255);

    glVertex2i(50, 450);
    glVertex2i(100, 420);
    glVertex2i(200, 470);
    glVertex2i(300, 440);
    glVertex2i(400, 460);
    glVertex2i(250, 430);
    glVertex2i(150, 480);

    glEnd();
}


void display(void)
{

    if (isNight)
        glClearColor(0.0, 0.0, 0.1, 0.0);
    else
        glClearColor(0.0, 0.9, 0.9, 0.0);

    glClear(GL_COLOR_BUFFER_BIT);


    //Ground Color
    if (isNight)
        glColor3ub(20, 100, 20);
    else
        glColor3ub(0, 255, 0);
    glBegin(GL_POLYGON);
    glVertex2d(0, 0);
    glVertex2d(500, 0);
    glVertex2d(500, 300);
    glVertex2d(0, 300);
    glEnd();


    // River

    if (isNight)
        glColor3ub(30, 60, 120);
    else
        glColor3ub(100, 149, 237);
    glBegin(GL_POLYGON);
    glVertex2d(300, 300);
    glVertex2d(250, 150);
    glVertex2d(400, 150);
    glVertex2d(450, 300);
    glEnd();


    if (isNight)
        glColor3ub(30, 60, 120);
    else
        glColor3ub(100, 149, 237);
    glBegin(GL_POLYGON);
    glVertex2d(300, 150);
    glVertex2d(250, 0);
    glVertex2d(400, 0);
    glVertex2d(450, 150);
    glEnd();


    if (isNight)
        glColor3ub(30, 60, 120);
    else
        glColor3ub(100, 149, 237);
    glBegin(GL_POLYGON);
    glVertex2d(-40, 200);
    glVertex2d(0, 300);
    glVertex2d(500, 300);
    glVertex2d(500, 200);
    glEnd();


    stars();

    // Hills 1
    if (isNight)
        glColor3ub(80, 70, 40);
    else
        glColor3ub(230, 200, 120);

    glBegin(GL_POLYGON);
    glVertex2d(-40, 300);
    glVertex2d(200, 300);
    glVertex2d(100, 450);
    glEnd();


    // Hills 2
    if (isNight)
        glColor3ub(70, 60, 30);
    else
        glColor3ub(200, 160, 60);

    glBegin(GL_POLYGON);
    glVertex2d(150, 300);
    glVertex2d(350, 300);
    glVertex2d(250, 450);
    glEnd();


    // Hills 3
    if (isNight)
        glColor3ub(50, 40, 20);
    else
        glColor3ub(160, 110, 30);

    glBegin(GL_POLYGON);
    glVertex2d(300, 300);
    glVertex2d(520, 300);
    glVertex2d(400, 450);
    glEnd();



    smallBoat();
    boat();


    bambooWall(-1, 255, 190);
    bambooWall(-1, 240, 10);
    bambooWall(250, 290, 135);

    bambooWall(420, 500, 190);
     bambooWall(420, 500, 10);


    // sun and moon
    if (isNight)
    {

        glColor3ub(220, 220, 220);
        drawCircleMidpoint(175, 450, 18);
    }
    else
    {
        glColor3ub(255, 215, 0);
        drawCircleMidpoint(175, 450, 25);
    }


    clouds();


    // Big Tree

    if (isNight)
        glColor3ub(60, 30, 10);
    else
        glColor3ub(139, 69, 19);
    glBegin(GL_POLYGON);
    glVertex2d(50, 150);
    glVertex2d(70, 150);
    glVertex2d(70, 300);
    glVertex2d(50, 300);
    glEnd();


    // Tree leaf


    if (isNight)
        glColor3ub(0, 60, 0);
    else
        glColor3ub(0, 128, 0);
    cloud(30, 40, 35, 320);


    if (isNight)
        glColor3ub(0, 60, 0);
    else
        glColor3ub(0, 128, 0);
    cloud(30, 40, 85, 320);


    if (isNight)
        glColor3ub(0, 60, 0);
    else
        glColor3ub(0, 128, 0);
    cloud(25, 30, 45, 370);


    if (isNight)
        glColor3ub(0, 60, 0);
    else
        glColor3ub(0, 128, 0);
    cloud(30, 30, 70, 370);


    if (isNight)
        glColor3ub(0, 60, 0);
    else
        glColor3ub(0, 128, 0);
    cloud(25, 30, 55, 400);



    // Small tree

    if (isNight)
        glColor3ub(60, 30, 10);
    else
        glColor3ub(139, 69, 19);
    glBegin(GL_POLYGON);
    glVertex2d(145, 220);
    glVertex2d(157, 220);
    glVertex2d(157, 310);
    glVertex2d(145, 310);
    glEnd();


    // leaves
    if (isNight)
        glColor3ub(0, 60, 0);
    else
        glColor3ub(0, 128, 0);
    cloud(22, 26, 136, 315);

    if (isNight)
        glColor3ub(0, 60, 0);
    else
        glColor3ub(0, 128, 0);
    cloud(22, 26, 166, 315);

    if (isNight)
        glColor3ub(0, 60, 0);
    else
        glColor3ub(0, 128, 0);
    cloud(16, 20, 151, 345);

    // 2nd House

    if (isNight)
        glColor3ub(120, 60, 20);
    else
        glColor3ub(210, 105, 30);

    glBegin(GL_POLYGON);
    glVertex2d(100, 220);
    glVertex2d(200, 220);
    glVertex2d(175, 270);
    glVertex2d(130, 270);
    glEnd();


    if (isNight)
        glColor3ub(140, 90, 50);
    else
        glColor3ub(244, 164, 96);

    glBegin(GL_POLYGON);
    glVertex2d(100, 170);
    glVertex2d(185, 170);
    glVertex2d(185, 220);
    glVertex2d(100, 220);
    glEnd();


    if (isNight)
        glColor3ub(90, 50, 25);
    else
        glColor3ub(160, 82, 45);

    glBegin(GL_POLYGON);
    glVertex2d(100, 170);
    glVertex2d(190, 170);
    glVertex2d(190, 160);
    glVertex2d(100, 160);
    glEnd();



    // 2nd house door and window


    if (isNight)
        glColor3ub(255, 255, 100); // light ON
    else
        glColor3ub(160, 82, 45);   // normal
    glBegin(GL_POLYGON);
    glVertex2d(140, 170);
    glVertex2d(165, 170);
    glVertex2d(165, 200);
    glVertex2d(140, 200);
    glEnd();




    // 1st House


    if (isNight)
        glColor3ub(90, 50, 25);
    else
        glColor3ub(160, 82, 45);

    glBegin(GL_POLYGON);
    glVertex2d(0, 220);
    glVertex2d(135, 220);
    glVertex2d(110, 270);
    glVertex2d(25, 270);
    glEnd();


    if (isNight)
        glColor3ub(140, 110, 70);
    else
        glColor3ub(255, 222, 173);

    glBegin(GL_POLYGON);
    glVertex2d(10, 220);
    glVertex2d(50, 220);
    glVertex2d(25, 255);
    glEnd();


    if (isNight)
        glColor3ub(120, 90, 60);
    else
        glColor3ub(255, 222, 173);

    glBegin(GL_POLYGON);
    glVertex2d(10, 150);
    glVertex2d(50, 150);
    glVertex2d(50, 220);
    glVertex2d(10, 220);
    glEnd();


    if (isNight)
        glColor3ub(100, 80, 50);
    else
        glColor3ub(222, 184, 135);

    glBegin(GL_POLYGON);
    glVertex2d(50, 150);
    glVertex2d(125, 150);
    glVertex2d(125, 220);
    glVertex2d(50, 220);
    glEnd();


    if (isNight)
        glColor3ub(80, 50, 25);
    else
        glColor3ub(160, 82, 45);

    glBegin(GL_POLYGON);
    glVertex2d(10, 150);
    glVertex2d(125, 150);
    glVertex2d(125, 140);
    glVertex2d(10, 140);
    glEnd();



    // 1st house door and window


    if (isNight)
        glColor3ub(255, 255, 100);
    else
        glColor3ub(160, 82, 45);
    glBegin(GL_POLYGON);
    glVertex2d(75, 150);
    glVertex2d(95, 150);
    glVertex2d(95, 195);
    glVertex2d(75, 195);
    glEnd();


    if (isNight)
        glColor3ub(255, 255, 100);
    else
        glColor3ub(160, 82, 45);
    glBegin(GL_POLYGON);
    glVertex2d(20, 200);
    glVertex2d(35, 200);
    glVertex2d(35, 175);
    glVertex2d(20, 175);
    glEnd();



    // Right side house

    // roof
    if (isNight)
        glColor3ub(90, 50, 25);
    else
        glColor3ub(160, 82, 45);

    glBegin(GL_POLYGON);
    glVertex2d(450, 220);
    glVertex2d(550, 220);
    glVertex2d(520, 270);
    glVertex2d(480, 270);
    glEnd();


    // wall
    if (isNight)
        glColor3ub(120, 90, 60);
    else
        glColor3ub(222, 184, 135);

    glBegin(GL_POLYGON);
    glVertex2d(460, 150);
    glVertex2d(550, 150);
    glVertex2d(550, 220);
    glVertex2d(460, 220);
    glEnd();


    // base
    if (isNight)
        glColor3ub(80, 50, 25);
    else
        glColor3ub(160, 82, 45);

    glBegin(GL_POLYGON);
    glVertex2d(460, 150);
    glVertex2d(550, 150);
    glVertex2d(550, 140);
    glVertex2d(460, 140);
    glEnd();

    // door
    if (isNight)
        glColor3ub(255, 255, 100);
    else
        glColor3ub(160, 82, 45);
    glBegin(GL_POLYGON);
    glVertex2d(480, 150);
    glVertex2d(500, 150);
    glVertex2d(500, 190);
    glVertex2d(480, 190);
    glEnd();



    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(900, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Nature and Village Illustration");

    glutSetKeyRepeat(GLUT_KEY_REPEAT_ON);

    init();

    glutDisplayFunc(display);

    glutKeyboardFunc(keyboard);


    glutMainLoop();

    return 0;
}

