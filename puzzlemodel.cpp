//
//  puzzlemodle.cpp
//  CS331_HW07
//
//  Created by Chenyu Wang on 12/17/19.
//  Copyright © 2019 chenyu wang. All rights reserved.
//

#include "puzzlemodel.h"
#include "qdebug.h"

PuzzleModel::PuzzleModel(QObject *parent) : QObject(parent)
{
    m_Rows=4;
    m_Cols=4;
    srand(time(0));
    int place[16];
    for(int i=0;i<16;i++)
        place[i]=i;

    int left=16;
    for(int i=0;i<15;i++){
        int r=rand()%left;
        m_Positions.append(place[r]);

        
        for(int j=r;j<left-1;j++)
            place[j]=place[j+1];
        left--;
    }
}

int PuzzleModel::value(int r,int c){
    int index=r*4+c;
    return m_Positions.at(index);
}

bool PuzzleModel::slide(int tilenum){
    int pos=m_Positions.at(tilenum);
    int r=pos/4;
    int c=pos%4;

    int x,y;
    int xarr[4]={-1,1,0,0};
    int yarr[4]={0,0,-1,1};

    
    for(int i=0;i<4;i++){
        x=xarr[i]+r;
        y=yarr[i]+c;
        if(this->neighboring(x,y)){
            m_Positions.replace(tilenum,x*4+y);
            emit gridChanged();
            break;
        }
    }
   
    bool win=true;
    for(int i=0;i<15;i++){
        int pos=m_Positions.at(i);
        if(pos!=i){
            win=false;
            break;
        }
    }
    return win;
}

bool PuzzleModel::neighboring(int r,int c){
    if(r<0||r>3||c<0||c>3)
        return false;

    int pos=r*4+c;
    bool find=true;
    for(int i=0;i<15;i++){
        if(m_Positions.at(i)==pos){
            find=false;
            break;
        }
    }
    return find;
}

int PuzzleModel::randmove(int freePos){
    int r=freePos/4;
    int c=freePos%4;
    int x[4],y[4];
    int xarr[4]={-1,1,0,0};
    int yarr[4]={0,0,-1,1};

    
    int count=0;
    int i;
    for(i=0;i<4;i++){
        int x1=xarr[i]+r;
        int y1=yarr[i]+c;
        if(x1>=0&&x1<4&&y1>=0&&y1<4){
            x[count]=x1;
            y[count]=y1;
            count++;
        }
    }

    
    int t=rand()%count;
    int pos=x[t]*4+y[t];
    for(i=0;i<15;i++){
        int k=m_Positions.at(i);
        if(k==pos)
            break;
    }
    m_Positions.replace(i,freePos);

    
    return pos;
}

void PuzzleModel::shuffle(){
    int i,j;
   
    for(i=0;i<16;i++){
        bool find=false;
        for(j=0;j<15;j++){
            int k=m_Positions.at(j);
            if(k==i){
                find=true;
                break;
            }
        }
        if(!find)
            break;
    }
    int pos=i;

  
    for(i=0;i<50;i++)
        pos=this->randmove(pos);
    emit gridChanged();
}

