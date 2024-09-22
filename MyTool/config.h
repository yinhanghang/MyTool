#ifndef CONFIG_H
#define CONFIG_H
#include <QFile>
#include <QSettings>//配置文件相关设置
#include <QTranslator>
#include <QTextCodec>
#include <QCoreApplication>
#include <QDebug>
#define  SETTINGFILE "./config/config.ini"


class Config
{
public:
    Config();
public:
    void RW_Default_settings();//写入默认设置
    void APPINFO();//程序的版本信息

public:
    QSettings settings=QSettings(SETTINGFILE, QSettings::IniFormat);

};

#endif // CONFIG_H
