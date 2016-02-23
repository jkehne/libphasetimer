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

#include <ctime>
#include <iostream>
#include <algorithm>

#include "PhaseTimer.hpp"
#include "TimerPhase.hpp"

#define NSEC_PER_SEC 1000000000ULL

uint64_t PhaseTimer::getTimeDiffAndUpdateTimestamp() {
  struct timespec now;
  clock_gettime(CLOCK_MONOTONIC, &now);

  uint64_t nowTS = now.tv_sec * NSEC_PER_SEC + now.tv_nsec;
  uint64_t diff = nowTS - lastTimestamp;

  lastTimestamp = nowTS;
  return diff;
}

void PhaseTimer::switchToPhase(uint32_t handle) {
  if (handle == lastPhase)
    return;

  uint64_t diff = getTimeDiffAndUpdateTimestamp();
  
  if (lastPhase != -1)
    phases[lastPhase] += diff;
  
  lastPhase = handle;
}

void PhaseTimer::printPhases() const {
  for (TimerPhase phase : phases)
    std::cout << phase;
}

uint32_t PhaseTimer::addPhase(std::string name) {
  TimerPhase phase(name);
  phases.push_back(phase);
  return phases.size() - 1;
}

void PhaseTimer::stopTimer() {
  switchToPhase(-1);
}

PhaseTimer::PhaseTimer() : lastTimestamp(0), lastPhase(-1) { }
PhaseTimer::PhaseTimer(PhaseTimer &other) = default;
#if __cplusplus>=201103L
PhaseTimer::PhaseTimer(PhaseTimer &&other) = default;
#endif
PhaseTimer::~PhaseTimer() = default;

PhaseTimer& PhaseTimer::operator=(const PhaseTimer &rhs)
{
  // Check for self-assignment!
  if (this == &rhs)
    return *this;

  lastPhase = rhs.lastPhase;
  lastTimestamp = rhs.lastTimestamp;
  phases = rhs.phases;
  
  return *this;
}

#if __cplusplus>=201103L
PhaseTimer& PhaseTimer::operator=(const PhaseTimer &&rhs)
{
  lastPhase = rhs.lastPhase;
  lastTimestamp = rhs.lastTimestamp;
  phases = std::move(rhs.phases);
  
  return *this;
}
#endif
