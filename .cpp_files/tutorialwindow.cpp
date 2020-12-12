#include "tutorialwindow.h"
#include "ui_tutorialwindow.h"
#include "openwindow.h"
#include "tutorialwindow1.h"

tutorialWindow::tutorialWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tutorialWindow)
{
    ui->setupUi(this);
}

tutorialWindow::~tutorialWindow()
{
    delete ui;
}

void tutorialWindow::on_Howtouseit_clicked()
{
   tutorialWindow::close();
   tutorialWindow1 *ms=new tutorialWindow1();
   ms->show();
}

void tutorialWindow::on_Gotimainpage_clicked()
{
    tutorialWindow::close();
   OpenWindow *f=new OpenWindow();
   f->show();

}
