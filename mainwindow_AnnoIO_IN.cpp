#include "mainwindow.h"
#include "ui_mainwindow.h"




void MainWindow::annotations_READ_CurrFrame()
{
    ///////////////////////////////////////////////////////////////
    if (annotations_CHECK_alreadyExistsCURR() == false)     return;
    ///////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////

    QFile fileIN( PATH_CURR_Anno );
    fileIN.open(QIODevice::ReadOnly);
    if (fileIN.size() == 0)
    {
        std::cout << "Current Frame - Empty annotation file, nothing to display ;) \t(this is not a problem!)" << std::endl;
        fileIN.close();
        return;
    }

    QTextStream myStreamIN(&fileIN);

    //////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////

    ////////////////////
    annotations.clear();
    ////////////////////

    //////////////////////////////////////////////
    annotations.resize( TOTAL_JOINTS__ALL_hands );
    //////////////////////////////////////////////

    for(int iii=0; iii<annotations.size(); iii++)
    {
        int           dummyInt;
        myStreamIN >> dummyInt;
        myStreamIN >> annotations[iii].joint_X;
        myStreamIN >> annotations[iii].joint_Y;

        //std::cout << "############ " << iii+1 << std::endl;
        //std::cout << annotations[iii].joint_X << std::endl;
        //std::cout << annotations[iii].joint_Y << std::endl;
    }

    ///////////////
    fileIN.close();
    ///////////////

}

