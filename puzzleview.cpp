//
//  puzzleview.cpp
//  CS331_HW07
//
//  Created by yongqiang chen on 12/17/19.
//  Copyright © 2019 yongqiang chen. All rights reserved.
//


#include "puzzleview.h"
#include "qdebug.h"
#include "QApplication"
#include "qmessagebox.h"

PuzzleView::PuzzleView(PuzzleModel *model)
{
    this->m_modal=model;
    m_layout = new QGridLayout();
    this->setLayout(m_Layout);

    connect(&m_buttons,SIGNAL(buttonClicked(int)),this,SLOT(onMove(int)));

    for(int i=0;i<15;i++){
        tiles[i]=new Tile(i);
        m_layout->addWidget(tiles[i],i/4,i%4);
        m_buttons.addButton(tiles[i],i);
    }

    shuffle=new QPushButton("Shuffle");
    connect(shuffle,SIGNAL(clicked()),this,SLOT(onShuffle()));
    m_layout->addWidget(shuffle,1,4);

    quit=new QPushButton("Quit");
    connect(quit,SIGNAL(clicked()),this,SLOT(onQuit()));
    m_Layout->addWidget(quit,2,4);

    connect(model,SIGNAL(gridChanged()),this,SLOT(refresh()));
    refresh();
}

void PuzzleView::refresh(){
    for(int i=0;i<15;i++)
        m_layout->removeWidget(tiles[i]);

    for(int i=0;i<15;i++){
        int pos=this->m_modal->value(i/4,i%4);
        m_layout->addWidget(tiles[i],pos/4,pos%4);
    }
}

void PuzzleView::tryToSlide(QAbstractButton *button){//try to slide the tile
    Tile *tile=(Tile *)button;
    bool win=this->m_modal->slide(tile->m_Number);
    if(win)
        QMessageBox::information(this,"Puzzle", "YOU WIN!                        ",QMessageBox::Ok);
}

void PuzzleView::onMove(int num){
    tryToSlide(tiles[num]);
}

void PuzzleView::onShuffle(){
    this->m_modal->shuffle();
}

void PuzzleView::onQuit(){
    QApplication::exit();
}
