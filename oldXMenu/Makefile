## Makefile for oldXMenu

## Copyright 1985, 1986, 1987 by the Massachusetts Institute of Technology

## Permission to use, copy, modify, and distribute this
## software and its documentation for any purpose and without
## fee is hereby granted, provided that the above copyright
## notice appear in all copies and that both that copyright
## notice and this permission notice appear in supporting
## documentation, and that the name of M.I.T. not be used in
## advertising or publicity pertaining to distribution of the
## software without specific, written prior permission.
## M.I.T. makes no representations about the suitability of
## this software for any purpose.  It is provided "as is"
## without express or implied warranty.


## Copyright (C) 2001-2013 Free Software Foundation, Inc.

## This program is free software: you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.

## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.

## You should have received a copy of the GNU General Public License
## along with this program.  If not, see <http://www.gnu.org/licenses/>.


### Commentary:

## To the best of our knowledge, this code was originally based on the
## X11 oldXMenu Makefile, which was automatically generated from the
## X11 oldXMenu Imakefile.  There was no explicit copyright information
## in the Imakefile, therefore we have added the same MIT license as
## used by the rest of the oldXMenu code.


### Code:

srcdir=/Users/netmask/Downloads/emacs-24.3/oldXMenu
VPATH=/Users/netmask/Downloads/emacs-24.3/oldXMenu
C_SWITCH_X_SITE=
C_SWITCH_SYSTEM=
C_SWITCH_MACHINE=
PROFILING_CFLAGS = 
WARN_CFLAGS = 
WERROR_CFLAGS = 

EXTRA=insque.o
CC=clang -fobjc-arc
CFLAGS=-g3 -O2
TAGS = etags
RM = rm -f
RANLIB = ranlib
AR = ar
ARFLAGS = cru

OBJS =  Activate.o \
	AddPane.o \
	AddSel.o \
	ChgPane.o \
	ChgSel.o \
	Create.o \
	DelPane.o \
	DelSel.o \
	Destroy.o \
	Error.o \
	EvHand.o \
	FindPane.o \
	FindSel.o \
	InsPane.o \
	InsSel.o \
	Internal.o \
	Locate.o \
	Post.o \
	Recomp.o \
	SetAEQ.o \
	SetFrz.o \
	SetPane.o \
	SetSel.o \
      XDelAssoc.o XLookAssoc.o XCrAssoc.o XDestAssoc.o XMakeAssoc.o

all:: libXMenu11.a

ALL_CFLAGS=$(C_SWITCH_SYSTEM) $(C_SWITCH_MACHINE) \
  $(C_SWITCH_X_SITE) \
  $(WARN_CFLAGS) $(WERROR_CFLAGS) ${PROFILING_CFLAGS} \
  $(CPPFLAGS) $(CFLAGS) -DEMACS_BITMAP_FILES \
  -I../src -I../lib -I${srcdir} -I${srcdir}/../src -I${srcdir}/../lib

.c.o:
	$(CC) -c ${ALL_CFLAGS} $<

libXMenu11.a: $(OBJS) $(EXTRA)
	$(RM) $@
	$(AR) $(ARFLAGS) $@ $(OBJS) $(EXTRA)
	$(RANLIB) $@

Activate.o: Activate.c XMenuInt.h XMenu.h X10.h
AddPane.o: AddPane.c XMenuInt.h XMenu.h X10.h
AddSel.o: AddSel.c XMenuInt.h XMenu.h X10.h
ChgPane.o: ChgPane.c XMenuInt.h XMenu.h X10.h
ChgSel.o: ChgSel.c XMenuInt.h XMenu.h X10.h
Create.o: Create.c XMenuInt.h XMenu.h X10.h
DelPane.o: DelPane.c XMenuInt.h XMenu.h X10.h
DelSel.o: DelSel.c XMenuInt.h XMenu.h X10.h
Destroy.o: Destroy.c XMenuInt.h XMenu.h X10.h
Error.o: Error.c XMenuInt.h XMenu.h X10.h
EvHand.o: EvHand.c XMenuInt.h XMenu.h X10.h
FindPane.o: FindPane.c XMenuInt.h XMenu.h X10.h
FindSel.o: FindSel.c XMenuInt.h XMenu.h X10.h
InsPane.o: InsPane.c XMenuInt.h XMenu.h X10.h
InsSel.o: InsSel.c XMenuInt.h XMenu.h X10.h
Internal.o: Internal.c XMenuInt.h XMenu.h X10.h
Locate.o: Locate.c XMenuInt.h XMenu.h X10.h
Post.o: Post.c XMenuInt.h XMenu.h X10.h
Recomp.o: Recomp.c XMenuInt.h XMenu.h X10.h
SetAEQ.o: SetAEQ.c XMenuInt.h XMenu.h X10.h
SetFrz.o: SetFrz.c XMenuInt.h XMenu.h X10.h
SetPane.o: SetPane.c XMenuInt.h XMenu.h X10.h
SetSel.o: SetSel.c XMenuInt.h XMenu.h X10.h
XDelAssoc.o: XDelAssoc.c X10.h
XLookAssoc.o: XLookAssoc.c X10.h
XCrAssoc.o: XCrAssoc.c X10.h
XDestAssoc.o: XDestAssoc.c X10.h
XMakeAssoc.o: XMakeAssoc.c X10.h
insque.o: insque.c

FRC.mostlyclean:
mostlyclean: FRC.mostlyclean
	rm -f libXMenu11.a ${OBJS} ${EXTRA}
clean: mostlyclean
distclean: clean
	rm -f Makefile
maintainer-clean: distclean

tags::
	$(TAGS) -t *.[ch]
