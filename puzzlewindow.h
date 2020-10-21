//
//  puzzlewindow.hpp
//  CS331_HW07
//
//  Created by Chenyu Wang on 12/17/19.
//  Copyright © 2019 chenyu wang. All rights reserved.
//

#ifndef puzzlewindow_h_
#define puzzlewindow_h_

#include <QMainWindow>

namespace Ui {
class PuzzleWindow;
}

class PuzzleWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PuzzleWindow(QWidget *parent = 0);
    ~PuzzleWindow();

private:
    Ui::PuzzleWindow *ui;
};

#endif /* puzzlewindow_hpp */
