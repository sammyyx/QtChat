﻿#if _MSC_VER >= 1600  
#pragma execution_character_set("utf-8")  
#endif
#ifndef LOGIN_H
#define LOGIN_H
#include "mainwindow.h"
#include <QWidget>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    mainwindow *mw;
    ~Login();

private:
    Ui::Login *ui;

public slots:
    void clicksignin();
    void clicksignup();

};

#endif // LOGIN_H
