#include "glparams.h"

#include <QTextStream>

GLParams::GLParams()
{
    x = y = z = 0;
    n = f = 0;
    l = r = 0;
    b = t = 0;
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
