#include "statisticswidget.h"
#include "ui_statisticswidget.h"
#include <QDateTime>
#include <QFileDialog>

StatisticsWidget::StatisticsWidget(QWidget *parent) : QWidget(parent), ui(new Ui::StatisticsWidget)
{
    init();
}

StatisticsWidget::~StatisticsWidget()
{
    delete ui;
}

void StatisticsWidget::on_reset_btn_clicked()
{
    m_total_counts = 0;
    m_ng_counts = 0;
    m_ok_counts = 0;
    m_pass_percent = 0.0000f;
    updateStatisticsResult();
}

void StatisticsWidget::init()
{
    initWidgets();
    initConnects();
}

void StatisticsWidget::initWidgets()
{
    ui->setupUi(this);
    updateStatisticsResult();
}

void StatisticsWidget::initConnects()
{
   
}

void StatisticsWidget::updateStatisticsResult()
{
    ui->total_counts_lab->setText(QString::number(m_total_counts));
    ui->pass_counts_lab->setText(QString::number(m_ok_counts));
    ui->fail_counts_lab->setText(QString::number(m_ng_counts));
    ui->percent_lab->setText(QString::number(m_pass_percent, 'f', 2) + "%");
}

void StatisticsWidget::changeEvent(QEvent *e)  //重写的事件处理方法
{
    QWidget::changeEvent(e);  //让基类执行事件处理方法
    switch (e->type())
    {
        case QEvent::LanguageChange:  //如果是语言改变事件
            if (ui)
                ui->retranslateUi(this);  //更新UI的语言
            break;
        default:
            break;
    }
}

void StatisticsWidget::on_export_btn_clicked()
{
   
}

  // namespace vilab::display
