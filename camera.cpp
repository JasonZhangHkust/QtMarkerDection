#include "camera.h"
#include "ui_camera.h"


#include<QtCore>
#include<QMessageBox>
using namespace cv;
Camera::Camera(QWidget *parent) :QMainWindow(parent),ui(new Ui::Camera),myserver(20001,false){
    ui->setupUi(this);
    capWebcam.open(0);
    loadCameraCalibration("Calibration", cameraMatrix, distanceCoefficients);
    if(capWebcam.isOpened() == false) {                 // if unsuccessful
        QMessageBox::information(this, "", "error: capWebcam not accessed successfully \n\n exiting program\n");        // show error message
        exitProgram();                                  // and exit program
        return;                                         //
    }

    qtimer = new QTimer(this);                          // instantiate timer
    connect(qtimer, SIGNAL(timeout()), this, SLOT(processFrameAndUpdateGUI()));     // associate timer to processFrameAndUpdateGUI
    qtimer->start(20);                                  // start timer, set to cycle every 20 msec (50x per sec), it will not actually cycle this often
}

Camera::~Camera()
{
    delete ui;
}

void Camera::exitProgram() {
    if(qtimer->isActive()) qtimer->stop();          // if timer is running, stop timer
    QApplication::quit();                           // and exit program
}
void Camera::processFrameAndUpdateGUI() {
    cv::Mat imgOriginal;                    // original image
    std::vector<std::vector<cv::Point2f>> markerCorners;
    std::vector<int> markerIds;
    cv::Ptr<cv::aruco::Dictionary> markerDictionary = cv::aruco::getPredefinedDictionary(aruco::PREDEFINED_DICTIONARY_NAME::DICT_4X4_50);// marker dictionary creation;
    bool blnFrameReadSuccessfully = capWebcam.read(imgOriginal);                    // get next frame from the webcam
    std::vector<cv::Vec3d> rotationVectors, translationVectors;
    cv::aruco::detectMarkers(imgOriginal, markerDictionary, markerCorners, markerIds); // find the markers
    cv::aruco::estimatePoseSingleMarkers(markerCorners, arucoSquareDimension, cameraMatrix, distanceCoefficients, rotationVectors, translationVectors);
    for (int i = 0; i < markerIds.size(); i++) {
        cv::aruco::drawAxis(imgOriginal, cameraMatrix, distanceCoefficients, rotationVectors[i], translationVectors[i], 0.035f);

    }

    if (!blnFrameReadSuccessfully || imgOriginal.empty()) {                            // if we did not get a frame
        QMessageBox::information(this, "", "unable to read from webcam \n\n exiting program\n");        // show error via message box
        exitProgram();                                                              // and exit program
        return;                                                                     //
    }
    cv::cvtColor(imgOriginal, imgOriginal, cv::COLOR_BGR2RGB);
    const QImage image((const unsigned char*)imgOriginal.data, imgOriginal.cols, imgOriginal.rows, imgOriginal.step,
                       QImage::Format_RGB888, &matDeleter, new cv::Mat(imgOriginal));
    image.rgbSwapped();
    Q_ASSERT(image.constBits() == imgOriginal.data);
   // QImage qimgOriginal = convertOpenCVMatToQtQImage(imgOriginal);                         // convert from OpenCV Mat to Qt QImage                       //

    ui->lblOriginal->setPixmap(QPixmap::fromImage(image));           // show images on form labels
}
///////////////////////////////////////////////////////////////////////////////////////////////////
QImage Camera::convertOpenCVMatToQtQImage(cv::Mat mat) {
    if(mat.channels() == 1) {                                   // if 1 channel (grayscale or black and white) image
        return QImage((uchar*)mat.data, mat.cols, mat.rows, mat.step, QImage::Format_Indexed8);     // return QImage
    } else if(mat.channels() == 3) {                            // if 3 channel color image
        cv::cvtColor(mat, mat, CV_BGR2RGB);                     // flip colors
        return QImage((uchar*)mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);       // return QImage
    } else {
        qDebug() << "in convertOpenCVMatToQtQImage, image was not 1 channel or 3 channel, should never get here";
    }
    return QImage();        // return a blank QImage if the above did not work
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void Camera::on_btnPauseOrResume_clicked() {
    if(qtimer->isActive() == true) {                // if timer is running we are currently processing an image, so . . .
        qtimer->stop();                                 // stop timer
        ui->btnPauseOrResume->setText(" Resume ");      // and update button text
    } else {                                        // else timer is not running, so we are currently paused, so . . .
        qtimer->start(20);                              // start timer again
        ui->btnPauseOrResume->setText(" Pause ");       // and update button text
    }
}
void Camera::on_Initialazition_clicked(){
    myserver.ListenForNewConnection();
    ui->Initialazition->setText("Connect...");
}

bool Camera::loadCameraCalibration(std::string name,cv::Mat& cameraMatrix, cv::Mat& distanceCoefficients) {
    std::ifstream inStream(name);
    if (inStream) {
        uint16_t rows;
        uint16_t columns;
        inStream >> rows;
        inStream >> columns;
        cameraMatrix = Mat(Size(columns, rows), CV_64F);
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < columns; c++) {
                double read = 0.0f;
                inStream >> read;
                cameraMatrix.at<double>(r, c) = read;
                std::cout << cameraMatrix.at<double>(r, c) << endl;

            }
        }
        //Distance Coefficients
        inStream >> rows;
        inStream >> columns;
        distanceCoefficients = Mat::zeros(rows, columns, CV_64F);
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < columns; c++) {
                double read = 0.0f;
                inStream >> read;
                distanceCoefficients.at<double>(r, c) = read;
                std::cout << distanceCoefficients.at<double>(r, c) << endl;

            }
        }
        inStream.close();
        return true;
    }
    return false;
}

void Camera::matDeleter(void *mat)
{
    delete static_cast<cv::Mat*>(mat);
}
