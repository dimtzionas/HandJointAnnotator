#include "mainwindow.h"
#include "ui_mainwindow.h"






bool MainWindow::annotations_CHECK_alreadyExistsCURR()
{
    QFile myFile( PATH_CURR_Anno );

  //std::cout << "MainWindow::annotations_CHECK_alreadyExistsCurr - " << PATH_CURR_Anno.toStdString() << " - " << myFile.exists() << std::endl;

    if   (myFile.exists())   {   ui->myLabel_AnnoExists->setText( "Yes" );   ui->myButton_ANNO_Load->setEnabled(true );                   }
    else                     {   ui->myLabel_AnnoExists->setText( "No"  );   ui->myButton_ANNO_Load->setEnabled(false);   return false;   }

    //    myFile.open(QIODevice::WriteOnly);

    return true;
}





bool MainWindow::annotations_CHECK_alreadyExistALL()
{
    /////////////////////////////////
    int rememberCurrID = currFrameID;
    /////////////////////////////////

    for (int iii=FRAMES_ID_START; iii<FRAMES_TOTAL+FRAMES_ID_START; iii++)
    {
        update_CURR_THINGS( iii ); // runs also **annotations_CHECK_alreadyExistALL** but without check ;)

        if (annotations_CHECK_alreadyExistsCURR() == false)
        {
          //std::cout << "MainWindow::annotations_CHECK_alreadyExistALL - " << false << std::endl;

            /////////////////////////////////////
            update_CURR_THINGS( rememberCurrID );
            /////////////////////////////////////

            std::cout << "Frame " << iii << " NOT annotated!!!" << std::endl;

            return false;
        }
    }

    /////////////////////////////////////
    update_CURR_THINGS( rememberCurrID );
    /////////////////////////////////////

  //std::cout << "MainWindow::annotations_CHECK_alreadyExistALL - " << true << std::endl;
    return true;
}

