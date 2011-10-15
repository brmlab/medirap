#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <qdebug.h>
#include <QMessageBox>

#define BLACK 0xFF000000
#define RED   0xFFFF0000
#define WHITE 0xFFFFFFFF
#define BLUE  0xFF0000FF

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

void MainWindow::on_pushLoad_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open Image", "", "Series of medical files (*.txt)");
    if (filename.isNull()) return;
    QFileInfo pathInfo(filename);
    if (!vdata.load(pathInfo.path(), pathInfo.fileName())) {
        QMessageBox("Error", "Error loading data");
    } else {
        ui->sliderPosition->setMaximum(vdata.getDimZ());
        ui->sliderPosition->setValue(vdata.getDimZ()/2);
    }

}

/*
void MainWindow::on_sliderThreshold_valueChanged(int value)
{
    thresholdimage = shownimage;
    for (int x = 0; x < shownimage.width(); ++x) {
        for (int y = 0; y < shownimage.height(); ++y) {
            int pval = shownimage.pixel(x, y) & 0xFF;
            if (pval > value) {
                thresholdimage.setPixel(x, y, WHITE);
            } else {
                thresholdimage.setPixel(x, y, BLACK);
            }
        }
    }
    scene.clear();
    pixmap.convertFromImage(thresholdimage);
    scene.addPixmap(pixmap);
}
*/

/*
void MainWindow::on_pushFill_clicked()
{
    fillupimage = thresholdimage;
    for (int x = 0; x < fillupimage.width(); ++x) {
        for (int y = 0; y < fillupimage.height(); ++y) {
            fillupimage.setPixel(x, y, BLACK);
        }
    }

    for (int x = 0; x < thresholdimage.width()-1; ++x) {
        for (int y = 0; y < thresholdimage.height()-1; ++y) {
            int pval1 = thresholdimage.pixel(x, y) & 0xFF;
            int pval2 = thresholdimage.pixel(x+1, y) & 0xFF;
            int pval3 = thresholdimage.pixel(x, y+1) & 0xFF;
            int pval4 = thresholdimage.pixel(x+1, y+1) & 0xFF;
            int cnt = 0;
            if (pval1 > 128) cnt++;
            if (pval2 > 128) cnt++;
            if (pval3 > 128) cnt++;
            if (pval4 > 128) cnt++;

            if (cnt < 4 && cnt > 1) {
                for (int a = -3; a <= +3; ++a) {
                    for (int b = -3; b <= +3; ++b) {
                        if (abs(a) + abs(b) < 6) {
                            fillupimage.setPixel(x+a, y+b, WHITE);
                        }
                    }
                }
            }
        }
    }

    floodfill(fillupimage);

    for (int x = 0; x < fillupimage.width(); ++x) {
        for (int y = 0; y < fillupimage.height(); ++y) {
            if (fillupimage.pixel(x, y) == RED) {
                fillupimage.setPixel(x, y, BLACK);
            } else {
                fillupimage.setPixel(x, y, WHITE);
            }
        }
    }

    scene.clear();
    pixmap.convertFromImage(fillupimage);
    scene.addPixmap(pixmap);
}

void MainWindow::floodfill(QImage &img)
{
    QVector<QPoint> q;

    q.push_back(QPoint(0,0));

    while (!q.isEmpty()) {
        QPoint p = q.last(); q.pop_back();
        bool shouldBeRed = true;

        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (i != 0 && j != 0 && img.valid(p.x()+i, p.y()+j) && img.pixel(p.x()+i, p.y()+j) == WHITE) shouldBeRed = false;
            }
        }
        img.setPixel(p.x(),p.y(), shouldBeRed ? RED : BLUE);
        if (p.x() > 0 && img.pixel(p.x()-1,p.y()) == BLACK) q.push_back(QPoint(p.x()-1,p.y()));
        if (p.y() > 0 && img.pixel(p.x(),p.y()-1) == BLACK) q.push_back(QPoint(p.x(),p.y()-1));
        if (p.x() < img.width()-1 && img.pixel(p.x()+1,p.y()) == BLACK) q.push_back(QPoint(p.x()+1,p.y()));
        if (p.y() < img.height()-1 && img.pixel(p.x(),p.y()+1) == BLACK) q.push_back(QPoint(p.x(),p.y()+1));
    }

}
*/

void MainWindow::on_sliderPosition_valueChanged(int value)
{
    QPixmap pixmap;
    scene.clear();
    pixmap.convertFromImage(image);
    scene.addPixmap(pixmap);
}
