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

#include "PhaseTimer.hpp"
#include "TimerPhase.hpp"

extern "C" {

  ptimer *ptimer_create() {
    return reinterpret_cast<ptimer *>(new PhaseTimer());
  }

  void ptimer_destroy(ptimer *timer) {
    delete reinterpret_cast<PhaseTimer *>(timer);
  }

  uint32_t ptimer_addPhase(ptimer *timer, char *name) {
    return reinterpret_cast<PhaseTimer *>(timer)->addPhase(name);
  }

  void ptimer_switchToPhase(ptimer *timer, uint32_t handle) {
    reinterpret_cast<PhaseTimer *>(timer)->switchToPhase(handle);
  }

  void ptimer_printPhases(ptimer *timer) {
    reinterpret_cast<PhaseTimer *>(timer)->printPhases();
  }

  void ptimer_stopTimer(ptimer *timer) {
    reinterpret_cast<PhaseTimer *>(timer)->stopTimer();
  }

} // extern "C"
