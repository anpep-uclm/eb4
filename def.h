//
//  eb4 -- software de control del ECoBot
//  escrito por ~angel
//

#pragma once

//#define TRACE

#ifdef TRACE
#  define tr(m) Serial.print(m)
#  define trd(v) Serial.print(v, DEC)
#else
#  define tr(m)
#  define trd(v)
#endif

/**
 * Configuración de los pines
 */
enum {
  PIN_SERVO_LEFT = 0,     //! servomotor de la rueda izquierda
  PIN_SERVO_RIGHT = 1,    //! servomotor de la rueda derecha
  PIN_SERVO_USND = 2,     //! servomotor del sensor de ultrasonidos

  PIN_IR_LEFT = 2,        //! sensor infrarrojo izquierdo
  PIN_IR_RIGHT = 3,       //! sensor infrarrojo derecho

  PIN_BUZZER = 6,         //! zumbador

  PIN_LDR_LEFT = A0,      //! sensor de luz izquierdo
  PIN_LDR_RIGHT = A1,     //! sensor de luz derecho

  PIN_SIG_TRI = 4,        //! pin de la salida TRI (probe)
  PIN_SIG_ECH = 5         //! pin de la entrada ECH (echo)
};

/**
 * Valores para el controlador PWM de los servomotores en las ruedas
 */
enum {
  PWM_SERVO_STOP = 340,   //! velocidad 0
  PWM_SERVO_MIN = 280,    //! velocidad -v_max
  PWM_SERVO_MAX = 400,    //! velocidad +v_max
};

#define LDR_THRESHOLD 35        //! umbral permisible de luz ambiental

#define USND_RANGE 5            //! distancia máxima de detección, en cm
#define USND_PULSE_DURATION 1   //! duración, en ms, de un pulso de ultrasonidos

#define BUZZFREQ_USND 500       //! frecuencia para la detección de ultrasonidos
#define BUZZFREQ_IR 3000        //! frecuencia del zumbador para la detección IR


#define USND_SERVO_N 320        //! servo 180deg mirando al frente

#define SYS_TTL (3 * 60 * 1000) //! tiempo de vida del sistema, en milisegundos
