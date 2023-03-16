#ifndef SETTINGPAGE_H
#define SETTINGPAGE_H
#include <QWidget>


class SettingPage : public QWidget
{
public:
    SettingPage(QWidget *parent = nullptr);
    virtual ~SettingPage() = default;

    /**
     * @brief 读取配置，初始化界面
     * @return
     */
    virtual void initConfigData() = 0;

    /**
     * @brief 取消配置，还原至上次保存的数据
     * @return
     */
    virtual void cancelConfigData() = 0;

    /**
     * @brief 保存配置
     * @return
     */
    virtual void saveConfigData() = 0;

    /**
     * @brief 判断页面是否有无效输入
     * @return
     */
    virtual bool validatePage() = 0;

    /**
     * @brief 取消输入框的Focus
     * @return
     */
    virtual void disableFocus() = 0;
};

  // namespace vilab::display
#endif  // SETTINGPAGE_H
