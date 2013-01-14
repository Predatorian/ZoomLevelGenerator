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
#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <QtGui/QImage>
#include <QString>
#include <QFileInfo>
#include <QtGui/QPainter>
using namespace std;

class FileHandler
{
  public:
    FileHandler(unsigned char r=33, unsigned char g=33, unsigned char b=33);
    ~FileHandler();
    void process(QString pathTile00, QString pathTile01, 
                 QString pathTile10, QString pathTile11,
                 QString pathOut);
    void setBgColor(unsigned char r, unsigned char g, unsigned char b);


  private:
    unsigned char   r,
                    g,
                    b;

};
#endif // FILEHANDLER_H
