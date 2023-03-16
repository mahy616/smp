#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SMP.h"
#include "station.h"
#include "commstatuswidget.h"
#include "titlebarwidget.h"
#include "statisticswidget.h"
class SMP : public QMainWindow
{
    Q_OBJECT

public:
    SMP(QWidget *parent = Q_NULLPTR);


private:
	void init();
	void initWidgets();
	void initConnects();

private:
    Ui::SMPClass *ui;
	TitleBarWidget *m_titlebar_widget{ nullptr };
	QGridLayout *m_ImagesWindow{ nullptr };
	station *m_station{ nullptr };
	CommStatusWidget *m_comm_widget{ nullptr };
	StatisticsWidget *m_statistics_widget{ nullptr };
};
