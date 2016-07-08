#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <customlabel.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ///////////////////////////////////////////////////////////////////////////////////////
    connect(   ui->myLabel_IMG, SIGNAL(Mouse_Pos()),       this, SLOT(Mouse_Pos())       );
    connect(   ui->myLabel_IMG, SIGNAL(Mouse_Left()),      this, SLOT(Mouse_Left())      );
    connect(   ui->myLabel_IMG, SIGNAL(Mouse_Pressed()),   this, SLOT(Mouse_Pressed())   );
    connect(   ui->myLabel_IMG, SIGNAL(Mouse_Release()),   this, SLOT(Mouse_Release())   );
    ///////////////////////////////////////////////////////////////////////////////////////
    ui->myLabel_IMG->setMouseTracking(true);
    ///////////////////////////////////////////////////////////////////////////////////////
    colorize_Black();
    ///////////////////////////////////////////////////////////////////////////////////////
    ui->myTabWidget->setEnabled(false);
    ///////////////////////////////////////////////////////////////////////////////////////
    isSequenceLoaded = false;
    ///////////////////////////////////////////////////////////////////////////////////////
    ctrl_key = false;
    ctrl_click = false;
    shift_click = false;
    shift_key = false;
}


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_myCheckBox_Hand_RIGHT_clicked()     {   changed_HandNumber();   }
void MainWindow::on_myCheckBox_Hand_LEFT_clicked()      {   changed_HandNumber();   }

void MainWindow::changed_HandNumber()
{
    ////////////////////////////
    TOTAL_JOINTS__one_hand = 14;
    ////////////////////////////
    TOTAL_JOINTS__ALL_hands = 0;
    ////////////////////////////

    if (ui->myCheckBox_Hand_RIGHT->isChecked())     TOTAL_JOINTS__ALL_hands += TOTAL_JOINTS__one_hand;
    if (ui->myCheckBox_Hand_LEFT->isChecked())      TOTAL_JOINTS__ALL_hands += TOTAL_JOINTS__one_hand;
}

void MainWindow::on_fingerList_currentRowChanged(int currentRow)
{
    if(currentRow == -1)
        return;
    ui->selFingerX->setEnabled(true);
    ui->selFingerY->setEnabled(true);
    ui->selFingerX->setValue(roundToInt(annotations[currentRow].joint_X));
    ui->selFingerY->setValue(roundToInt(annotations[currentRow].joint_Y));

}

void MainWindow::on_selFingerX_valueChanged(int arg1)
{
    annotations[roundToInt(ui->fingerList->currentRow())].joint_X = arg1;
    update_CURR_Image();
    update_CURR_Display(true);
}

void MainWindow::on_selFingerY_valueChanged(int arg1)
{
    annotations[roundToInt(ui->fingerList->currentRow())].joint_Y = arg1;
    update_CURR_Image();
    update_CURR_Display(true);
}

void MainWindow::on_fingerList_itemSelectionChanged()
{
    update_CURR_Display();
}

int MainWindow::roundToInt(double num){
    return std::floor(num + 0.5);
}
