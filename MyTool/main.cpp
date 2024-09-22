#include "mainwindow.h"
#include <QApplication>

#include "config.h"
QTranslator translator;// 全局翻译器对象
Config config;// 全局配置对象
int main(int argc, char *argv[])
{
    QString language;

    QApplication a(argc, argv);
    config.RW_Default_settings();
    config.APPINFO();
    language=config.settings.value("i18n/language").toString();
    if(language=="zh_CN")
    {
        translator.load(":/MyTool_zh_CN.qm");
    }else if(language=="zh_TW")
    {
        translator.load(":/MyTool_zh_TW.qm");
    }
    else if(language=="en_US")
    {
        translator.load(":/MyTool_en_US.qm");
    }
    a.installTranslator(&translator);
    MainWindow w;
    w.show();
    return a.exec();
}
