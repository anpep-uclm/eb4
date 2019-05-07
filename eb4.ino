//
//  eb4 -- software de control del ECoBot
//  escrito por ~angel
//

#include "Adafruit_PWMServoDriver.h"
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#include "ctl.h"
#include "def.h"
#include "ir.h"
#include "ldr.h"
#include "tra.h"
#include "usnd.h"
#include "watchdog.h"

void
setup(void)
{
#ifdef TRACE
  Serial.begin(9600);
  tr("setup: serial online\n");
#endif

  pwm.begin();
  pwm.setPWMFreq(60);
  tr("setup: pwm set\n");

  ctl_halt();
  ctl_reset();
  watchdog_init();
}

void
loop(void)
{
  ldr_read();              // leemos los niveles de luz
  if (!_ctl_stat) return;  // no hacemos nada si estamos en modo de espera

  // si no hemos detectado cambios en los sensores IR, ejecutamos el bucle
  if (_ir_flag != IR_CHANGE) goto end;

  // hemos detectado un cambio en los sensores IR, nos aseguramos de que alguno
  // de ellos está detectando una mancha
  if (digitalRead(PIN_IR_LEFT) && digitalRead(PIN_IR_RIGHT))
    goto end; // ninguno de ellos está detectando manchas

  tr("ir_check: handling signal\n");
  tone(PIN_BUZZER, BUZZFREQ_IR);
  pwm.setPWM(PIN_SERVO_LEFT, 0, PWM_SERVO_STOP);
  pwm.setPWM(PIN_SERVO_RIGHT, 0, PWM_SERVO_STOP);

  delay(4000);
  pwm.setPWM(PIN_SERVO_LEFT, 0, PWM_SERVO_MIN);
  pwm.setPWM(PIN_SERVO_RIGHT, 0, PWM_SERVO_MIN);

  delay(1000);
  noTone(PIN_BUZZER);

end:
  tra_iter();
  watchdog_check();
  usnd_check();
}
