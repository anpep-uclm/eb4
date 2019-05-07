//
//  eb4 -- software de control del ECoBot
//  escrito por ~angel
//

#pragma once

#include "def.h"

void
usnd_check(void)
{
  digitalWrite(PIN_SIG_TRI, LOW);
  delay(USND_PULSE_DURATION);
  digitalWrite(PIN_SIG_TRI, HIGH);
  delay(USND_PULSE_DURATION);
  digitalWrite(PIN_SIG_TRI, LOW);

  unsigned raw_dur = pulseIn(PIN_SIG_ECH, HIGH),
           rg = raw_dur / 58;
  if (raw_dur && rg <= USND_RANGE)
  {
    tr("usnd_check: perceived distance within range\n");
    pwm.setPWM(PIN_SERVO_LEFT, 0, PWM_SERVO_STOP);
    pwm.setPWM(PIN_SERVO_RIGHT, 0, PWM_SERVO_STOP);

    tone(PIN_BUZZER, BUZZFREQ_USND);
    delay(500);
    noTone(PIN_BUZZER);
    tr("usnd_check: continuing\n");
  }
}
