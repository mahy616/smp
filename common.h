
#ifndef COMMON_H
#define COMMON_H

#include <QApplication>
#include <QDebug>
#include <QFile>
#include <QImage>
#include <QSettings>
#include <QUuid>
#include <opencv2/opencv.hpp>

#ifdef Q_OS_WINDOWS
#include <filesystem>
using namespace std::filesystem;
#elif defined(Q_OS_LINUX)
#include <experimental/filesystem>
using namespace std::experimental::filesystem;
#endif

struct IntegratedAlgoResult
{
    size_t elapsed_time{0};
    size_t total_elapsed_time{0};
    cv::Mat image;
    std::vector<cv::Mat> ai_images;
    std::vector<std::string> lab_names;
    
};
class Message : public QObject
{
    Q_OBJECT
public:
    enum MessageType
    {
        info = 0,
        warning,
        error
    };

    static Message &getInstance()
    {
        static Message s_message;
        return s_message;
    }
    static void postInfoMessage(const QString &msg)
    {
        emit getInstance().signalPostMessage(msg, MessageType::info);
    }

    static void postWarningMessage(const QString &msg)
    {
        emit getInstance().signalPostMessage(msg, MessageType::warning);
    }

    static void postErrorMessage(const QString &msg)
    {
        emit getInstance().signalPostMessage(msg, MessageType::error);
    }

signals:
    void signalPostMessage(const QString &msg, Message::MessageType type);

private:
    Message()
    {
        qRegisterMetaType<Message::MessageType>("vilab::common::Message::MessageType");
    }
};

class ImageListForwarder : public QObject
{
    Q_OBJECT
public:
    struct ImageInfo
    {
        std::string image_path;
        std::string image_uuid;
    };
    static ImageListForwarder &getInstance()
    {
        static ImageListForwarder s_forwarder;
        return s_forwarder;
    }

signals:
    void signalPostImageListInfo(const std::string &view_uuid, const std::vector<ImageInfo> &image_info_list);

private:
    ImageListForwarder() = default;
};


  // namespace vilab::common

#endif  // VILABCOMMON_H
