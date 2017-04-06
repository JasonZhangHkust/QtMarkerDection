#-------------------------------------------------
#
# Project created by QtCreator 2017-03-15T15:18:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = camera
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        camera.cpp \
    server.cpp

HEADERS  += camera.h \
    server.h

FORMS    += camera.ui

INCLUDEPATH +=G:\opencv3\mybuild\install\include

LIBS +=-LG:\opencv3\mybuild\install\x64\vc14\lib \
    -lopencv_aruco320d \
    -lopencv_bgsegm320d \
    -lopencv_bioinspired320d \
    -lopencv_calib3d320d \
    -lopencv_ccalib320d \
    -lopencv_core320d \
    -lopencv_datasets320d \
    -lopencv_dnn320d \
    -lopencv_dpm320d \
    -lopencv_face320d \
    -lopencv_features2d320d \
    -lopencv_flann320d \
    -lopencv_fuzzy320d \
    -lopencv_hdf320d \
    -lopencv_highgui320d \
    -lopencv_imgcodecs320d \
    -lopencv_imgproc320d \
    -lopencv_line_descriptor320d \
    -lopencv_ml320d \
    -lopencv_objdetect320d \
    -lopencv_optflow320d \
    -lopencv_phase_unwrapping320d \
    -lopencv_photo320d \
    -lopencv_plot320d \
    -lopencv_reg320d \
    -lopencv_rgbd320d \
    -lopencv_structured_light320d \
    -lopencv_saliency320d \
    -lopencv_shape320d \
    -lopencv_stereo320d \
    -lopencv_stitching320d \
    -lopencv_superres320d \
    -lopencv_surface_matching320d \
    -lopencv_text320d \
    -lopencv_tracking320d \
    -lopencv_video320d \
    -lopencv_videoio320d \
    -lopencv_videostab320d \
    -lopencv_xfeatures2d320d \
    -lopencv_ximgproc320d \
    -lopencv_xobjdetect320d \
    -lopencv_xphoto320d \
