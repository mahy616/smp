#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

//#include "titlebar.h"
#include <QDialog>
#include <QLabel>
#include <QWidget>
#include "settingpage.h"
#include "titlebar.h"
namespace Ui
{
class ConfigDialog;
}

class ConfigDialogTab : public QWidget
{
    Q_OBJECT
public:
    ConfigDialogTab(const QString &tab_name, const QString &icon_style, QWidget *parent = nullptr);
    ~ConfigDialogTab() = default;
};

class ConfigDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConfigDialog(QWidget *parent = nullptr);
    ~ConfigDialog();

signals:
    void signalCloseWaitingDialog();

protected:
    bool eventFilter(QObject *wcg, QEvent *event) override;

private:
    void initWidgets();
    void initConnections();
    void switchPage(int);
    void initTitleBar();
    bool validatePage(int);
    void saveConfig();
    void cancelConfig();
    void createSettingWidgets();

    template <typename PageType, typename... Args> void createSettingWidget(Args &&...args);

private:
    Ui::ConfigDialog *ui;
    TitleBar *m_titleBar{nullptr};
};
  // namespace vilab::display
#endif  // CONFIGDIALOG_H
