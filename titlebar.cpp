#include "titlebar.h"
#include <QApplication>
#include <QDebug>
#include <QEvent>
#include <QFile>
#include <QMouseEvent>
#include <QPainter>

#define BUTTON_HEIGHT 20  // 按钮高度;
#define BUTTON_WIDTH 20  // 按钮宽度;
#define TITLE_HEIGHT 30  // 标题栏高度;

TitleBar::TitleBar(QWidget *parent)
    : QWidget(parent), m_parent(parent), m_color_r(153), m_color_g(153), m_color_b(153), m_is_pressed(false),
      m_window_border_width(0)
{
    init();
}

void TitleBar::init()
{
    m_icon = new QLabel(this);
    m_title = new QLabel(this);

    m_title->setObjectName("TitleContent");
    m_title->setAlignment(Qt::AlignCenter);
    m_title->setStyleSheet("color: rgba(0,0,0,0.8); font-size: 16px;");
    m_title->setText(tr("Settings"));
    m_title->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    m_layout = new QHBoxLayout(this);
    m_layout->addWidget(m_title);
    m_layout->setSpacing(0);
    m_layout->setContentsMargins(10, 0, 10, 0);

    this->setWindowFlags(Qt::FramelessWindowHint);

    setBackgroundColor(233, 238, 242);
}

void TitleBar::setBackgroundColor(int r, int g, int b)
{
    // 标题栏背景色;
    m_color_r = r;
    m_color_g = g;
    m_color_b = b;

    update();
}

void TitleBar::setTitleIcon(QString filePath, QSize IconSize)
{
    QPixmap titleIcon(filePath);
    m_icon->setPixmap(titleIcon.scaled(IconSize));
}

void TitleBar::setTitleContent(QString titleContent)
{
    m_title->setText(titleContent);
    m_title_content = titleContent;
}

void TitleBar::setTitleWidth(int width)
{
    this->setFixedWidth(width);
}

void TitleBar::setWindowBorderWidth(int borderWidth)
{
    m_window_border_width = borderWidth;
}

void TitleBar::setMargins(int left, int top, int right, int bottom)
{
    m_layout->setContentsMargins(left, top, right, bottom);
}

void TitleBar::setTextStyle(QString style)
{
    m_title->setStyleSheet(style);
}

void TitleBar::setAlignment(Qt::Alignment align)
{
    m_title->setAlignment(align);
}

void TitleBar::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPainterPath pathBack;
    pathBack.setFillRule(Qt::WindingFill);
    pathBack.addRoundedRect(QRect(0, 0, this->width(), this->height()), 3, 3);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.fillPath(pathBack, QBrush(QColor(m_color_r, m_color_g, m_color_b)));
    if (this->width() != (this->parentWidget()->width() - m_window_border_width))
    {
        this->setFixedWidth(this->parentWidget()->width() - m_window_border_width);
    }

    QWidget::paintEvent(event);
}

void TitleBar::mousePressEvent(QMouseEvent *event)
{
    m_is_pressed = true;
    m_start_move_pos = event->globalPos();

    return QWidget::mousePressEvent(event);
}

void TitleBar::mouseMoveEvent(QMouseEvent *event)
{
    if (m_is_pressed)
    {
        QPoint movePoint = event->globalPos() - m_start_move_pos;
        QPoint widgetPos = m_parent->pos();
        m_start_move_pos = event->globalPos();
        m_parent->move(widgetPos.x() + movePoint.x(), widgetPos.y() + movePoint.y());
    }
    return QWidget::mouseMoveEvent(event);
}

void TitleBar::mouseReleaseEvent(QMouseEvent *event)
{
    m_is_pressed = false;
    return QWidget::mouseReleaseEvent(event);
}

