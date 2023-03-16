#include "SMP.h"

SMP::SMP(QWidget *parent)
    : QMainWindow(parent)
	, ui(new Ui::SMPClass)
{
	init();
}

void SMP::init()
{
	initWidgets();
	initConnects();
} 

void SMP::initWidgets()
{
	ui->setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint);
	m_station = new station(1);
	ui->layout->addWidget(m_station->m_window);

	m_comm_widget = new CommStatusWidget();
	ui->status_layout->addWidget(m_comm_widget);

	m_titlebar_widget = new TitleBarWidget("SmartMore", ":/f/images/titlebar/logo.svg",this);
	ui->titlebar_layout->addWidget(m_titlebar_widget);

	m_statistics_widget = new StatisticsWidget;
	ui->others_layout->addWidget(m_statistics_widget);



}

void SMP::initConnects()
{
}
