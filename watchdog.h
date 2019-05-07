//
//  eb4 -- software de control del ECoBot
//  escrito por ~angel
//

#pragma once

#include "def.h"
#include "ctl.h"
#include "mus.h"

unsigned long _watchdog_time0 = 0;

void
watchdog_init(void)
{
  _watchdog_time0 = millis();
  tr("watchdog_init: system online at timestamp ");
  trd(_watchdog_time0);
  tr("\n");
}

void
watchdog_check(void)
{
  if (millis() - _watchdog_time0 >= SYS_TTL) {
    tr("watchdog_check: reached system EOL\n");
    ctl_halt();
    mus_play();
    tr("watchdog_check: system halted\n");
    for (;;);
  }
}
