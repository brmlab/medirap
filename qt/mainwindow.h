#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "voxeldata.h"

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
    void on_pushLoad_clicked();

    void on_sliderPosition_valueChanged(int value);

    void on_sliderThreshold_valueChanged(int value);

    void on_checkThreshold_clicked();

private:
    Ui::MainWindow *ui;
    VoxelData vdata;
    QGraphicsScene scene;
};

#endif // MAINWINDOW_H
