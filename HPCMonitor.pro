#-------------------------------------------------
#
# Project created by QtCreator 2018-08-20T18:37:12
#
#-------------------------------------------------

QT       += core gui
QT       += printsupport


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HPCMonitor
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Project directory and outputs

#PROJECT_DIR = $$system(pwd)
#OBJECTS_DIR = $$PROJECT_DIR/Obj
#DESTDIR = ../bin

SYSTEM_NAME = x64         # Depending on your system either 'Win32', 'x64', or 'Win64'
SYSTEM_TYPE = 64            # '32' or '64', depending on your system

# Define output directories

CONFIG(release, debug|release): CUDA_OBJECTS_DIR = release/cuda
else: CUDA_OBJECTS_DIR = debug/cuda

unix: {
    CUDA_SDK = /usr/local/cuda-8.0
    CUDA_DIR = /usr/local/cuda-8.0
}
CUDA_ARCH = sm_61
NVCCFLAGS = --compiler-options -fno-strict-aliasing -use_fast_math --ptxas-options=-v --std=c++11 -Xcompiler -fPIE

unix: {
    SYSTEM_NAME = unix
}

unix: {
    INCLUDEPATH += $$CUDA_DIR/include
    INCLUDEPATH += /usr/include/
    INCLUDEPATH += $$CUDA_DIR/lib64
    INCLUDEPATH += $$CUDA_DIR/lib

    INCLUDEPATH += /home/main/Qt5.10.1/5.10.1/gcc_64/include/QtGui
    INCLUDEPATH += .
    INCLUDEPATH += /home/main/Qt5.10.1/5.10.1/gcc_64/include
    INCLUDEPATH += /home/main/Qt5.10.1/5.10.1/gcc_64/include/QtWidgets
    INCLUDEPATH += /home/main/Qt5.10.1/5.10.1/gcc_64/include/QtCore
    INCLUDEPATH += /home/main/Qt5.10.1/5.10.1/gcc_64/include/QtPrintSupport

    QMAKE_LIBDIR += $$CUDA_DIR/lib64
    QMAKE_LIBDIR += $$CUDA_DIR/lib
    QMAKE_LIBDIR += $$CUDA_DIR/include
    QMAKE_LIBDIR += $$CUDA_DIR/samples/common/lib

}


##########################################
#  LIBS
##########################################

LIBS += -lnvToolsExt
#LIBS += -lopengl
#libcudart_static
#LIBS += -lcudart_static
LIBS += -lcuda
LIBS += -lcudart
LIBS += -lGL
# My library is added here
#LIBS += -lmyLib
LIBS += -lnvidia-ml


# join the includes in a line
CUDA_INC = $$join(INCLUDEPATH,' -I','-I',' ')

HEADERS += \
        mainwindow.h \
        qcustomplot.h

SOURCES += \
        main.cpp \
        mainwindow.cpp \
        #init_gpuinfo.cpp \
        #init_combobox.cpp \
        #init_hostoverview.cpp \
        #init_deviceoverview.cpp \
        #init_devprocusage.cpp \
        #init_devmemusage.cpp \
        #init_devproperties.cpp \
        #reset_devprocusage.cpp \
        #del_devprocusage.cpp \
        #reset_devmemusage.cpp \
        #reset_devproperties.cpp \
        #del_devproperties.cpp \
        #del_devmemusage.cpp \
        #update_window.cpp \
        #update_hostoverview.cpp \
        #update_deviceoverview.cpp \
        #update_devprocusage.cpp \
        #update_devmemusage.cpp \
        #reset_ltchkptdsp.cpp \
        qcustomplot.cpp \
    init_cpuloadoverview.cpp \
    update_cpuloadoverview.cpp \
    update.cpp \
    init_memloadoverview.cpp \
    update_memloadoverview.cpp \
    checkpoint_start_coordinator.cpp \
    checkpoint_launch.cpp \
    checkpoint_setting.cpp \
    checkpoint_restart.cpp \
    checkpoint_reset.cpp \
    checkpoint_optimal.cpp \
    checkpoint_close.cpp
    #init_checkpoint.cpp \
    #checkpoint_launch.cpp \
    #checkpoint_start_coordinator.cpp \
    #checkpoint_restart.cpp \
    #checkpoint_close.cpp \
    #checkpoint_setting.cpp \
    #checkpoint_reset.cpp \
    #checkpoint_optimal.cpp

#CUSOURCES += \
#        gpu_testperformance.cu \
#        gpu_testmemcpy.cu \
#        testdouble.cu \
#        testsingle.cu \
#        testint.cu \
#        testlong.cu \
#        testdevicememcpy.cu



FORMS += \
        mainwindow.ui

include(cuda.pri)
