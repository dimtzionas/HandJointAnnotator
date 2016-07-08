#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <QImageWriter>
#include <QTextStream>
#include <opencv2/opencv.hpp>

#include <fstream>
#include <libconfig.h++>

struct AnnotationPatch
{
    double joint_X;
    double joint_Y;
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QString PATH_BASE_SeqCam;
    QString PATH_BASE_Base;
    QString PATH_BASE_PCL;
    QString PATH_BASE_RGB;
    QString PATH_BASE_RGBD;
    QString PATH_BASE_Depth;
    QString PATH_BASE_DepthViz;
    QString PATH_BASE_Anno;

    QString PATH_CURR_PCL;
    QString PATH_CURR_RGB;
    QString PATH_CURR_RGBD;
    QString PATH_CURR_Depth;
    QString PATH_CURR_DepthViz;
    QString PATH_CURR_Anno;
    QString PATH_CURR_DISPLAY;

    QString PATH_CURR_EXTRACT_ALL;
    QString PATH_CURR_EXTRACT_PCD;

    int     FRAMES_TOTAL;
    int     FRAMES_ID_START;

    int     ID_NUMB_OF_DIGITS;
    int     currFrameID;
    QString currFrameID_STR;
    QString currFrameID_STRshort;

    cv::Mat imgCV;
    cv::Mat imgCV_source;
    cv::Mat imgCV_DEPTH;
    QImage  imgQT;
    bool ctrl_key;
    bool ctrl_click;
    bool shift_key;
    bool shift_click;
    int selMouseX;
    int selMouseY;

    bool isSequenceLoaded;

    QVector<AnnotationPatch> annotations;

    void update_CURR_THINGS(  bool removeAnnotationsALL );
    void update_CURR_THINGS(  int  newFrameID );
    void update_CURR_frameID( int  newFrameID );
    void update_CURR_Image();
    void update_CURR_Display(bool spin_box=false);
    void update_CURR_AnnotationsOVERLAY();
    void update_CURR_Paths();
    void update_BASE_Paths();
    void update_list();

    void annotations_ADD( int mouseX, int mouseY );
    void annotations_REMOVE_Last();
    void annotations_REMOVE_All();
    void annotations_SAVE_CurrFrame();
    void annotations_READ_CurrFrame();
    void annotations_EXTRACT_All();
    bool annotations_CHECK_alreadyExistsCURR();
    bool annotations_CHECK_alreadyExistALL();
    void move_joint( int direction);
    void rotate_joints( int direction);
    int roundToInt(double num);

    void print_CURR_Paths();

    void colorize_Black();
    void colorize_Red();

    void testtt_CURR_Depth();

    void changed_HandNumber();

    int TOTAL_JOINTS__ALL_hands;
    int TOTAL_JOINTS__one_hand;

private slots:
    void on_myButton_Next_clicked();

    void on_myButton_Prev_clicked();

    void on_myButton_UpdateFrameID_clicked();

    void on_myRadioButton_Annotate_clicked();

    void on_myRadioButton_Replay_clicked();

    void on_myRadioButton_Image_RGB_clicked();

    void on_myRadioButton_Image_DepthVIZ_clicked();

    void on_myRadioButton_Image_RGBD_clicked();

private slots:
    void Mouse_Pos();
    void Mouse_Left();
    void Mouse_Pressed();
    void Mouse_Release();

    void keyPressEvent(QKeyEvent *myKey);
    void keyReleaseEvent(QKeyEvent *myKey);
    void wheelEvent(QWheelEvent* event);

    void on_myButton_Update_PATH_clicked();

    void on_myButton_ANNO_Clear_ALL_clicked();

    void on_myButton_ANNO_Clear_LAST_clicked();

    void on_myButton_test_CURR_DEPTH_YML_clicked();

    void on_myButton_ANNO_Save_clicked();

    void on_myButton_ANNO_Extract_clicked();

    void on_myButton_ANNO_Load_clicked();

    void on_myRadioButton_Image_DepthREAL_clicked();

    void on_myButton_DETECTOR_generateAnnotationMovie_clicked();

    void on_myCheckBox_Hand_RIGHT_clicked();

    void on_myCheckBox_Hand_LEFT_clicked();

    void on_fingerList_currentRowChanged(int currentRow);

    void on_selFingerX_valueChanged(int arg1);

    void on_selFingerY_valueChanged(int arg1);

    void on_fingerList_itemSelectionChanged();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
