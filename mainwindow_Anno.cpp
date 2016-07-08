#include "mainwindow.h"
#include "ui_mainwindow.h"



void MainWindow::annotations_ADD( int mouseX, int mouseY )
{
    ////////////////////////
    AnnotationPatch annoTMP;
    ////////////////////////

    annoTMP.joint_X = (double) mouseX;
    annoTMP.joint_Y = (double) mouseY;

    //////////////////////////////
    annotations.append( annoTMP );
    //////////////////////////////
    update_CURR_Display();
    update_list();
    //////////////////////

    int annoCurrNUMB = annotations.size();

    std::string                                           existSTR;
    if (annoTMP.joint_X == 0 || annoTMP.joint_Y == 0)     existSTR="---";
    else                                                  existSTR="";

        if      (annoCurrNUMB ==  1)      std::cout << "annotationID "<<QString::number(annoCurrNUMB).rightJustified(2,'0').toStdString() << "\t" << "Hand_R" << "\t" << "Fing_Little " << "\t" << "Joint_0" << "\t" << existSTR << std::endl;
        else if (annoCurrNUMB ==  2)      std::cout << "annotationID "<<QString::number(annoCurrNUMB).rightJustified(2,'0').toStdString() << "\t" << "Hand_R" << "\t" << "Fing_Little " << "\t" << "Joint_1" << "\t" << existSTR << std::endl;
        else if (annoCurrNUMB ==  3)      std::cout << "annotationID "<<QString::number(annoCurrNUMB).rightJustified(2,'0').toStdString() << "\t" << "Hand_R" << "\t" << "Fing_Little " << "\t" << "Joint_2" << "\t" << existSTR << std::endl;
        else if (annoCurrNUMB ==  4)      std::cout << "annotationID "<<QString::number(annoCurrNUMB).rightJustified(2,'0').toStdString() << "\t" << "Hand_R" << "\t" << "Fing_Ring   " << "\t" << "Joint_0" << "\t" << existSTR << std::endl;
        else if (annoCurrNUMB ==  5)      std::cout << "annotationID "<<QString::number(annoCurrNUMB).rightJustified(2,'0').toStdString() << "\t" << "Hand_R" << "\t" << "Fing_Ring   " << "\t" << "Joint_1" << "\t" << existSTR << std::endl;
        else if (annoCurrNUMB ==  6)      std::cout << "annotationID "<<QString::number(annoCurrNUMB).rightJustified(2,'0').toStdString() << "\t" << "Hand_R" << "\t" << "Fing_Ring   " << "\t" << "Joint_2" << "\t" << existSTR << std::endl;
        else if (annoCurrNUMB ==  7)      std::cout << "annotationID "<<QString::number(annoCurrNUMB).rightJustified(2,'0').toStdString() << "\t" << "Hand_R" << "\t" << "Fing_Middle " << "\t" << "Joint_0" << "\t" << existSTR << std::endl;
        else if (annoCurrNUMB ==  8)      std::cout << "annotationID "<<QString::number(annoCurrNUMB).rightJustified(2,'0').toStdString() << "\t" << "Hand_R" << "\t" << "Fing_Middle " << "\t" << "Joint_1" << "\t" << existSTR << std::endl;
        else if (annoCurrNUMB ==  9)      std::cout << "annotationID "<<QString::number(annoCurrNUMB).rightJustified(2,'0').toStdString() << "\t" << "Hand_R" << "\t" << "Fing_Middle " << "\t" << "Joint_2" << "\t" << existSTR << std::endl;
        else if (annoCurrNUMB == 10)      std::cout << "annotationID "<<QString::number(annoCurrNUMB).rightJustified(2,'0').toStdString() << "\t" << "Hand_R" << "\t" << "Fing_Pointer" << "\t" << "Joint_0" << "\t" << existSTR << std::endl;
        else if (annoCurrNUMB == 11)      std::cout << "annotationID "<<QString::number(annoCurrNUMB).rightJustified(2,'0').toStdString() << "\t" << "Hand_R" << "\t" << "Fing_Pointer" << "\t" << "Joint_1" << "\t" << existSTR << std::endl;
        else if (annoCurrNUMB == 12)      std::cout << "annotationID "<<QString::number(annoCurrNUMB).rightJustified(2,'0').toStdString() << "\t" << "Hand_R" << "\t" << "Fing_Pointer" << "\t" << "Joint_2" << "\t" << existSTR << std::endl;
        else if (annoCurrNUMB == 13)      std::cout << "annotationID "<<QString::number(annoCurrNUMB).rightJustified(2,'0').toStdString() << "\t" << "Hand_R" << "\t" << "Fing_Thumb  " << "\t" << "Joint_0" << "\t" << existSTR << std::endl;
        else if (annoCurrNUMB == 14)      std::cout << "annotationID "<<QString::number(annoCurrNUMB).rightJustified(2,'0').toStdString() << "\t" << "Hand_R" << "\t" << "Fing_Thumb  " << "\t" << "Joint_1" << "\t" << existSTR << std::endl;

    else if (TOTAL_JOINTS__ALL_hands > TOTAL_JOINTS__one_hand)
    {
        if      (annoCurrNUMB == 15)      std::cout << "annotationID "<<QString::number(annoCurrNUMB).rightJustified(2,'0').toStdString() << "\t" << "Hand_L" << "\t" << "Fing_Little " << "\t" << "Joint_0" << "\t" << existSTR << std::endl;
        else if (annoCurrNUMB == 16)      std::cout << "annotationID "<<QString::number(annoCurrNUMB).rightJustified(2,'0').toStdString() << "\t" << "Hand_L" << "\t" << "Fing_Little " << "\t" << "Joint_1" << "\t" << existSTR << std::endl;
        else if (annoCurrNUMB == 17)      std::cout << "annotationID "<<QString::number(annoCurrNUMB).rightJustified(2,'0').toStdString() << "\t" << "Hand_L" << "\t" << "Fing_Little " << "\t" << "Joint_2" << "\t" << existSTR << std::endl;
        else if (annoCurrNUMB == 18)      std::cout << "annotationID "<<QString::number(annoCurrNUMB).rightJustified(2,'0').toStdString() << "\t" << "Hand_L" << "\t" << "Fing_Ring   " << "\t" << "Joint_0" << "\t" << existSTR << std::endl;
        else if (annoCurrNUMB == 19)      std::cout << "annotationID "<<QString::number(annoCurrNUMB).rightJustified(2,'0').toStdString() << "\t" << "Hand_L" << "\t" << "Fing_Ring   " << "\t" << "Joint_1" << "\t" << existSTR << std::endl;
        else if (annoCurrNUMB == 20)      std::cout << "annotationID "<<QString::number(annoCurrNUMB).rightJustified(2,'0').toStdString() << "\t" << "Hand_L" << "\t" << "Fing_Ring   " << "\t" << "Joint_2" << "\t" << existSTR << std::endl;
        else if (annoCurrNUMB == 21)      std::cout << "annotationID "<<QString::number(annoCurrNUMB).rightJustified(2,'0').toStdString() << "\t" << "Hand_L" << "\t" << "Fing_Middle " << "\t" << "Joint_0" << "\t" << existSTR << std::endl;
        else if (annoCurrNUMB == 22)      std::cout << "annotationID "<<QString::number(annoCurrNUMB).rightJustified(2,'0').toStdString() << "\t" << "Hand_L" << "\t" << "Fing_Middle " << "\t" << "Joint_1" << "\t" << existSTR << std::endl;
        else if (annoCurrNUMB == 23)      std::cout << "annotationID "<<QString::number(annoCurrNUMB).rightJustified(2,'0').toStdString() << "\t" << "Hand_L" << "\t" << "Fing_Middle " << "\t" << "Joint_2" << "\t" << existSTR << std::endl;
        else if (annoCurrNUMB == 24)      std::cout << "annotationID "<<QString::number(annoCurrNUMB).rightJustified(2,'0').toStdString() << "\t" << "Hand_L" << "\t" << "Fing_Pointer" << "\t" << "Joint_0" << "\t" << existSTR << std::endl;
        else if (annoCurrNUMB == 25)      std::cout << "annotationID "<<QString::number(annoCurrNUMB).rightJustified(2,'0').toStdString() << "\t" << "Hand_L" << "\t" << "Fing_Pointer" << "\t" << "Joint_1" << "\t" << existSTR << std::endl;
        else if (annoCurrNUMB == 26)      std::cout << "annotationID "<<QString::number(annoCurrNUMB).rightJustified(2,'0').toStdString() << "\t" << "Hand_L" << "\t" << "Fing_Pointer" << "\t" << "Joint_2" << "\t" << existSTR << std::endl;
        else if (annoCurrNUMB == 27)      std::cout << "annotationID "<<QString::number(annoCurrNUMB).rightJustified(2,'0').toStdString() << "\t" << "Hand_L" << "\t" << "Fing_Thumb  " << "\t" << "Joint_0" << "\t" << existSTR << std::endl;
        else if (annoCurrNUMB == 28)      std::cout << "annotationID "<<QString::number(annoCurrNUMB).rightJustified(2,'0').toStdString() << "\t" << "Hand_L" << "\t" << "Fing_Thumb  " << "\t" << "Joint_1" << "\t" << existSTR << std::endl;
    }

    else                              std::cout << "annotationID "<<QString::number(annoCurrNUMB).rightJustified(2,'0').toStdString() << "\t" << "------" << "\t" << "------------" << "\t" << "-------" << "\t" << existSTR << std::endl;
}

void MainWindow::move_joint(int direction){
    for (int iii=0; iii<annotations.size(); iii++)
    {
        if(ui->fingerList->count() > iii && ui->fingerList->item(iii)->isSelected()){
            switch (direction){
                case 1:
                    annotations[iii].joint_X += 1.0;
                    break;
                case 2:
                    annotations[iii].joint_X -= 1.0;
                    break;
                case 3:
                    annotations[iii].joint_Y += 1.0;
                    break;
                case 4:
                    annotations[iii].joint_Y -= 1.0;
                    break;
                default:
                    break;
            }
        }
    }

    update_CURR_Image();
    update_CURR_Display(true);
}


void MainWindow::rotate_joints(int direction){

    if(ui->fingerList->count() == 0){
        return;
    }
    double theta = 1.0;

    if(direction < 0){
        theta *= -1.0;
    }

    double centerX = 0;
    double centerY = 0;

    //get the centroid
    for (int iii=0; iii<annotations.size(); iii++){
        if(ui->fingerList->count() > iii && ui->fingerList->item(iii)->isSelected()){
            centerX +=  annotations[iii].joint_X;
            centerY +=  annotations[iii].joint_Y;
        }
    }

    centerX /= (double) ui->fingerList->selectedItems().count();
    centerY /= (double) ui->fingerList->selectedItems().count();

    //change theta to radians
    theta *= M_PI / 180;

    for (int iii=0; iii<annotations.size(); iii++){
        if(ui->fingerList->count() > iii && ui->fingerList->item(iii)->isSelected()){
            double curr_X = annotations[iii].joint_X - centerX;
            double curr_Y = annotations[iii].joint_Y - centerY;
            curr_X = (curr_X * std::cos(theta)) - (curr_Y * std::sin(theta));
            curr_Y = (curr_X * std::sin(theta)) + (curr_Y * std::cos(theta));
            curr_X = curr_X + centerX;
            curr_Y = curr_Y + centerY;
            annotations[iii].joint_X = curr_X;
            annotations[iii].joint_Y = curr_Y;
        }
    }
    update_CURR_Image();
    update_CURR_Display(true);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void MainWindow::annotations_REMOVE_Last()   {   if (annotations.size() > 0)   annotations.remove(annotations.size()-1  );   }
void MainWindow::annotations_REMOVE_All()    {                                 annotations.clear();                          }


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



