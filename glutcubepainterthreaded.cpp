#include "glutcubepainterthreaded.h"

GLUTCubePainterThreaded::GLUTCubePainterThreaded()
{
    params = NULL;
    painter = NULL;
}

void GLUTCubePainterThreaded::updateParameters(GLParams new_params)
{
    Q_ASSERT(params != NULL);
    Q_ASSERT(painter != NULL);

    // copying data
    *params = new_params;
}

void GLUTCubePainterThreaded::run()
{
    // variables must be non-initialized now
    Q_ASSERT(params == NULL);
    Q_ASSERT(painter == NULL);

    // obtaining parameters object
    params = GLUTCubePainter::getParameters();

    // starting drawing
    GLUTCubePainter::run();
}
