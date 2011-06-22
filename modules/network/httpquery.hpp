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

#ifndef HTTPQUERY_HPP
#define HTTPQUERY_HPP

#include "anetworkquery.hpp"

#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QUrl>
#include <QString>

namespace nwk{
    class HttpQuery : public ANetworkQuery{
        Q_OBJECT

        protected :
            QUrl *mUrl;
            QNetworkAccessManager *mAccess;
            const QNetworkRequest *mRequest;
            QNetworkReply *mReply;

        public:
            HttpQuery(QString url);

        signals:

        public slots:
            virtual void launch();

        protected slots :
                virtual void slotFinish();
                virtual void slotProgress(qint64, qint64);
    };
}

#endif // HTTPQUERY_HPP
