# Makefile for lib-src subdirectory in GNU Emacs.
# Copyright (C) 1985, 1987-1988, 1993-1994, 2001-2013 Free Software
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


# Avoid trouble on systems where the `SHELL' variable might be
# inherited from the environment.
SHELL = /bin/sh

# Following ../lisp/Makefile.in.
EMACS = ../src/emacs
EMACSOPT = -batch --no-site-file --no-site-lisp

# ==================== Things `configure' will edit ====================

CC=clang -fobjc-arc
CFLAGS=-g3 -O2
version=24.3
## Used in $archlibdir.
configuration=x86_64-apple-darwin12.2.0
EXEEXT=
C_SWITCH_SYSTEM=
C_SWITCH_MACHINE=
PROFILING_CFLAGS = 
WARN_CFLAGS = 
WERROR_CFLAGS = 

# Program name transformation.
TRANSFORM = s,x,x,

# ==================== Where To Install Things ====================

# Location to install Emacs.app under GNUstep / Mac OS X.
# Later values may use this.
ns_appbindir=

# The default location for installation.  Everything is placed in
# subdirectories of this directory.  The default values for many of
# the variables below are expressed in terms of this one, so you may
# not need to change them.  This is set with the --prefix option to
# `../configure'.
prefix=/usr/local

# Like `prefix', but used for architecture-specific files.  This is
# set with the --exec-prefix option to `../configure'.
exec_prefix=${prefix}

# Where to install Emacs and other binaries that people will want to
# run directly (like etags).  This is set with the --bindir option
# to `../configure'.
bindir=${exec_prefix}/bin

# Where to install and expect executable files to be run by Emacs
# rather than directly by users, and other architecture-dependent
# data.  ${archlibdir} is usually below this.  This is set with the
# --libexecdir option to `../configure'.
libexecdir=${exec_prefix}/libexec

# Directory for local state files for all programs.
localstatedir=${prefix}/var

# Where to find the source code.  This is set by the configure
# script's `--srcdir' option.  However, the value of ${srcdir} in
# this makefile is not identical to what was specified with --srcdir,
# since the variable here has `/lib-src' added at the end.

# We use $(srcdir) explicitly in dependencies so as not to depend on VPATH.
srcdir=/Users/netmask/Downloads/emacs-24.3/lib-src
VPATH=/Users/netmask/Downloads/emacs-24.3/lib-src

# The top-level source directory, also set by configure.
top_srcdir=/Users/netmask/Downloads/emacs-24.3

# ==================== Emacs-specific directories ====================

# These variables hold the values Emacs will actually use.  They are
# based on the values of the standard Make variables above.

# Where to put executables to be run by Emacs rather than the user.
# This path usually includes the Emacs version and configuration name,
# so that multiple configurations for multiple versions of Emacs may
# be installed at once.  This can be set with the --archlibdir option
# to `../configure'.
archlibdir=${libexecdir}/emacs/${version}/${configuration}

gamedir=${localstatedir}/games/emacs
gameuser=games

# ==================== Utility Programs for the Build =================

# ../configure figures out the correct values for these.
INSTALL = /usr/local/bin/ginstall -c
INSTALL_PROGRAM = ${INSTALL}
INSTALL_SCRIPT = ${INSTALL}
# By default, we uphold the dignity of our programs.
INSTALL_STRIP =
MKDIR_P = /usr/local/bin/gmkdir -p

# ========================== Lists of Files ===========================

# Things that a user might actually run, which should be installed in bindir.
INSTALLABLES = etags${EXEEXT} ctags${EXEEXT} emacsclient${EXEEXT} \
               ebrowse${EXEEXT}

INSTALLABLE_SCRIPTS = grep-changelog

# Things that Emacs runs internally, or during the build process,
#  which should not be installed in bindir.
UTILITIES = profile${EXEEXT} movemail${EXEEXT} hexl${EXEEXT} \
            update-game-score${EXEEXT}

DONT_INSTALL= test-distrib${EXEEXT} make-docfile${EXEEXT}

# Like UTILITIES, but they're not system-dependent, and should not be
#  deleted by the distclean target.
SCRIPTS= rcs2log

# All files that are created by the linker, i.e., whose names end in ${EXEEXT}.
EXE_FILES = ${INSTALLABLES} ${UTILITIES} ${DONT_INSTALL}

# Specify additional -D flags for movemail. Options:
# -DMAIL_USE_FLOCK or -DMAIL_USE_LOCKF (use flock or lockf for file locking).
# See the comments about locking in movemail.c.  Normally the values
# set by configure should be correct and you should not need to do anything.
# If neither flag is set, you need to use blessmail.
MOVE_FLAGS=

## Empty if either MAIL_USE_FLOCK or MAIL_USE_LOCKF, else need-blessmail.
BLESSMAIL_TARGET=

## -lkrb if HAVE_LIBKRB or -lkrb4 if HAVE_LIBKRB4
KRB4LIB=
## -ldes if HAVE_LIBDES or -ldes425 if HAVE_LIBDES425
DESLIB=
## -lkrb5 if HAVE_LIBKRB5
KRB5LIB=
## -lk5crypto if HAVE_LIBK5CRYPTO or -lcrypto if HAVE_LIBCRYPTO
CRYPTOLIB=
## -lcom_err if HAVE_LIBCOM_ERR
COM_ERRLIB=
## -lhesiod if HAVE_LIBHESIOD
LIBHESIOD=
## -lresolv if HAVE_LIBRESOLV
LIBRESOLV=
## -llockfile if HAVE_LIBLOCKFILE or -lmail if HAVE_LIBMAIL
LIBS_MAIL=
## empty or -lrt or -lposix4 if HAVE_CLOCK_GETTIME
LIB_CLOCK_GETTIME = 

## Extra libraries to use when linking movemail.
LIBS_MOVE = $(LIBS_MAIL) $(KRB4LIB) $(DESLIB) $(KRB5LIB) $(CRYPTOLIB) \
            $(COM_ERRLIB) $(LIBHESIOD) $(LIBRESOLV)

## Some systems define this to request special libraries.
LIBS_SYSTEM = 

BASE_CFLAGS = $(C_SWITCH_SYSTEM) $(C_SWITCH_MACHINE) \
	      $(WARN_CFLAGS) $(WERROR_CFLAGS) \
	      -I. -I../src -I../lib \
	      -I${srcdir} -I${srcdir}/../src -I${srcdir}/../lib

ALL_CFLAGS = ${BASE_CFLAGS} ${PROFILING_CFLAGS} ${LDFLAGS} ${CPPFLAGS} ${CFLAGS}
LINK_CFLAGS = ${BASE_CFLAGS} ${LDFLAGS} ${CFLAGS}
CPP_CFLAGS = ${BASE_CFLAGS} ${PROFILING_CFLAGS} ${CPPFLAGS} ${CFLAGS}

# Configuration files for .o files to depend on.
config_h = ../src/config.h $(srcdir)/../src/conf_post.h

all: ${EXE_FILES} ${SCRIPTS} ${INSTALLABLE_SCRIPTS}

.PHONY: all need-blessmail maybe-blessmail

LOADLIBES = ../lib/libgnu.a $(LIBS_SYSTEM)
$(EXE_FILES): ../lib/libgnu.a

## Only used if we need blessmail, but no harm in always defining.
## This makes the actual blessmail executable.
blessmail:
	$(EMACS) $(EMACSOPT) -l $(srcdir)/../lisp/mail/blessmail.el
	chmod +x blessmail

## This checks if we need to run blessmail.
## Do not charge ahead and do it!  Let the installer decide.
need-blessmail: blessmail
	@if [ `wc -l <blessmail` != 2 ] ; then \
	  dir=`sed -n -e 's/echo mail directory = \(.*\)/\1/p' blessmail`; \
	  echo Assuming $$dir is really the mail spool directory, you should; \
	  echo run  lib-src/blessmail $(DESTDIR)${archlibdir}/movemail${EXEEXT}; \
	  echo as root, to give  movemail${EXEEXT}  appropriate permissions.; \
	  echo Do that after running  make install.; \
	fi

## This is the target invoked by the top-level Makefile.
maybe-blessmail: $(BLESSMAIL_TARGET)

## Install the internal utilities.  Until they are installed, we can
## just run them directly from lib-src.
## If the chown/chmod commands fail, that is not a big deal.
## update-game-score will detect at runtime that it is not setuid,
## and handle things accordingly.
$(DESTDIR)${archlibdir}: all
	@echo
	@echo "Installing utilities run internally by Emacs."
	umask 022; ${MKDIR_P} $(DESTDIR)${archlibdir}
	if [ `cd $(DESTDIR)${archlibdir} && /bin/pwd` != `/bin/pwd` ]; then \
	  for file in ${UTILITIES}; do \
	    $(INSTALL_PROGRAM) $(INSTALL_STRIP) $$file $(DESTDIR)${archlibdir}/$$file ; \
	  done ; \
        fi
	umask 022; ${MKDIR_P} $(DESTDIR)${gamedir}; \
	touch $(DESTDIR)${gamedir}/snake-scores; \
	touch $(DESTDIR)${gamedir}/tetris-scores
	-if chown ${gameuser} $(DESTDIR)${archlibdir}/update-game-score && chmod u+s $(DESTDIR)${archlibdir}/update-game-score; then \
	  chown ${gameuser} $(DESTDIR)${gamedir}; \
	  chmod u=rwx,g=rwx,o=rx $(DESTDIR)${gamedir}; \
	fi
	if [ `cd $(DESTDIR)${archlibdir} && /bin/pwd` \
             != `cd ${srcdir} && /bin/pwd` ]; then \
	  for file in ${SCRIPTS}; do \
	    $(INSTALL_SCRIPT) ${srcdir}/$$file $(DESTDIR)${archlibdir}/$$file; \
	  done ; \
	fi

.PHONY: install uninstall mostlyclean clean distclean maintainer-clean
.PHONY: extraclean check tags

install: $(DESTDIR)${archlibdir}
	@echo
	@echo "Installing utilities for users to run."
	umask 022; ${MKDIR_P} $(DESTDIR)${bindir}
	for file in ${INSTALLABLES} ; do \
	  $(INSTALL_PROGRAM) $(INSTALL_STRIP) $${file} $(DESTDIR)${bindir}/`echo $${file} | sed -e 's/${EXEEXT}$$//' -e '$(TRANSFORM)'`${EXEEXT} ; \
	done
	for file in ${INSTALLABLE_SCRIPTS} ; do \
	  $(INSTALL_SCRIPT) ${srcdir}/$${file} $(DESTDIR)${bindir}/`echo $${file} | sed '$(TRANSFORM)'`  ; \
	done

uninstall:
	for file in ${INSTALLABLES}; do \
	  rm -f $(DESTDIR)${bindir}/`echo $${file} | sed -e 's/${EXEEXT}$$//' -e '$(TRANSFORM)'`${EXEEXT} ; \
	done
	for file in ${INSTALLABLE_SCRIPTS}; do \
	  rm -f $(DESTDIR)${bindir}/`echo $${file} | sed '$(TRANSFORM)'` ; \
	done
	if [ -d $(DESTDIR)${archlibdir} ]; then \
	  (cd $(DESTDIR)${archlibdir} && rm -f ${UTILITIES} ${SCRIPTS}) \
	fi

mostlyclean:
	-rm -f core *.o

clean: mostlyclean
	-rm -f ${EXE_FILES}

distclean: clean
	-rm -f TAGS
	-rm -f Makefile blessmail

maintainer-clean: distclean
	true

extraclean: maintainer-clean
	-rm -f *~ \#*

## Test the contents of the directory.
check:
	@echo "We don't have any tests for the lib-src/ directory yet."

tags: TAGS
TAGS: etags${EXEEXT}
	etags *.[ch]

## This verifies that the non-ASCII characters in the file \`testfile\'
## have not been clobbered by whatever means were used to copy and
## distribute Emacs.  If they were clobbered, all the .elc files were
## clobbered too.
test-distrib${EXEEXT}: ${srcdir}/test-distrib.c
	$(CC) ${ALL_CFLAGS} -o test-distrib ${srcdir}/test-distrib.c
	./test-distrib ${srcdir}/testfile

../lib/libgnu.a: $(config_h)
	cd ../lib && $(MAKE) libgnu.a

regex.o: $(srcdir)/../src/regex.c $(srcdir)/../src/regex.h $(config_h)
	${CC} -c ${CPP_CFLAGS} -DCONFIG_BROKETS -DINHIBIT_STRING_HEADER \
	  ${srcdir}/../src/regex.c

etags${EXEEXT}: ${srcdir}/etags.c regex.o $(config_h)
	$(CC) ${ALL_CFLAGS} -DEMACS_NAME="\"GNU Emacs\"" \
	  -DVERSION="\"${version}\"" ${srcdir}/etags.c \
	  regex.o $(LOADLIBES) -o etags

ebrowse${EXEEXT}: ${srcdir}/ebrowse.c ${srcdir}/../lib/min-max.h $(config_h)
	$(CC) ${ALL_CFLAGS} -DVERSION="\"${version}\"" \
	  ${srcdir}/ebrowse.c $(LOADLIBES) -o ebrowse

## We depend on etags to assure that parallel makes do not write two
## etags.o files on top of each other.
ctags${EXEEXT}: etags${EXEEXT}
	$(CC) ${ALL_CFLAGS} -DCTAGS -DEMACS_NAME="\"GNU Emacs\"" \
	  -DVERSION="\"${version}\"" ${srcdir}/etags.c \
	  regex.o $(LOADLIBES) -o ctags

profile${EXEEXT}: ${srcdir}/profile.c $(config_h)
	$(CC) ${ALL_CFLAGS} ${srcdir}/profile.c \
	  $(LOADLIBES) $(LIB_CLOCK_GETTIME) -o profile

make-docfile${EXEEXT}: ${srcdir}/make-docfile.c $(config_h)
	$(CC) ${ALL_CFLAGS} ${srcdir}/make-docfile.c $(LOADLIBES) \
	  -o make-docfile

movemail${EXEEXT}: ${srcdir}/movemail.c pop.o $(config_h)
	$(CC) ${ALL_CFLAGS} ${MOVE_FLAGS} ${srcdir}/movemail.c pop.o \
	  $(LOADLIBES) $(LIBS_MOVE) -o movemail

pop.o: ${srcdir}/pop.c ${srcdir}/../lib/min-max.h $(config_h)
	$(CC) -c ${CPP_CFLAGS} ${MOVE_FLAGS} ${srcdir}/pop.c

emacsclient${EXEEXT}: ${srcdir}/emacsclient.c $(config_h)
	$(CC) ${ALL_CFLAGS} ${srcdir}/emacsclient.c \
	   -DVERSION="\"${version}\"" \
	   $(LOADLIBES) -o emacsclient

hexl${EXEEXT}: ${srcdir}/hexl.c $(config_h)
	$(CC) ${ALL_CFLAGS} ${srcdir}/hexl.c $(LOADLIBES) -o hexl

update-game-score${EXEEXT}: ${srcdir}/update-game-score.c $(config_h)
	$(CC) ${ALL_CFLAGS} -DHAVE_SHARED_GAME_DIR="\"$(gamedir)\"" \
	  ${srcdir}/update-game-score.c $(LOADLIBES) -o update-game-score

## Makefile ends here.
