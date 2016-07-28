#if _MSC_VER >= 1600  
#pragma execution_character_set("utf-8")  
#endif
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "server.h"
#include "csoftwareconfig.h"
#include "cdatabaseoperation.h"
#include <QWidget>
#include <QListWidgetItem>
#include <QListWidget>
#include <QMessageBox>
#include <qevent.h>
#include <QToolTip>


namespace Ui {
class mainwindow;
}
class mainwindow : public QWidget
{
    Q_OBJECT

private:
    Ui::mainwindow *ui;

public:
    ~mainwindow();

    explicit mainwindow(QWidget *parent = 0);

    void configWidgets();
    QString username;
    Server *server;
    CSoftwareConfig *sendMsgConfig;
    CSoftwareConfig *recvWidgetConfig;

public slots:

	void currentTextEditFontFamilyChanged(QFont currentFont);
	void currentTextEditFontPointSizeChanged(int value);
	void currentTextEditFontItaticChanged(int state);
	void currentTextEditFontBoldChanged(int state);
	void currentTextEditFontColorChanged(const QColor color);
    void updateFontStyle();
	void openColorSetting();
    void AddOnlineMember(QString username);
    void RemoveOnlineMember(QString username);
    void ShowMemberDetial(QListWidgetItem *item);
    void PointToPointChat(QListWidgetItem *item);
    void updateViewText();
    void GetSendInformationSlot();

signals:
    void SendInformationOKSignal(CSoftwareConfig config);

protected:
     void closeEvent(QCloseEvent *event) override;




};

#endif // MAINWINDOW_H
