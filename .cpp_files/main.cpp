#include "mainwindow.h"
#include "openwindow.h"
#include <QApplication>
#include<QLabel>
#include<QMessageBox>
#include<QSlider>
#include<QSpinBox>
#include<QHBoxLayout>
#include<QGraphicsItemAnimation>
#include<QMap>
int main(int argc, char *argv[])
{
 QApplication a(argc, argv);
OpenWindow wind;
wind.show();
 a.exec();
}
