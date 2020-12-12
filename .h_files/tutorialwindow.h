#ifndef TUTORIALWINDOW_H
#define TUTORIALWINDOW_H
#include "openwindow.h"
#include <QWidget>

namespace Ui {
class tutorialWindow;
}

class tutorialWindow : public QWidget
{
    Q_OBJECT

public:
    explicit tutorialWindow(QWidget *parent = 0);
    ~tutorialWindow();

private slots:


    void on_Howtouseit_clicked();

    void on_Gotimainpage_clicked();

private:
    Ui::tutorialWindow *ui;
   // Ui::OpenWindow *ms;
};

#endif // TUTORIALWINDOW_H
