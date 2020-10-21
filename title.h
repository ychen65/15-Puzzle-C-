//
//  title.hpp
//  CS331_HW07
//
//  Created by yongqiang chen on 12/17/19.
//  Copyright © 2019 yongqiang chen. All rights reserved.
//

#ifndef title_h_
#define title_h_

#include <QObject>
#include "qpushbutton.h"

class Tile : public QPushButton
{
public:
    int m_Number;

public:
    Tile(int tileNumber);
};

#endif /* title_hpp */
