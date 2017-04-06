#ifndef CAMERA_H
#define CAMERA_H

#include <QMainWindow>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2\aruco.hpp>
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include "server.h"
class Server;
namespace Ui {
class Camera;
}

class Camera : public QMainWindow
{
    Q_OBJECT
    static void matDeleter(void* mat);
public slots:
    void processFrameAndUpdateGUI();                // function prototype
public:
    explicit Camera(QWidget *parent = 0);
    ~Camera();

private slots:
    void on_btnPauseOrResume_clicked();
    void on_Initialazition_clicked();

private:
    Ui::Camera *ui;
    bool sending = false;
    cv::VideoCapture capWebcam;
    Server myserver;
    float arucoSquareDimension = 0.07f;
    cv::Mat cameraMatrix = cv::Mat::eye(3, 3, CV_64F);
    cv::Mat distanceCoefficients;
    QTimer* qtimer;
    QImage Camera::convertOpenCVMatToQtQImage(cv::Mat mat);
    bool loadCameraCalibration(std::string name, cv::Mat& cameraMatrix, cv::Mat& distanceCoefficients);
    void Camera::exitProgram();
};

#endif // CAMERA_H
