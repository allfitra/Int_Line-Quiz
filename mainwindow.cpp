#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "paintwidget.h"
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QHBoxLayout * hbox = new QHBoxLayout();
    ui->centralWidget->setLayout(hbox);
    hbox->addWidget(new PaintWidget());
}

MainWindow::~MainWindow()
{
    delete ui;
}
