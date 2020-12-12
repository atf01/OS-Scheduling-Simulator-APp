#ifndef OPENWINDOW_H
#define OPENWINDOW_H
#include<QMainWindow>
#include "mainwindow.h"
#include <QWidget>

namespace Ui {
class OpenWindow;
}

class OpenWindow : public QWidget
{
    Q_OBJECT

public:
    explicit OpenWindow(QWidget *parent = 0);
    ~OpenWindow();

private slots:
    void on_Ok_clicked();

    void on_Ok_2_clicked();


    void on_GO_clicked();

private:

    Ui::OpenWindow *ui;
     //MainWindow *se;

};

#endif // OPENWINDOW_H
