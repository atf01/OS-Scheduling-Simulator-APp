#ifndef OUTPUT_H
#define OUTPUT_H
#include "Sched.h"
#include <QWidget>
#include<vector>
#include<QPainter>
using namespace std;
namespace Ui {
class output;
}

class output : public QWidget
{
    Q_OBJECT

public:
    explicit output(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent* event);
    void setRectangles(vector<QRect>vals,float res,vector<Process>sim,QString t);
    ~output();

private slots:
    void on_pushButton_clicked();

private:
    vector<Process>sim;
    Ui::output *ui;
    vector<QRect>rectangles;
    float res;
    QString t;
};

#endif // OUTPUT_H
