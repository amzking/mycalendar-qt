#ifndef MYYEAR_H
#define MYYEAR_H

#include <QWidget>
#include <QSplitter>
#include "MyMonth.h"

class MyYear : public QWidget
{
    Q_OBJECT
public:
    explicit MyYear(int nianfen,QWidget *parent = 0);


    QSplitter *Hsplitter0;
    QSplitter *Hsplitter1;
    QSplitter *Hsplitter2;
    QSplitter *Vsplitter;


    MyMonth *mymonth1;
    MyMonth *mymonth2;
    MyMonth *mymonth3;
    MyMonth *mymonth4;
    MyMonth *mymonth5;
    MyMonth *mymonth6;
    MyMonth *mymonth7;
    MyMonth *mymonth8;
    MyMonth *mymonth9;
    MyMonth *mymonth10;
    MyMonth *mymonth11;
    MyMonth *mymonth12;

    int years;

signals:

public slots:
};

#endif // MYYEAR_H
