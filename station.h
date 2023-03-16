#pragma once

#include <QWidget>
#include "ImageWindow.h"

class station : public QObject
{
	Q_OBJECT

public:
	station(int index_window);
	~station();
	void init(int index_window);
	void initWindow(int index_window);
	void initConnects();
public:
	ImageWindow *m_window{ nullptr };
};

