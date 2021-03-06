////////////////////////////////////////////////////////////
//
// RSD
// Copyright (C) 17/06/2011 Benjamin Herbomez (benjamin.herbomez@gmail.com)
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

#ifndef ANETWORKQUERY_HPP
#define ANETWORKQUERY_HPP

#include <QObject>
#include <QNetworkReply>

namespace nwk{
    class ANetworkQuery : public QObject{
        Q_OBJECT

        friend class Network;

        protected:
            ANetworkQuery();


        public slots:
            virtual void launch();

        protected :
            virtual void launchPro() = 0;

        signals :
            void finish(QNetworkReply::NetworkError);
            void progress(qint64, qint64);
    };
}
#endif // ANETWORKQUERY_HPP
