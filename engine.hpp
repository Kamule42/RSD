#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <QObject>

class Engine : public QObject
{
    Q_OBJECT
    public:
        explicit Engine(QObject *parent = 0);

    signals:

    public slots:

};

#endif // ENGINE_HPP
