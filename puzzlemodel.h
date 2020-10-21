//
//  puzzlemodle.hpp
//  CS331_HW07
//
//  Created by yongqiang chen on 12/17/19.
//  Copyright © 2019 yongqiang chen. All rights reserved.
//

#ifndef puzzlemodel_h_
#define puzzlemodel_h_

#include <QObject>
#include<stdlib.h>
#include<time.h>
#include "qlist.h"

namespace Ui{
    class PuzzleModel;
}
class PuzzleModel : public QObject
{
    Q_OBJECT
private:
    QList<int> m_Positions;
    int m_Rows;
    int m_Cols;

public:
    explicit PuzzleModel(QObject *parent = 0);
    int value(int r,int c);
    bool slide(int tilenum);
    bool neighboring(int r,int c);

    void shuffle();
    int randmove(int freePos);

signals:
    void gridChanged();

};

#endif /* puzzlemodel_h_ */
