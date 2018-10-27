#include "CMqttClient.h"
#include <QDebug>
#include <QDataStream>
#include <QIODevice>

QByteArray qRealToByteArray(qreal value)
{
    QByteArray data;
    QDataStream stream(&data, QIODevice::WriteOnly);
    stream << value;
    return data;
}

CMqttClient::CMqttClient()
{
    //initialisation de la classe capteur
    m_sensors = new CSensors();

    //initialisation du client mqtt
    m_mqttClient = new QMqttClient();
    m_mqttClient->setHostname("test.mosquitto.org");
    m_mqttClient->setPort(1883);
    m_mqttClient->connectToHost();
    connect(m_mqttClient, &QMqttClient::stateChanged, this, &CMqttClient::clientStateChanged);

    //initialisation de la boucle de mise à jour et la démarrer
    m_updateEventLoopTimer = new QTimer();
    connect(m_updateEventLoopTimer, &QTimer::timeout, this, &CMqttClient::updateBroker);
    m_updateEventLoopTimer->start(100);
}

CMqttClient::~CMqttClient()
{
    //delete timer
    m_updateEventLoopTimer->stop();
    delete m_updateEventLoopTimer;

    //delete client mqtt
    m_mqttClient->disconnectFromHost();
    delete m_mqttClient;

    //delete sensors
    delete m_sensors;
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
void CMqttClient::updateBroker()
{
    //on met à jour les données lues sur les capteurs
    m_sensors->readData();

    //on envoie au broker
    //qos = 0
    //retain msg = true
    m_mqttClient->publish(TOPIC_PATH_ACC_X, QByteArray::number(m_sensors->accelerometerX()), 0, true);
    m_mqttClient->publish(TOPIC_PATH_ACC_Y, QByteArray::number(m_sensors->accelerometerY()), 0, true);
    m_mqttClient->publish(TOPIC_PATH_ACC_Z, QByteArray::number(m_sensors->accelerometerZ()), 0, true);
    m_mqttClient->publish(TOPIC_PATH_TEMP, QByteArray::number(m_sensors->temperature()), 0, true);
}
