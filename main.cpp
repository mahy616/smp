#include "SMP.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	QFile styleFile("://file/style/stylesheet.qss");
	styleFile.open(QFile::ReadOnly);
	QString style = QString::fromUtf8(styleFile.readAll());
	a.setStyleSheet(style);
	styleFile.close();
    SMP w;
    w.show();
    return a.exec();
}
