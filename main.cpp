#include "controlswindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ControlsWindow w;
    w.show();

    return a.exec();
}
