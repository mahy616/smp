#include "configdialog.h"
//#include "savesetting/savesettingpage.h"
#include "ui_configdialog.h"
#include <QGraphicsDropShadowEffect>



ConfigDialogTab::ConfigDialogTab(const QString &tab_name, const QString &icon_style, QWidget *parent) : QWidget(parent)
{
    auto tab_layout = new QHBoxLayout(this);
    tab_layout->setContentsMargins(20, 0, 20, 0);
    tab_layout->setSpacing(10);
    QLabel *tab_icon = new QLabel();
    QLabel *tab_text = new QLabel();
    tab_text->setObjectName("tab_text");
    tab_text->setText(tab_name);
    tab_text->setStyleSheet("color: rgba(0, 0, 0, 0.80); font-size: 14px;");
    tab_icon->setFixedSize(20, 20);
    tab_icon->setStyleSheet(icon_style);
    tab_layout->addWidget(tab_icon);
    tab_layout->addWidget(tab_text);
}

ConfigDialog::ConfigDialog(QWidget *parent) : QDialog(parent), ui(new Ui::ConfigDialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
    setWindowModality(Qt::ApplicationModal);

    // add box shadow
    this->setAttribute(Qt::WA_TranslucentBackground);
    QGraphicsDropShadowEffect *pEffect = new QGraphicsDropShadowEffect(ui->frame);
    pEffect->setOffset(0, 0);
    pEffect->setColor(QColor(100, 100, 100));
    pEffect->setBlurRadius(10);
    ui->frame->setGraphicsEffect(pEffect);
    ui->main_layout->setMargin(10);

    initWidgets();
    initConnections();
}

ConfigDialog::~ConfigDialog()
{
    delete ui;
}

void ConfigDialog::initWidgets()
{
    initTitleBar();

    if (qApp->property("lang") == "zh")
    {
        this->setFixedWidth(1120);
        ui->tabs->setFixedWidth(140);
    }
    else
    {
        this->setFixedWidth(1160);
        ui->tabs->setFixedWidth(180);
    }

    for (int i = ui->stack->count(); i >= 0; i--)
    {
        auto page_widget = ui->stack->widget(i);
        ui->stack->removeWidget(page_widget);
        delete page_widget;
    }

    createSettingWidgets();
    connect(ui->tab_list, &QListWidget::currentRowChanged, this, [&](int index) { switchPage(index); });

    for (int i = 0; i < ui->stack->count(); i++)
    {
        dynamic_cast<SettingPage *>(ui->stack->widget(i))->initConfigData();
    }

    ui->tab_list->setCurrentRow(0);
    ui->tab_list->viewport()->installEventFilter(this);
}

void ConfigDialog::createSettingWidgets()
{
    
    //createSettingWidget<SaveSettingPage>(tr("Save Setting"),
    //                                     "background-image:url(\":/uiframe/images/config/save_icon.svg\")");
}

template <typename PageType, typename... Args> void ConfigDialog::createSettingWidget(Args &&...args)
{
    auto item = new QListWidgetItem;
    item->setSizeHint(QSize(140, 40));
    ui->tab_list->addItem(item);
    ui->tab_list->setItemWidget(item, new ConfigDialogTab(std::forward<Args>(args)...));
    ui->stack->addWidget(new PageType(this));
}

void ConfigDialog::initConnections()
{
    connect(ui->confirm_btn, &QPushButton::clicked, this, [=] { saveConfig(); });
    connect(ui->cancel_btn, &QPushButton::clicked, this, [=] { cancelConfig(); });
}

void ConfigDialog::initTitleBar()
{
    m_titleBar = new TitleBar(this);
    ui->titlebar_layout->addWidget(m_titleBar);
}

void ConfigDialog::switchPage(int index)
{
    if (index == -1)
        return;
    // first validate current page
    int original_index = ui->stack->currentIndex();
    if (!validatePage(original_index))
    {
        ui->tab_list->setCurrentRow(original_index);
        return;
    }
    if (original_index != index)
    {
        dynamic_cast<SettingPage *>(ui->stack->widget(original_index))->saveConfigData();
    }
    ui->stack->setCurrentIndex(index);
}

bool ConfigDialog::validatePage(int index)
{
    auto page = dynamic_cast<SettingPage *>(ui->stack->widget(index));
    return page->validatePage();
}

void ConfigDialog::saveConfig()
{
    const auto current_index = ui->stack->currentIndex();
    if (!validatePage(current_index))
    {
       // ToastWidget::showErrorTip(tr("Save failed: You have invalid input."), this);
        return;
    }
    for (int i = 0; i < ui->stack->count(); i++)
    {
        dynamic_cast<SettingPage *>(ui->stack->widget(i))->saveConfigData();
    }
    accept();
}

void ConfigDialog::cancelConfig()
{
    reject();
}

bool ConfigDialog::eventFilter(QObject *wcg, QEvent *event)
{
    // 鼠标点击其他区域时，输入框失去焦点
    if (wcg == this && event->type() == QEvent::MouseButtonPress)
    {
        dynamic_cast<SettingPage *>(ui->stack->currentWidget())->disableFocus();
    }
    if (wcg == ui->tab_list->viewport())
    {
        if (event->type() == QEvent::MouseButtonPress || event->type() == QEvent::MouseButtonDblClick)
        {
            int index = ui->stack->currentIndex();
            auto page = dynamic_cast<SettingPage *>(ui->stack->widget(index));
            if (index != -1 && page && !page->validatePage())
            {
                event->ignore();
                return true;
            }
        }
    }

    return QWidget::eventFilter(wcg, event);
}
 // namespace vilab::display
