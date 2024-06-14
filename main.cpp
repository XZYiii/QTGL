#include <QApplication>
#include "mainwindow.h"
#include <GL/glut.h>

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);

    QApplication app(argc, argv);
    MainWindow window;
    window.resize(800, 600);
    window.show();
    return app.exec();
}
