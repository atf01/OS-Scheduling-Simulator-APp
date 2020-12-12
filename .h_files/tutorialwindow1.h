#ifndef TUTORIALWINDOW1_H
#define TUTORIALWINDOW1_H

#include <QWidget>

namespace Ui {
class tutorialWindow1;
}

class tutorialWindow1 : public QWidget
{
    Q_OBJECT

public:
    explicit tutorialWindow1(QWidget *parent = 0);
    ~tutorialWindow1();

private slots:
    void on_Back_clicked();

private:
    Ui::tutorialWindow1 *ui;
};

#endif // TUTORIALWINDOW1_H
