#### Makefile for the Emacs Lisp Introduction manual

# Copyright (C) 1994-1999, 2001-2013 Free Software Foundation, Inc.

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

srcdir = /Users/netmask/Downloads/emacs-24.3/doc/lispintro
version=24.3

buildinfodir = $(srcdir)/../../info
# Directory with the (customized) texinfo.tex file.
texinfodir = $(srcdir)/../misc

MKDIR_P = /usr/local/bin/gmkdir -p

INFO_EXT=.info
# Options used only when making info output.
INFO_OPTS=--no-split

MAKEINFO = /usr/bin/makeinfo
MAKEINFO_OPTS = --force -I $(srcdir)
TEXI2DVI = texi2dvi
TEXI2PDF = texi2pdf
DVIPS = dvips

ENVADD = TEXINPUTS="$(srcdir):$(texinfodir):$(TEXINPUTS)" \
         MAKEINFO="$(MAKEINFO) $(MAKEINFO_OPTS)"

mkinfodir = @${MKDIR_P} ${buildinfodir}

srcs = ${srcdir}/emacs-lisp-intro.texi ${srcdir}/doclicense.texi

.PHONY: info dvi html pdf ps

info: ${buildinfodir}/eintr$(INFO_EXT)

dvi: emacs-lisp-intro.dvi
html: emacs-lisp-intro.html
pdf: emacs-lisp-intro.pdf
ps: emacs-lisp-intro.ps

# The file name eintr must fit within 5 characters, to allow for
# -NN extensions to fit into DOS 8+3 limits without clashing.
# Note: "<" is not portable in ordinary make rules.
${buildinfodir}/eintr$(INFO_EXT): ${srcs}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/emacs-lisp-intro.texi

emacs-lisp-intro.dvi: ${srcs}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/emacs-lisp-intro.texi

emacs-lisp-intro.ps: emacs-lisp-intro.dvi
	$(DVIPS) -o $@ emacs-lisp-intro.dvi

emacs-lisp-intro.pdf: ${srcs}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/emacs-lisp-intro.texi

emacs-lisp-intro.html: ${srcs}
	$(MAKEINFO) $(MAKEINFO_OPTS) --html -o $@ ${srcdir}/emacs-lisp-intro.texi

.PHONY: mostlyclean clean distclean maintainer-clean infoclean

mostlyclean:
	rm -f *.aux *.log *.toc *.cp *.cps *.fn *.fns *.ky *.kys \
	  *.op *.ops *.pg *.pgs *.tp *.tps *.vr *.vrs

clean: mostlyclean
	rm -f emacs-lisp-intro.dvi emacs-lisp-intro.pdf emacs-lisp-intro.ps
	rm -rf emacs-lisp-intro.html/
	rm -f emacs-lispintro-${version}.tar*

distclean: clean

infoclean:
	-cd $(buildinfodir) && rm -f eintr$(INFO_EXT) eintr$(INFO_EXT)-[1-9]

maintainer-clean: distclean infoclean

.PHONY: dist

dist:
	rm -rf emacs-lispintro-${version}
	mkdir emacs-lispintro-${version}
	cp ${srcdir}/*.texi ${srcdir}/*.eps ${srcdir}/*.pdf \
	  ${texinfodir}/texinfo.tex \
	  ${srcdir}/ChangeLog* ${srcdir}/README emacs-lispintro-${version}/
	sed -e 's/@sr[c]dir@/./' -e 's/^\(texinfodir *=\).*/\1 ./' \
	  -e 's/^\(buildinfodir *=\).*/\1 ./' \
	  -e 's/^\(clean:.*\)/\1 infoclean/' \
	  -e "s/@ver[s]ion@/${version}/" \
	  ${srcdir}/Makefile.in > emacs-lispintro-${version}/Makefile
	tar -cf emacs-lispintro-${version}.tar emacs-lispintro-${version}
	rm -rf emacs-lispintro-${version}

### Makefile ends here
