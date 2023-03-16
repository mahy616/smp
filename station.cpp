#include "station.h"

station::station(int index_window)
{
	init(index_window);
}

station::~station()
{
}

void station::init(int index_window)
{
	initWindow(index_window);
	initConnects();
}

void station::initWindow(int index_window)
{
	m_window = new ImageWindow(index_window);

}

void station::initConnects()
{
}
