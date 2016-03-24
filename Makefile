# Copyright (C) 2016 Jens Kehne, Karlsruhe Institute of Technology (KIT)
# This file is part of LibPhaseTimer
#
# LibPhaseTimer is free software; you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as
# published by the Free Software Foundation; either version 2.1 of the
# License, or (at your option) any later version.
#
# LibPhaseTimer is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with LibPhaseTimer; if not, see
# <https://www.gnu.org/licenses/>

LIBNAME := libphasetimer
OBJS := PhaseTimer TimerPhase CBinding
CFLAGS := -O2 -std=c++0x -fPIC -flto -fuse-linker-plugin -ffat-lto-objects
LDFLAGS := -lrt
CC := g++
RM := rm -f
INSTALL := install -D
LN := ln -s
AR := gcc-ar

PREFIX ?= $(DESTDIR)/usr

all: shared static

shared: $(LIBNAME).so

$(LIBNAME).so: $(addsuffix .o,$(OBJS))
	$(CC) -shared $(CFLAGS) -o $@ $^ $(LDFLAGS)

static: $(LIBNAME).a

$(LIBNAME).a: $(addsuffix .o,$(OBJS))
	$(AR) rcs $@ $^

%.o: %.cpp
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	$(RM) $(LIBNAME).so $(LIBNAME).a $(addsuffix .o,$(OBJS))

install: all
	$(INSTALL) -m 644 $(LIBNAME).a $(PREFIX)/lib/$(LIBNAME).a
	$(INSTALL) -m 644 $(LIBNAME).so $(PREFIX)/lib/$(LIBNAME).so.0.0.0
	$(INSTALL) -m 644 PhaseTimer.hpp $(PREFIX)/include/phasetimer.h
	$(LN) $(LIBNAME).so.0.0.0 $(PREFIX)/lib/$(LIBNAME).so.0
	$(LN) $(LIBNAME).so.0.0.0 $(PREFIX)/lib/$(LIBNAME).so

.PHONY: all clean install shared static
