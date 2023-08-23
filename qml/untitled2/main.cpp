#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

//    QGuiApplication app(argc, argv);

//    QQuickView *view = new QQuickView;
//    view->setSource(QUrl::fromLocalFile(":/main.qml"));
//    view->show();
    return app.exec();
}
