#include "glparams.h"

#include <QTextStream>
#include <Qt3DRender/QCameraLens>

GLParams::GLParams()
{
    x = y = z = 0;
    n = f = 0;
    l = r = 0;
    b = t = 0;
}

QVector4D GLParams::project() {
    Qt3DRender::QCameraLens lens;
    lens.setFrustumProjection(l, r, b, t, n, f);
    QMatrix4x4 pm = lens.projectionMatrix();
    return pm.map(QVector4D(x, y, z, 1));
}

QString GLParams::toString()
{
    QString res;
    QTextStream stream(&res);
    stream << "x=" << x << " "
           << "y=" << y << " "
           << "z=" << z << " "

           << "n=" << n << " "
           << "f=" << f << " "

           << "l=" << l << " "
           << "r=" << r << " "

           << "b=" << b << " "
           << "t=" << t;
    return(res);
}
