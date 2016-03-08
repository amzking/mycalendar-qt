#include "MyYear.h"

MyYear::MyYear(int nianfen,QWidget *parent) : years(nianfen),QWidget(parent)
{
    Hsplitter0 = new QSplitter(Qt::Horizontal,this);
    mymonth1 = new MyMonth(1,years);
    mymonth2 = new MyMonth(2,years);
    mymonth3 = new MyMonth(3,years);
    mymonth4 = new MyMonth(4,years);
    Hsplitter0->addWidget(mymonth1);
    Hsplitter0->addWidget(mymonth2);
    Hsplitter0->addWidget(mymonth3);
    Hsplitter0->addWidget(mymonth4);

    Hsplitter1 = new QSplitter(Qt::Horizontal,this);
    mymonth5 = new MyMonth(5,years);
    mymonth6 = new MyMonth(6,years);
    mymonth7 = new MyMonth(7,years);
    mymonth8 = new MyMonth(8,years);
    Hsplitter1->addWidget(mymonth5);
    Hsplitter1->addWidget(mymonth6);
    Hsplitter1->addWidget(mymonth7);
    Hsplitter1->addWidget(mymonth8);

    Hsplitter2 = new QSplitter(Qt::Horizontal,this);
    mymonth9 = new MyMonth(9,years);
    mymonth10 = new MyMonth(10,years);
    mymonth11 = new MyMonth(11,years);
    mymonth12 = new MyMonth(12,years);
    Hsplitter2->addWidget(mymonth9);
    Hsplitter2->addWidget(mymonth10);
    Hsplitter2->addWidget(mymonth11);
    Hsplitter2->addWidget(mymonth12);

    Vsplitter = new QSplitter(Qt::Vertical,this);
    Vsplitter->addWidget(Hsplitter0);
    Vsplitter->addWidget(Hsplitter1);
    Vsplitter->addWidget(Hsplitter2);

    this->setMinimumSize(Vsplitter->sizeHint());


}

