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
#include "fileorganizer.h"
#include <iostream>

FileOrganizer::FileOrganizer(QString srcPath, QString targetPath)
{
    this->sDir= new QDir(srcPath);
    this->tPath= targetPath;
    this->sDir->setFilter(QDir::Files);
    this->process();
}

bool FileOrganizer::filesLeft()
{
    return this->sFiles.size()>0;
}

QString * FileOrganizer::getNext()
{
    return new QString[5];
}

void FileOrganizer::process()
{
  this->readCoords();
}

void FileOrganizer::readCoords()
{
    QFileInfoList sList= sDir->entryInfoList();
    QPoint filePos;
    QString fileName;
    int posXstart,posXstop,xLen,posYstart,posYstop,yLen;
    for(int i=0;i<sList.size();i++)
    {
        fileName=sList.at(i).fileName();
        posXstart=fileName.indexOf("_")+1;
        posXstop=fileName.indexOf("_",posXstart);
        xLen=posXstop-posXstart;

        filePos.setX(fileName.mid(posXstart,xLen).toInt());

        posYstart=posXstop+1;
        posYstop=fileName.indexOf(".",posYstart);
        yLen=posYstop-posYstart;

        filePos.setY(fileName.mid(posYstart,yLen).toInt());
        this->sFiles.push_back(filePos);
    }
}

void FileOrganizer::createFilePacketList()
{

}
