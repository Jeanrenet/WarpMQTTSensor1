#include "CSensors.h"

#include <QFile>
#include <QString>
#include <QDebug>

double stringToValue(QString path)
{
    double value = 0;

    QFile file(path);
    if (file.exists())
    {
        if (file.open(QIODevice::ReadOnly))
        {
            QByteArray array = file.readAll().trimmed();

            value = array.toDouble();
            file.close();
        }
    }
    return value;
}
CSensors::CSensors()
{
    //récupération des échelles
    m_accelerometerScale = stringToValue(ACCEL_SCALE);
    m_magnetometerScale = stringToValue(MAGNET_SCALE);
    m_barometerScale = stringToValue(PRESSURE_SCALE);
    m_temperatureScale = stringToValue(TEMP_SCALE);
    m_gyroscopeScale = stringToValue(GYRO_SCALE);
}

CSensors::~CSensors()
{
}

void CSensors::readData()
{
    //lecture des données et application de l'échelle
    m_accelerometerX = stringToValue(ACCEL_X) * m_accelerometerScale;
    m_accelerometerY = stringToValue(ACCEL_Y) * m_accelerometerScale;
    m_accelerometerZ = stringToValue(ACCEL_Z) * m_accelerometerScale;
    m_magnetometerX = stringToValue(MAGNET_X) * m_magnetometerScale;
    m_magnetometerY = stringToValue(MAGNET_Y) * m_magnetometerScale;
    m_magnetometerZ = stringToValue(MAGNET_Z) * m_magnetometerScale;
    //m_pressure = stringToValue(PRESSURE_RAW) * m_barometerScale;
    //m_temperature = stringToValue(TEMP_RAW) * m_temperatureScale;
    m_gyroscopeX = stringToValue(GYRO_X) * m_gyroscopeScale;
    m_gyroscopeY = stringToValue(GYRO_Y) * m_gyroscopeScale;
    m_gyroscopeZ = stringToValue(GYRO_Z) * m_gyroscopeScale;
}

qreal CSensors::accelerometerZ() const
{
    return m_accelerometerZ;
}

qreal CSensors::accelerometerY() const
{
    return m_accelerometerY;
}

qreal CSensors::accelerometerX() const
{
    return m_accelerometerX;
}
