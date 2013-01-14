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

#include "filehandler.h"

FileHandler::FileHandler(unsigned char r, unsigned char g, unsigned char b)
{
  this->setBgColor(r,g,b);  
}

FileHandler::~FileHandler()
{
}

void FileHandler::setBgColor(unsigned char r, unsigned char g, unsigned char b)
{
  //background color of unused tiles
  this->r=r;
  this->g=g;
  this->b=b;
}

void FileHandler::process(QString pathTile00, QString pathTile01,
                          QString pathTile10, QString pathTile11,
                          QString pathOut)
{
  
  QString pathTiles[]={pathTile00, pathTile01, pathTile10, pathTile11};

  //loading 4 images
  QVector<QImage> tileBuffers;
  QImage tileOut(200, 200, QImage::Format_RGB32); 
  QRgb color;
  color=qRgb(r,g,b);
  for(int i=0;i<4;i++)  
  {
    QImage buffer(100, 100, QImage::Format_RGB32);
    buffer.fill(color);

    if(pathTiles[i]!="")
      if(QFileInfo(pathTiles[i]).exists())
        buffer.load(pathTiles[i]);

    tileBuffers.append(buffer);
  }
  //glueing 4 images together
  QPainter painter(&tileOut);
  painter.setCompositionMode(QPainter::CompositionMode_Source);
  painter.drawImage(  0,  0,tileBuffers[0]);
  painter.drawImage(100,  0,tileBuffers[1]);
  painter.drawImage(  0,100,tileBuffers[2]);
  painter.drawImage(100,100,tileBuffers[3]);
  painter.end();

  //resize to fit original image size
  tileOut=tileOut.scaled(100,100);

  //saving ...
  tileOut.save(pathOut,"PNG",100);
}
