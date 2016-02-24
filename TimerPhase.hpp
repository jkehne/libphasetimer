/* 
Copyright (C) 2016 Jens Kehne, Karlsruhe Institute of Technology (KIT)
This file is part of LibPhaseTimer

LibPhaseTimer is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as
published by the Free Software Foundation; either version 2.1 of the
License, or (at your option) any later version.

LibPhaseTimer is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with LibPhaseTimer; if not, see
<https://www.gnu.org/licenses/>
*/

#ifndef TIMERPHASE_H
#define TIMERPHASE_H

#include <string>
#include <cstdint>

class TimerPhase {
private:
  std::string name;
  uint64_t time;
  static uint32_t maxPhaseNameLength;

public:
  TimerPhase(std::string &name);

  void reset();
  TimerPhase& operator+=(uint64_t amount);
  friend std::ostream& operator<<(std::ostream& os, const TimerPhase &phase);
};

#endif /* TIMERPHASE_H */
