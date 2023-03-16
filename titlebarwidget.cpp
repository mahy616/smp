#include "titlebarwidget.h"
#include "ui_titlebarwidget.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QMainWindow>
#include <QMouseEvent>
#include "configdialog.h"
TitleBarWidget::TitleBarWidget(QWidget *parent) : QWidget(parent), ui(new Ui::TitleBarWidget), m_parent(parent)
{
    init();
}

TitleBarWidget::TitleBarWidget(const QString &project_name, const QString &logo_path, QWidget *parent)
    : QWidget(parent), ui(new Ui::TitleBarWidget), m_project_name(project_name), m_logo_path(logo_path),
      m_parent(parent)
{
    init();
}

TitleBarWidget::~TitleBarWidget()
{
    delete ui;
}


void TitleBarWidget::mousePressEvent(QMouseEvent *event)
{
    m_start_move_pos = event->globalPos();
    return QWidget::mousePressEvent(event);
}

void TitleBarWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (!property("maximum").toBool())
    {
        auto move_point = event->globalPos() - m_start_move_pos;
        auto widget_pos = m_parent->pos();
        m_start_move_pos = event->globalPos();
        m_parent->move(widget_pos.x() + move_point.x(), widget_pos.y() + move_point.y());
    }
    return QWidget::mouseMoveEvent(event);
}

void TitleBarWidget::mouseReleaseEvent(QMouseEvent *event)
{
    return QWidget::mouseReleaseEvent(event);
}

void TitleBarWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    auto checked = ui->maximum_btn->isChecked();
    on_maximum_btn_clicked(!checked);
    ui->maximum_btn->setChecked(!checked);
    return QWidget::mouseDoubleClickEvent(event);
}

void TitleBarWidget::init()
{
    initWidgets();
    initConnects();
}

void TitleBarWidget::initWidgets()
{
    ui->setupUi(this);
    ui->project_name_lab->setText(m_project_name);
    ui->logo_lab->setPixmap(QPixmap(m_logo_path));
    setProperty("maximum", false);
}

void TitleBarWidget::initConnects()
{
    //m_config_changed.addObserver([&] { updateTitle(); });
}

void TitleBarWidget::on_settings_btn_clicked()
{
    ConfigDialog config_dialog;
    if (config_dialog.exec() == QDialog::Accepted)
    {
      //  vilab::config::ConfigManager::saveToFile();
    }
    else
    {
        //vilab::config::ConfigManager::loadFromFile();
    }
}

void TitleBarWidget::on_lang_btn_clicked()
{
    emit signalChangeLang();
}

void TitleBarWidget::on_about_btn_clicked()
{
    //AboutDialog about_dialog;
    //about_dialog.exec();
}

void TitleBarWidget::on_minimum_btn_clicked()
{
    if (m_parent)
        m_parent->showMinimized();
}

void TitleBarWidget::on_maximum_btn_clicked(bool checked)
{
    if (m_parent)
    {
        if (checked)
        {
            m_parent_last_rect = m_parent->geometry();
            auto desktop_rect = QApplication::desktop()->availableGeometry();
            auto rect = QRect(desktop_rect.x(), desktop_rect.y(), desktop_rect.width(), desktop_rect.height());
            m_parent->setGeometry(rect);
            setProperty("maximum", true);
        }
        else
        {
            m_parent->setGeometry(m_parent_last_rect);
            setProperty("maximum", false);
        }
    }
}

void TitleBarWidget::on_close_btn_clicked()
{
    if (m_parent)
        m_parent->close();
}

void TitleBarWidget::updateTitle()
{
    //m_project_name = QString::fromLocal8Bit(ConfigManager::getInstance().getSystemConfigData().app_name.c_str());
    //ui->project_name_lab->setText(m_project_name);
    //m_logo_path = QString::fromLocal8Bit(ConfigManager::getInstance().getSystemConfigData().logo_path.c_str());
    //ui->logo_lab->setPixmap(QPixmap(m_logo_path));
}

void TitleBarWidget::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type())
    {
        case QEvent::LanguageChange:
            if (ui)
                ui->retranslateUi(this);
            break;
        default:
            break;
    }
}

