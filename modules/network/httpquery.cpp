////////////////////////////////////////////////////////////
//
// RSD
// Copyright (C) 22/06/2011 Benjamin Herbomez (benjamin.herbomez@gmail.com)
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

#include "httpquery.hpp"

#include <QtDebug>

namespace nwk{
    HttpQuery::HttpQuery(QString url) : ANetworkQuery(){
        this->mUrl = new QUrl(url);
        this->mAccess = new QNetworkAccessManager();
        this->mRequest = new QNetworkRequest(*this->mUrl);
        this->mReply    = 0;
        this->mContent = "";
    }

    QString HttpQuery::getContent(){
        return this->mContent;
    }


    void HttpQuery::launchPro(){
        this->mReply = this->mAccess->get(*this->mRequest);
        connect(this->mReply, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(slotProgress(qint64, qint64) ));
        connect(this->mReply, SIGNAL(finished()), this, SLOT(slotFinish()));
    }

    void HttpQuery::slotFinish(){
        this->mContent = this->mReply->readAll();
        qDebug() << this->mContent;
        emit finish();
    }

    void HttpQuery::slotProgress(qint64 i1, qint64 i2){
        emit progress(i1,i2);
    }
}
