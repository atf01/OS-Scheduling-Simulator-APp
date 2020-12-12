#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "dataadapter.h"
#include "openwindow.h"
#include "firstInFirstOut.h"
#include<vector>
#include <QMainWindow>
using std::vector;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_pushButton_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_2_clicked();
  //  virtual void paintRecatangle(QPaintEvent *event);
private:
   Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
