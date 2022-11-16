#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPixmap>
#include <QLine>

class PaintWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PaintWidget(QWidget *parent = 0);
    ~PaintWidget();

signals:

public slots:

protected:
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);
private:
    QLine x_line;
    QPixmap TPixmap;
    bool MousePressed;
};

#endif // PAINTWIDGET_H
