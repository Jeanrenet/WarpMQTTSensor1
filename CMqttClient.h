#ifndef CMQTTCLIENT_H
#define CMQTTCLIENT_H

#include <QtMqtt>
#include <QTimer>
#include <QString>

#include "CSensors.h"

#define UPDATE_RATE 100 //toute les 100 ms
#define ROOT_TOPIC  QString("Warp7MQTT/")
#define HOME_NAME   QString("Pierre-Jean/")
const QString TOPIC_PATH_ACC_X = QString(ROOT_TOPIC + HOME_NAME + "accelerometer/X");
const QString TOPIC_PATH_ACC_Y = QString(ROOT_TOPIC + HOME_NAME + "accelerometer/Y");
const QString TOPIC_PATH_ACC_Z = QString(ROOT_TOPIC + HOME_NAME + "accelerometer/Z");
const QString TOPIC_PATH_TEMP = QString(ROOT_TOPIC + HOME_NAME + "temperature");

class CMqttClient : public QObject
{
    Q_OBJECT
public:
    CMqttClient();
    ~CMqttClient();

protected:
    /**
     * @brief clientStateChanged
     * @param state
     */
    Q_SLOT void clientStateChanged(QMqttClient::ClientState state);
    /**
     * @brief updateBroker
     */
    Q_SLOT void updateBroker();

private:
    QMqttClient     *m_mqttClient;
    CSensors        *m_sensors;
    QTimer          *m_updateEventLoopTimer;
};

#endif // CMQTTCLIENT_H
