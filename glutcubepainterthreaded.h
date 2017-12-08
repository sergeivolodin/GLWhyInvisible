#ifndef GLUTCUBEPAINTERTHREADED_H
#define GLUTCUBEPAINTERTHREADED_H

#include <QThread>
#include "glparams.h"
#include "glutcubepainter.h"

class GLUTCubePainterThreaded : public QThread
{ Q_OBJECT
public:
    GLUTCubePainter* painter = NULL;
    GLParams* params = NULL;
    GLUTCubePainterThreaded();

    void updateParameters(GLParams new_params);
private:
    void run();
};

#endif // GLUTCUBEPAINTERTHREADED_H
