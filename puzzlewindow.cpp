//
//  puzzlewindow.cpp
//  CS331_HW07
//
//  Created by yongqiang chen on 12/17/19.
//  Copyright © 2019 yongqiang chen. All rights reserved.
//

#include "puzzlewindow.h"
#include "puzzleview.h"

PuzzleWindow::PuzzleWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PuzzleWindow)
{
    ui->setupUi(this);

    PuzzleModel *m_modal=new PuzzleModel();
    PuzzleView *puzzleView=new PuzzleView(m_modal);
    this->setCentralWidget(puzzleView);
}

PuzzleWindow::~PuzzleWindow()
{
    delete ui;
}
