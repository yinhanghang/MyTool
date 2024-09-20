#include "mainwindow.h"
#include "ui_mainwindow.h"

#define VERSION "V 0.0.2"


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
    // ui->action_English->setChecked(true);
    //根据选择调用对应的翻译文件
    m_QTranslator =new QTranslator(this);
    if(ui->action_English->isChecked())
    {
        m_QTranslator->load("MyTool_en_US.qm");
        //修改配置文件语言
    }else if(ui->action_Traditional_Chinese->isChecked())
    {
        m_QTranslator->load("MyTool_zh_TW.qm");
    }else if(ui->action_Simplified_Chinese->isChecked())
    {
        m_QTranslator->load("MyTool_zh_CN.qm");
    }
    qApp->installTranslator(m_QTranslator);
    ui->retranslateUi(this);
    //状态栏添加子控件
    //显示版本
    QLabel  *statuLabel_version=new QLabel("版本");
    statuLabel_version->setMinimumWidth(50);
    statuLabel_version->setAlignment(Qt::AlignHCenter);//水平居中
    statuLabel_version->setText(VERSION);
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
    m_QTranslator->load(":/MyTool_zh_CN.qm");
    qApp->installTranslator(m_QTranslator);
    ui->retranslateUi(this);
}


void MainWindow::on_action_Traditional_Chinese_triggered()
{
    m_QTranslator->load(":/MyTool_zh_TW.qm");
    qApp->installTranslator(m_QTranslator);
    ui->retranslateUi(this);
}


void MainWindow::on_action_English_triggered()
{
    m_QTranslator->load(":/MyTool_en_US.qm");
    qApp->installTranslator(m_QTranslator);
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
    // if ((time.time().second() % 2) == 0)
    //     text = time.toString(tr("yyyy-MM-dd hh:mm:ss"));
    // else
    //     text = time.toString(tr("yyyy-MM-dd hh:mmss"));
    statuLabel_time->setText(text);
}

