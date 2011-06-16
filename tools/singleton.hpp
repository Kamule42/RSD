////////////////////////////////////////////////////////////
//
// RSD
// Copyright (C) 13/06/2011 Benjamin Herbomez (benjamin.herbomez@gmail.com)
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

#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <QMutex>

template <class T>
class Singleton{
    public:
        static T*  instance(){
            static QMutex mutex;
            if (!Singleton<T>::m_Instance){
                mutex.lock();

                if (!Singleton<T>::m_Instance)
                   Singleton<T>:: m_Instance = new T;

                mutex.unlock();
            }

            return (static_cast<T*>(Singleton<T>::m_Instance));
        }

        static void drop(){
            static QMutex mutex;
            mutex.lock();
            delete Singleton<T>::m_Instance;
            Singleton<T>::m_Instance = 0;
            mutex.unlock();
        }

    protected:
        Singleton() {};
        ~Singleton(){
                if(m_Instance != NULL)
                        delete m_Instance;
        };

    private:
        Singleton(const Singleton &); // hide copy constructor
        Singleton& operator=(const Singleton &); // hide assign op
                                     // we leave just the declarations, so the compiler will warn us
                                     // if we try to use those two functions by accident

        static T* m_Instance;
};

    template <typename T>
    T* Singleton<T>::m_Instance = NULL;

#endif // SINGLETON_HPP
