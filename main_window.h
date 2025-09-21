#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QCamera>
#include <QMediaCaptureSession>
#include <QMediaDevices>
#include <QLabel>
#include <QPushButton>
#include <QVideoWidget>
#include <QWidget>
#include <QtWidgets>
#include <QVBoxLayout>
#include <QApplication>
#include <QDebug>

class QLabel;
class QPushButtton;
class QVideoWidget;

class MainWindow : public QWidget
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void  on_toggleButton_clicked();

private:

    QLabel *status_label;
    QLabel *py_label;
    QPushButton *m_toggleButton;
    QVideoWidget *m_videoWidget;
    QCamera *m_camera;
    QMediaCaptureSession *m_captureSession;

};

#endif // MAIN_WINDOW_H
