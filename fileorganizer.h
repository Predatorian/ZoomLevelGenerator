/*
*  This file is part of the ZoomLevelGenerator.
*  Copyright (C) 2013 Alexander Wahlen <wahlen001@aol.com>.
*
*  This file is part of ZoomLevelGenerator.
*
*  ZoomLevelGenerator is free software: you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation, either version 3 of the License, or
*  (at your option) any later version.
*
*  ZoomLevelGenerator is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  A copy the GNU General Public License version 3 is distributed along
*  with the source tree of which this file is a part in the file
*  `./COPYING'. If it is missing for any reason,
*  please see <http://www.gnu.org/licenses/>.
*/
#ifndef FILEORGANIZER_H
#define FILEORGANIZER_H
#include <QString>
#include <QDir>
#include <QPoint>
#include <QVector>
#include "structs.h"

class FileOrganizer
{
public:
    FileOrganizer(QString srcPath, QString targetPath);
    bool filesLeft();
    QString * getNext();
    void process();
private:
    void readCoords();
    void createFilePacketList();
    QDir * sDir;
    QString tPath;
    QVector<QPoint>  sFiles;
    QVector<FilePathPacket> packets;

};

#endif // FILEORGANIZER_H
