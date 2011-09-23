////////////////////////////////////////////////////////////
//
// RSD
// Copyright (C) %DATE% Benjamin Herbomez (benjamin.herbomez@gmail.com)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#include "engine.hpp"
#include <QDeclarativeContext>
#include <QDeclarativeEngine>
#include <QtGui/QApplication>
#include <QSplashScreen>
#include <QResource>
#include <QFile>
#include <QtXml/QDomDocument>
#include "qmlapplicationviewer.h"

#include <QDebug>

void loadResources();

int main(int argc, char * argv[]){
    QApplication app(argc, argv);
    loadResources();

    QPixmap pixmap(":/splash/img.png");
    QSplashScreen *mSplash = new QSplashScreen(pixmap);
    mSplash->show();

    Engine *engine = new Engine();
    engine->run();

    QmlApplicationViewer viewer;


    QDeclarativeContext *context = viewer.rootContext();
        context->setContextProperty("cppArmyList",QVariant::fromValue(engine->config()->armyList()));

    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    //viewer.setMainQmlFile(QLatin1String(":/qml/main.qml"));
    viewer.setSource(QUrl("qrc:/qml/main.qml"));
    viewer.showExpanded();
    //viewer.showFullScreen();


    mSplash->finish(&viewer);

    return app.exec();
}

//Load all resources files from the main resource file
//create a resource file from qrc : rcc -binary input.qrc -o  output.rcc
void loadResources(){
     QResource::registerResource("medias/Resources.rcc");

     QDomDocument doc("ResourceDoc");
     QFile file(":/Resources/list.xml");
     if(!file.open( QIODevice::ReadOnly ))
         return;
     if(!doc.setContent(&file)){
        file.close();
        qDebug() << "Erreur";
        return;
     }

     QDomElement root = doc.documentElement();
     if(root.tagName() != "list")
         return;
     QDomNode n = root.firstChild();
     while(!n.isNull()){
         QDomElement e = n.toElement();
         if(e.tagName() == "res" && e.nodeType() == QDomNode::ElementNode
                 && e.childNodes().count()  == 1)
             QResource::registerResource("medias/"+e.text()+".rcc");

         n = n.nextSibling();
     }

     file.close();

}
