### mac/Makefile for GNU Emacs Mac port

## Copyright (C) 2012-2013  YAMAMOTO Mitsuharu

## This file is part of GNU Emacs Mac port.

## GNU Emacs Mac port is free software: you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
## 
## GNU Emacs Mac port is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
## 
## You should have received a copy of the GNU General Public License
## along with GNU Emacs Mac port.  If not, see <http://www.gnu.org/licenses/>.

### Commentary:

### Code:
SHELL = /bin/sh

srcdir = /Users/netmask/Downloads/emacs-24.3/mac
EXEEXT = 


MKDIR_P = /usr/local/bin/gmkdir -p

lprojdirs = Emacs.app/Contents/Resources/English.lproj \
  Emacs.app/Contents/Resources/Dutch.lproj \
  Emacs.app/Contents/Resources/French.lproj \
  Emacs.app/Contents/Resources/German.lproj \
  Emacs.app/Contents/Resources/Italian.lproj \
  Emacs.app/Contents/Resources/Japanese.lproj \
  Emacs.app/Contents/Resources/Spanish.lproj \
  Emacs.app/Contents/Resources/ar.lproj \
  Emacs.app/Contents/Resources/ca.lproj \
  Emacs.app/Contents/Resources/cs.lproj \
  Emacs.app/Contents/Resources/da.lproj \
  Emacs.app/Contents/Resources/el.lproj \
  Emacs.app/Contents/Resources/fi.lproj \
  Emacs.app/Contents/Resources/he.lproj \
  Emacs.app/Contents/Resources/hr.lproj \
  Emacs.app/Contents/Resources/hu.lproj \
  Emacs.app/Contents/Resources/ko.lproj \
  Emacs.app/Contents/Resources/no.lproj \
  Emacs.app/Contents/Resources/pl.lproj \
  Emacs.app/Contents/Resources/pt.lproj \
  Emacs.app/Contents/Resources/pt_PT.lproj \
  Emacs.app/Contents/Resources/ro.lproj \
  Emacs.app/Contents/Resources/ru.lproj \
  Emacs.app/Contents/Resources/sk.lproj \
  Emacs.app/Contents/Resources/sv.lproj \
  Emacs.app/Contents/Resources/th.lproj \
  Emacs.app/Contents/Resources/tr.lproj \
  Emacs.app/Contents/Resources/uk.lproj \
  Emacs.app/Contents/Resources/zh_CN.lproj \
  Emacs.app/Contents/Resources/zh_TW.lproj

${lprojdirs}:
	${MKDIR_P} $@

ifneq ($(CURDIR),${srcdir})
Emacs.app/Contents/MacOS/Emacs.sh: ${srcdir}/Emacs.app/Contents/MacOS/Emacs.sh
	${MKDIR_P} Emacs.app/Contents/MacOS
	cp $< $@
Emacs.app/Contents/PkgInfo: ${srcdir}/Emacs.app/Contents/PkgInfo
	cp $< $@
Emacs.app/Contents/Resources/Emacs.icns: ${srcdir}/Emacs.app/Contents/Resources/Emacs.icns
	${MKDIR_P} Emacs.app/Contents/Resources
	cp $< $@
endif

macosx-bundle: ${lprojdirs} Emacs.app/Contents/MacOS/Emacs.sh \
	Emacs.app/Contents/PkgInfo Emacs.app/Contents/Resources/Emacs.icns
macosx-app: macosx-bundle Emacs.app/Contents/MacOS/Emacs
Emacs.app/Contents/MacOS/Emacs: ../src/emacs${EXEEXT}
	cp $< $@

.PHONY: all

all: macosx-app


.PHONY: clean distclean maintainer-clean

clean:
	rm -rf ${lprojdirs}
	rm -f Emacs.app/Contents/MacOS/Emacs

distclean: clean
	rm -f Makefile
	rm -f Emacs.app/Contents/Info.plist \
	  Emacs.app/Contents/Resources/English.lproj/InfoPlist.strings

maintainer-clean: distclean

### Makefile.in ends here
