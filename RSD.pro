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
    modules/network/httpperiodquery.cpp \
    modules/config/config.cpp \
    modules/config/army.cpp \
    modules/config/armyfactory.cpp \
    modules/config/unit.cpp \
    modules/config/utils.cpp


# Please do not modify the following two lines. Required for deployment.
include(qmlapplicationviewer/qmlapplicationviewer.pri)
#qtcAddDeployment()

OTHER_FILES += \
    license \
    medias/GUI/qml/RSD/main.qml \
    medias/GUI/qml/RSD/UI/Title.qml \
    medias/GUI/qml/RSD/UI/Menu.qml \
    medias/GUI/qml/RSD/UI/Button.qml \
    medias/GUI/qml/RSD/UI/JS/main.js \
    README \
    medias/GUI/qml/RSD/UI/Option/Option.qml \
    medias/GUI/qml/RSD/UI/Option/OptionGame.qml \
    medias/GUI/qml/RSD/UI/Option/OptionMain.qml \
    medias/GUI.qrc\
    medias/Resources.qrc \
    medias/Resources/list.xml \
    medias/Army.qrc \
    medias/GUI/qml/RSD/UI/Army/Army.qml \
    medias/GUI/qml/RSD/UI/Game/Game.qml \
    medias/Army/list.xml \
    medias/Army/0.xml \
    medias/Army/section.xml \
    medias/Army/3.xml \
    medias/GUI/qml/RSD/UI/ComboBox.qml


TRANSLATIONS = RSD_en.ts RSD_fr.ts

HEADERS += \
    modules/module.hpp \
    engine.hpp \
    modules/game/game.hpp \
    tools/singleton.hpp \
    modules/network/network.hpp \
    modules/network/anetworkquery.hpp \
    modules/network/httpquery.hpp \
    modules/network/httpperiodquery.hpp \
    modules/config/config.hpp \
    modules/config/army.hpp \
    modules/config/armyfactory.hpp \
    modules/config/unit.hpp \
    modules/config/utils.hpp


QT += network xml

CONFIG += debug

