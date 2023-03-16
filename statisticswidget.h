﻿#ifndef STATISTICSWIDGET_H
#define STATISTICSWIDGET_H

#include <QWidget>

namespace Ui
{
class StatisticsWidget;
}


class StatisticsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StatisticsWidget(QWidget *parent = nullptr);
    ~StatisticsWidget();

protected:
    void changeEvent(QEvent *e) override;

private slots:
    void on_reset_btn_clicked();
    void on_export_btn_clicked();

private:
    void init();
    void initWidgets();
    void initConnects();
    void updateStatisticsResult();

private:
    Ui::StatisticsWidget *ui;
    size_t m_total_counts{0};
    size_t m_ng_counts{0};
    size_t m_ok_counts{0};
    float m_pass_percent{0.0000f};

};

#endif  // STATISTICSWIDGET_H
