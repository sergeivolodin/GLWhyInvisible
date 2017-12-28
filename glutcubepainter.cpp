/* Copyright (c) Mark J. Kilgard, 1997. */

/* This program is freely distributable without licensing fees
   and is provided without guarantee or warrantee expressed or
   implied. This program is -not- in the public domain. */

/* This program was requested by Patrick Earl; hopefully someone else
   will write the equivalent Direct3D immediate mode program. */

#include <GL/glut.h>
#include <GL/freeglut.h>
#include "glutcubepainter.h"
#include <QDebug>

GLfloat GLUTCubePainter::light_diffuse[4] = {1.0, 0.0, 0.0, 1.0};  /* Red diffuse light. */
GLfloat GLUTCubePainter::light_position[4] = {1.0, 1.0, 1.0, 0.0};  /* Infinite light location. */
GLfloat GLUTCubePainter::n[6][3] = {  /* Normals for the 6 faces of a cube. */
                                      {-1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {1.0, 0.0, 0.0},
                                      {0.0, -1.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, -1.0} };
GLint GLUTCubePainter::faces[6][4] = {  /* Vertex indices for the 6 faces of a cube. */
                                        {0, 1, 2, 3}, {3, 2, 6, 7}, {7, 6, 5, 4},
                                        {4, 5, 1, 0}, {5, 6, 2, 1}, {7, 4, 0, 3} };
GLfloat GLUTCubePainter::v[8][3];
volatile GLParams* GLUTCubePainter::parameters = NULL;
volatile int* GLUTCubePainter::need_exit = NULL;

void GLUTCubePainter::drawBox(void)
{
    for (int i = 0; i < 6; i++) {
        glBegin(GL_QUADS);
        glColor3f(0.3 * i + 0.1, 0.1 * i, 0.2 * i);
        glNormal3fv(&n[i][0]);
        glVertex3fv(&v[faces[i][0]][0]);
        glVertex3fv(&v[faces[i][1]][0]);
        glVertex3fv(&v[faces[i][2]][0]);
        glVertex3fv(&v[faces[i][3]][0]);
        glEnd();
    }
}

void GLUTCubePainter::display(void)
{
    Q_ASSERT(need_exit != NULL);
    Q_ASSERT(parameters != NULL);

    // check if we are done
    if(*need_exit)
    {
        qDebug() << "Need exit";
        glutLeaveMainLoop();
    }

    /* Use depth buffering for hidden surface elimination. */
    glEnable(GL_DEPTH_TEST);

    /* Setup the view of the cube. */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glFrustum(parameters->l, parameters->r, parameters->b, parameters->t, parameters->n, parameters->f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glTranslatef(parameters->x, parameters->y, parameters->z);

    /* Adjust cube position to be asthetic angle. */
    //glRotatef(60, 1.0, 0.0, 0.0);
    //glRotatef(-20, 0.0, 0.0, 1.0);

    drawBox();
    glutSwapBuffers();

}

GLUTCubePainter::GLUTCubePainter()
{
}

void GLUTCubePainter::setNeedExit(volatile int *need_exit_)
{
    Q_ASSERT(need_exit_ != NULL);
    need_exit = need_exit_;
}

void GLUTCubePainter::setParameters(volatile GLParams* params)
{
    Q_ASSERT(params != NULL);
    parameters = params;
}

void GLUTCubePainter::glutTimer(int value)
{ Q_UNUSED(value);
    if(*need_exit == 1)
        return;
    glutPostRedisplay();
    glutTimerFunc(update_ms, glutTimer, 0);
}

void GLUTCubePainter::quit()
{
    qDebug() << "Exiting GLUT";
}

void GLUTCubePainter::run()
{
    /* Setup cube vertex data. */
    v[0][0] = v[1][0] = v[2][0] = v[3][0] = -1;
    v[4][0] = v[5][0] = v[6][0] = v[7][0] = 1;
    v[0][1] = v[1][1] = v[4][1] = v[5][1] = -1;
    v[2][1] = v[3][1] = v[6][1] = v[7][1] = 1;
    v[0][2] = v[3][2] = v[4][2] = v[7][2] = 1;
    v[1][2] = v[2][2] = v[5][2] = v[6][2] = -1;

    int argc = 1;
    const char* argv[] = {"main", NULL};
    glutInit(&argc, (char**) argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("red 3D lighted cube");
    glutDisplayFunc(display);
    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);
    glutTimerFunc(update_ms, glutTimer, 0);
    atexit(quit);
    glutMainLoop();
}
