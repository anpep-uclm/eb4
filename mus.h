//
//  eb4 -- software de control del ECoBot
//  escrito por ~angel
//

#pragma once

#include "def.h"

const unsigned short _mus_tones[] = {
  587, 988, 784, 659, 587, 988, 784, 988, 784,
  988, 880, 784, 784, 880, 784, 698, 784
};

const unsigned short _mus_timings[] = {
  500, 250, 250, 250, 250, 250, 250, 500, 500,
  750, 250, 250, 125, 125, 250, 250, 750
};

void
mus_play(void)
{
  tr("mus_play: playing melody\n");
  for (int i = 0; i < sizeof(_mus_tones) / sizeof(unsigned short); i++) {
    tone(PIN_BUZZER, _mus_tones[i] / 4);
    delay(_mus_timings[i] * 0.75);
    noTone(PIN_BUZZER);
  }
  tr("mus_play: done\n");
}
