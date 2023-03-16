#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SMP.h"
#include "station.h"
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
	QGridLayout *m_ImagesWindow{ nullptr };
	station *m_station{ nullptr };
};
