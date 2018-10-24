#include "CMqttClient.h"
#include <QDebug>

CMqttClient::CMqttClient()
{
    m_mqttClient = new QMqttClient();
    m_mqttClient->setHostname("test.mosquitto.org");
    m_mqttClient->setPort(1883);
    m_mqttClient->connectToHost();

    connect(m_mqttClient, &QMqttClient::stateChanged, this, &CMqttClient::clientStateChanged);
}

CMqttClient::~CMqttClient()
{
    m_mqttClient->disconnectFromHost();
    delete m_mqttClient;
}

void CMqttClient::clientStateChanged(QMqttClient::ClientState state)
{
    switch (state) {

    case QMqttClient::Disconnected:
        qDebug() << "Client Disconnected";
        break;
    case QMqttClient::Connecting:
        qDebug() << "Client Connecting";
        break;
    case QMqttClient::Connected:
        qDebug() << "Client Connected";
        break;
    }
}
