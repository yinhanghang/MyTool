#include "config.h"

Config::Config() {
    Config::settings.setIniCodec(QTextCodec::codecForName("UTF-8"));
}

void Config::RW_Default_settings()
{
    QFile settingfile(SETTINGFILE);//配置文件
    //键值对  只有值可以中文
    if(!settingfile.exists())//判断配置文件是否存在
    {
        settings.beginGroup("Info");//节名
        Config::settings.setValue("Name", "MyTool");
        Config::settings.setValue("Version", "V0.0.3");
        Config:: settings.endGroup();
        settings.beginGroup("i18n");//节名
        //en_US,zh_CN,zh_TW
        Config::settings.setValue("language", "zh_CN"); // 设置默认语言  键名  值名
        Config::settings.endGroup();
        Config::settings.beginGroup("proxy");//节名
        Config::settings.setValue("ip", "127.0.0.1"); // 设置键名  值名
        Config::settings.setValue("port", "10808"); // 设置键名  值名
        Config::settings.setValue("123", "代理"); // 设置键名  值名
        Config:: settings.endGroup();
        Config::settings.sync(); // 立即保存设置
        qDebug() <<"!exists";
    }
}
void Config::APPINFO()
{
    QCoreApplication::setApplicationName(Config::settings.value("Info/Name").toString());
    QCoreApplication::setApplicationVersion(Config::settings.value("Info/Version").toString());
    QCoreApplication::setOrganizationName("yhh");
    QCoreApplication::setOrganizationDomain("yanbei");
}
