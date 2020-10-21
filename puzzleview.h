//
//  puzzleview.hpp
//  CS331_HW07
//
//  Created by Chenyu Wang on 12/17/19.
//  Copyright © 2019 chenyu wang. All rights reserved.
//

#ifndef puzzleview_h_
#define puzzleview_h_

#include <QObject>
#include <QWidget>
#include "puzzlemodel.h"
#include "QGridLayout.h"
#include "QButtonGroup.h"
#include "qpushbutton.h"
#include "tile.h"

class PuzzleView : public QWidget
{
    Q_OBJECT
public:
    explicit PuzzleView(PuzzleModel *model);

private:
    PuzzleModel *m_modal;
    QGridLayout *m_layout;
    QButtonGroup m_buttons;
    QPushButton *shuffle;
    QPushButton *quit;
    Tile *tiles[15];

public:
    void tryToSlide(QAbstractButton *button);
signals:

public slots:
    void refresh();
    void onMove(int num);
    void onShuffle();
    void onQuit();
};
#endif /* puzzleview_hpp */
