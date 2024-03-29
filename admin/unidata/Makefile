# Makefile -- Makefile to generate character property tables.

# Copyright (C) 2012-2013 Free Software Foundation, Inc.

# Copyright (C) 2005, 2006, 2007, 2008, 2009, 2010, 2011
#   National Institute of Advanced Industrial Science and Technology (AIST)
#   Registration Number H13PRO009
#
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

SHELL = /bin/sh

srcdir = /Users/netmask/Downloads/emacs-24.3/admin/unidata
abs_builddir = /Users/netmask/Downloads/emacs-24.3/admin/unidata
top_srcdir = /Users/netmask/Downloads/emacs-24.3
abs_top_builddir = /Users/netmask/Downloads/emacs-24.3

EMACS = ${abs_top_builddir}/src/emacs
DSTDIR = ${top_srcdir}/lisp/international
emacs = ${EMACS} -batch --no-site-file --no-site-lisp

all: ${DSTDIR}/charprop.el

.el.elc:
	${emacs} -f batch-byte-compile $<

unidata.txt: ${srcdir}/UnicodeData.txt
	sed -e 's/\([^;]*\);\(.*\)/(#x\1 "\2")/' -e 's/;/" "/g' < ${srcdir}/UnicodeData.txt > $@

${DSTDIR}/charprop.el: ${srcdir}/unidata-gen.elc unidata.txt
	cd ${DSTDIR} && ${emacs} -l ${srcdir}/unidata-gen \
	  -f unidata-gen-files ${srcdir} ${abs_builddir}/unidata.txt

## Like the above, but generate in PWD rather than lisp/international.
charprop.el: ${srcdir}/unidata-gen.elc unidata.txt
	${emacs} -l ${srcdir}/unidata-gen \
	  -f unidata-gen-files ${srcdir} unidata.txt

install: charprop.el
	cp charprop.el ${DSTDIR}
	cp `sed -n 's/^;; FILE: //p' < charprop.el` ${DSTDIR}

clean:
	if test -f charprop.el; then \
	  rm -f `sed -n 's/^;; FILE: //p' < charprop.el`; \
	fi
	rm -f charprop.el ${srcdir}/unidata-gen.elc unidata.txt

distclean: clean
	-rm -f ./Makefile

maintainer-clean: distclean
