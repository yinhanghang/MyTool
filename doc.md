# MyTool项目

#### 版本：0.0.1

##### 1.项目创建

Qt creator：文件-->新项目-->Application(Qt)-->Qt Widgets Application

填入名称，路径，构建套件，选择5.15.2 MinGW 64-bit

##### 2.使用visual studio打开项目

使用插件qt tool，打开pro文件自动生成项目

sln文件,启动项目

ui文件，双击打不开，右键选择打开方式，选择对应版本的设计器

##### 3.git设置

1.删除全部生成文件，在vs使用git创建本地和远程仓库

2.修改文件.gitignore，将生成文件目录放入

​	qt creator 构建和生成目录修改

​	vs的相关文件在生成时会自动屏蔽

#### 版本0.0.2

工具栏
	在ui界面添加工具栏
​	1.语言切换
		简体中文 
		繁体中文
		英文

​	2.退出

状态条
​	版本号

​	时间



问题1：
创建变量在类的.h文件还是在.cpp文件
	QLabel * statuLabel_time;//私有变量
	statuLabel_time=new QLabel();
	
	QLabel  *statuLabel_version=new QLabel("版本");

小技巧：
	在使用ui界面添加label时，在代码里面不需要引入Qlabel 
	界面的工具栏不显示,重新构建项目
	修改完ui界面

	F:\chengxu\qt\MyTool\MyTool\mainwindow.cpp:1: warning: C4819: 该文件包含不能在当前代码页(936)中表示的字符。请将该文件保存为 Unicode 格式以防止数据丢失