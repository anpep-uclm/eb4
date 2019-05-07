//
//  eb4 -- software de control del ECoBot
//  escrito por ~angel
//

#pragma once

#include "def.h"
#include "ir.h"
#include "ldr.h"
#include "tra.h"
#include "usnd.h"
#include "watchdog.h"

void
tra_iter(void)
{
  static unsigned ctr = 0;
  ctr += 4;

  pwm.setPWM(PIN_SERVO_RIGHT, 0, PWM_SERVO_STOP + ctr);
  delay(500 + ctr);
  pwm.setPWM(PIN_SERVO_LEFT, 0, PWM_SERVO_MIN - ctr);
  delay(500 - ctr);

  usnd_check();
}
