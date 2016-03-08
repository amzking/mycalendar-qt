#ifndef MYMAINWD_H
#define MYMAINWD_H

#include <QMainWindow>
#include <QAction>
#include <QPushButton>
#include <QToolBar>
#include <QLabel>
#include "MyMonth.h"
#include "MyYear.h"
#include <QToolBar>
#include <QLineEdit>
#include <QSpacerItem>


class MyMainWD : public QMainWindow
{
    Q_OBJECT
public:
    explicit MyMainWD(QWidget *parent = 0);
        QLabel *currentYear;
        QLabel *yearShow;


signals:

public slots:
//    slot();


private slots:
    void slotclicked();


private:

    QToolBar *select;
    QLabel *xuanze;
    QLineEdit *year_input;
    QPushButton *button;


    QString yearstr;

    MyMonth *month;
    MyYear *year;


};

#endif // MYMAINWD_H
