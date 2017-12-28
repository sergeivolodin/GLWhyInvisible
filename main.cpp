#include "controlswindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ControlsWindow w;
    w.show();

    w.setApp(&a);

    return a.exec();
}
