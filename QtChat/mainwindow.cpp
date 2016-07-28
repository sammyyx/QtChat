#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGlobal>
#include <QColorDialog>

#define MINIMUM_FONTSIZE 10
#define MAXIMUM_FONTSIZE 40

/* 初始化列表必须按照成员声明顺序，否则会出现错误 */
mainwindow::mainwindow(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::mainwindow),
	server(new Server),
	sendMsgConfig(new CSoftwareConfig),
	recvWidgetConfig(new CSoftwareConfig)
{
	ui->setupUi(this);

	/* 服务器和ui绑定 */
	ui->listWidget_OnMembers->setMouseTracking(true);
	connect(ui->Buttom_Send, SIGNAL(clicked()), this, SLOT(GetSendInformationSlot()));
	connect(this, SIGNAL(SendInformationOKSignal(CSoftwareConfig)), server, SLOT(SendProcess(CSoftwareConfig)));
	connect(server, SIGNAL(NewUsrOnline(QString)), this, SLOT(AddOnlineMember(QString)));
	connect(server, SIGNAL(OldUsrOffline(QString)), this, SLOT(RemoveOnlineMember(QString)));
	connect(ui->listWidget_OnMembers, SIGNAL(itemEntered(QListWidgetItem*)), this, SLOT(ShowMemberDetial(QListWidgetItem*)));
	connect(ui->listWidget_OnMembers, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(PointToPointChat(QListWidgetItem*)));

	connect(ui->SBox_FontSize, SIGNAL(valueChanged(int)), this, SLOT(currentTextEditFontPointSizeChanged(int)));
	connect(ui->Comb_Font, SIGNAL(currentFontChanged(QFont)), this, SLOT(currentTextEditFontFamilyChanged(QFont)));
	connect(ui->CB_Bold, SIGNAL(stateChanged(int)), this, SLOT(currentTextEditFontBoldChanged(int)));
	connect(ui->CB_Italic, SIGNAL(stateChanged(int)), this, SLOT(currentTextEditFontItaticChanged(int)));
	ui->SBox_FontSize->setMinimum(MINIMUM_FONTSIZE);
	ui->SBox_FontSize->setMaximum(MAXIMUM_FONTSIZE);
}

mainwindow::~mainwindow()
{
	/* 关闭窗口时，将窗口配置最后写入数据库，以更新 */
	QSqlQuery q;
	CDatabaseOperation::addUserConfig(q, username, sendMsgConfig->fontConfig.fontFamily, sendMsgConfig->fontConfig.fontPointSize,
		sendMsgConfig->fontConfig.colorR, sendMsgConfig->fontConfig.colorG, sendMsgConfig->fontConfig.colorB,
		sendMsgConfig->fontConfig.itatic, sendMsgConfig->fontConfig.bold);

	/* 释放堆资源 */
	delete ui;
	delete server;
	delete sendMsgConfig;
	delete recvWidgetConfig;
}

void mainwindow::currentTextEditFontFamilyChanged(QFont currentFont) {
	sendMsgConfig->fontConfig.fontFamily = currentFont.family();
	updateFontStyle();
}
void mainwindow::currentTextEditFontPointSizeChanged(int value) {
	sendMsgConfig->fontConfig.fontPointSize = value;
	updateFontStyle();
}
void mainwindow::currentTextEditFontItaticChanged(int state) {
	sendMsgConfig->fontConfig.itatic = (state == Qt::Checked ? true : false);
	updateFontStyle();
}
void mainwindow::currentTextEditFontBoldChanged(int state) {
	sendMsgConfig->fontConfig.bold = (state == Qt::Checked ? true : false);
	updateFontStyle();
}
void mainwindow::currentTextEditFontColorChanged(const QColor color) {
	color.getRgb(&sendMsgConfig->fontConfig.colorR, &sendMsgConfig->fontConfig.colorG, &sendMsgConfig->fontConfig.colorB);
	updateFontStyle();
}

void mainwindow::configWidgets() {
	QFont currentFont;
	currentFont.setFamily(sendMsgConfig->fontConfig.fontFamily);
	currentFont.setPointSize(sendMsgConfig->fontConfig.fontPointSize);
	currentFont.setItalic(sendMsgConfig->fontConfig.itatic);
	currentFont.setBold(sendMsgConfig->fontConfig.bold);
	ui->Comb_Font->setCurrentFont(currentFont);
	ui->TextEdit_SendMsg->setFont(currentFont);
	ui->SBox_FontSize->setValue(sendMsgConfig->fontConfig.fontPointSize);
	if (sendMsgConfig->fontConfig.itatic) {
		ui->CB_Italic->setCheckState(Qt::Checked);
	}
	if (sendMsgConfig->fontConfig.bold) {
		ui->CB_Bold->setCheckState(Qt::Checked);
	}
	QPalette pl = ui->TextEdit_SendMsg->palette();
	pl.setColor(QPalette::Text, QColor(sendMsgConfig->fontConfig.colorR, sendMsgConfig->fontConfig.colorG, sendMsgConfig->fontConfig.colorB));
	ui->TextEdit_SendMsg->setPalette(pl);
}

/*
 * 功能：更新输入框字体大小和样式
 * */
void mainwindow::updateFontStyle() {
	QFont currentFont;
	currentFont.setFamily(sendMsgConfig->fontConfig.fontFamily);
	currentFont.setPointSize(sendMsgConfig->fontConfig.fontPointSize);
	currentFont.setBold(sendMsgConfig->fontConfig.bold);
	currentFont.setItalic(sendMsgConfig->fontConfig.itatic);
	ui->TextEdit_SendMsg->setFont(currentFont);
	QPalette pl = ui->TextEdit_SendMsg->palette();
	pl.setColor(QPalette::Text, QColor(sendMsgConfig->fontConfig.colorR, sendMsgConfig->fontConfig.colorG, sendMsgConfig->fontConfig.colorB));
	ui->TextEdit_SendMsg->setPalette(pl);
}

/*
 * 功能：设置输入框字体颜色
 * */
void mainwindow::openColorSetting() {
	QColor currentColor = QColorDialog::getColor();
	currentTextEditFontColorChanged(currentColor);
}

void mainwindow::GetSendInformationSlot()
{
	qDebug("push send button,and get information");
	CSoftwareConfig config = *sendMsgConfig;
	emit SendInformationOKSignal(config);
}

void mainwindow::updateViewText() {
	QString sendContent = ui->TextEdit_SendMsg->toPlainText();
	if (sendContent == NULL) return;
	ui->TextEdit_RecvMsg->setTextBackgroundColor(Qt::GlobalColor::gray);
	ui->TextEdit_RecvMsg->setFontFamily("WenQuanYi Micro Hei");
	ui->TextEdit_RecvMsg->setFontPointSize(10);
	ui->TextEdit_RecvMsg->setFontItalic(false);
	ui->TextEdit_RecvMsg->setFontWeight(QFont::Thin);
	ui->TextEdit_RecvMsg->setTextColor(Qt::GlobalColor::black);
	QTime currentSendTime = QTime::currentTime();
	ui->TextEdit_RecvMsg->append(currentSendTime.toString());
	ui->TextEdit_RecvMsg->setAlignment(Qt::AlignCenter);
	ui->TextEdit_RecvMsg->setTextBackgroundColor(Qt::GlobalColor::gray);
	ui->TextEdit_RecvMsg->setFontFamily("WenQuanYi Micro Hei");
	ui->TextEdit_RecvMsg->setFontPointSize(10);
	ui->TextEdit_RecvMsg->setFontItalic(false);
	ui->TextEdit_RecvMsg->setFontWeight(QFont::Thin);
	ui->TextEdit_RecvMsg->setTextColor(Qt::GlobalColor::black);
	ui->TextEdit_RecvMsg->append(username + " 说:");
	ui->TextEdit_RecvMsg->setAlignment(Qt::AlignLeft);
	ui->TextEdit_RecvMsg->setTextBackgroundColor(Qt::GlobalColor::transparent);
	ui->TextEdit_RecvMsg->setFontFamily(sendMsgConfig->fontConfig.fontFamily);
	ui->TextEdit_RecvMsg->setFontPointSize(sendMsgConfig->fontConfig.fontPointSize);
	ui->TextEdit_RecvMsg->setFontItalic(sendMsgConfig->fontConfig.itatic);
	ui->TextEdit_RecvMsg->setFontWeight(sendMsgConfig->fontConfig.bold == true ? QFont::Bold : QFont::Thin);
	ui->TextEdit_RecvMsg->setTextColor(QColor(sendMsgConfig->fontConfig.colorR, sendMsgConfig->fontConfig.colorG, sendMsgConfig->fontConfig.colorB));
	ui->TextEdit_RecvMsg->append(sendContent);
	ui->TextEdit_RecvMsg->setAlignment(Qt::AlignLeft);
}

/*
 * 新用户上线更新
 * */
void mainwindow::AddOnlineMember(QString username)
{
	QListWidgetItem *newItem = new QListWidgetItem;
	newItem->setText(username);
	ui->listWidget_OnMembers->insertItem(0, newItem);
}
/*
 * 用户下线更新
 * */
void mainwindow::RemoveOnlineMember(QString username)
{
	QList<QListWidgetItem*> qlistItems = ui->listWidget_OnMembers->findItems(username, 0);
	QList<QListWidgetItem*>::iterator it = qlistItems.begin();
	if (it != qlistItems.end()) {
		ui->listWidget_OnMembers->removeItemWidget(*it);
		it++;
	}
}
/*
 * 显示用户详细信息
 * */
void mainwindow::ShowMemberDetial(QListWidgetItem *item)
{
	qDebug("show user detail");
	QString usrname = item->text();
	QString ip = server->mOnlineUsrMap->find(usrname).value().toString();
	QToolTip::showText(cursor().pos(), "username: " + usrname + "\n" + "IP：" + ip);

}
/* 建立私聊窗口
 * */
void mainwindow::PointToPointChat(QListWidgetItem *item)
{

}
/*
 * 关闭主窗口的时候进行提示，并发送广播退出消息
 * */
void mainwindow::closeEvent(QCloseEvent *event)
{
	QMessageBox msgBox;
	msgBox.setIcon(QMessageBox::Information);
	msgBox.setWindowTitle("提示");
	msgBox.setInformativeText("确定关闭所有聊天窗口吗？");
	QAbstractButton *discardButton = msgBox.addButton(tr("取消"), QMessageBox::ActionRole);
	QAbstractButton *okButton = msgBox.addButton(tr("确定"), QMessageBox::ActionRole);
	msgBox.exec();
	if (msgBox.clickedButton() == okButton) {
		server->LogoutBrocast(username);
		event->accept();
	}
	else if (msgBox.clickedButton() == discardButton)
		event->ignore();

}
