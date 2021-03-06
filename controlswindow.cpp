#include "controlswindow.h"
#include "ui_controlswindow.h"
#include <QTextStream>

ControlsWindow::ControlsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ControlsWindow)
{
    ui->setupUi(this);
    painter = new GLUTCubePainterThreaded();
    painter->start();

    updateValues(0);
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


    // projected point
    QVector4D res = p.project();
    QString res_str;
    QTextStream stream(&res_str);
    stream << res.x() / res.w() << " " << res.y() / res.w() << " " << res.z() / res.w();
    ui->result->setText(res_str);
}
