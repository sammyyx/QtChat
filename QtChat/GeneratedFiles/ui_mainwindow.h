/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainwindow
{
public:
    QHBoxLayout *mainwindowlayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QTextEdit *TextEdit_RecvMsg;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QFontComboBox *Comb_Font;
    QLabel *label_3;
    QSpinBox *SBox_FontSize;
    QCheckBox *CB_Italic;
    QCheckBox *CB_Bold;
    QPushButton *Buttom_Color;
    QTextEdit *TextEdit_SendMsg;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *Buttom_Send;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QListWidget *listWidget_OnMembers;

    void setupUi(QWidget *mainwindow)
    {
        if (mainwindow->objectName().isEmpty())
            mainwindow->setObjectName(QStringLiteral("mainwindow"));
        mainwindow->setEnabled(true);
        mainwindow->resize(777, 459);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mainwindow->sizePolicy().hasHeightForWidth());
        mainwindow->setSizePolicy(sizePolicy);
        mainwindow->setAutoFillBackground(false);
        mainwindowlayout = new QHBoxLayout(mainwindow);
        mainwindowlayout->setObjectName(QStringLiteral("mainwindowlayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        TextEdit_RecvMsg = new QTextEdit(mainwindow);
        TextEdit_RecvMsg->setObjectName(QStringLiteral("TextEdit_RecvMsg"));
        TextEdit_RecvMsg->setUndoRedoEnabled(true);
        TextEdit_RecvMsg->setReadOnly(true);
        TextEdit_RecvMsg->setAcceptRichText(true);
        TextEdit_RecvMsg->setTextInteractionFlags(Qt::NoTextInteraction);

        verticalLayout->addWidget(TextEdit_RecvMsg);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(mainwindow);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label);

        Comb_Font = new QFontComboBox(mainwindow);
        Comb_Font->setObjectName(QStringLiteral("Comb_Font"));
        sizePolicy.setHeightForWidth(Comb_Font->sizePolicy().hasHeightForWidth());
        Comb_Font->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(Comb_Font);

        label_3 = new QLabel(mainwindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label_3);

        SBox_FontSize = new QSpinBox(mainwindow);
        SBox_FontSize->setObjectName(QStringLiteral("SBox_FontSize"));

        horizontalLayout_2->addWidget(SBox_FontSize);

        CB_Italic = new QCheckBox(mainwindow);
        CB_Italic->setObjectName(QStringLiteral("CB_Italic"));

        horizontalLayout_2->addWidget(CB_Italic);

        CB_Bold = new QCheckBox(mainwindow);
        CB_Bold->setObjectName(QStringLiteral("CB_Bold"));

        horizontalLayout_2->addWidget(CB_Bold);

        Buttom_Color = new QPushButton(mainwindow);
        Buttom_Color->setObjectName(QStringLiteral("Buttom_Color"));

        horizontalLayout_2->addWidget(Buttom_Color);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 10);
        horizontalLayout_2->setStretch(2, 1);
        horizontalLayout_2->setStretch(3, 5);

        verticalLayout->addLayout(horizontalLayout_2);

        TextEdit_SendMsg = new QTextEdit(mainwindow);
        TextEdit_SendMsg->setObjectName(QStringLiteral("TextEdit_SendMsg"));

        verticalLayout->addWidget(TextEdit_SendMsg);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        Buttom_Send = new QPushButton(mainwindow);
        Buttom_Send->setObjectName(QStringLiteral("Buttom_Send"));
        sizePolicy.setHeightForWidth(Buttom_Send->sizePolicy().hasHeightForWidth());
        Buttom_Send->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(Buttom_Send);

        horizontalLayout_4->setStretch(0, 2);

        verticalLayout->addLayout(horizontalLayout_4);

        verticalLayout->setStretch(0, 20);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 10);
        verticalLayout->setStretch(3, 1);

        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_2 = new QLabel(mainwindow);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_3->addWidget(label_2);


        verticalLayout_2->addLayout(verticalLayout_3);

        listWidget_OnMembers = new QListWidget(mainwindow);
        listWidget_OnMembers->setObjectName(QStringLiteral("listWidget_OnMembers"));

        verticalLayout_2->addWidget(listWidget_OnMembers);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 20);

        horizontalLayout->addLayout(verticalLayout_2);

        horizontalLayout->setStretch(0, 4);
        horizontalLayout->setStretch(1, 1);

        mainwindowlayout->addLayout(horizontalLayout);


        retranslateUi(mainwindow);
        QObject::connect(Buttom_Color, SIGNAL(clicked()), mainwindow, SLOT(openColorSetting()));
        QObject::connect(Buttom_Send, SIGNAL(clicked()), mainwindow, SLOT(updateViewText()));

        QMetaObject::connectSlotsByName(mainwindow);
    } // setupUi

    void retranslateUi(QWidget *mainwindow)
    {
        mainwindow->setWindowTitle(QApplication::translate("mainwindow", "\347\276\244\350\201\212", 0));
        label->setText(QApplication::translate("mainwindow", "\345\255\227\344\275\223", 0));
        label_3->setText(QApplication::translate("mainwindow", "\345\255\227\344\275\223\345\244\247\345\260\217", 0));
        CB_Italic->setText(QApplication::translate("mainwindow", "\346\226\234\344\275\223", 0));
        CB_Bold->setText(QApplication::translate("mainwindow", "\345\212\240\347\262\227", 0));
        Buttom_Color->setText(QApplication::translate("mainwindow", "\351\242\234\350\211\262\350\256\276\347\275\256", 0));
        Buttom_Send->setText(QApplication::translate("mainwindow", "\345\217\221\351\200\201", 0));
        label_2->setText(QApplication::translate("mainwindow", "\345\234\250\347\272\277\347\224\250\346\210\267", 0));
    } // retranslateUi

};

namespace Ui {
    class mainwindow: public Ui_mainwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
