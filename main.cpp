#include <QApplication>
#include <QCamera>
#include <QMediaCaptureSession>
#include <QMediaDevices>
#include <QLabel>
#include <QPushButton>
#include <QVideoWidget>
#include <QWidget>
#include <QtWidgets>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget *window = new QWidget();
    window->setFixedSize(500, 500);
    window->setWindowTitle("myApp");

    QVideoWidget *videoWidget = new QVideoWidget();

    QPushButton *pb = new QPushButton("Record");
    QLabel *label = new QLabel("Hi Raspi W?!!!");

    QVBoxLayout *vlayout = new QVBoxLayout();
    vlayout->addWidget(label);
    vlayout->addWidget(pb);
    vlayout->addWidget(videoWidget);



    window->setLayout(vlayout);

    QCamera *camera1 = new QCamera(QMediaDevices::defaultVideoInput());

    QMediaCaptureSession *captureSession = new QMediaCaptureSession();

    captureSession->setCamera(camera1);
    captureSession->setVideoOutput(videoWidget);

    window->show();
    camera1->start();

    return app.exec();
}
