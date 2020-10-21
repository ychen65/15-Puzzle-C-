//
//  main.cpp
//  CS331_HW07
//
//  Created by yongqiang chen on 12/17/19.
//  Copyright © 2019 yongqiang chen. All rights reserved.
//


#include "puzzlewindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PuzzleWindow window;
    window.show();

    return a.exec();
}
