#include "glutcubepainterthreaded.h"
#include <QDebug>

GLUTCubePainterThreaded::GLUTCubePainterThreaded()
{
    params = NULL;
}

void GLUTCubePainterThreaded::updateParameters(GLParams new_params)
{
    Q_ASSERT(params != NULL);

    qDebug() << "Updating" << new_params.toString();

    // copying data
    *params = new_params;
}

void GLUTCubePainterThreaded::run()
{
    // variables must be non-initialized now
    Q_ASSERT(params == NULL);

    // obtaining parameters object
    params = GLUTCubePainter::getParameters();

    // starting drawing
    GLUTCubePainter::run();
}
