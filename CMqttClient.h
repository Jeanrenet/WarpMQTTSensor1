#ifndef CMQTTCLIENT_H
#define CMQTTCLIENT_H

#include <QtMqtt/QtMqtt>

class CMqttClient : public QObject
{
    Q_OBJECT
public:
    CMqttClient();
    ~CMqttClient();

protected:
    Q_SLOT void clientStateChanged(QMqttClient::ClientState state);

private:
    QMqttClient     *m_mqttClient;
};

#endif // CMQTTCLIENT_H
