#include "openwindow.h"
#include "ui_openwindow.h"
#include "mainwindow.h"
#include "tutorialwindow.h"
#include<QMainWindow>
#include<QMessageBox>
#include<QDebug>
OpenWindow::OpenWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OpenWindow)
{
    ui->setupUi(this);
}

OpenWindow::~OpenWindow()
{
    delete ui;
}



void OpenWindow::on_Ok_clicked()
{
OpenWindow::close();
MainWindow *ms=new MainWindow(this);
ms->show();

}

void OpenWindow::on_Ok_2_clicked()
{
    OpenWindow::close();

}


void OpenWindow::on_GO_clicked()
{
   OpenWindow::close();
   tutorialWindow *page=new tutorialWindow();
   page->show();
}
