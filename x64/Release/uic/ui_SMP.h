/********************************************************************************
** Form generated from reading UI file 'SMP.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SMP_H
#define UI_SMP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SMPClass
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *titlebar_layout;
    QWidget *view_frame;
    QVBoxLayout *layout;
    QWidget *widget;
    QVBoxLayout *view_frame_layout;
    QHBoxLayout *toolbar_layout;
    QWidget *toolbar_widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QWidget *status_widget;
    QHBoxLayout *status_layout;
    QVBoxLayout *others_layout;

    void setupUi(QMainWindow *SMPClass)
    {
        if (SMPClass->objectName().isEmpty())
            SMPClass->setObjectName(QString::fromUtf8("SMPClass"));
        SMPClass->resize(1300, 800);
        centralwidget = new QWidget(SMPClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        titlebar_layout = new QHBoxLayout();
        titlebar_layout->setObjectName(QString::fromUtf8("titlebar_layout"));

        gridLayout->addLayout(titlebar_layout, 0, 0, 1, 2);

        view_frame = new QWidget(centralwidget);
        view_frame->setObjectName(QString::fromUtf8("view_frame"));
        layout = new QVBoxLayout(view_frame);
        layout->setSpacing(6);
        layout->setObjectName(QString::fromUtf8("layout"));
        layout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(view_frame);
        widget->setObjectName(QString::fromUtf8("widget"));
        view_frame_layout = new QVBoxLayout(widget);
        view_frame_layout->setSpacing(6);
        view_frame_layout->setObjectName(QString::fromUtf8("view_frame_layout"));
        view_frame_layout->setContentsMargins(0, 0, 0, 0);

        layout->addWidget(widget);


        gridLayout->addWidget(view_frame, 2, 0, 1, 1);

        toolbar_layout = new QHBoxLayout();
        toolbar_layout->setObjectName(QString::fromUtf8("toolbar_layout"));
        toolbar_layout->setContentsMargins(-1, -1, 4, -1);
        toolbar_widget = new QWidget(centralwidget);
        toolbar_widget->setObjectName(QString::fromUtf8("toolbar_widget"));
        toolbar_widget->setMinimumSize(QSize(0, 40));
        toolbar_widget->setMaximumSize(QSize(16777215, 40));
        horizontalLayout = new QHBoxLayout(toolbar_widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(925, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        status_widget = new QWidget(toolbar_widget);
        status_widget->setObjectName(QString::fromUtf8("status_widget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(status_widget->sizePolicy().hasHeightForWidth());
        status_widget->setSizePolicy(sizePolicy);
        status_widget->setMinimumSize(QSize(0, 0));
        status_layout = new QHBoxLayout(status_widget);
        status_layout->setSpacing(20);
        status_layout->setObjectName(QString::fromUtf8("status_layout"));
        status_layout->setContentsMargins(0, 0, 20, 0);

        horizontalLayout->addWidget(status_widget);


        toolbar_layout->addWidget(toolbar_widget);


        gridLayout->addLayout(toolbar_layout, 1, 0, 1, 1);

        others_layout = new QVBoxLayout();
        others_layout->setSpacing(4);
        others_layout->setObjectName(QString::fromUtf8("others_layout"));
        others_layout->setContentsMargins(-1, 0, -1, -1);

        gridLayout->addLayout(others_layout, 1, 1, 2, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 1);
        gridLayout->setRowStretch(2, 24);
        gridLayout->setColumnStretch(0, 3);
        gridLayout->setColumnStretch(1, 1);
        SMPClass->setCentralWidget(centralwidget);

        retranslateUi(SMPClass);

        QMetaObject::connectSlotsByName(SMPClass);
    } // setupUi

    void retranslateUi(QMainWindow *SMPClass)
    {
        SMPClass->setWindowTitle(QCoreApplication::translate("SMPClass", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SMPClass: public Ui_SMPClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMP_H
