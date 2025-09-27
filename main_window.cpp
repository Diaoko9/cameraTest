#include "main_window.h"

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
#include <QColor>
#include <QPalette>
//
#pragma push_macro("slots")
#undef slots
#include <Python.h>
#pragma pop_macro("slots")

MainWindow::MainWindow(QWidget *parent)
    :QWidget(parent)
{

    setFixedSize(600, 600);
    setWindowTitle("myApp");

    Py_Initialize();

    const QList<QCameraDevice> cameras = QMediaDevices::videoInputs();
    if (cameras.isEmpty()){
        qDebug() << "no camera found...";

        status_label = new QLabel("No Camera detected", this);

        QVBoxLayout *vlayout = new QVBoxLayout(this);
        vlayout->addWidget(status_label);

    }else {
        qDebug() << "Found" << cameras.count() << " camera(s)";
        for(const QCameraDevice &cameraDevice : cameras){
            qDebug() << "Camera Name:" << cameraDevice.description();
        }

        m_videoWidget = new QVideoWidget(this);
        m_toggleButton = new QPushButton("Stop", this);
        status_label = new QLabel("Hi Raspi W!!!", this);


        py_label = new QLabel(this);

        QFont answerFont =py_label->font();
        answerFont.setPointSize(32);
        answerFont.setBold(true);
        answerFont.setFamily("arial");

        QPalette answerPalette = py_label->palette();
        answerPalette.setColor(QPalette::WindowText, Qt::darkBlue);


        py_label->setFrameStyle(QFrame::Panel | QFrame::Sunken|QFrame::Box);
        py_label->setText("answer from python");
        py_label->setFont(answerFont);
        py_label->setPalette(answerPalette);
        //py_label->setStyleSheet("color: red; font-weight: bold; font-family: arial;");
        py_label->size();
        py_label->setAlignment(Qt::AlignCenter | Qt::AlignCenter);


        QVBoxLayout *vlayout = new QVBoxLayout(this);
        vlayout->addWidget(status_label);
        vlayout->addWidget(py_label);
        vlayout->addWidget(m_toggleButton);
        vlayout->addWidget(m_videoWidget);

        m_camera = new QCamera(QMediaDevices::defaultVideoInput(), this);
        m_captureSession = new QMediaCaptureSession(this);
        m_captureSession->setCamera(m_camera);
        m_captureSession->setVideoOutput(m_videoWidget);

        connect(m_toggleButton, &QPushButton::clicked, this, &MainWindow::on_toggleButton_clicked);

        m_camera->start();

        //Py_Finalize();

    }





}

MainWindow::~MainWindow(){

}

void MainWindow::on_toggleButton_clicked(){
    if (m_camera->isActive()){
        m_camera->stop();

        m_toggleButton->setText("Start");
    }else {
        m_camera->start();
        m_toggleButton->setText("Stop");
    }
}
