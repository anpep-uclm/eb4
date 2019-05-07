//
//  eb4 -- software de control del ECoBot
//  escrito por ~angel
//

#pragma once

#include "def.h"

enum {
  IR_BLANK = 0,
  IR_CHANGE = 1
} _ir_flag = IR_BLANK;

void
ir_isr(void)
{
  _ir_flag = IR_CHANGE;
}
