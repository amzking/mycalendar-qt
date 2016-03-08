#include "MyMainWD.h"
#include <QDebug>

MyMainWD::MyMainWD(QWidget *parent) : QMainWindow(parent)
{
//    labeltest = new QLabel("test",this);
//    labeltest->setMargin(2);
//    labeltest->setSizePolicy();


    select = this->addToolBar("xuanze");
    select->setFixedHeight(25);

    xuanze = new QLabel("输入年份: ");
    year_input = new QLineEdit;
    year_input->setFixedWidth(100);
    year_input->setMaxLength(4);
    button = new QPushButton("OK");
    currentYear = new QLabel(tr("显示的年份是："));
    yearShow = new QLabel;

    xuanze->setBuddy(year_input);
    select->addWidget(xuanze);
    select->addWidget(year_input);
    select->addWidget(button);
    select->addSeparator();
    select->addWidget(currentYear);

    year = new MyYear(2015,this);

    this->setCentralWidget(year);
    connect(button,SIGNAL(clicked()), this,SLOT(slotclicked()));


//    int yearnum = yearstr.toInt();
//    year = new MyYear(yearnum,this);
//    this->setCentralWidget(year);

}

void MyMainWD::slotclicked()
{
    yearstr = year_input->text();
    yearShow->setText(yearstr);
    int yearnum = yearstr.toInt();
        select->addWidget(yearShow);
    year = new MyYear(yearnum,this);


    this->setCentralWidget(year);
}
