#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class MainWindow : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override; // resizeGL 方法
    void paintGL() override;
    void renderTeapot(); // 渲染茶壶方法

};

#endif // MAINWINDOW_H
