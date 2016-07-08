#include "mainwindow.h"
#include "ui_mainwindow.h"



void MainWindow::keyPressEvent(QKeyEvent *myKey)
{

    if      (myKey->key() == Qt::Key_Escape)    this->close();
    else if (myKey->key() == Qt::Key_L)         on_myButton_Update_PATH_clicked();
                                                ///////
    else if (isSequenceLoaded == false)         return;
                                                ///////
    else if (myKey->key() == Qt::Key_Left && !ctrl_key)      on_myButton_Prev_clicked();
    else if (myKey->key() == Qt::Key_Right && !ctrl_key)     on_myButton_Next_clicked();
    else if (myKey->key() == Qt::Key_Right && ctrl_key) move_joint(1);
    else if (myKey->key() == Qt::Key_Left && ctrl_key) move_joint(2);
    else if (myKey->key() == Qt::Key_Down && ctrl_key) move_joint(3);
    else if (myKey->key() == Qt::Key_Up && ctrl_key) move_joint(4);
    else if (myKey->key() == Qt::Key_U)         on_myButton_UpdateFrameID_clicked();

    else if (myKey->key() == Qt::Key_R)     {   ui->myRadioButton_Image_RGB->      setChecked(true);   on_myRadioButton_Image_RGB_clicked();         }
    else if (myKey->key() == Qt::Key_T)     {   ui->myRadioButton_Image_RGBD->     setChecked(true);   on_myRadioButton_Image_RGBD_clicked();        }
    else if (myKey->key() == Qt::Key_D)     {   ui->myRadioButton_Image_DepthVIZ-> setChecked(true);   on_myRadioButton_Image_DepthVIZ_clicked();    }
  //else if (myKey->key() == Qt::Key_F)     {   ui->myRadioButton_Image_DepthREAL->setChecked(true);   on_myRadioButton_Image_DepthREAL_clicked();   }

    else if (myKey->key() == Qt::Key_Backspace) on_myButton_ANNO_Clear_LAST_clicked();
    else if (myKey->key() == Qt::Key_Delete)    on_myButton_ANNO_Clear_ALL_clicked();

    else if (myKey->key() == Qt::Key_Return)    on_myButton_ANNO_Save_clicked();
    else if (myKey->key() == Qt::Key_Control)    ctrl_key = true;
    else if (myKey->key() == Qt::Key_Shift)    shift_key = true;

}


void MainWindow::keyReleaseEvent(QKeyEvent *myKey)
{
    if (myKey->key() == Qt::Key_Control)    ctrl_key = false;
    else if (myKey->key() == Qt::Key_Shift)    shift_key = false;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::wheelEvent(QWheelEvent* event){
    if (ctrl_key){
        rotate_joints(event->delta());
    }
}

void MainWindow::Mouse_Pos()
{
    ui->myLabel_Mouse_X->setText( QString::number( ui->myLabel_IMG->mouse_X ) );
    ui->myLabel_Mouse_Y->setText( QString::number( ui->myLabel_IMG->mouse_Y ) );
    if (ctrl_click || shift_click){
        update_CURR_Display();
    }
}



void MainWindow::Mouse_Pressed()
{
    ///////////////////////////////////////
    if (isSequenceLoaded == false)  return;
    ///////////////////////////////////////

    if (!ctrl_key && !shift_key){
        if (   (QApplication::mouseButtons() & Qt::LeftButton  )   ||   (QApplication::mouseButtons() & Qt::RightButton )   )
        {
            //std::cout << "button" << std::endl;

            annotations_ADD( ui->myLabel_IMG->mouse_X,
                             ui->myLabel_IMG->mouse_Y );
        }
        else if (   (QApplication::mouseButtons() & Qt::MiddleButton)   )
        {
            //std::cout << "wheel" << std::endl;

            annotations_ADD( 0, 0 );
        }

    } else {
        if(ctrl_key)
            ctrl_click = true;
        if(shift_key)
            shift_click = true;
        selMouseX = ui->myLabel_IMG->mouse_X;
        selMouseY = ui->myLabel_IMG->mouse_Y;
    }
}

void MainWindow::Mouse_Release(){
    if (ctrl_click || shift_click){
        if (annotations.size() == 0)
            return;
        if (ctrl_click && !shift_key)
            ui->fingerList->clearSelection();
        if (abs(selMouseX-ui->myLabel_IMG->mouse_X) < 2 && abs(selMouseY-ui->myLabel_IMG->mouse_Y) < 2){
            double best_dist = 999999999;
            int best_id = -1;
            // find the closest point to the clicked position
            for(int i = 0; i < (int) annotations.size(); i++){
                // calculate distance
                double dist = sqrt(pow((double)ui->myLabel_IMG->mouse_X - annotations[i].joint_X,2) + pow((double)ui->myLabel_IMG->mouse_Y - annotations[i].joint_Y,2));
                if (dist < best_dist){
                    best_id = i;
                    best_dist = dist;
                }
            }
            // select the closest point
            ui->fingerList->setCurrentRow(best_id, QItemSelectionModel::Toggle );
        } else {
            // create the selection box
            cv::Rect rect(cv::Point(selMouseX, selMouseY), cv::Point(ui->myLabel_IMG->mouse_X, ui->myLabel_IMG->mouse_Y));
            for(int i = 0; i < (int) annotations.size(); i++){
                // check if it is inside the box
                cv::Point current(roundToInt(annotations[i].joint_X), roundToInt(annotations[i].joint_Y));
                if (current.inside(rect) ){
                    ui->fingerList->setCurrentRow(i, QItemSelectionModel::Select );
                }
            }
        }

    }
    ctrl_click = false;
    shift_click = false;
    update_CURR_Display();

}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void MainWindow::Mouse_Left(){} // Leaving the QLabel area !!!

