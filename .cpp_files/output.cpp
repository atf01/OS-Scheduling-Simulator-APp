#include "output.h"
#include "ui_output.h"
#include<mainwindow.h>
#include<QPainter>
output::output(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::output)
{
    ui->setupUi(this);
}

output::~output()
{
    delete ui;
}
void output::paintEvent(QPaintEvent* event)
{

QPainter paint(this);
for(int i=0;i<rectangles.size();i++)
{
    paint.drawRect(rectangles[i]);
 if(sim[i].index>-1)paint.drawText(QPoint(rectangles[i].x()+rectangles[i].height()/2,rectangles[i].y()+30),"P"+QString::number(sim[i].index));
 else paint.drawText(QPoint(rectangles[i].x()+rectangles[i].height()/3,rectangles[i].y()+30),"NOP");

}
for(int i=0;i<rectangles.size();i++)
    paint.drawText(QPoint(rectangles[i].x(),rectangles[i].y()+70),QString::number(sim[i].start));
paint.drawText(QPoint(rectangles[rectangles.size()-1].x()+rectangles[rectangles.size()-1].width(),rectangles[rectangles.size()-1].y()+70),QString::number(sim[sim.size()-1].finish));
paint.drawText(QPoint(rectangles[0].x(),rectangles[0].y()+90),"Average Waiting Time:  "+QString::number(output::res)+"  "+t);
}
void output::setRectangles(vector<QRect>vals,float res,vector<Process>sim,QString t)
{
  output::rectangles=vals;
  output::res=res;
  output::sim=sim;
  output::t=t;
}


void output::on_pushButton_clicked()
{
    output::close();
    MainWindow *mainw=new MainWindow();
    mainw->show();

}
