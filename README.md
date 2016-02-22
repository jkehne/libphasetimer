LibPhaseTimer
=============

LibPhaseTimer is a simple library for measuring the time spent in
different parts of a program.

Usage
-----

1. Construct a `PhaseTimer`-object (if you are not using C++, use
   `ptimer_create()` and store the `struct ptimer` it returns)
2. Add one or more phases to the timer using `timer.addPhase(name)`
   (C++) or `ptimer_addPhase(timer, name)` (C). The integer returned
   by these methods is a handle for the respective phase; store it,
   you will need it in the next step.
3. Whenever a phase you are interested in starts, switch to the
   appropriate phase using `timer.switchToPhase(handle)` (C++) or
   `ptimer_switchToPhase(timer, handle)` (C). There is no need to
   explicitly start the timer, it will start automatically the first
   time you switch to a phase.
4. After the last phase of your program, call `timer.stopTimer()`
   (C++) or `ptimer_stopTimer(timer)` (C).
5. Call `timer.printPhases()` (C++) or `ptimer_printPhases(timer)` (C)
   to print out the time accumulated in each phase

License
-------

LibPhaseTimer is licensed under the
[GNU Lesser General Public License (LGPL) version 2.1](https://www.gnu.org/licenses/old-licenses/lgpl-2.1)
or later.
