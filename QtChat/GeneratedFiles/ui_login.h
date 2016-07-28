/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLineEdit *user;
    QLineEdit *password;
    QLabel *label;
    QLabel *label_2;
    QPushButton *signup;
    QPushButton *signin;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(270, 213);
        user = new QLineEdit(Login);
        user->setObjectName(QStringLiteral("user"));
        user->setGeometry(QRect(90, 50, 141, 23));
        password = new QLineEdit(Login);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(90, 100, 141, 23));
        password->setEchoMode(QLineEdit::Password);
        label = new QLabel(Login);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 50, 41, 16));
        label_2 = new QLabel(Login);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 100, 31, 16));
        signup = new QPushButton(Login);
        signup->setObjectName(QStringLiteral("signup"));
        signup->setGeometry(QRect(30, 150, 80, 23));
        signin = new QPushButton(Login);
        signin->setObjectName(QStringLiteral("signin"));
        signin->setGeometry(QRect(150, 150, 80, 23));

        retranslateUi(Login);
        QObject::connect(signin, SIGNAL(clicked()), Login, SLOT(clicksignin()));
        QObject::connect(signup, SIGNAL(clicked()), Login, SLOT(clicksignup()));

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "\347\231\273\345\275\225\347\225\214\351\235\242", 0));
        label->setText(QApplication::translate("Login", "\347\224\250\346\210\267\345\220\215", 0));
        label_2->setText(QApplication::translate("Login", "\345\257\206\347\240\201", 0));
        signup->setText(QApplication::translate("Login", "\346\263\250\345\206\214", 0));
        signin->setText(QApplication::translate("Login", "\347\231\273\345\275\225", 0));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
