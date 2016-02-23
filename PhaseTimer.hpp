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

#ifndef PHASETIMER_H
#define PHASETIMER_H

#include <stdint.h>

#ifdef __cplusplus

#include <vector>
#include <string>

class TimerPhase;

class PhaseTimer {
private:
  std::vector<TimerPhase> phases;
  uint64_t lastTimestamp;
  uint32_t lastPhase;
  uint64_t getTimeDiffAndUpdateTimestamp();

public:
  PhaseTimer();
  PhaseTimer(PhaseTimer &other);
#if __cplusplus>=201103L
  PhaseTimer(PhaseTimer &&other);
#endif
  ~PhaseTimer();

  PhaseTimer& operator=(const PhaseTimer &rhs);
#if __cplusplus>=201103L
  PhaseTimer& operator=(const PhaseTimer &&rhs);
#endif
  
  uint32_t addPhase(std::string name);
  void switchToPhase(uint32_t handle);
  void printPhases() const;
  void stopTimer();
};

extern "C" {

#endif // __cplusplus

  struct ptimer;
  typedef struct ptimer ptimer;

  ptimer *ptimer_create();
  void ptimer_destroy(ptimer *timer);
  
  uint32_t ptimer_addPhase(ptimer *timer, char *name);
  void ptimer_switchToPhase(ptimer *timer, uint32_t handle);
  void ptimer_printPhases(ptimer *timer);
  void ptimer_stopTimer(ptimer *timer);
  
#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus
  
#endif /* PHASETIMER_H */
