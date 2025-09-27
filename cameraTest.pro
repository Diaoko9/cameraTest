QT += core gui widgets multimedia multimediawidgets

SOURCES += \
    main.cpp \
    main_window.cpp

HEADERS += \
    main_window.h

DISTFILES += \
    objectDetection/math.py \
    objectDetection/objectDetector.py

FORMS += \
    mainwindow.ui

PYTHON_INCLUDE = /usr/include/python3.9
INCLUDEPATH += $$PYTHON_INCLUDE
LIBS += -L/usr/lib/python3.9 -lpython3.9

DEFINES += Py_LIMITED_API
