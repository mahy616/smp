#ifndef COMMSTATUSWIDGET_H
#define COMMSTATUSWIDGET_H

#include <QLabel>
#include <QWidget>

namespace Ui
{
class CommStatusWidget;
}



class StatusItem : public QWidget
{
    Q_OBJECT
public:
    StatusItem(const QString &name, bool open, QWidget *parent = nullptr);
    ~StatusItem() = default;

private:
    void setStatus(bool is_connect);

    QLabel *m_status_icon;
};

class CommStatusWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CommStatusWidget(QWidget *parent = nullptr);
    ~CommStatusWidget();


protected:
    void changeEvent(QEvent *e) override;

private:
    Ui::CommStatusWidget *ui;
};

  // namespace vilab::display
#endif  // COMMSTATUSWIDGET_H
