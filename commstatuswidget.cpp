#include "commstatuswidget.h"
#include "ui_commstatuswidget.h"


StatusItem::StatusItem(const QString &name, bool open, QWidget *parent) : QWidget(parent)
{
    auto horizontalLayout = new QHBoxLayout(this);
    horizontalLayout->setContentsMargins(0, 0, 0, 0);
    m_status_icon = new QLabel;
    horizontalLayout->addWidget(m_status_icon);

    setStatus(open);
    m_status_icon->setToolTip(name);
}

void StatusItem::setStatus(bool is_connect)
{
    QString icon_path = ":/uiframe/images/status_widget/off.svg";
    if (is_connect)
    {
        icon_path = ":/uiframe/images/status_widget/on.svg";
    }
    m_status_icon->setPixmap(QPixmap(icon_path));
}

CommStatusWidget::CommStatusWidget(QWidget *parent) : QWidget(parent), ui(new Ui::CommStatusWidget)
{
    ui->setupUi(this);
    ui->status_widget->setTitle(tr("Communication"));
    ui->status_widget->setIcon(":/uiframe/images/config/communication_icon.svg");
}

CommStatusWidget::~CommStatusWidget()
{
    delete ui;
}

void CommStatusWidget::changeEvent(QEvent *e)  //重写的事件处理方法
{
    QWidget::changeEvent(e);  //让基类执行事件处理方法
    switch (e->type())
    {
        case QEvent::LanguageChange:  //如果是语言改变事件
            if (ui)
            {
                ui->retranslateUi(this);  //更新UI的语言
                ui->status_widget->setTitle(tr("Communication"));
            }
            break;
        default:
            break;
    }
}


