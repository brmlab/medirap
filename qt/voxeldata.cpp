#include "voxeldata.h"
#include <QFile>
#include <QImage>
#include <QTextStream>
#include <QDebug>

bool VoxelData::load(QString path, QString filename)
{
    qDebug() << "Processing " + path + "/" + filename + " ...";
    QFile file(path + "/" + filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;
    QTextStream in(&file);
    int i = 0;
    data = new VOXELDATA[512*512*512];
    while (!in.atEnd()) {
        QString line = in.readLine();
        QImage img;
        qDebug() << "Loading " + line + " ...";
        img.load(path + "/" + line);
        dimx = img.width();
        dimy = img.height();
        qDebug() << img.format() ;
        i++;
    }
    dimz = i;
    file.close();
    return true;
}
