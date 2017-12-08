#include "controlswindow.h"
#include "ui_controlswindow.h"

ControlsWindow::ControlsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ControlsWindow)
{
    ui->setupUi(this);
    painter = new GLUTCubePainterThreaded();
    painter->start();
}

ControlsWindow::~ControlsWindow()
{
    delete ui;
}

void ControlsWindow::updateValues(double callerNewValue)
{ Q_UNUSED(callerNewValue)
    GLParams p;

    p.x = ui->model_x->value();
    p.y = ui->model_y->value();
    p.z = ui->model_z->value();

    p.n = ui->projection_n->value();
    p.f = ui->projection_f->value();

    p.l = ui->projection_l->value();
    p.r = ui->projection_r->value();

    p.b = ui->projection_b->value();
    p.t = ui->projection_t->value();

    painter->updateParameters(p);
}
