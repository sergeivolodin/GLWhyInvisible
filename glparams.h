#ifndef GLPARAMS_H
#define GLPARAMS_H

#include <QString>
#include <QVector4D>

/*
 * This class stores the parameters from the UI
 */

class GLParams {
public:
    // zero all members
    GLParams();

    // model coordinates
    double x, y, z;

    // projection parameters
    double n, f, l, r, t, b;

    QString toString();
    QVector4D project();
};

#endif // GLPARAMS_H
