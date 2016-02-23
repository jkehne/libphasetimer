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

#include <iostream>
#include <iomanip>

#include "TimerPhase.hpp"

uint32_t TimerPhase::maxPhaseNameLength = 0;

std::ostream& operator<<(std::ostream& os, const TimerPhase &phase) {
  os << std::setw(TimerPhase::maxPhaseNameLength) << phase.name << ": " << std::setw(20) << phase.time << " ns\n";
  return os; 
}

TimerPhase& TimerPhase::operator+=(uint64_t amount) {
  this->time += amount;
  return *this;
}

TimerPhase::TimerPhase(std::string &name) : name(name), time(0) { 
  maxPhaseNameLength = std::max(maxPhaseNameLength, static_cast<uint32_t>(name.length()));
}
