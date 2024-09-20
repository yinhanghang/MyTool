#include "mainwindow.h"
  #include <QSettings>
#include <QApplication>
  #include <QTranslator>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 创建翻译器对象
    QTranslator translator;
    // // 设置默认语言
    // QString language = "en"; // 假设默认为英语

    // // 从配置文件或系统设置中读取用户首选语言
    // // 例如，使用 QSettings 读取用户设置
    // QSettings settings;
    // language = settings.value("Language", language).toString();

    // // 根据读取的语言加载翻译文件
    // if (translator.load(QLocale(language), QLatin1String("MyApp"),
    //                     QLatin1String("_"), QLatin1String(":/translations"))) {
    //     a.installTranslator(&translator);
    // }



//需要添加代码，读取配置项，判断加载那种语言
    translator.load(":/MyTool_zh_CN.qm");
    a.installTranslator(&translator);
    MainWindow w;
    w.show();
    return a.exec();
}
