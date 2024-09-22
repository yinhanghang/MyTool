#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "config.h"
extern QTranslator translator;
extern Config config;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //动作分组
    languageAlignmentGroup = new QActionGroup(this);
    languageAlignmentGroup->addAction(ui->action_English);
    languageAlignmentGroup->addAction(ui->action_Simplified_Chinese);
    languageAlignmentGroup->addAction(ui->action_Traditional_Chinese);
    //判断配置文件选择语言
    QString language;
    language=config.settings.value("i18n/language").toString();
    if(language=="zh_CN")
    {
        ui->action_Simplified_Chinese->setChecked(true);
    }else if(language=="zh_TW")
    {
        ui->action_Traditional_Chinese->setChecked(true);
    }
    else if(language=="en_US")
    {
        ui->action_English->setChecked(true);
    }

    //状态栏添加子控件
    //显示版本
    QLabel  *statuLabel_version=new QLabel("版本");
    statuLabel_version->setMinimumWidth(50);
    statuLabel_version->setAlignment(Qt::AlignHCenter);//水平居中
    statuLabel_version->setText(QCoreApplication::applicationVersion());
    ui->statusbar->addWidget(statuLabel_version);
    //显示时间
    statuLabel_time=new QLabel();
    statuLabel_time->setMinimumWidth(120);
    //statuLabel->setAlignment(Qt::AlignHCenter);
    ui->statusbar->addWidget(statuLabel_time);
    statuLabel_time->setText(QDateTime ::currentDateTime().toString(tr("yyyy-MM-dd hh:mm:ss")));//界面开始就显示时间

    //定时器，刷机时间：1000毫秒
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::showTime);
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_Simplified_Chinese_triggered()
{
    translator.load(":/MyTool_zh_CN.qm");
    qApp->installTranslator(&translator);
    config.settings.setValue("i18n/language", "zh_CN"); // 设置键名  值名
    config.settings.sync(); // 立即保存设置
    ui->retranslateUi(this);
}


void MainWindow::on_action_Traditional_Chinese_triggered()
{
    translator.load(":/MyTool_zh_TW.qm");
    qApp->installTranslator(&translator);
    config.settings.setValue("i18n/language", "zh_TW"); // 设置键名  值名
    config.settings.sync(); // 立即保存设置
    ui->retranslateUi(this);
}


void MainWindow::on_action_English_triggered()
{
    translator.load(":/MyTool_en_US.qm");
    qApp->installTranslator(&translator);
    config.settings.setValue("i18n/language", "en_US"); // 设置键名  值名
    config.settings.sync(); // 立即保存设置
    ui->retranslateUi(this);
}


void MainWindow::on_action_exit_triggered()
{
    this->close();
}

void MainWindow::showTime()
{
    QDateTime  time = QDateTime ::currentDateTime();
    QString text;
    text = time.toString(tr("yyyy-MM-dd hh:mm:ss"));
    statuLabel_time->setText(text);
}

