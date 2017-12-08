#include "glutcubepainterthreaded.h"
#include <QDebug>

GLUTCubePainterThreaded::GLUTCubePainterThreaded()
{
    params = new GLParams();
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
    // variables must be initialized
    Q_ASSERT(params != NULL);

    // obtaining parameters object
    GLUTCubePainter::setParameters(params);

    // starting drawing
    GLUTCubePainter::run();
}
