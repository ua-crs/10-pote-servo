/*
 *     Project 10-pote-servo - main.cpp
 *         Muestra el funcionamiento de un servo
 *         el cual gira un angulo proporcional a la posicion de un potenciometro
 *
 *         Usar con shield IAE
 *         Verificar cuidadosamente la conexión del servo
 */

#include <Arduino.h>

#include <Servo.h>

/*
 *  Constant definitions
 *      Defined in platformio.ini
 *      MY_SERVO    IOPort of data servo
 *      ANAIN       IOPort of ADC input
 *      RANGE       ADC range
 *      SERIAL_BAUD Baud rate of serial port
 */


#define LOOP_DELAY  250

Servo servo;    //    Construccion de un nuevo objeto tipo Servo

//  static variables

static int last_angle;

void
setup()
{
    Serial.begin(SERIAL_BAUD);
    servo.attach(MY_SERVO);        //    Inicializacion declarando el GPIO donde esta conectado
    last_angle = 0;
    delay(2000);
}

void
loop()
{
    int sensorValue, angle;

    sensorValue = analogRead(ANAIN);
    angle = map( sensorValue, 0, RANGE, 0, 180 );

    if( angle != last_angle )
    {
        Serial.printf( "angle = %d\n\r", angle );
        servo.write(angle);
        last_angle = angle;
        delay(LOOP_DELAY);
    }
}
