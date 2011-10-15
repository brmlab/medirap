#ifndef VOXELDATA_H
#define VOXELDATA_H

#include <QString>

#define VOXELDATA char

class VoxelData
{
public:
    inline int getDimX() { return dimx; }
    inline int getDimY() { return dimy; }
    inline int getDimZ() { return dimz; }
    bool load(QString path, QString filename);
private:
    int dimx, dimy, dimz;
    VOXELDATA *data;
};

#endif
