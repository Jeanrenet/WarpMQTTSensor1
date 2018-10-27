#ifndef CSENSORS_H
#define CSENSORS_H

#include <QObject>

#define PRESSURE_RAW    "/sys/bus/iio/devices/iio:device0/in_pressure_raw"
#define PRESSURE_SCALE  "/sys/bus/iio/devices/iio:device0/in_pressure_scale"
#define TEMP_RAW        "/sys/bus/iio/devices/iio:device0/in_temp_raw"
#define TEMP_SCALE      "/sys/bus/iio/devices/iio:device0/in_temp_scale"

#define ACCEL_X         "/sys/bus/iio/devices/iio:device1/in_accel_x_raw"
#define ACCEL_Y         "/sys/bus/iio/devices/iio:device1/in_accel_y_raw"
#define ACCEL_Z         "/sys/bus/iio/devices/iio:device1/in_accel_z_raw"
#define ACCEL_SCALE     "/sys/bus/iio/devices/iio:device1/in_accel_scale"

#define MAGNET_X        "/sys/bus/iio/devices/iio:device1/in_magn_x_raw"
#define MAGNET_Y        "/sys/bus/iio/devices/iio:device1/in_magn_y_raw"
#define MAGNET_Z        "/sys/bus/iio/devices/iio:device1/in_magn_z_raw"
#define MAGNET_SCALE    "/sys/bus/iio/devices/iio:device1/in_magn_scale"

#define GYRO_SCALE      "/sys/bus/iio/devices/iio:device2/in_gyro_scale"
#define GYRO_X          "/sys/bus/iio/devices/iio:device2/in_gyro_x_raw"
#define GYRO_Y          "/sys/bus/iio/devices/iio:device2/in_gyro_y_raw"
#define GYRO_Z          "/sys/bus/iio/devices/iio:device2/in_gyro_z_raw"

class CSensors: public QObject
{
    Q_OBJECT
public:
    CSensors();
    ~CSensors();

    /**
     * @brief accelerometerX
     * @return acc X value
     */
    qreal accelerometerX() const;
    /**
     * @brief accelerometerY
     * @return acc Y value
     */
    qreal accelerometerY() const;
    /**
     * @brief accelerometerZ
     * @return acc Z value
     */
    qreal accelerometerZ() const;

    /**
     * @brief readData :  read data from sensors
     */
    void readData();

private:
    qreal           m_accelerometerX;
    qreal           m_accelerometerY;
    qreal           m_accelerometerZ;
    qreal           m_accelerometerScale;
    qreal           m_magnetometerX;
    qreal           m_magnetometerY;
    qreal           m_magnetometerZ;
    qreal           m_magnetometerScale;
    qreal           m_pressure;
    qreal           m_temperature;
    qreal           m_barometerScale;
    qreal           m_temperatureScale;
    qreal           m_gyroscopeX;
    qreal           m_gyroscopeY;
    qreal           m_gyroscopeZ;
    qreal           m_gyroscopeScale;
};

#endif // CSENSORS_H
