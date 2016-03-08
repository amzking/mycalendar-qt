#ifndef MYMONTH_H
#define MYMONTH_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QVector>
#include <QDateTime>
#include <QPalette>


class MyMonth : public QWidget
{
    Q_OBJECT
public:
    explicit MyMonth(int monthnum, int year ,QWidget *parent = 0);

    QLabel *monthTitle;

    QLabel *Monday;
    QLabel *Tuesday;
    QLabel *Wensday;
    QLabel *Thursday;
    QLabel *Friday;
    QLabel *Saturday;
    QLabel *Sunday;

    QGridLayout *gridlayout0;
    QGridLayout *gridlayout1;
    QGridLayout *gridlayout2;
    QVBoxLayout *vlayout;

private:
    int daynum=1;
    int monthnum;
    bool rn4=false;
    int year;
    QVector<int> ivec={1,3,5,7,8,10,12};
    bool month31=false;


    //起始时间计算点，1900年1月1日是周一
    int weekDay =0;
    int searchDayWeek(int searchyear); //返回查询年1月1日星期几，返回1为星期1。。。。。



    //绘制每月1号分两次绘制
    int monthDay_Start = 0;
    int searchDayWeek_month(int yuefen, bool isLeap);


    //闰年or not
    bool isLeapYear(int year4th);


    //点亮今天
    void lightToday(int year,int month, int day,QLabel *lightLabel);



signals:

public slots:
};


#endif // MYMONTH_H
