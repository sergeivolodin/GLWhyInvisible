#ifndef GLUTCUBEPAINTERTHREADED_H
#define GLUTCUBEPAINTERTHREADED_H

#include <QThread>
#include "glparams.h"
#include "glutcubepainter.h"

class GLUTCubePainterThreaded : public QThread
{ Q_OBJECT
public:
    GLUTCubePainterThreaded();
    void updateParameters(GLParams new_params);

private:
    volatile GLParams params;
    volatile int need_exit;
    void run();

public slots:
    void stopGLUT();
};

#endif // GLUTCUBEPAINTERTHREADED_H
