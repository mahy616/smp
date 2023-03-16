#include "statuswidget.h"
#include "ui_statuswidget.h"

#include <QDebug>
#include <QTime>

StatusWidget::StatusWidget(QWidget *parent) : QWidget(parent), ui(new Ui::StatusWidget)
{
    ui->setupUi(this);
    ui->more_btn->installEventFilter(this);
}

StatusWidget::~StatusWidget()
{
    delete ui;
}

void StatusWidget::setTitle(const QString &title)
{
    ui->title->setText(title);
}

void StatusWidget::setIcon(const QString &icon_path)
{
    ui->icon->setPixmap(QPixmap(icon_path));
}

void StatusWidget::addItem(QWidget *item)
{
    auto list_item = new QListWidgetItem;
    list_item->setSizeHint(QSize(16, 16));
    ui->status_list->addItem(list_item);
    ui->status_list->setItemWidget(list_item, item);
}

void StatusWidget::clearItems()
{
    ui->status_list->clear();
}

void StatusWidget::showBtn(bool show)
{
    ui->more_btn->setVisible(show);
}

int StatusWidget::getItemCount()
{
    return ui->status_list->count();
}

QWidget *StatusWidget::getListItemWidget(int row)
{
    return ui->status_list->itemWidget(ui->status_list->item(row));
}

bool StatusWidget::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->more_btn)
    {
        switch (event->type())
        {
            case QEvent::HoverEnter:
                emit signalShowList(ui->more_btn->pos());
                break;
            case QEvent::HoverLeave:
            {
                emit signalHideList();
                break;
            }
            default:
                break;
        }
    }
    return false;
}

void StatusWidget::setListWidth(int width)
{
    ui->status_list->setFixedWidth(width);
}

  // namespace vilab::display
