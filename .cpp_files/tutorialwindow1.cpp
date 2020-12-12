#include "tutorialwindow1.h"
#include "ui_tutorialwindow1.h"
#include "tutorialwindow.h"

tutorialWindow1::tutorialWindow1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tutorialWindow1)
{
    ui->setupUi(this);
}

tutorialWindow1::~tutorialWindow1()
{
    delete ui;
}

void tutorialWindow1::on_Back_clicked()
{
    tutorialWindow1::close();
    tutorialWindow *ms=new tutorialWindow();
    ms->show();

}
