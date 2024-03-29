#### Makefile for the Emacs Manual

# Copyright (C) 1994, 1996-2013 Free Software Foundation, Inc.

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

# Where to find the source code.  $(srcdir) will be the doc/emacs subdirectory
# of the source tree.  This is set by configure's `--srcdir' option.
srcdir=/Users/netmask/Downloads/emacs-24.3/doc/emacs

# Only for make dist.
version=24.3

## Where the output files go.
## Note that the setfilename command in the .texi files assumes this.
## This is a bit funny.  Because the info files are in the
## distribution tarfiles, they are always made in $scrdir/../../info,
## even for out-of-tree builds.
buildinfodir = $(srcdir)/../../info
# Directory with the (customized) texinfo.tex file.
texinfodir = $(srcdir)/../misc

MKDIR_P = /usr/local/bin/gmkdir -p

INFO_EXT=.info
# Options used only when making info output.
# --no-split is only needed because of MS-DOS.
# For a possible alternative, see
# http://lists.gnu.org/archive/html/emacs-devel/2011-01/msg01182.html
INFO_OPTS=--no-split

# The makeinfo program is part of the Texinfo distribution.
# Use --force so that it generates output even if there are errors.
MAKEINFO = /usr/bin/makeinfo
MAKEINFO_OPTS = --force --enable-encoding -I $(srcdir)

TEXI2DVI = texi2dvi
TEXI2PDF = texi2pdf
DVIPS = dvips


ENVADD = TEXINPUTS="$(srcdir):$(texinfodir):$(TEXINPUTS)" \
         MAKEINFO="$(MAKEINFO) $(MAKEINFO_OPTS)"


EMACS_XTRA= \
	${srcdir}/emacs-xtra.texi \
	$(srcdir)/arevert-xtra.texi \
	$(srcdir)/cal-xtra.texi \
	$(srcdir)/dired-xtra.texi \
	$(srcdir)/picture-xtra.texi \
	$(srcdir)/emerge-xtra.texi \
	$(srcdir)/vc-xtra.texi \
	$(srcdir)/vc1-xtra.texi \
	$(srcdir)/fortran-xtra.texi \
	$(srcdir)/msdog-xtra.texi

EMACSSOURCES= \
	${srcdir}/emacs.texi \
	${srcdir}/emacsver.texi \
	${srcdir}/doclicense.texi \
	${srcdir}/gpl.texi \
	${srcdir}/screen.texi \
	${srcdir}/commands.texi \
	${srcdir}/entering.texi \
	${srcdir}/basic.texi \
	${srcdir}/mini.texi \
	${srcdir}/m-x.texi \
	${srcdir}/help.texi \
	${srcdir}/mark.texi \
	${srcdir}/killing.texi \
	${srcdir}/regs.texi \
	${srcdir}/display.texi \
	${srcdir}/search.texi \
	${srcdir}/fixit.texi \
	${srcdir}/files.texi \
	${srcdir}/buffers.texi \
	${srcdir}/windows.texi \
	${srcdir}/frames.texi \
	${srcdir}/mule.texi \
	${srcdir}/modes.texi \
	${srcdir}/indent.texi \
	${srcdir}/text.texi \
	${srcdir}/programs.texi \
	${srcdir}/building.texi \
	${srcdir}/maintaining.texi \
	${srcdir}/abbrevs.texi \
	${srcdir}/sending.texi \
	${srcdir}/rmail.texi \
	${srcdir}/dired.texi \
	${srcdir}/calendar.texi \
	${srcdir}/misc.texi \
	${srcdir}/package.texi \
	${srcdir}/custom.texi \
	${srcdir}/trouble.texi \
	${srcdir}/cmdargs.texi \
	${srcdir}/xresources.texi \
	${srcdir}/anti.texi \
	${srcdir}/macport.texi \
	${srcdir}/macos.texi \
	${srcdir}/msdog.texi \
	${srcdir}/gnu.texi \
	${srcdir}/glossary.texi \
	${srcdir}/ack.texi \
	${srcdir}/kmacro.texi \
	$(EMACS_XTRA)

## This seems pointless.  The info/ directory exists in both the
## repository and the release tarfiles.
mkinfodir = @${MKDIR_P} ${buildinfodir}

.PHONY: info dvi html pdf ps

info: $(buildinfodir)/emacs$(INFO_EXT)
dvi: emacs.dvi
html: emacs.html
pdf: emacs.pdf
ps: emacs.ps

# Note that all the Info targets build the Info files in srcdir.
# There is no provision for Info files to exist in the build directory.
# In a distribution of Emacs, the Info files should be up to date.
# Note: "<" is not portable in ordinary make rules.
$(buildinfodir)/emacs$(INFO_EXT): ${EMACSSOURCES}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/emacs.texi

emacs.dvi: ${EMACSSOURCES}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/emacs.texi

emacs.ps: emacs.dvi
	$(DVIPS) -o $@ emacs.dvi

emacs.pdf: ${EMACSSOURCES}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/emacs.texi

emacs.html: ${EMACSSOURCES}
	$(MAKEINFO) $(MAKEINFO_OPTS) --html -o $@ ${srcdir}/emacs.texi

emacs-xtra.dvi: $(EMACS_XTRA)
	$(ENVADD) $(TEXI2DVI) ${srcdir}/emacs-xtra.texi

emacs-xtra.ps: emacs-xtra.dvi
	$(DVIPS) -o $@ emacs-xtra.dvi

emacs-xtra.pdf: $(EMACS_XTRA)
	$(ENVADD) $(TEXI2PDF) ${srcdir}/emacs-xtra.texi

.PHONY: mostlyclean clean distclean maintainer-clean infoclean

## Temp files.
mostlyclean:
	rm -f *.aux *.log *.toc *.cp *.cps *.fn *.fns *.ky *.kys \
	  *.op *.ops *.pg *.pgs *.tp *.tps *.vr *.vrs

## Products not in the release tarfiles.
clean: mostlyclean
	rm -f emacs.dvi emacs-xtra.dvi emacs.pdf emacs-xtra.pdf \
	  emacs.ps emacs-xtra.ps
	rm -rf emacs.html/
	rm -f emacs-manual-${version}.tar*

distclean: clean

## In the standalone tarfile, the clean rule runs this.
infoclean:
	-cd $(buildinfodir) && rm -f emacs$(INFO_EXT) emacs$(INFO_EXT)-[1-9] emacs$(INFO_EXT)-[1-9][0-9]

maintainer-clean: distclean infoclean

.PHONY: dist

## Make a standalone tarfile of the Emacs manual sources.
## The [c] is a dumb way to prevent configure expanding it.
dist:
	rm -rf emacs-manual-${version}
	mkdir emacs-manual-${version}
	cp ${srcdir}/*.texi ${texinfodir}/texinfo.tex \
	  ${srcdir}/ChangeLog* emacs-manual-${version}/
	sed -e 's/@sr[c]dir@/./' -e 's/^\(texinfodir *=\).*/\1 ./' \
	  -e 's/^\(buildinfodir *=\).*/\1 ./' \
	  -e 's/^\(clean:.*\)/\1 infoclean/' \
	  -e "s/@ver[s]ion@/${version}/" \
	  ${srcdir}/Makefile.in > emacs-manual-${version}/Makefile
	tar -cf emacs-manual-${version}.tar emacs-manual-${version}
	rm -rf emacs-manual-${version}

### Makefile ends here
