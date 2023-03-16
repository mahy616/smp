#include "ImageWindow.h"
#include <QMessageBox>
#include <QString>
#include <QPointer>

ImageWindow::ImageWindow(int WindowIndex, QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	m_windowIndex= WindowIndex;
	InintMenu();           //…Ë÷√≤Àµ•     
	InintConnection();
}

ImageWindow::~ImageWindow()
{

}


void ImageWindow::InintConnection()
{

}

void ImageWindow::InintMenu()
{
}

