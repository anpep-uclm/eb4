//
//  eb4 -- software de control del ECoBot
//  escrito por ~angel
//

#pragma once

#define _is_under_threshold() (analogRead(PIN_LDR_LEFT) < LDR_THRESHOLD || \
                               analogRead(PIN_LDR_RIGHT) < LDR_THRESHOLD)

void
ldr_read()
{
  static int _last_stat = -1;
  int curr_stat;

  if ((curr_stat = _is_under_threshold()) == _last_stat)
    return;

  _last_stat = curr_stat;

  tr("ldr_read: threshold status changed to ");
  trd(curr_stat);
  tr("\n");

  if (curr_stat)
    ctl_halt();
  else
    ctl_reset();
}
