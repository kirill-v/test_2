TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    wordcounter.cpp \
    basecounter.cpp \
    checksumcounter.cpp

HEADERS += \
    wordcounter.h \
    basecounter.h \
    checksumcounter.h

QMAKE_CXXFLAGS += --std=c++11
