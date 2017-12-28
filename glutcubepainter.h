#ifndef GLUTCUBEPAINTER_H
#define GLUTCUBEPAINTER_H

#include <GL/glut.h>
#include "glparams.h"

class GLUTCubePainter
{
public:
    GLUTCubePainter();
    static void setNeedExit(volatile int* need_exit_);
    static void setParameters(volatile GLParams* params);

    static void run();
private:
    // parameters for opengl
    static volatile GLParams* parameters;

    // set to true to exit from inside loop
    static volatile int* need_exit;

    static void drawBox();
    static void init();
    static void display();
    static void glutTimer(int value);
    static void drawCube();
    static void quit();

    static GLfloat light_diffuse[4];
    static GLfloat light_position[4];
    static GLfloat n[6][3];
    static GLint faces[6][4];
    static GLfloat v[8][3];

    const static int update_ms = 10;
};

#endif // GLUTCUBEPAINTER_H
