#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QHBoxLayout>
#include <QLabel>
#include <QTimer>
#include <QToolButton>
#include <QWidget>

class TitleBar : public QWidget
{
    Q_OBJECT
public:
    explicit TitleBar(QWidget *parent = 0);

    //设置标题栏背景色
    void setBackgroundColor(int r, int g, int b);
    //设置标题栏图标
    void setTitleIcon(QString filePath, QSize IconSize = QSize(25, 25));
    //设置标题栏内容
    void setTitleContent(QString titleContent);
    //设置标题栏长度
    void setTitleWidth(int width);
    // 设置窗口边框宽度;
    void setWindowBorderWidth(int borderWidth);
    // 设置标题栏边距
    void setMargins(int left, int top, int right, int bottom);
    // 设置标题栏字体样式
    void setTextStyle(QString style);
    // 设置标题栏对齐方式
    void setAlignment(Qt::Alignment align);

signals:
    void signalClose();

private:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    //控件初始化
    void init();

private:
    QLabel *m_icon{nullptr};   // 标题栏图标;
    QLabel *m_title{nullptr};  // 标题栏内容;
    QWidget *m_parent{nullptr};
    QHBoxLayout *m_layout{nullptr};

    // 标题栏背景色;
    int m_color_r;
    int m_color_g;
    int m_color_b;

    // 移动窗口的变量;
    bool m_is_pressed;
    QPoint m_start_move_pos;

    // 标题栏内容;
    QString m_title_content;

    // 窗口边框宽度;
    int m_window_border_width;
};
#endif  // TITLEBAR_H
