# src/Makefile for GNU Emacs.

# Copyright (C) 1985, 1987-1988, 1993-1995, 1999-2013 Free Software
# Foundation, Inc.

# This file is part of GNU Emacs.

# GNU Emacs is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# GNU Emacs is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with GNU Emacs.  If not, see <http://www.gnu.org/licenses/>.


# Note that this file is edited by msdos/sed1v2.inp for MSDOS.  That
# script may need modifying in sync with changes made here.  Try to
# avoid shell-ism because the DOS build has to use the DOS shell.

SHELL = /bin/sh

# Here are the things that we expect ../configure to edit.
# We use $(srcdir) explicitly in dependencies so as not to depend on VPATH.
srcdir = /Users/netmask/Downloads/emacs-24.3/src
abs_builddir = /Users/netmask/Downloads/emacs-24.3/src
VPATH = $(srcdir)
CC = clang -fobjc-arc
CFLAGS = -g3 -O2
CPPFLAGS =   
LDFLAGS = 
LD_FIRSTFLAG=
EXEEXT = 
version = 24.3
# Substitute an assignment for the MAKE variable, because
# BSD doesn't have it as a default.

MKDIR_P = /usr/local/bin/gmkdir -p
# Don't use LIBS.  configure puts stuff in it that either shouldn't be
# linked with Emacs or is duplicated by the other stuff below.
# LIBS = -lm  -L/usr/local/Cellar/imagemagick/6.7.7-6/lib -lMagickWand -lMagickCore   -lpthread  
LIBOBJS = 

lispsource = $(srcdir)/../lisp
lib = ../lib
libsrc = ../lib-src
etc = ../etc
leimdir = ../leim
oldXMenudir = ../oldXMenu
lwlibdir = ../lwlib
lispdir = ../lisp

# Configuration files for .o files to depend on.
config_h = config.h $(srcdir)/conf_post.h

bootstrap_exe = $(abs_builddir)/bootstrap-emacs$(EXEEXT)

## ns-app if HAVE_NS, else empty.
OTHER_FILES = macosx-app

## Flags to pass for profiling builds
PROFILING_CFLAGS = 

## Flags to pass to the compiler to enable build warnings
WARN_CFLAGS = 
WERROR_CFLAGS = 

## Machine-specific CFLAGS.
C_SWITCH_MACHINE=
## System-specific CFLAGS.
C_SWITCH_SYSTEM=

MAC_CFLAGS=-fconstant-cfstrings
GNUSTEP_CFLAGS=

## Define C_SWITCH_X_SITE to contain any special flags your compiler
## may need to deal with X Windows.  For instance, if you've defined
## HAVE_X_WINDOWS and your X include files aren't in a place that your
## compiler can find on its own, you might want to add "-I/..." or
## something similar.  This is normally set by configure.
C_SWITCH_X_SITE=

## Define LD_SWITCH_X_SITE to contain any special flags your loader
## may need to deal with X Windows.  For instance, if your X libraries
## aren't in a place that your loader can find on its own, you might
## want to add "-L/..." or something similar.  Only used if
## HAVE_X_WINDOWS.
## FIXME? configure sets a value for this, but it has never been
## substituted in this or any other Makefile. Cf C_SWITCH_X_SITE.
LD_SWITCH_X_SITE=

## This must come before LD_SWITCH_SYSTEM.
## If needed, a -rpath option that says where to find X windows at run time.
LD_SWITCH_X_SITE_RPATH=-Wl,-rpath,/usr/X11/lib

## System-specific LDFLAGS.
LD_SWITCH_SYSTEM=

## This holds any special options for linking temacs only (ie, not
## used by configure).  Not used elsewhere because it sometimes
## contains options that have to do with using Emacs's crt0,
## which are only good with temacs.
LD_SWITCH_SYSTEM_TEMACS=-fno-pie -prebind -framework Carbon -framework WebKit -framework QuartzCore -framework Cocoa -Xlinker -headerpad -Xlinker 690

## Flags to pass to ld only for temacs.
TEMACS_LDFLAGS = $(LD_SWITCH_SYSTEM) $(LD_SWITCH_SYSTEM_TEMACS)

## If available, the full path to the paxctl program.
## On grsecurity/PaX systems, unexec will fail due to a gap between
## the bss section and the heap.  This can be prevented by disabling
## memory randomization in temacs with "paxctl -r".  See bug#11398.
PAXCTL = 

## Some systems define this to request special libraries.
LIBS_SYSTEM=

## Where to find libgcc.a, if using gcc and necessary.
LIB_GCC=

CRT_DIR=
## May use $CRT_DIR.
LIB_STANDARD=
START_FILES = pre-crt0.o

## -lm, or empty.
LIB_MATH=

## -lpthreads, or empty.
LIB_PTHREAD=-lpthread

LIBIMAGE=    

XFT_LIBS=
LIBX_EXTRA=-lX11 $(XFT_LIBS)

FONTCONFIG_CFLAGS = 
FONTCONFIG_LIBS = 
FREETYPE_CFLAGS = 
FREETYPE_LIBS = 
LIBOTF_CFLAGS = 
LIBOTF_LIBS = 
M17N_FLT_CFLAGS = 
M17N_FLT_LIBS = 

LIB_CLOCK_GETTIME=
LIB_TIMER_TIME=

DBUS_CFLAGS = 
DBUS_LIBS = 
## dbusbind.o if HAVE_DBUS, else empty.
DBUS_OBJ = 

LIB_EXECINFO=

SETTINGS_CFLAGS = 
SETTINGS_LIBS = 

## gtkutil.o if USE_GTK, else empty.
GTK_OBJ=

## -ltermcap, or -lncurses, or -lcurses, or "".
LIBS_TERMCAP=-lncurses
## terminfo.o if TERMINFO, else tparam.o.
TERMCAP_OBJ=terminfo.o

LIBXMU=-lXmu

LIBXSM=

LIBXTR6=

## $(LIBXMU) -lXt $(LIBXTR6) -lXext if USE_X_TOOLKIT, else $(LIBXSM).
## Only used if HAVE_X_WINDOWS.
LIBXT_OTHER=$(LIBXSM)

## If !HAVE_X11 || USE_GTK, empty.
## Else if USE_X_TOOLKIT really-lwlib, else really-oldxmenu.
OLDXMENU_TARGET=really-oldXMenu

## If !HAVE_X11 || USE_GTK, empty.
## Else if USE_X_TOOLKIT, $(lwlibdir)/liblw.a.
## Else $(oldXMenudir)/libXMenu11.a.
## (Actually, rather than being empty, it is set to "nothing".
## It is never actually used for anything in this case.
## This is done because there is a rule with target $(OLDXMENU) below,
## and I think it might be a syntax error with some makes to have
## an empty target, even if the associated rule is never run.
## http://lists.gnu.org/archive/html/help-make/2010-05/msg00058.html
## The alternative would be to put that rule in a makefile fragment.)
OLDXMENU=nothing

## If HAVE_X11 && !USE_GTK, $(OLDXMENU) ../src/$(OLDXMENU); else empty.
## We use stamp-xmenu with these two deps to both ensure that lwlib
## gets remade based on its dependencies in its own makefile,
## and remake temacs if lwlib gets changed by this.
OLDXMENU_DEPS=

## If !HAVE_X11 && HAVE_X_WINDOWS, -lXMenu (this case no longer possible).
## Else if !HAVE_X11 || USE_GTK, empty.
## Else $(OLDXMENU).
LIBXMENU=

## xmenu.o if HAVE_X_WINDOWS, else empty.
XMENU_OBJ=
## xterm.o xfns.o xselect.o xrdb.o xsmfns.o xsettings.o xgselect.o if
## HAVE_X_WINDOWS, else empty.
XOBJ=

TOOLKIT_LIBW=

## Only used if HAVE_X11, in LIBX_OTHER.
LIBXT=$(TOOLKIT_LIBW) $(LIBXT_OTHER)

## If HAVE_X11, $(LIBXT) $(LIBX_EXTRA), else empty.
LIBX_OTHER=

## LIBXMENU is nil if !HAVE_X_WINDOWS.
## LD_SWITCH_X_SITE should not be used if not using X, but nothing
## sets it at present, and if something ever does, it should be
## configure, which should set it to nil in non-X builds.
LIBX_BASE=$(LIBXMENU) $(LD_SWITCH_X_SITE)

## Only used for GNUstep
LIBS_GNUSTEP=

LIBSOUND= 
CFLAGS_SOUND= 

RSVG_LIBS= 
RSVG_CFLAGS= 

IMAGEMAGICK_LIBS= -L/usr/local/Cellar/imagemagick/6.7.7-6/lib -lMagickWand -lMagickCore  
IMAGEMAGICK_CFLAGS= -I/usr/local/Cellar/imagemagick/6.7.7-6/include/ImageMagick  

LIBXML2_LIBS = 
LIBXML2_CFLAGS = 

## widget.o if USE_X_TOOLKIT, otherwise empty.
WIDGET_OBJ=

## sheap.o if CYGWIN, otherwise empty.
CYGWIN_OBJ=

## fontset.o fringe.o image.o if we have any window system
WINDOW_SYSTEM_OBJ=fontset.o fringe.o image.o

## dosfns.o msdos.o w16select.o if MSDOS.
MSDOS_OBJ =
## w16select.o termcap.o if MSDOS && HAVE_X_WINDOWS.
MSDOS_X_OBJ =

## mac.o macterm.o macfns.o macmenu.o macselect.o macfont.o fontset.o
## fringe.o image.o if HAVE_MACGUI, otherwise empty.
MAC_OBJ=mac.o macterm.o macfns.o macmenu.o macselect.o macfont.o
## macappkit.o if HAVE_MACGUI, otherwise empty.
MAC_OBJC_OBJ=macappkit.o

NS_OBJ=
## nsterm.o nsfns.o nsmenu.o nsselect.o nsimage.o nsfont.o if HAVE_NS.
NS_OBJC_OBJ=
## Only set if NS_IMPL_GNUSTEP.
GNU_OBJC_CFLAGS=
## w32fns.o w32menu.c w32reg.o fringe.o fontset.o w32font.o w32term.o
## w32xfns.o w32select.o image.o w32uniscribe.o if HAVE_W32, else
## empty.
W32_OBJ=
## -lkernel32 -luser32 -lgdi32 -lole32 -lcomdlg32 lusp10 -lcomctl32
## --lwinspool if HAVE_W32, else empty.
W32_LIBS=

## Empty if !HAVE_X_WINDOWS
## xfont.o ftfont.o xftfont.o ftxfont.o if HAVE_XFT
## xfont.o ftfont.o ftxfont.o if HAVE_FREETYPE
## else xfont.o
FONT_OBJ=

LIBGPM = 

## -lresolv, or empty.
LIBRESOLV = 

LIBSELINUX_LIBS = 

LIBGNUTLS_LIBS = 
LIBGNUTLS_CFLAGS = 

LIB_PTHREAD_SIGMASK = 

INTERVALS_H = dispextern.h intervals.h composite.h

GETLOADAVG_LIBS = 

RUN_TEMACS = `/bin/pwd`/temacs

UNEXEC_OBJ = unexmacosx.o

CANNOT_DUMP=no

DEPDIR=deps
## -MMD -MF $(DEPDIR)/$*.d if AUTO_DEPEND; else empty.
DEPFLAGS=-MMD -MF ${DEPDIR}/$*.d -MP
## ${MKDIR_P} ${DEPDIR} (if AUTO_DEPEND); else ':'.
MKDEPDIR=${MKDIR_P} ${DEPDIR}

## DO NOT use -R.  There is a special hack described in lastfile.c
## which is used instead.  Some initialized data areas are modified
## at initial startup, then labeled as part of the text area when
## Emacs is dumped for the first time, and never changed again.
##
## -Demacs is needed to make some files produce the correct version
## for use in Emacs.
##
## FIXME? MYCPPFLAGS only referenced in etc/DEBUG.
ALL_CFLAGS=-Demacs $(MYCPPFLAGS) -I. -I$(srcdir) \
  -I$(lib) -I$(srcdir)/../lib \
  $(C_SWITCH_MACHINE) $(C_SWITCH_SYSTEM) $(C_SWITCH_X_SITE) \
  $(MAC_CFLAGS) $(GNUSTEP_CFLAGS) $(CFLAGS_SOUND) $(RSVG_CFLAGS) $(IMAGEMAGICK_CFLAGS) \
  $(LIBXML2_CFLAGS) $(DBUS_CFLAGS) \
  $(SETTINGS_CFLAGS) $(FREETYPE_CFLAGS) $(FONTCONFIG_CFLAGS) \
  $(LIBOTF_CFLAGS) $(M17N_FLT_CFLAGS) $(DEPFLAGS) $(PROFILING_CFLAGS) \
  $(LIBGNUTLS_CFLAGS) \
  $(WARN_CFLAGS) $(WERROR_CFLAGS) $(CFLAGS)
ALL_OBJC_CFLAGS=$(ALL_CFLAGS) $(GNU_OBJC_CFLAGS)

.SUFFIXES: .m
.c.o:
	@$(MKDEPDIR)
	$(CC) -c $(CPPFLAGS) $(ALL_CFLAGS) $<
.m.o:
	@$(MKDEPDIR)
	$(CC) -c $(CPPFLAGS) $(ALL_OBJC_CFLAGS) $<


## lastfile must follow all files whose initialized data areas should
## be dumped as pure by dump-emacs.
base_obj = dispnew.o frame.o scroll.o xdisp.o menu.o $(XMENU_OBJ) window.o \
	charset.o coding.o category.o ccl.o character.o chartab.o bidi.o \
	cm.o term.o terminal.o xfaces.o $(XOBJ) $(GTK_OBJ) $(DBUS_OBJ) \
	emacs.o keyboard.o macros.o keymap.o sysdep.o \
	buffer.o filelock.o insdel.o marker.o \
	minibuf.o fileio.o dired.o \
	cmds.o casetab.o casefiddle.o indent.o search.o regex.o undo.o \
	alloc.o data.o doc.o editfns.o callint.o \
	eval.o floatfns.o fns.o font.o print.o lread.o \
	syntax.o $(UNEXEC_OBJ) bytecode.o \
	process.o gnutls.o callproc.o \
	region-cache.o sound.o atimer.o \
	doprnt.o intervals.o textprop.o composite.o xml.o \
	profiler.o \
	$(MSDOS_OBJ) $(MSDOS_X_OBJ) $(MAC_OBJ) $(NS_OBJ) $(CYGWIN_OBJ) $(FONT_OBJ) \
	$(W32_OBJ) $(WINDOW_SYSTEM_OBJ)
obj = $(base_obj) $(MAC_OBJC_OBJ) $(NS_OBJC_OBJ)

## Object files used on some machine or other.
## These go in the DOC file on all machines in case they are needed.
## Some of them have no DOC entries, but it does no harm to have them
## in the list, in case they ever add any such entries.
SOME_MACHINE_OBJECTS = dosfns.o msdos.o \
  xterm.o xfns.o xmenu.o xselect.o xrdb.o xsmfns.o fringe.o image.o \
  mac.o macterm.o macfns.o macmenu.o macselect.o fontset.o dbusbind.o cygw32.o \
  nsterm.o nsfns.o nsmenu.o nsselect.o nsimage.o nsfont.o \
  w32.o w32console.o w32fns.o w32heap.o w32inevt.o \
  w32menu.o w32proc.o w32reg.o w32select.o w32term.o w32xfns.o \
  w16select.o widget.o xfont.o ftfont.o xftfont.o ftxfont.o gtkutil.o \
  xsettings.o xgselect.o termcap.o

## gmalloc.o if !SYSTEM_MALLOC && !DOUG_LEA_MALLOC, else empty.
GMALLOC_OBJ=

## vm-limit.o if !SYSTEM_MALLOC, else empty.
VMLIMIT_OBJ=

## ralloc.o if !SYSTEM_MALLOC && REL_ALLOC, else empty.
RALLOC_OBJ=

## Empty on Cygwin, lastfile.o elsewhere.
PRE_ALLOC_OBJ=lastfile.o
## lastfile.o on Cygwin, empty elsewhere.
POST_ALLOC_OBJ=

## List of object files that make-docfile should not be told about.
otherobj= $(TERMCAP_OBJ) $(PRE_ALLOC_OBJ) $(GMALLOC_OBJ) $(RALLOC_OBJ) \
  $(POST_ALLOC_OBJ) $(VMLIMIT_OBJ) $(WIDGET_OBJ) $(LIBOBJS)


## Configure inserts the file lisp.mk at this point, defining $lisp.
### lisp.mk --- src/Makefile fragment for GNU Emacs

## Copyright (C) 1985, 1987-1988, 1993-1995, 1999-2013 Free Software
## Foundation, Inc.

## This file is part of GNU Emacs.

## GNU Emacs is free software: you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.

## GNU Emacs is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.

## You should have received a copy of the GNU General Public License
## along with GNU Emacs.  If not, see <http://www.gnu.org/licenses/>.

### Commentary:

## This is the list of all Lisp files that might be loaded into the
## dumped Emacs.  Some of them are not loaded on all platforms, but
## the DOC file on every platform uses them (because the DOC file is
## supposed to be platform-independent).
## It is arranged like this because it is easier to generate it
## semi-mechanically from loadup.el this way.
## Eg something like:
##   sed -e 's/"[ )].*//' -n -e '/(load "/ s/.*load "//p' loadup.el | \
##   grep -vE 'site-|ldefs-boot'
## minus any duplicates.
## Note that you can generally just add a ".elc" extension to every file
## that does not have an explicit .el extension, but beware of any
## no-byte-compile ones.

## Confusingly, international/cp51932 and international/eucjp-ms are
## unconditionally loaded from language/japanese, instead of being
## loaded directly from loadup.el; FIXME.

## Note that this list should not include lisp files which might not
## be present, like site-load.el and site-init.el; this makefile
## expects them all to be either present or buildable.

## Place loaddefs.el first, so it gets generated first, since it is on
## the critical path (relevant in parallel compilations).

### Code:

## NB: This list is parsed by sed in the main src/Makefile.
## Do not change the formatting.
lisp = \
	$(lispsource)/loaddefs.el \
	$(lispsource)/loadup.el \
	$(lispsource)/emacs-lisp/byte-run.elc \
	$(lispsource)/emacs-lisp/backquote.elc \
	$(lispsource)/subr.elc \
	$(lispsource)/version.elc \
	$(lispsource)/widget.elc \
	$(lispsource)/custom.elc \
	$(lispsource)/emacs-lisp/map-ynp.elc \
	$(lispsource)/cus-start.elc \
	$(lispsource)/international/mule.elc \
	$(lispsource)/international/mule-conf.elc \
	$(lispsource)/env.elc \
	$(lispsource)/format.elc \
	$(lispsource)/bindings.elc \
	$(lispsource)/files.elc \
	$(lispsource)/emacs-lisp/macroexp.elc \
	$(lispsource)/cus-face.elc \
	$(lispsource)/faces.elc \
	$(lispsource)/button.elc \
	$(lispsource)/startup.elc \
	$(lispsource)/minibuffer.elc \
	$(lispsource)/abbrev.elc \
	$(lispsource)/simple.elc \
	$(lispsource)/help.elc \
	$(lispsource)/jka-cmpr-hook.elc \
	$(lispsource)/epa-hook.elc \
	$(lispsource)/international/mule-cmds.elc \
	$(lispsource)/case-table.elc \
	$(lispsource)/international/characters.elc \
	$(lispsource)/composite.elc \
	$(lispsource)/international/charprop.el \
	$(lispsource)/language/chinese.elc \
	$(lispsource)/language/cyrillic.elc \
	$(lispsource)/language/indian.elc \
	$(lispsource)/language/sinhala.elc \
	$(lispsource)/language/english.elc \
	$(lispsource)/language/ethiopic.elc \
	$(lispsource)/language/european.elc \
	$(lispsource)/language/czech.elc \
	$(lispsource)/language/slovak.elc \
	$(lispsource)/language/romanian.elc \
	$(lispsource)/language/greek.elc \
	$(lispsource)/language/hebrew.elc \
	$(lispsource)/language/japanese.elc \
	$(lispsource)/international/cp51932.el \
	$(lispsource)/international/eucjp-ms.el \
	$(lispsource)/language/korean.elc \
	$(lispsource)/language/lao.elc \
	$(lispsource)/language/tai-viet.elc \
	$(lispsource)/language/thai.elc \
	$(lispsource)/language/tibetan.elc \
	$(lispsource)/language/vietnamese.elc \
	$(lispsource)/language/misc-lang.elc \
	$(lispsource)/language/utf-8-lang.elc \
	$(lispsource)/language/georgian.elc \
	$(lispsource)/language/khmer.elc \
	$(lispsource)/language/burmese.elc \
	$(lispsource)/language/cham.elc \
	$(lispsource)/indent.elc \
	$(lispsource)/window.elc \
	$(lispsource)/frame.elc \
	$(lispsource)/term/tty-colors.elc \
	$(lispsource)/font-core.elc \
	$(lispsource)/facemenu.elc \
	$(lispsource)/emacs-lisp/syntax.elc \
	$(lispsource)/font-lock.elc \
	$(lispsource)/jit-lock.elc \
	$(lispsource)/mouse.elc \
	$(lispsource)/scroll-bar.elc \
	$(lispsource)/select.elc \
	$(lispsource)/emacs-lisp/timer.elc \
	$(lispsource)/isearch.elc \
	$(lispsource)/rfn-eshadow.elc \
	$(lispsource)/menu-bar.elc \
	$(lispsource)/emacs-lisp/lisp.elc \
	$(lispsource)/textmodes/page.elc \
	$(lispsource)/register.elc \
	$(lispsource)/textmodes/paragraphs.elc \
	$(lispsource)/emacs-lisp/lisp-mode.elc \
	$(lispsource)/textmodes/text-mode.elc \
	$(lispsource)/textmodes/fill.elc \
	$(lispsource)/newcomment.elc \
	$(lispsource)/replace.elc \
	$(lispsource)/emacs-lisp/tabulated-list.elc \
	$(lispsource)/buff-menu.elc \
	$(lispsource)/fringe.elc \
	$(lispsource)/emacs-lisp/regexp-opt.elc \
	$(lispsource)/image.elc \
	$(lispsource)/international/fontset.elc \
	$(lispsource)/dnd.elc \
	$(lispsource)/tool-bar.elc \
	$(lispsource)/dynamic-setting.elc \
	$(lispsource)/x-dnd.elc \
	$(lispsource)/term/common-win.elc \
	$(lispsource)/term/x-win.elc \
	$(lispsource)/w32-vars.elc \
	$(lispsource)/term/w32-win.elc \
	$(lispsource)/ls-lisp.elc \
	$(lispsource)/disp-table.elc \
	$(lispsource)/dos-w32.elc \
	$(lispsource)/w32-fns.elc \
	$(lispsource)/dos-fns.elc \
	$(lispsource)/dos-vars.elc \
	$(lispsource)/term/pc-win.elc \
	$(lispsource)/term/internal.elc \
	$(lispsource)/term/mac-win.elc \
	$(lispsource)/term/ns-win.elc \
	$(lispsource)/mwheel.elc \
	$(lispsource)/emacs-lisp/float-sup.elc \
	$(lispsource)/vc/vc-hooks.elc \
	$(lispsource)/vc/ediff-hook.elc \
	$(lispsource)/tooltip.elc


### lisp.mk ends here


## Construct full set of libraries to be linked.
## Note that SunOS needs -lm to come before -lc; otherwise, you get
## duplicated symbols.  If the standard libraries were compiled
## with GCC, we might need LIB_GCC again after them.
LIBES = $(LIBS) $(W32_LIBS) $(LIBS_GNUSTEP) $(LIBX_BASE) $(LIBIMAGE) \
   $(LIBX_OTHER) $(LIBSOUND) \
   $(RSVG_LIBS) $(IMAGEMAGICK_LIBS) $(LIB_CLOCK_GETTIME) \
   $(LIB_TIMER_TIME) $(DBUS_LIBS) \
   $(LIB_EXECINFO) \
   $(LIBXML2_LIBS) $(LIBGPM) $(LIBRESOLV) $(LIBS_SYSTEM) \
   $(LIBS_TERMCAP) $(GETLOADAVG_LIBS) $(SETTINGS_LIBS) $(LIBSELINUX_LIBS) \
   $(FREETYPE_LIBS) $(FONTCONFIG_LIBS) $(LIBOTF_LIBS) $(M17N_FLT_LIBS) \
   $(LIBGNUTLS_LIBS) $(LIB_PTHREAD) $(LIB_PTHREAD_SIGMASK) \
   $(LIB_GCC) $(LIB_MATH) $(LIB_STANDARD) $(LIB_GCC)

all: emacs$(EXEEXT) $(OTHER_FILES)
.PHONY: all

$(leimdir)/leim-list.el: bootstrap-emacs$(EXEEXT)
	cd $(leimdir) && $(MAKE) $(MFLAGS) leim-list.el EMACS=$(bootstrap_exe)

## The dumped Emacs is as functional and more efficient than
## bootstrap-emacs, so we replace the latter with the former.
## Strictly speaking, emacs does not depend directly on all of $lisp,
## since not all pieces are used on all platforms.  But DOC depends
## on all of $lisp, and emacs depends on DOC, so it is ok to use $lisp here.
emacs$(EXEEXT): temacs$(EXEEXT) $(etc)/DOC $(lisp) $(leimdir)/leim-list.el
	if test "$(CANNOT_DUMP)" = "yes"; then \
	  rm -f emacs$(EXEEXT); \
	  ln temacs$(EXEEXT) emacs$(EXEEXT); \
	else \
	  LC_ALL=C $(RUN_TEMACS) -batch -l loadup dump || exit 1; \
	  test "X$(PAXCTL)" = X || $(PAXCTL) -zex emacs$(EXEEXT); \
	  rm -f bootstrap-emacs$(EXEEXT); \
	  ln emacs$(EXEEXT) bootstrap-emacs$(EXEEXT); \
	fi

## We run make-docfile twice because the command line may get too long
## on some systems.  The sed command operating on lisp.mk also reduces
## the length of the command line.  Unfortunately, no-one has any idea
## exactly how long the maximum safe command line length is on all the
## various systems that Emacs supports.  Obviously, the length depends
## on what your value of $srcdir is.  If the length restriction goes
## away, lisp.mk can be merged back into this file.
##
## $(SOME_MACHINE_OBJECTS) comes before $(obj) because some files may
## or may not be included in $(obj), but they are always included in
## $(SOME_MACHINE_OBJECTS).  Since a file is processed when it is mentioned
## for the first time, this prevents any variation between configurations
## in the contents of the DOC file.
##
$(etc)/DOC: $(libsrc)/make-docfile$(EXEEXT) $(obj) $(lisp)
	-rm -f $(etc)/DOC
	$(libsrc)/make-docfile -d $(srcdir) $(SOME_MACHINE_OBJECTS) $(obj) > $(etc)/DOC
	$(libsrc)/make-docfile -a $(etc)/DOC -d $(lispsource) `sed -n -e 's| \\\\||' -e 's|^[ 	]*$$(lispsource)/||p' $(srcdir)/lisp.mk`

$(libsrc)/make-docfile$(EXEEXT):
	cd $(libsrc); $(MAKE) $(MFLAGS) make-docfile$(EXEEXT)

buildobj.h: Makefile
	echo "#define BUILDOBJ \"$(obj) $(otherobj) " "\"" > buildobj.h

globals.h: gl-stamp; @true

GLOBAL_SOURCES = $(base_obj:.o=.c) $(MAC_OBJC_OBJ:.o=.m) $(NS_OBJC_OBJ:.o=.m)

gl-stamp: $(libsrc)/make-docfile$(EXEEXT) $(GLOBAL_SOURCES)
	@rm -f gl-tmp
	$(libsrc)/make-docfile -d $(srcdir) -g $(obj) > gl-tmp
	$(srcdir)/../build-aux/move-if-change gl-tmp globals.h
	echo timestamp > $@

$(obj) $(otherobj): globals.h

$(lib)/libgnu.a: $(config_h)
	cd $(lib) && $(MAKE) libgnu.a

temacs$(EXEEXT): $(START_FILES) stamp-oldxmenu $(obj) $(otherobj) $(lib)/libgnu.a
	$(CC) $(LD_FIRSTFLAG) $(ALL_CFLAGS) $(TEMACS_LDFLAGS) $(LDFLAGS) \
	  -o temacs $(START_FILES) $(obj) $(otherobj) $(lib)/libgnu.a $(LIBES)
	test "$(CANNOT_DUMP)" = "yes" || \
	  test "X$(PAXCTL)" = X || $(PAXCTL) -r temacs$(EXEEXT)

## The following oldxmenu-related rules are only (possibly) used if
## HAVE_X11 && !USE_GTK, but there is no harm in always defining them
## (provided we take a little care that OLDXMENU is never empty).
really-lwlib: globals.h
	cd $(lwlibdir); $(MAKE) $(MFLAGS) \
    CC='$(CC)' CFLAGS='$(CFLAGS)' MAKE='$(MAKE)'
	@true  # make -t should not create really-lwlib.
.PHONY: really-lwlib

really-oldXMenu:
	cd $(oldXMenudir); $(MAKE) $(MFLAGS) \
    CC='$(CC)' CFLAGS='$(CFLAGS)' MAKE='$(MAKE)'
	@true  # make -t should not create really-oldXMenu.
.PHONY: really-oldXMenu

## We do not really need this when OLDXMENU_DEPS is empty, but as
## things stand we need something to satisfy the temacs dependency.
stamp-oldxmenu: $(OLDXMENU_DEPS)
	touch stamp-oldxmenu

## Supply an ordering for parallel make.
../src/$(OLDXMENU): $(OLDXMENU)

$(OLDXMENU): $(OLDXMENU_TARGET)

../config.status:: epaths.in
	@echo "The file epaths.h needs to be set up from epaths.in."
	@echo "Please run the `configure' script again."
	exit 1

../config.status:: config.in
	@echo "The file config.h needs to be set up from config.in."
	@echo "Please run the `configure' script again."
	exit 1

doc.o: buildobj.h

macosx-app: emacs$(EXEEXT)
	cd ../mac && $(MAKE) $(MFLAGS) all

ns-app: emacs$(EXEEXT)
	cd ../nextstep && $(MAKE) $(MFLAGS) all


.PHONY: mostlyclean clean bootstrap-clean distclean maintainer-clean
.PHONY: versionclean extraclean frc

mostlyclean:
	rm -f temacs$(EXEEXT) core *.core \#* *.o libXMenu11.a liblw.a
	rm -f ../etc/DOC
	rm -f bootstrap-emacs$(EXEEXT) emacs-$(version)$(EXEEXT)
	rm -f buildobj.h
	rm -f globals.h gl-stamp
clean: mostlyclean
	rm -f emacs-*.*.*$(EXEEXT) emacs$(EXEEXT)
	-rm -rf $(DEPDIR)

## bootstrap-clean is used to clean up just before a bootstrap.
## It should remove all files generated during a compilation/bootstrap,
## but not things like config.status or TAGS.
bootstrap-clean: clean
	rm -f epaths.h config.h config.stamp stamp-oldxmenu ../etc/DOC-*
	if test -f ./.gdbinit; then \
	  mv ./.gdbinit ./.gdbinit.save; \
	  if test -f "$(srcdir)/.gdbinit"; then rm -f ./.gdbinit.save; \
	  else mv ./.gdbinit.save ./.gdbinit; fi; \
	fi
## This is used in making a distribution.
## Do not use it on development directories!
distclean: bootstrap-clean
	rm -f Makefile
maintainer-clean: distclean
	@echo "This command is intended for maintainers to use;"
	@echo "it deletes files that may require special tools to rebuild."
	rm -f TAGS
versionclean:
	-rm -f emacs$(EXEEXT) emacs-*.*.*$(EXEEXT) ../etc/DOC*
extraclean: distclean
	-rm -f *~ \#* m/?*~ s/?*~

## Arrange to make a tags table TAGS-LISP for ../lisp,
## plus TAGS for the C files, which includes ../lisp/TAGS by reference.

ctagsfiles1 = [xyzXYZ]*.[hcm]
ctagsfiles2 = [a-wA-W]*.[hcm]

TAGS: $(srcdir)/$(ctagsfiles1) $(srcdir)/$(ctagsfiles2) $(S_FILE)
	../lib-src/etags --include=TAGS-LISP --include=$(lwlibdir)/TAGS \
	  --regex='/[ 	]*DEFVAR_[A-Z_ 	(]+"\([^"]+\)"/' \
	  $(srcdir)/$(ctagsfiles1) $(srcdir)/$(ctagsfiles2) $(S_FILE)
frc:
TAGS-LISP: frc
	$(MAKE) -f $(lispdir)/Makefile TAGS-LISP ETAGS=../lib-src/etags

$(lwlibdir)/TAGS:
	(cd $(lwlibdir); $(MAKE) -f $(lwlibdir)/Makefile tags ETAGS=../lib-src/etags)

tags: TAGS TAGS-LISP $(lwlibdir)/TAGS
.PHONY: tags


### Bootstrapping.

## Bootstrapping right is difficult because of the circular dependencies.
## Furthermore, we have to deal with the fact that many compilation targets
## such as loaddefs.el or *.elc can typically be produced by any old
## Emacs executable, so we would like to avoid rebuilding them whenever
## we build a new Emacs executable.
## To solve the circularity, we use 2 different Emacs executables,
## "emacs" is the main target and "bootstrap-emacs" is the one used
## to build the *.elc and loaddefs.el files.
## To solve the freshness issue, we used to use a third file "witness-emacs"
## which was used to witness the fact that there is a bootstrap-emacs
## executable, and then have dependencies on witness-emacs rather than
## bootstrap-emacs, but that lead to problems in parallel builds (because
## witness-emacs needed to be free from dependencies (to avoid rebuilding
## it), so it was compiled in parallel, leading typically to having 2
## processes dumping bootstrap-emacs at the same time).
## So instead, we replace the witness-emacs dependencies by conditional
## bootstrap-dependencies (via $(BOOTSTRAPEMACS)).  Of course, since we do
## not want to rely on GNU Make features, we have to rely on an external
## script to do the conditional part of the dependency
## (i.e. see the $(SUBDIR) rule ../Makefile.in).

.SUFFIXES: .elc .el

## These suffix rules do not allow additional dependencies, sadly, so
## instead of adding a $(BOOTSTRAPEMACS) dependency here, we add it
## separately below.
## With GNU Make, we would just say "%.el : %.elc $(BOOTSTRAPEMACS)"
.el.elc:
	@cd ../lisp; $(MAKE) $(MFLAGS) compile-onefile \
	                     THEFILE=$< EMACS=$(bootstrap_exe)

## Since the .el.elc rule cannot specify an extra dependency, we do it here.
$(lisp): $(BOOTSTRAPEMACS)

## VCSWITNESS points to the file that holds info about the current checkout.
## We use it as a heuristic to decide when to rebuild loaddefs.el.
$(lispsource)/loaddefs.el: $(BOOTSTRAPEMACS) $(VCSWITNESS)
	cd ../lisp; $(MAKE) $(MFLAGS) autoloads EMACS=$(bootstrap_exe)

## Dump an Emacs executable named bootstrap-emacs containing the
## files from loadup.el in source form.
bootstrap-emacs$(EXEEXT): temacs$(EXEEXT)
	cd ../lisp; $(MAKE) $(MFLAGS) update-subdirs
	if test "$(CANNOT_DUMP)" = "yes"; then \
	  rm -f bootstrap-emacs$(EXEEXT); \
	  ln temacs$(EXEEXT) bootstrap-emacs$(EXEEXT); \
	else \
	  $(RUN_TEMACS) --batch --load loadup bootstrap || exit 1; \
	  test "X$(PAXCTL)" = X || $(PAXCTL) -zex emacs$(EXEEXT); \
	  mv -f emacs$(EXEEXT) bootstrap-emacs$(EXEEXT); \
	fi
	@: Compile some files earlier to speed up further compilation.
	cd ../lisp; $(MAKE) $(MFLAGS) compile-first EMACS=$(bootstrap_exe)

## Insert either autodeps.mk (if AUTO_DEPEND), else deps.mk.
### autodeps.mk --- src/Makefile fragment for GNU Emacs

## This is inserted in src/Makefile if AUTO_DEPEND=yes.

ALLOBJS=$(START_FILES) ${obj} ${otherobj}
-include $(ALLOBJS:%.o=${DEPDIR}/%.d)


### Makefile.in ends here
