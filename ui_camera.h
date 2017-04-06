/********************************************************************************
** Form generated from reading UI file 'camera.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERA_H
#define UI_CAMERA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Camera
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnPauseOrResume;
    QPushButton *Initialazition;
    QPlainTextEdit *txtXYRadius;
    QLabel *lblOriginal;

    void setupUi(QMainWindow *Camera)
    {
        if (Camera->objectName().isEmpty())
            Camera->setObjectName(QStringLiteral("Camera"));
        Camera->resize(640, 610);
        centralWidget = new QWidget(Camera);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 490, 581, 101));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        btnPauseOrResume = new QPushButton(layoutWidget);
        btnPauseOrResume->setObjectName(QStringLiteral("btnPauseOrResume"));

        horizontalLayout_2->addWidget(btnPauseOrResume);

        Initialazition = new QPushButton(layoutWidget);
        Initialazition->setObjectName(QStringLiteral("Initialazition"));

        horizontalLayout_2->addWidget(Initialazition);

        txtXYRadius = new QPlainTextEdit(layoutWidget);
        txtXYRadius->setObjectName(QStringLiteral("txtXYRadius"));

        horizontalLayout_2->addWidget(txtXYRadius);

        lblOriginal = new QLabel(centralWidget);
        lblOriginal->setObjectName(QStringLiteral("lblOriginal"));
        lblOriginal->setGeometry(QRect(0, 0, 640, 480));
        lblOriginal->setFrameShape(QFrame::Box);
        lblOriginal->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        Camera->setCentralWidget(centralWidget);

        retranslateUi(Camera);

        QMetaObject::connectSlotsByName(Camera);
    } // setupUi

    void retranslateUi(QMainWindow *Camera)
    {
        Camera->setWindowTitle(QApplication::translate("Camera", "Camera", Q_NULLPTR));
        btnPauseOrResume->setText(QApplication::translate("Camera", " Pause ", Q_NULLPTR));
        Initialazition->setText(QApplication::translate("Camera", "PushButton", Q_NULLPTR));
        lblOriginal->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Camera: public Ui_Camera {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERA_H
