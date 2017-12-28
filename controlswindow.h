#ifndef CONTROLSWINDOW_H
#define CONTROLSWINDOW_H

#include <QCoreApplication>
#include <QMainWindow>
#include "glparams.h"
#include "glutcubepainterthreaded.h"

namespace Ui {
class ControlsWindow;
}

class ControlsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ControlsWindow(QWidget *parent = 0);
    ~ControlsWindow();

    void setApp(QCoreApplication* app);
private:
    GLUTCubePainterThreaded* painter;
    Ui::ControlsWindow *ui;
private slots:
    // called by ui on update of a value
    void updateValues(double callerNewValue);
};

#endif // CONTROLSWINDOW_H
