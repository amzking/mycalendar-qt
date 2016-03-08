#include "MyMonth.h"
#include <QLabel>
#include <QDebug>

MyMonth::MyMonth(int mon12,int nianfen,QWidget *parent) : QWidget(parent),monthnum(mon12),year(nianfen)
{

    gridlayout0 = new QGridLayout;
    monthTitle = new QLabel(QString::number(monthnum)+tr("月"), this);
    gridlayout0->addWidget(monthTitle,0,3);



    weekDay = searchDayWeek(year);
    rn4 = isLeapYear(year);



    Monday = new QLabel("Mon",this);
    Monday->setMinimumSize(25,15);
    Tuesday = new QLabel("Tue",this);
    Tuesday->setMinimumSize(25,15);
    Wensday = new QLabel("Wen",this);
    Wensday->setMinimumSize(25,15);
    Thursday = new QLabel("Tur",this);
    Thursday->setMinimumSize(25,15);
    Friday = new QLabel("Fri",this);
    Friday->setMinimumSize(25,15);
    Saturday = new QLabel("Sat",this);
    Saturday->setMinimumSize(25,15);
    Sunday = new QLabel("Sun",this);
    Sunday->setMinimumSize(25,15);

    gridlayout1 = new QGridLayout;
    gridlayout1->addWidget(Monday,0,0);
    gridlayout1->addWidget(Tuesday,0,1);
    gridlayout1->addWidget(Wensday,0,2);
    gridlayout1->addWidget(Thursday,0,3);
    gridlayout1->addWidget(Friday,0,4);
    gridlayout1->addWidget(Saturday,0,5);
    gridlayout1->addWidget(Sunday,0,6);







    gridlayout2 = new QGridLayout;


    for(int i= 0; i < ivec.size();i++)
    {
        if(monthnum == ivec[i])
            month31=true;
    }




    if(monthnum == 2)
    {
        monthDay_Start =searchDayWeek_month(monthnum, rn4);
        daynum = monthDay_Start;
        for(int i = 1; i<5; i++)
        {
            if(rn4 == false)
            {
                for(int j = 0; j<7 && daynum<30; j++)
                {
                    QLabel *label = new QLabel(QString::number(daynum),this);
                    label->setMinimumSize(25,15);
                    lightToday(year,monthnum,daynum,label);
                    gridlayout2->addWidget(label,i,j);
                    daynum++;
                }
            }
            if(rn4 == true)
            {
                for(int j = 0; j<7 && daynum<30; j++)
                {
                    QLabel *label = new QLabel(QString::number(daynum),this);
                    label->setMinimumSize(25,15);
                    lightToday(year,monthnum,daynum,label);
                    gridlayout2->addWidget(label,i,j);
                    if(daynum==29)
                        label->setText("");
                    daynum++;
                }
            }
        }

    }else if(month31 == true)
    {
        monthDay_Start =searchDayWeek_month(monthnum, rn4);
        daynum = monthDay_Start;

        for(int i = 1; i<5; i++)
        {
            for(int j = 0; j<7 && daynum<32; j++)
            {
                QLabel *label = new QLabel(QString::number(daynum),this);
                label->setMinimumSize(25,15);
                lightToday(year,monthnum,daynum,label);
                gridlayout2->addWidget(label,i,j);
                daynum++;
            }
        }
    }else if(month31 == false)
    {
        monthDay_Start =searchDayWeek_month(monthnum, rn4);
        daynum = monthDay_Start;
        for(int i = 1; i<5; i++)
        {
            for(int j = 0; j<7 && daynum<31; j++)
            {
                QLabel *label = new QLabel(QString::number(daynum),this);
                label->setMinimumSize(25,15);
                lightToday(year,monthnum,daynum,label);
                gridlayout2->addWidget(label,i,j);
                daynum++;
            }
        }
    }


    vlayout = new QVBoxLayout;
    vlayout->addLayout(gridlayout0);
    vlayout->addLayout(gridlayout1);
    vlayout->addLayout(gridlayout2);
    setLayout(vlayout);
}




bool MyMonth::isLeapYear(int year4th)
{
    if(year4th%400 == 0)
    {
        rn4= true;
    }else if(year4th %4 == 0)
    {
        rn4 = true;
    }
    return rn4;
}



int MyMonth::searchDayWeek(int searchyear)
{
    int yeargap_temp = searchyear - 1901;
    int LeapYears = yeargap_temp/4;//距离1900年1月1日有多少个闰年；
    int yeargap = searchyear -1900;
    int days = LeapYears*366+ (yeargap-LeapYears)*365 + 1;//计算到查询年一月一号过了多少天。

    int weekDay = days%7;
    return weekDay;
}


int MyMonth::searchDayWeek_month(int yuefen, bool isLeap)
{
    int daynuminit = 1;
    if(yuefen ==1)
    {
        for(int j=weekDay-1; j!=7; j++)
        {
            QLabel *label = new QLabel(QString::number(daynuminit),this);
            label->setMinimumSize(25,15);
            lightToday(year,monthnum,daynum,label);
            gridlayout2->addWidget(label,0,j);
            daynuminit++;
        }
        return daynuminit;
    }
    //先计算这个月份1号 距离 该年 1月1号多少天
    QVector<int> days_vec= {0,31,59,90,120,151,181,212,243,273,304,334,365};


    if(isLeap == false)
    {
        int monthgap = days_vec[yuefen-1]%7;
        int monthstart =monthgap+ weekDay;
        if(monthstart>7)
            monthstart =  monthstart-7;

        for(int j=monthstart-1; j!=7; j++)
        {
            QLabel *label = new QLabel(QString::number(daynuminit),this);
            label->setMinimumSize(25,15);
            lightToday(year,monthnum,daynum,label);
            gridlayout2->addWidget(label,0,j);
            daynuminit++;
        }
        return daynuminit;
    }

    if(isLeap ==true)
    {
        for(auto i=2;i!=13;i++)
            days_vec[i]++;

        int monthgap = days_vec[yuefen-1]%7;
        int monthstart =monthgap+ weekDay;
        if(monthstart>7)
            monthstart =  monthstart-7;

        for(int j=monthstart-1; j!=7; j++)
        {
            QLabel *label = new QLabel(QString::number(daynuminit),this);
            label->setMinimumSize(25,15);
            lightToday(year,monthnum,daynum,label);
            gridlayout2->addWidget(label,0,j);
            daynuminit++;
        }
        return daynuminit;
    }
}


void MyMonth::lightToday(int year, int month,int day, QLabel *lightLabel)
{
    QDateTime Nowtime = QDateTime::currentDateTime();
    QString time_str = Nowtime.toString("yyyy-MM-dd");
    int nowyear = time_str.mid(0,4).toInt();
    int nowmonth = time_str.mid(5,2).toInt();
    int nowday = time_str.mid(8,2).toInt();

    QPalette pe;
    pe.setColor(QPalette::WindowText,Qt::red);

    QFont font;
    font.setBold(true);

    if(nowyear == year && nowmonth ==month &&nowday ==day)
    {
        lightLabel->setPalette(pe);
        lightLabel->setFont(font);
        //lightLabel->setStyle();
    }

}
