#include "glutcubepainterthreaded.h"
#include <QDebug>

GLUTCubePainterThreaded::GLUTCubePainterThreaded()
{
    need_exit = 0;
}

void GLUTCubePainterThreaded::updateParameters(GLParams new_params)
{
    qDebug() << "Updating" << new_params.toString();

    // copying data
    memcpy((void*) &params, (void*) &new_params, sizeof(GLParams));
}

void GLUTCubePainterThreaded::run()
{
    // obtaining parameters object
    GLUTCubePainter::setParameters(&params);
    GLUTCubePainter::setNeedExit(&need_exit);

    // starting drawing
    GLUTCubePainter::run();
}

void GLUTCubePainterThreaded::stopGLUT()
{
    qDebug() << "Stopping GLUT";
    need_exit = 1;
}
