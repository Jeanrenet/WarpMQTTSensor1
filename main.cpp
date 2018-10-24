#include <QCoreApplication>
#include "CMqttClient.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    new CMqttClient();

    return a.exec();
}
