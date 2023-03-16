#include "common.h"
#include <QProcess>
#include <QTextCodec>
#include <ctime>
#include <memory>


std::string currentTime(const std::string &format)
{
    time_t time_seconds = time(nullptr);
    struct tm now_time;
#ifdef Q_OS_WIN
    localtime_s(&now_time, &time_seconds);
#else
    localtime_r(&time_seconds, &now_time);
#endif

    std::array<char, 32> buff;
    strftime(buff.data(), buff.size(), format.c_str(), &now_time);
    return std::string(buff.data());
}

QImage matToQImage(const cv::Mat &mat)
{
    QImage image;
    auto channels = mat.channels();
    if (channels == 3)  // RGB image
    {
        image = QImage((const uchar *)(mat.data), mat.cols, mat.rows, mat.cols * mat.channels(), QImage::Format_RGB888)
                    .rgbSwapped();
    }
    else if (channels == 4)  // RGBA image
    {
        image = QImage((const uchar *)(mat.data), mat.cols, mat.rows, mat.cols * mat.channels(), QImage::Format_RGB32);
    }
    else  // gray image
    {
        image =
            QImage((const uchar *)(mat.data), mat.cols, mat.rows, mat.cols * mat.channels(), QImage::Format_Indexed8);
    }
    return image;
}



 // namespace vilab::common
