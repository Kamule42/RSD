////////////////////////////////////////////////////////////
//
// RSD
// Copyright (C) 23/06/2011 Benjamin Herbomez (benjamin.herbomez@gmail.com)
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

#include "httpperiodquery.hpp"
#include <QObject>

namespace nwk{

     HttpPeriodQuery::HttpPeriodQueryThread::HttpPeriodQueryThread(HttpPeriodQuery *obj, qint64 inter){
        this->mObject = obj;
        this->mInter = inter;
    }

     void  HttpPeriodQuery::HttpPeriodQueryThread::run(){
         while(this->isRunning()){
             this->mObject->run();
             this->sleep(this->mInter);
         }
     }

    HttpPeriodQuery::HttpPeriodQuery(QString url, qint64 inter) : HttpQuery(url){
        this->mThread = new HttpPeriodQueryThread(this, inter);
    }

    void HttpPeriodQuery::run(){
        this->mReply = this->mAccess->get(*this->mRequest);
        QObject::connect(this->mReply, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(slotProgress(qint64, qint64) ));
        QObject::connect(this->mReply, SIGNAL(finished()), this, SLOT(slotFinish()));
    }

    void HttpPeriodQuery::launch(){
        this->mThread->start();
    }
}