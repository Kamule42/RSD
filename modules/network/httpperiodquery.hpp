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

#ifndef HTTPPERIODQUERY_HPP
#define HTTPPERIODQUERY_HPP

#include "httpquery.hpp"
#include <QThread>

namespace nwk{
    class HttpPeriodQuery : public HttpQuery{

        protected:

            class HttpPeriodQueryThread : public QThread{
                protected :
                    HttpPeriodQuery *mObject;
                     qint64 mInter;
                public :
                    HttpPeriodQueryThread(HttpPeriodQuery*, qint64);
                    virtual void run();
            };

            HttpPeriodQueryThread *mThread;

        public:
            HttpPeriodQuery(QString, qint64);

        protected :
            virtual void run();

        public slots:
            virtual void launch();
    };
}
#endif // HTTPPERIODQUERY_HPP
