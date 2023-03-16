#pragma once

#include <QWidget>
#include "ui_ImageWindow.h"
#include "qmessagebox.h"
#include <QFileDialog>
#include <QDirIterator>
#include <QAction>
#include <QMenu>
#include <QResizeEvent>

// ͼ�񴰿����Ͻ�Ok/Ng��logo
typedef struct LabelOkNg_Info
{
	QLabel* Label_OkNg;
	int OldWidth;
	int OldHeight;
	const int LabelWidth = 50;
	const int LabelHeight = 50;
}LabelOkNg_Info;

class ImageWindow : public QWidget
{
	Q_OBJECT
public:
	// WindowIndex��ǰStaion��ID ��inShowFlag�Ƿ���ʾOK/Ng���
	ImageWindow(int WindowIndex, QWidget *parent = nullptr);
	~ImageWindow();
	// ��StaionID�ı�ʱ�޸ı���
private:
	Ui::ImageWindowClass ui;
	int m_windowIndex;             //��ǰ���ڵ�StaionID
	LabelOkNg_Info m_LabelOkNg;     //��ǰͼ�񴰿����Ͻ�Ok/Ng��logo
	QMenu* buttonMenu = nullptr;    //�˵���
private:
	void InintMenu();                       //��ʼ���˵���
	void InintConnection();


signals:
	void AddWindowSignal();  //��Ӵ����ź�
signals:
	void SendCloseEvent(int);//ɾ�������ź�
};
