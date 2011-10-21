#ifndef VOXELDATA_H
#define VOXELDATA_H

#include <QString>
#include <QImage>
#include <QVector>

class VoxelData
{
public:
    inline int getDimX() { return dimx; }
    inline int getDimY() { return dimy; }
    inline int getDimZ() { return dimz; }
    bool load(QString path, QString filename);
    const QImage *getSlice(int z);
private:
    int dimx, dimy, dimz;
    QVector<QImage *> data;
};

#endif
