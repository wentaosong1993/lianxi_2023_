#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

//#include <DApplication>
//#include <DMainWindow>
//#include <DTitlebar>
//DWIDGET_USE_NAMESPACE


//int main(int argc, char *argv[])
//{
//    DApplication app(argc, argv);
//    QIcon icon = QIcon::fromTheme("face-smile");
//    app.setApplicationVersion("1.0.0");// 设置(关于中显示)版本号
//    app.setProductName("dtk-dialog-demo");// 设置(关于中显示)产品名称
//    app.setProductIcon(icon); // 设置(关于中显示)产品icon
//    DMainWindow w;
//    w.titlebar()->setIcon(icon); //设置标题栏左上角icon
//    w.show();
//    return app.exec();
//}
