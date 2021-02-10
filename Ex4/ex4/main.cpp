#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "cardmodel.hh"
#include "cardcontroller.hh"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    CardModel cardModel;
    engine.rootContext()->setContextProperty("cardModel", &cardModel);

    CardController cardController(nullptr, &cardModel);
    engine.rootContext()->setContextProperty("cardController", &cardController);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
