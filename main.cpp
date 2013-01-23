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

#include <iostream>
#include <QtCore/QCoreApplication>
#include <QString>
#include <QFileInfo>
#include "filehandler.h"
#include "fileorganizer.h"

using namespace std;

int main(int argc, char *argv[])
{
    QString helpmsg="usage: zoomlevelgenerator \"path/to/tiles\" \"path/to/maps/folder\" [-f] [-c r g b]\n";
            helpmsg+="-f    force recreation of existing tiles\n";
            helpmsg+="-c    select backgroundcolor ex. \"-c 255 255 255\"";
    QString srcPath, targetPath;
    bool force_creation=false, help=false;
    unsigned char r=33,g=33,b=33;
    //QCoreApplication a(argc, argv);
    if(argc>=3)
      for(int i=3;i<argc;i++)
      {
        if(argv[i]=="-f\0")
        {
          force_creation=true;
          continue;
        }
        if(!strcmp(argv[i],"-c"))
        {
          QString sR=argv[i+1],
                  sG=argv[i+2],
                  sB=argv[i+3];
          r=sR.toUShort();
          g=sG.toUShort();
          b=sB.toUShort();
          i+=3;
          continue;
        }
        help=true;
        break;
      }
    else
      help=true;



    if(help)
    {
      cout<<helpmsg.toStdString().c_str();
      return -1;
    }
    srcPath=argv[1];
    targetPath=argv[2];

    FileHandler fileHandler(r,g,b);
    FileOrganizer fileOrganizer(srcPath, targetPath);
    fileOrganizer.process();
    return 0;
    //fileHandler.process("c:/qttest/tile_0_0.png","c:/qttest/tile_1_0.png","c:/qttest/tile_0_1.png","c:/qttest/tile_1_1.png","c:/qttest/google/tile_0_0.png");
    //attantion tile_X_Y.png
    while(fileOrganizer.filesLeft())
    {
      QString *nextFiles;
      nextFiles=fileOrganizer.getNext();
      if(QFileInfo(nextFiles[4]).exists()&&!force_creation)
        continue;
      fileHandler.process(nextFiles[0],nextFiles[1],nextFiles[2],nextFiles[3],nextFiles[4]);
    }
    return 0;
    //return a.exec();
}
