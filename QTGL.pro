QT += core gui opengl

CONFIG += c++11

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

LIBS += -lGL -lGLU -lglut

QMAKE_POST_LINK += "cp -u $${_PRO_FILE_PWD_}/facefile/shape_predictor_68_face_landmarks.dat $${OUT_PWD};" \

