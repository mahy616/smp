#ifndef STATUSWIDGET_H
#define STATUSWIDGET_H

#include <QWidget>

namespace Ui
{
class StatusWidget;
}

class StatusWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StatusWidget(QWidget *parent = nullptr);
    ~StatusWidget();

    void setTitle(const QString &title);
    void setIcon(const QString &icon_path);
    void addItem(QWidget *item);
    void clearItems();
    void showBtn(bool show);
    int getItemCount();
    QWidget *getListItemWidget(int row);
    void setListWidth(int width);

signals:
    void signalShowList(const QPoint &pos);
    void signalHideList();

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;

private:
    Ui::StatusWidget *ui;
};

  // namespace vilab::display
#endif  // STATUSWIDGET_H
