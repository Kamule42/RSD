# Add more folders to ship with the application, here
folder_01.source = qml/RSD
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

symbian:TARGET.UID3 = 0xE1126360

# Smart Installer package's UID
# This UID is from the protected range and therefore the package will
# fail to install if self-signed. By default qmake uses the unprotected
# range value if unprotected UID is defined for the application and
# 0x2002CCCF value if protected UID is given to the application
#symbian:DEPLOYMENT.installer_header = 0x2002CCCF

# Allow network access on Symbian
symbian:TARGET.CAPABILITY += NetworkServices

# If your application uses the Qt Mobility libraries, uncomment the following
# lines and add the respective components to the MOBILITY variable.
# CONFIG += mobility
# MOBILITY +=

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp \
    modules/module.cpp \
    engine.cpp \
    modules/game/game.cpp \
    modules/network/network.cpp \
    modules/network/anetworkquery.cpp \
    modules/network/httpquery.cpp \
    modules/network/httpperiodquery.cpp

# Please do not modify the following two lines. Required for deployment.
include(qmlapplicationviewer/qmlapplicationviewer.pri)
#qtcAddDeployment()

OTHER_FILES += \
    license \
    medias/GUI/qml/RSD/main.qml \
    medias/GUI/qml/RSD/UI/Title.qml \
    medias/GUI/qml/RSD/UI/Menu.qml \
    medias/GUI/qml/RSD/UI/Button.qml \
    medias/GUI/qml/RSD/UI/JS/main.js


TRANSLATIONS = RSD_en.ts RSD_fr.ts

HEADERS += \
    modules/module.hpp \
    engine.hpp \
    modules/game/game.hpp \
    tools/singleton.hpp \
    modules/network/network.hpp \
    modules/network/anetworkquery.hpp \
    modules/network/httpquery.hpp \
    modules/network/httpperiodquery.hpp

RESOURCES += \
    medias/GUI.qrc

QT += network
