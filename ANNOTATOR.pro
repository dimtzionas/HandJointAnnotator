#-------------------------------------------------
#
# Project created by QtCreator 2014-02-26T15:34:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ANNOTATOR
TEMPLATE = app


SOURCES  += main.cpp\
            mainwindow.cpp \
            customlabel.cpp \
            mainwindow_UI_Keyboard_Mouse.cpp \
            mainwindow_GUI.cpp \
            mainwindow_Updates.cpp \
            mainwindow_Paths.cpp \
            mainwindow_Anno.cpp \
            mainwindow_AnnoMEM.cpp \
            mainwindow_AnnoIO_IN.cpp \
            mainwindow_AnnoIO_OUT.cpp \
            mainwindow_wTest.cpp

HEADERS  += mainwindow.h \
            customlabel.h

FORMS    += mainwindow.ui

LIBS      += -L/usr/local/lib/        # SOS
LIBS      += -lopencv_core            # basic
LIBS      += -lopencv_imgproc         # basic
LIBS      += -lopencv_highgui         # basic
LIBS      += -lopencv_video           # gia OptFlow
#LIBS     += -lopencv_ml
#LIBS     += -lopencv_features2d
#LIBS     += -lopencv_calib3d
#LIBS     += -lopencv_objdetect
#LIBS     += -lopencv_contrib
#LIBS     += -lopencv_legacy
#LIBS     += -lopencv_ﬂann

# OR !!!!!!!!!!!!!
# CONFIG += link_pkgconfig
# PKGCONFIG += opencv
