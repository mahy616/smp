#pragma once

#include <QWidget>
#include "ui_ImageWindow.h"
#include "qmessagebox.h"
#include <QFileDialog>
#include <QDirIterator>
#include <QAction>
#include <QMenu>
#include <QResizeEvent>

// 图像窗口右上角Ok/Ng的logo
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
	// WindowIndex当前Staion的ID ；inShowFlag是否显示OK/Ng结果
	ImageWindow(int WindowIndex, QWidget *parent = nullptr);
	~ImageWindow();
	// 当StaionID改变时修改标题
private:
	Ui::ImageWindowClass ui;
	int m_windowIndex;             //当前窗口的StaionID
	LabelOkNg_Info m_LabelOkNg;     //当前图像窗口右上角Ok/Ng的logo
	QMenu* buttonMenu = nullptr;    //菜单栏
private:
	void InintMenu();                       //初始化菜单栏
	void InintConnection();


signals:
	void AddWindowSignal();  //添加窗口信号
signals:
	void SendCloseEvent(int);//删除窗口信号
};
