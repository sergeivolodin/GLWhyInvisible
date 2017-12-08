#ifndef GLUTCUBEPAINTER_H
#define GLUTCUBEPAINTER_H

#include <GL/glut.h>
#include "glparams.h"

class GLUTCubePainter
{
public:
    GLUTCubePainter();
    static GLParams* getParameters();

    static void run();
private:
    static GLParams parameters;
    static void drawBox();
    static void init();
    static void display();

    static GLfloat light_diffuse[4];
    static GLfloat light_position[4];
    static GLfloat n[6][3];
    static GLint faces[6][4];
    static GLfloat v[8][3];
};

#endif // GLUTCUBEPAINTER_H
