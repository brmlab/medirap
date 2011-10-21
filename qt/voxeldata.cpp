#include "voxeldata.h"
#include <QFile>
#include <QImage>
#include <QTextStream>
#include <QDebug>

bool VoxelData::load(QString path, QString filename)
{
    data.clear();
    qDebug() << "Processing " + path + "/" + filename + " ...";
    QFile file(path + "/" + filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        qDebug() << "Loading " + line + " ...";
        data.push_back(new QImage(path + "/" + line));
    }
    dimz = data.size();
    file.close();
    return true;
}

const QImage *VoxelData::getSlice(int z)
{
    return data[z];
}
