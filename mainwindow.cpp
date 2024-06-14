#include "mainwindow.h"
#include <GL/glut.h>

MainWindow::MainWindow(QWidget *parent)
    : QOpenGLWidget(parent)
{
}

MainWindow::~MainWindow()
{
}

void MainWindow::initializeGL()
{
    initializeOpenGLFunctions();
    glEnable(GL_DEPTH_TEST); // 深度测试
    glEnable(GL_LIGHTING);   // 光照
    glEnable(GL_LIGHT0);     // 光源0

    // 光源参数
    GLfloat light_pos[] = { 0.0f, 0.0f, 5.0f, 1.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);

    // 材质参数
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

}
void MainWindow::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, GLfloat(w) / GLfloat(h), 0.01, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void MainWindow::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -5.0f); // 把茶壶移入视野

    // 调用渲染茶壶的方法
    renderTeapot();
}

void MainWindow::renderTeapot()
{
    // 设置茶壶颜色
    GLfloat mat_ambient[] = { 0.0, 0.5, 0.5, 1.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);

    // 使用 GLUT 渲染茶壶
    glutSolidTeapot(1.0);
}
