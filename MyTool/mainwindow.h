#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QLabel>
#include <QTimer>
#include <QDateTime>
#include <QTranslator>
  #include <QActionGroup>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //主菜单的语言选择
    void on_action_Simplified_Chinese_triggered();

    void on_action_Traditional_Chinese_triggered();

    void on_action_English_triggered();

    void on_action_exit_triggered();

 void showTime();

private:
    Ui::MainWindow *ui;

    QActionGroup *languageAlignmentGroup;//选项分组
    QTranslator *m_QTranslator;//翻译文件
    QLabel * statuLabel_time;//状态栏时间

};
#endif // MAINWINDOW_H
