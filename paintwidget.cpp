#include "paintwidget.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QDebug>

PaintWidget::PaintWidget(QWidget *parent) : QWidget(parent)
{
    TPixmap = QPixmap(400,400);
    TPixmap.fill();
    MousePressed = false;
}

PaintWidget::~PaintWidget()
{
//    delete ui;
}

void PaintWidget::mousePressEvent(QMouseEvent* event)
{
    MousePressed = true;
    x_line.setP1(event->pos());
    x_line.setP2(event->pos());
}

void PaintWidget::mouseReleaseEvent(QMouseEvent*)
{
    MousePressed = false;
    update();
}

void PaintWidget::paintEvent(QPaintEvent*)
{
    static bool wasPressed = false;
    QPainter painter(this);

    if(MousePressed)
    {
        painter.drawPixmap(0, 0, TPixmap);
        painter.drawLine(x_line);
        wasPressed = true;
    }
    else if(wasPressed)
    {
        QPainter PixmapPainter(&TPixmap);
        QPen pen(Qt::red);
        PixmapPainter.setPen(pen);
        PixmapPainter.drawLine(x_line);

        painter.drawPixmap(0, 0, TPixmap);
        wasPressed = false;
    }
}

void PaintWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->type() == QEvent::MouseMove)
    {
        x_line.setP2(event->pos());
    }
    update();
}
