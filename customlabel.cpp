#include "customlabel.h"

////////////////////////////////////////////////
// http://www.youtube.com/watch?v=d0CDMtfefB4 //
////////////////////////////////////////////////

CustomLabel::CustomLabel(QWidget *parent) :
    QLabel(parent)
{
}

void CustomLabel::mouseMoveEvent(QMouseEvent *ev)
{
    this->mouse_X = ev->x();
    this->mouse_Y = ev->y();
    emit Mouse_Pos();
}

void CustomLabel::mousePressEvent(QMouseEvent *ev)
{
    emit Mouse_Pressed();
}

void CustomLabel::leaveEvent(QEvent *)
{
    emit Mouse_Left();
}

void CustomLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    emit Mouse_Release();
}
