#include "mainwindow.h"
#include "ui_mainwindow.h"



void MainWindow::annotations_SAVE_CurrFrame()
{
    if (annotations.size() < TOTAL_JOINTS__ALL_hands)
    {
        std::cout << "\n\nNOT ALL JOINTS DEFINED !!! - Size of anntation vector = "  << annotations.size() << "\t" << "instead of " << TOTAL_JOINTS__ALL_hands << " \n\n" << std::endl;
        system("beep -f 800 -l 200");
        return;
    }
    if (annotations.size() > TOTAL_JOINTS__ALL_hands)
    {
        std::cout << "\n\nTOO MANY JOINTS DEFINED !!! - Size of anntation vector = " << annotations.size() << "\t" << "instead of " << TOTAL_JOINTS__ALL_hands << " \n\n" << std::endl;
        system("beep -f 800 -l 200");
        return;
    }

                                                            std::ofstream  fileOUT;
                                                                           fileOUT.open( PATH_CURR_Anno.toStdString().data(), std::ofstream::out | std::ofstream::trunc);

        for (int iii=0; iii<annotations.size(); iii++)
        {
                                                                           fileOUT <<      iii;
                                                                           fileOUT << "\t";
                                                                           fileOUT <<      QString::number(roundToInt(annotations[iii].joint_X)).toStdString();
                                                                           fileOUT << "\t";
                                                                           fileOUT <<      QString::number(roundToInt(annotations[iii].joint_Y)).toStdString();
                                         if (iii <annotations.size()-1)    fileOUT << "\n";
        }
                                                                           fileOUT.close();

        std::cout << "MainWindow::annotations_SAVE_CurrFrame - " << PATH_CURR_Anno.toStdString() << std::endl;

}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void MainWindow::annotations_EXTRACT_All()
{

    if (annotations_CHECK_alreadyExistALL() == false)
    {
        std::cout << "Not all frames have Annotations !!!" << std::endl;
        return;
    }

    std::ofstream  fileOUT;
                   fileOUT.open( PATH_CURR_EXTRACT_ALL.toStdString().data() );
                   fileOUT << "image_files = ( \n\n\n\n";

    /////////////////////////////////
    int rememberCurrID = currFrameID;
    /////////////////////////////////

    ////////////////////////////////
    QString  gap = "              ";
    ////////////////////////////////

//                                int loopEND = 3 + FRAMES_ID_START;
                                  int loopEND = FRAMES_TOTAL+FRAMES_ID_START;

    for (int iii=FRAMES_ID_START; iii<loopEND; iii++)
    {

        update_CURR_THINGS( iii );

        QFile fileIN( PATH_CURR_Anno );
        fileIN.open(QIODevice::ReadOnly);
        if (fileIN.size() == 0)
        {
            std::cout << "Frame " << iii << " - Empty annotation file, Skipping them in the final *FingerTipAnno.txt* file \t (this is not a problem!)" << std::endl;
            continue;
        }
        if( !fileIN.isOpen() )
        {
            std::cout << "MainWindow::annotations_EXTRACT_All - ERROR anno No" << iii << std::endl;
            /////////////////////////////////////
            update_CURR_THINGS( rememberCurrID );
            /////////////////////////////////////
            return;
        }
        fileOUT << gap.toStdString();
        fileOUT << gap.toStdString();
        fileOUT << "{\n";

        QTextStream         myTextStream( &fileIN );
        QString             myStringLINE;
        QVector<QString>    myStringLineVECT;
        QString             myStringFULL;

                                                                           myStringLINE = myTextStream.readLine();   myStringLineVECT.append( QString( gap + gap + gap + myStringLINE + "\n") );
        while (myStringLINE.isNull() == false || myStringLINE != "")   {   myStringLINE = myTextStream.readLine();   myStringLineVECT.append( QString( gap + gap + gap + myStringLINE + "\n") );   }

        for (int strr=0; strr<myStringLineVECT.size()-1; strr++) // because in the end there is a dummy "\n"
        {
            myStringFULL += myStringLineVECT[strr];
        }

        fileOUT << myStringFULL.toStdString();
        fileOUT << gap.toStdString();
        fileOUT << gap.toStdString();

        if (iii < loopEND-1)    fileOUT << "},\n\n\n\n";
        else                    fileOUT << "}\n\n\n\n";
    }

    fileOUT << ");\n\n\n";
    fileOUT.close();

    std::cout << "MainWindow::annotations_EXTRACT_All    - " << PATH_CURR_EXTRACT_ALL.toStdString() << std::endl;
//    annotations_CHECK_alreadyExistALL();

    /////////////////////////////////////
    update_CURR_THINGS( rememberCurrID );
    /////////////////////////////////////

}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void MainWindow::on_myButton_DETECTOR_generateAnnotationMovie_clicked()
{

//    ///////////////////////////////////////////
//    ui->myRadioButton_Replay->setChecked(true);
//     on_myRadioButton_Replay_clicked();
//    ///////////////////////////////////////////

//    /////////////////////////////////////////////////////////////////////////////////////
//    if ( QDir(         QString( PATH_BASE_Base + "movieFramesGT/" )  ).exists() == false)
//         QDir().mkdir( QString( PATH_BASE_Base + "movieFramesGT/" ) );
//    /////////////////////////////////////////////////////////////////////////////////////

//    for (int frameID=FRAMES_ID_START; frameID<=FRAMES_ID_START+FRAMES_TOTAL-1; frameID++)
//    {
//        on_myButton_Next_clicked();
//        std::string  imgToWritePATH = QString(  PATH_BASE_Base + "movieFramesGT/" + QString::number(frameID).rightJustified(ID_NUMB_OF_DIGITS,'0',false) + ".png"  ).toStdString();
//        cv::imwrite( imgToWritePATH, imgCV );
//        std::cout << imgToWritePATH << std::endl;
//        QApplication::processEvents();
//    }

}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

