# Copyright (C) 1992, 1993 Lucid, Inc.
# Copyright (C) 1994, 2001-2013 Free Software Foundation, Inc.
#
# This file is part of the Lucid Widget Library.
#
# The Lucid Widget Library is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 1, or (at your option)
# any later version.
#
# The Lucid Widget Library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with GNU Emacs.  If not, see <http://www.gnu.org/licenses/>.


# This was taken from the output of Imake using Lucid's Imakefile.
# and set up to be configured by ../configure.

srcdir=/Users/netmask/Downloads/emacs-24.3/lwlib
VPATH=/Users/netmask/Downloads/emacs-24.3/lwlib

C_SWITCH_X_SITE=
C_SWITCH_SYSTEM=
C_SWITCH_MACHINE=
PROFILING_CFLAGS = 
WARN_CFLAGS = `echo  | sed 's/ -Wwrite-strings//'`
WERROR_CFLAGS = 

CC=clang -fobjc-arc
CFLAGS=-g3 -O2
CPPFLAGS=  
RANLIB=ranlib

AR = ar
ARFLAGS = cru

LUCID_OBJS = lwlib-Xlw.o xlwmenu.o lwlib-Xaw.o
MOTIF_OBJS = lwlib-Xm.o

## LUCID_OBJS or MOTIF_OBJS.
TOOLKIT_OBJS = $(none_OBJS)

OBJS = lwlib.o $(TOOLKIT_OBJS) lwlib-utils.o

## ../src is where the generated file (config.h, globals.h) are.
## $(srcdir)/../src is where the non-generated files (lisp.h) are.
## (In an out-of-tree build, these two are not the same.)
## $(srcdir) is where the lwlib sources are.
## There are no generated lwlib files, hence no need for -I.
ALL_CFLAGS= $(C_SWITCH_SYSTEM) $(C_SWITCH_X_SITE) \
  $(C_SWITCH_MACHINE) \
  $(WARN_CFLAGS) $(WERROR_CFLAGS) $(PROFILING_CFLAGS) $(CFLAGS) \
  -Demacs -I../src \
  -I$(srcdir) -I$(srcdir)/../src -I../lib -I$(srcdir)/../lib

.c.o:
	$(CC) -c $(CPPFLAGS) $(ALL_CFLAGS) $<

all:: liblw.a

liblw.a: $(OBJS)
	rm -f $@
	$(AR) $(ARFLAGS) $@ $(OBJS)
	$(RANLIB) $@

## Generated files in ../src, non-generated in $(srcdir)/../src.
config_h = ../src/config.h $(srcdir)/../src/conf_post.h
lisp_h = $(srcdir)/../src/lisp.h
## lisp.h includes this.
globals_h = ../src/globals.h
src_h = $(config_h) $(lisp_h) $(globals_h)

$(globals_h):
	cd ../src && $(MAKE) $(MFLAGS) globals.h

lwlib-utils.o: $(src_h) lwlib-utils.c lwlib-utils.h lwlib.h
lwlib.o:       $(src_h) lwlib.c lwlib.h lwlib-int.h lwlib-utils.h \
  lwlib-Xlw.h lwlib-Xm.h lwlib-Xaw.h
lwlib-Xlw.o:   $(src_h) lwlib-Xlw.c lwlib.h lwlib-int.h lwlib-Xlw.h xlwmenu.h
lwlib-Xaw.o:   $(src_h) lwlib-Xaw.c lwlib-Xaw.h lwlib.h lwlib-int.h
lwlib-Xm.o:    $(src_h) lwlib-Xm.c lwlib-Xm.h lwlib.h lwlib-int.h lwlib-utils.h
xlwmenu.o:     $(src_h) xlwmenu.c xlwmenu.h lwlib.h xlwmenuP.h \
  $(srcdir)/../src/xterm.h

mostlyclean:
	rm -f *.o liblw.a \#*

clean: mostlyclean
distclean: clean
	rm -f Makefile
maintainer-clean: distclean
	rm -f TAGS

TAGS:
	../lib-src/etags $(srcdir)/*.[ch]
tags: TAGS
.PHONY: tags
