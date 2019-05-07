//
//  eb4 -- software de control del ECoBot
//  escrito por ~angel
//

#pragma once

#include "def.h"
#include "ir.h"

enum
{
  CTL_OFFLINE = 0,
  CTL_ONLINE = 1
} _ctl_stat;

void
ctl_halt(void)
{
  _ctl_stat = CTL_OFFLINE;
  pwm.setPWM(PIN_SERVO_LEFT, 0, PWM_SERVO_STOP);
  pwm.setPWM(PIN_SERVO_RIGHT, 0, PWM_SERVO_STOP);
  pwm.setPWM(PIN_SERVO_USND, 0, USND_SERVO_N);
  tr("ctl_halt: system offline\n");
}

void
ctl_reset(void)
{
  _ctl_stat = CTL_ONLINE;

  pinMode(PIN_IR_LEFT, INPUT_PULLUP);
  pinMode(PIN_IR_RIGHT, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(PIN_IR_LEFT), ir_isr, CHANGE);
  attachInterrupt(digitalPinToInterrupt(PIN_IR_RIGHT), ir_isr, CHANGE);

  pinMode(PIN_SIG_TRI, OUTPUT);
  pinMode(PIN_SIG_ECH, INPUT);

  pwm.setPWM(PIN_SERVO_USND, 0, USND_SERVO_N);
  tr("ctl_reset: system online\n");
}
