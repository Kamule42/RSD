#ifndef MODULE_HPP
#define MODULE_HPP

#include <QThread>

class Module: public QThread{
    Q_OBJECT
    public:
        Module();
};

#endif // MODULE_HPP
