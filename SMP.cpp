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
	//m_ImagesWindow = new QGridLayout(ui->widget);
	//QVBoxLayout *layouts = new QVBoxLayout(this);

	//layouts->setContentsMargins(0, 0, 0, 0);
	m_station = new station(1);
	
	
	//layouts->addLayout(m_ImagesWindow);
	//ui->widget->setLayout(m_ImagesWindow);
	ui->layout->addWidget(m_station->m_window);

	//setWindowFlags(Qt::FramelessWindowHint);
}

void SMP::initConnects()
{
}
