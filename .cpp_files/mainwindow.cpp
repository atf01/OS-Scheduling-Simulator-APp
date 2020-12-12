#include "mainwindow.h"
#include "openwindow.h"
#include "ui_mainwindow.h"
#include "output.h"
#include "dataadapter.h"
#include<vector>
#include<QString>
#include<QMessageBox>
#include<QDebug>
#include<QPainter>
#include "firstInFirstOut.h"
#include "output.h"
#include "sched.h"
using std::vector;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString Arrival,Burst,priority;
    QString Quantum_time;
    float q;
    int n;
     n=ui->lineEdit_4->text().toInt();
    QString algorithm,type,timeunit;
    Arrival=ui->lineEdit_5->text();
    Burst=ui->lineEdit_6->text();
    priority=ui->lineEdit_7->text();
    Quantum_time=ui->lineEdit_8->text();
    q=Quantum_time.toFloat();
    algorithm=ui->comboBox->currentText();
    type=ui->comboBox_2->currentText();
    timeunit=ui->comboBox_3->currentText();
    DataAdapter data(Arrival,Burst,priority,algorithm.toStdString(),type.toStdString(),n,q,timeunit);
    if(!data.checkError())
    {

        QMessageBox::warning(this,"ERROR!","your input contains letters or empty !");

    }

    else if(data.checkInputError())
    {

      QMessageBox::warning(this,"ERROR","check your number of processes or incompatability between Arrival time and burst time!");

    }
    else
    {
       MainWindow::close();
      data.simulation();
    }
}

void MainWindow::on_comboBox_activated(const QString &arg1)
{

}

void MainWindow::on_comboBox_3_activated(const QString &arg1)
{

}

void MainWindow::on_pushButton_2_clicked()
{

}
