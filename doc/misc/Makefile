#### Makefile for documentation other than the Emacs manual.

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

# Where to find the source code.  $(srcdir) will be the man-aux
# subdirectory of the source tree.  This is
# set by the configure script's `--srcdir' option.
srcdir=/Users/netmask/Downloads/emacs-24.3/doc/misc

## Where the output files go.
buildinfodir = $(srcdir)/../../info
## Directory with emacsver.texi.
## Currently only used by efaq and calc.
emacsdir = $(srcdir)/../emacs

MKDIR_P = /usr/local/bin/gmkdir -p

INFO_EXT=.info
# Options used only when making info output.
INFO_OPTS=--no-split

# The makeinfo program is part of the Texinfo distribution.
# Use --force so that it generates output even if there are errors.
MAKEINFO = /usr/bin/makeinfo
MAKEINFO_OPTS = --force -I$(emacsdir)

INFO_TARGETS = ada-mode auth autotype bovine calc ccmode cl \
	dbus dired-x ebrowse ede ediff edt eieio \
	emacs-mime epa erc ert eshell eudc efaq \
	flymake forms gnus emacs-gnutls htmlfontify idlwave info.info \
	mairix-el message mh-e newsticker nxml-mode \
	org pcl-cvs pgg rcirc remember reftex sasl \
	sc semantic ses sieve smtpmail speedbar srecode tramp \
	url vip viper widget wisent woman

DVI_TARGETS = \
	ada-mode.dvi \
	auth.dvi \
	autotype.dvi \
	bovine.dvi \
	calc.dvi \
	cc-mode.dvi \
	cl.dvi \
	dbus.dvi \
	dired-x.dvi \
	ebrowse.dvi \
	ede.dvi \
	ediff.dvi \
	edt.dvi \
	eieio.dvi \
	emacs-mime.dvi \
	epa.dvi \
	erc.dvi \
	ert.dvi \
	eshell.dvi \
	eudc.dvi \
	faq.dvi \
	flymake.dvi \
	forms.dvi \
	gnus.dvi \
	emacs-gnutls.dvi \
	htmlfontify.dvi \
	idlwave.dvi \
	info.dvi \
	mairix-el.dvi \
	message.dvi \
	mh-e.dvi \
	newsticker.dvi \
	nxml-mode.dvi \
	org.dvi \
	pcl-cvs.dvi \
	pgg.dvi \
	rcirc.dvi \
	reftex.dvi \
	remember.dvi \
	sasl.dvi \
	sc.dvi \
	semantic.dvi \
	ses.dvi \
	sieve.dvi \
	smtpmail.dvi \
	speedbar.dvi \
	srecode.dvi \
	tramp.dvi \
	url.dvi \
	vip.dvi \
	viper.dvi \
	widget.dvi \
	wisent.dvi \
	woman.dvi

PDF_TARGETS = \
	ada-mode.pdf \
	auth.pdf \
	autotype.pdf \
	bovine.pdf \
	calc.pdf \
	cc-mode.pdf \
	cl.pdf \
	dbus.pdf \
	dired-x.pdf \
	ebrowse.pdf \
	ede.pdf \
	ediff.pdf \
	edt.pdf \
	eieio.pdf \
	emacs-mime.pdf \
	epa.pdf \
	erc.pdf \
	ert.pdf \
	eshell.pdf \
	eudc.pdf \
	faq.pdf \
	flymake.pdf \
	forms.pdf \
	gnus.pdf \
	htmlfontify.pdf \
	emacs-gnutls.pdf \
	idlwave.pdf \
	info.pdf \
	mairix-el.pdf \
	message.pdf \
	mh-e.pdf \
	newsticker.pdf \
	nxml-mode.pdf \
	org.pdf \
	pcl-cvs.pdf \
	pgg.pdf \
	rcirc.pdf \
	reftex.pdf \
	remember.pdf \
	sasl.pdf \
	sc.pdf \
	semantic.pdf \
	ses.pdf \
	sieve.pdf \
	smtpmail.pdf \
	speedbar.pdf \
	srecode.pdf \
	tramp.pdf \
	url.pdf \
	vip.pdf \
	viper.pdf \
	widget.pdf \
	wisent.pdf \
	woman.pdf

HTML_TARGETS = emacs-faq.html

TEXI2DVI = texi2dvi
TEXI2PDF = texi2pdf

ENVADD = TEXINPUTS="$(srcdir):$(emacsdir):$(TEXINPUTS)" \
         MAKEINFO="$(MAKEINFO) $(MAKEINFO_OPTS)"

mkinfodir = @${MKDIR_P} ${buildinfodir}

gfdl = ${srcdir}/doclicense.texi

.PHONY: info dvi pdf echo-info
## Prevent implicit rule triggering for foo.info.
.SUFFIXES:

# Default.
info: $(INFO_TARGETS)

## Used by top-level Makefile.
## Base file names of output info files.
echo-info:
	@echo "$(INFO_TARGETS) " | \
	  sed -e 's|[^ ]*/||g' -e 's/\.info//g' -e "s/  */$(INFO_EXT) /g"

# please modify this for all the web manual targets
webhack: clean
	$(MAKE) pdf MAKEINFO_OPTS="-DWEBHACKDEVEL $(MAKEINFO_OPTS)"

dvi: $(DVI_TARGETS)

pdf: $(PDF_TARGETS)

# Note that all the Info targets build the Info files in srcdir.
# There is no provision for Info files to exist in the build directory.
# In a distribution of Emacs, the Info files should be up to date.

# Note: "<" is not portable in ordinary make rules.

ada-mode : $(buildinfodir)/ada-mode$(INFO_EXT)
$(buildinfodir)/ada-mode$(INFO_EXT): ${srcdir}/ada-mode.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/ada-mode.texi
ada-mode.dvi: ${srcdir}/ada-mode.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/ada-mode.texi
ada-mode.pdf: ${srcdir}/ada-mode.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/ada-mode.texi

auth : $(buildinfodir)/auth$(INFO_EXT)
$(buildinfodir)/auth$(INFO_EXT): ${srcdir}/auth.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/auth.texi
auth.dvi: ${srcdir}/auth.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/auth.texi
auth.pdf: ${srcdir}/auth.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/auth.texi

autotype : $(buildinfodir)/autotype$(INFO_EXT)
$(buildinfodir)/autotype$(INFO_EXT): ${srcdir}/autotype.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/autotype.texi
autotype.dvi: ${srcdir}/autotype.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/autotype.texi
autotype.pdf: ${srcdir}/autotype.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/autotype.texi

bovine : $(buildinfodir)/bovine$(INFO_EXT)
$(buildinfodir)/bovine$(INFO_EXT): ${srcdir}/bovine.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/bovine.texi
bovine.dvi: ${srcdir}/bovine.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/bovine.texi
bovine.pdf: ${srcdir}/bovine.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/bovine.texi

calc : $(buildinfodir)/calc$(INFO_EXT)
$(buildinfodir)/calc$(INFO_EXT): ${srcdir}/calc.texi $(emacsdir)/emacsver.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/calc.texi
calc.dvi: ${srcdir}/calc.texi $(emacsdir)/emacsver.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/calc.texi
calc.pdf: ${srcdir}/calc.texi $(emacsdir)/emacsver.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/calc.texi

ccmode : $(buildinfodir)/ccmode$(INFO_EXT)
$(buildinfodir)/ccmode$(INFO_EXT): ${srcdir}/cc-mode.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/cc-mode.texi
cc-mode.dvi: ${srcdir}/cc-mode.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/cc-mode.texi
cc-mode.pdf: ${srcdir}/cc-mode.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/cc-mode.texi

cl : $(buildinfodir)/cl$(INFO_EXT)
$(buildinfodir)/cl$(INFO_EXT): ${srcdir}/cl.texi $(emacsdir)/emacsver.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/cl.texi
cl.dvi: ${srcdir}/cl.texi $(emacsdir)/emacsver.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/cl.texi
cl.pdf: ${srcdir}/cl.texi $(emacsdir)/emacsver.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/cl.texi

dbus : $(buildinfodir)/dbus$(INFO_EXT)
$(buildinfodir)/dbus$(INFO_EXT): ${srcdir}/dbus.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/dbus.texi
dbus.dvi: ${srcdir}/dbus.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/dbus.texi
dbus.pdf: ${srcdir}/dbus.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/dbus.texi

dired-x : $(buildinfodir)/dired-x$(INFO_EXT)
$(buildinfodir)/dired-x$(INFO_EXT): ${srcdir}/dired-x.texi $(emacsdir)/emacsver.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/dired-x.texi
dired-x.dvi: ${srcdir}/dired-x.texi $(emacsdir)/emacsver.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/dired-x.texi
dired-x.pdf: ${srcdir}/dired-x.texi $(emacsdir)/emacsver.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/dired-x.texi

ebrowse : $(buildinfodir)/ebrowse$(INFO_EXT)
$(buildinfodir)/ebrowse$(INFO_EXT): ${srcdir}/ebrowse.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/ebrowse.texi
ebrowse.dvi: ${srcdir}/ebrowse.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/ebrowse.texi
ebrowse.pdf: ${srcdir}/ebrowse.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/ebrowse.texi

ede : $(buildinfodir)/ede$(INFO_EXT)
$(buildinfodir)/ede$(INFO_EXT): ${srcdir}/ede.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/ede.texi
ede.dvi: ${srcdir}/ede.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/ede.texi
ede.pdf: ${srcdir}/ede.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/ede.texi

ediff : $(buildinfodir)/ediff$(INFO_EXT)
$(buildinfodir)/ediff$(INFO_EXT): ${srcdir}/ediff.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/ediff.texi
ediff.dvi: ${srcdir}/ediff.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/ediff.texi
ediff.pdf: ${srcdir}/ediff.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/ediff.texi

edt : $(buildinfodir)/edt$(INFO_EXT)
$(buildinfodir)/edt$(INFO_EXT): ${srcdir}/edt.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/edt.texi
edt.dvi: ${srcdir}/edt.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/edt.texi
edt.pdf: ${srcdir}/edt.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/edt.texi

eieio : $(buildinfodir)/eieio$(INFO_EXT)
$(buildinfodir)/eieio$(INFO_EXT): ${srcdir}/eieio.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/eieio.texi
eieio.dvi: ${srcdir}/eieio.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/eieio.texi
eieio.pdf: ${srcdir}/eieio.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/eieio.texi

emacs-gnutls : $(buildinfodir)/emacs-gnutls$(INFO_EXT)
$(buildinfodir)/emacs-gnutls$(INFO_EXT): ${srcdir}/emacs-gnutls.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/emacs-gnutls.texi
emacs-gnutls.dvi: ${srcdir}/emacs-gnutls.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/emacs-gnutls.texi
emacs-gnutls.pdf: ${srcdir}/emacs-gnutls.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/emacs-gnutls.texi

emacs-mime : $(buildinfodir)/emacs-mime$(INFO_EXT)
$(buildinfodir)/emacs-mime$(INFO_EXT): ${srcdir}/emacs-mime.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) --enable-encoding -o $@ ${srcdir}/emacs-mime.texi
emacs-mime.dvi: ${srcdir}/emacs-mime.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/emacs-mime.texi
emacs-mime.pdf: ${srcdir}/emacs-mime.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/emacs-mime.texi

epa : $(buildinfodir)/epa$(INFO_EXT)
$(buildinfodir)/epa$(INFO_EXT): ${srcdir}/epa.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/epa.texi
epa.dvi: ${srcdir}/epa.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/epa.texi
epa.pdf: ${srcdir}/epa.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/epa.texi

erc : $(buildinfodir)/erc$(INFO_EXT)
$(buildinfodir)/erc$(INFO_EXT): ${srcdir}/erc.texi $(emacsdir)/emacsver.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/erc.texi
erc.dvi: ${srcdir}/erc.texi $(emacsdir)/emacsver.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/erc.texi
erc.pdf: ${srcdir}/erc.texi $(emacsdir)/emacsver.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/erc.texi

ert : $(buildinfodir)/ert$(INFO_EXT)
$(buildinfodir)/ert$(INFO_EXT): ${srcdir}/ert.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/ert.texi
ert.dvi: ${srcdir}/ert.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/ert.texi
ert.pdf: ${srcdir}/ert.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/ert.texi

eshell : $(buildinfodir)/eshell$(INFO_EXT)
$(buildinfodir)/eshell$(INFO_EXT): ${srcdir}/eshell.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/eshell.texi
eshell.dvi: ${srcdir}/eshell.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/eshell.texi
eshell.pdf: ${srcdir}/eshell.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/eshell.texi

eudc : $(buildinfodir)/eudc$(INFO_EXT)
$(buildinfodir)/eudc$(INFO_EXT): ${srcdir}/eudc.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/eudc.texi
eudc.dvi: ${srcdir}/eudc.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/eudc.texi
eudc.pdf: ${srcdir}/eudc.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/eudc.texi

## No gfdl dependency.
efaq : $(buildinfodir)/efaq$(INFO_EXT)
$(buildinfodir)/efaq$(INFO_EXT): ${srcdir}/faq.texi $(emacsdir)/emacsver.texi
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/faq.texi
faq.dvi: ${srcdir}/faq.texi $(emacsdir)/emacsver.texi
	$(ENVADD) $(TEXI2DVI) ${srcdir}/faq.texi
faq.pdf: ${srcdir}/faq.texi $(emacsdir)/emacsver.texi
	$(ENVADD) $(TEXI2PDF) ${srcdir}/faq.texi
## This is the name used on the Emacs web-page.
## sed fixes up links to point to split version of the manual.
emacs-faq.html: ${srcdir}/faq.texi $(emacsdir)/emacsver.texi
	$(MAKEINFO) $(MAKEINFO_OPTS) --no-split \
	  --css-ref='/layout.css' --html -o $@ ${srcdir}/faq.texi
	sed -i -e 's|a href="\([a-z]*\)\.html#\([^"]*\)"|a href="manual/html_node/\1/\2.html"|g' \
	  -e 's|/Top\.html|/|g' $@
emacs-faq.text: ${srcdir}/faq.texi $(emacsdir)/emacsver.texi
	$(MAKEINFO) $(MAKEINFO_OPTS) --plaintext -o $@ ${srcdir}/faq.texi

flymake : $(buildinfodir)/flymake$(INFO_EXT)
$(buildinfodir)/flymake$(INFO_EXT): ${srcdir}/flymake.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/flymake.texi
flymake.dvi: ${srcdir}/flymake.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/flymake.texi
flymake.pdf: ${srcdir}/flymake.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/flymake.texi

forms : $(buildinfodir)/forms$(INFO_EXT)
$(buildinfodir)/forms$(INFO_EXT): ${srcdir}/forms.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/forms.texi
forms.dvi: ${srcdir}/forms.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/forms.texi
forms.pdf: ${srcdir}/forms.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/forms.texi

# gnus/message/emacs-mime/sieve/pgg are part of Gnus:
gnus : $(buildinfodir)/gnus$(INFO_EXT)
$(buildinfodir)/gnus$(INFO_EXT): ${srcdir}/gnus.texi ${srcdir}/gnus-faq.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/gnus.texi
gnus.dvi: ${srcdir}/gnus.texi ${srcdir}/gnus-faq.texi ${gfdl}
	sed -e '/@iflatex/,/@end iflatex/d' ${srcdir}/gnus.texi > gnustmp.texi
	$(ENVADD) $(TEXI2DVI) gnustmp.texi
	cp gnustmp.dvi $@
	rm gnustmp.*
gnus.pdf: ${srcdir}/gnus.texi ${srcdir}/gnus-faq.texi ${gfdl}
	sed -e '/@iflatex/,/@end iflatex/d' ${srcdir}/gnus.texi > gnustmp.texi
	$(ENVADD) $(TEXI2PDF) gnustmp.texi
	cp gnustmp.pdf $@
	rm gnustmp.*

htmlfontify : $(buildinfodir)/htmlfontify$(INFO_EXT)
$(buildinfodir)/htmlfontify$(INFO_EXT): ${srcdir}/htmlfontify.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/htmlfontify.texi
htmlfontify.dvi: ${srcdir}/htmlfontify.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/htmlfontify.texi
htmlfontify.pdf: ${srcdir}/htmlfontify.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/htmlfontify.texi

# NB this one needs --no-split even without a .info extension.
idlwave : $(buildinfodir)/idlwave$(INFO_EXT)
$(buildinfodir)/idlwave$(INFO_EXT): ${srcdir}/idlwave.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/idlwave.texi
idlwave.dvi: ${srcdir}/idlwave.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/idlwave.texi
idlwave.pdf: ${srcdir}/idlwave.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/idlwave.texi

# NB this one needs --no-split even without a .info extension.
# Avoid name clash with overall "info" target.
info.info : $(buildinfodir)/info$(INFO_EXT)
$(buildinfodir)/info$(INFO_EXT): ${srcdir}/info.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/info.texi
info.dvi: ${srcdir}/info.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/info.texi
info.pdf: ${srcdir}/info.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/info.texi

mairix-el : $(buildinfodir)/mairix-el$(INFO_EXT)
$(buildinfodir)/mairix-el$(INFO_EXT): ${srcdir}/mairix-el.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/mairix-el.texi
mairix-el.dvi: ${srcdir}/mairix-el.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/mairix-el.texi
mairix-el.pdf: ${srcdir}/mairix-el.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/mairix-el.texi

message : $(buildinfodir)/message$(INFO_EXT)
$(buildinfodir)/message$(INFO_EXT): ${srcdir}/message.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/message.texi
message.dvi: ${srcdir}/message.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/message.texi
message.pdf: ${srcdir}/message.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/message.texi

mh-e : $(buildinfodir)/mh-e$(INFO_EXT)
$(buildinfodir)/mh-e$(INFO_EXT): ${srcdir}/mh-e.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/mh-e.texi
mh-e.dvi: ${srcdir}/mh-e.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/mh-e.texi
mh-e.pdf: ${srcdir}/mh-e.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/mh-e.texi

newsticker : $(buildinfodir)/newsticker$(INFO_EXT)
$(buildinfodir)/newsticker$(INFO_EXT): ${srcdir}/newsticker.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/newsticker.texi
newsticker.dvi: ${srcdir}/newsticker.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/newsticker.texi
newsticker.pdf: ${srcdir}/newsticker.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/newsticker.texi

nxml-mode : $(buildinfodir)/nxml-mode$(INFO_EXT)
$(buildinfodir)/nxml-mode$(INFO_EXT): ${srcdir}/nxml-mode.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/nxml-mode.texi
nxml-mode.dvi: ${srcdir}/nxml-mode.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/nxml-mode.texi
nxml-mode.pdf: ${srcdir}/nxml-mode.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/nxml-mode.texi

org : $(buildinfodir)/org$(INFO_EXT)
$(buildinfodir)/org$(INFO_EXT): ${srcdir}/org.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/org.texi
org.dvi: ${srcdir}/org.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/org.texi
org.pdf: ${srcdir}/org.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/org.texi

pcl-cvs : $(buildinfodir)/pcl-cvs$(INFO_EXT)
$(buildinfodir)/pcl-cvs$(INFO_EXT): ${srcdir}/pcl-cvs.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/pcl-cvs.texi
pcl-cvs.dvi: ${srcdir}/pcl-cvs.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/pcl-cvs.texi
pcl-cvs.pdf: ${srcdir}/pcl-cvs.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/pcl-cvs.texi

pgg : $(buildinfodir)/pgg$(INFO_EXT)
$(buildinfodir)/pgg$(INFO_EXT): ${srcdir}/pgg.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/pgg.texi
pgg.dvi: ${srcdir}/pgg.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/pgg.texi
pgg.pdf: ${srcdir}/pgg.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/pgg.texi

rcirc : $(buildinfodir)/rcirc$(INFO_EXT)
$(buildinfodir)/rcirc$(INFO_EXT): ${srcdir}/rcirc.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/rcirc.texi
rcirc.dvi: ${srcdir}/rcirc.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/rcirc.texi
rcirc.pdf: ${srcdir}/rcirc.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/rcirc.texi

reftex : $(buildinfodir)/reftex$(INFO_EXT)
$(buildinfodir)/reftex$(INFO_EXT): ${srcdir}/reftex.texi $(emacsdir)/emacsver.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/reftex.texi
reftex.dvi: ${srcdir}/reftex.texi $(emacsdir)/emacsver.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/reftex.texi
reftex.pdf: ${srcdir}/reftex.texi $(emacsdir)/emacsver.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/reftex.texi

remember : $(buildinfodir)/remember$(INFO_EXT)
$(buildinfodir)/remember$(INFO_EXT): ${srcdir}/remember.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/remember.texi
remember.dvi: ${srcdir}/remember.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/remember.texi
remember.pdf: ${srcdir}/remember.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/remember.texi

sasl : $(buildinfodir)/sasl$(INFO_EXT)
$(buildinfodir)/sasl$(INFO_EXT): ${srcdir}/sasl.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/sasl.texi
sasl.dvi: ${srcdir}/sasl.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/sasl.texi
sasl.pdf: ${srcdir}/sasl.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/sasl.texi

sc : $(buildinfodir)/sc$(INFO_EXT)
$(buildinfodir)/sc$(INFO_EXT): ${srcdir}/sc.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/sc.texi
sc.dvi: ${srcdir}/sc.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/sc.texi
sc.pdf: ${srcdir}/sc.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/sc.texi

semantic : $(buildinfodir)/semantic$(INFO_EXT)
$(buildinfodir)/semantic$(INFO_EXT): ${srcdir}/semantic.texi ${srcdir}/sem-user.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/semantic.texi
semantic.dvi: ${srcdir}/semantic.texi ${srcdir}/sem-user.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/semantic.texi
semantic.pdf: ${srcdir}/semantic.texi ${srcdir}/sem-user.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/semantic.texi

ses : $(buildinfodir)/ses$(INFO_EXT)
$(buildinfodir)/ses$(INFO_EXT): ${srcdir}/ses.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/ses.texi
ses.dvi: ${srcdir}/ses.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/ses.texi
ses.pdf: ${srcdir}/ses.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/ses.texi

sieve : $(buildinfodir)/sieve$(INFO_EXT)
$(buildinfodir)/sieve$(INFO_EXT): ${srcdir}/sieve.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/sieve.texi
sieve.dvi: ${srcdir}/sieve.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/sieve.texi
sieve.pdf: ${srcdir}/sieve.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/sieve.texi

smtpmail : $(buildinfodir)/smtpmail$(INFO_EXT)
$(buildinfodir)/smtpmail$(INFO_EXT): ${srcdir}/smtpmail.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/smtpmail.texi
smtpmail.dvi: ${srcdir}/smtpmail.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/smtpmail.texi
smtpmail.pdf: ${srcdir}/smtpmail.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/smtpmail.texi

speedbar : $(buildinfodir)/speedbar$(INFO_EXT)
$(buildinfodir)/speedbar$(INFO_EXT): ${srcdir}/speedbar.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/speedbar.texi
speedbar.dvi: ${srcdir}/speedbar.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/speedbar.texi
speedbar.pdf: ${srcdir}/speedbar.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/speedbar.texi

srecode : $(buildinfodir)/srecode$(INFO_EXT)
$(buildinfodir)/srecode$(INFO_EXT): ${srcdir}/srecode.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/srecode.texi
srecode.dvi: ${srcdir}/srecode.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/srecode.texi
srecode.pdf: ${srcdir}/srecode.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/srecode.texi

tramp : $(buildinfodir)/tramp$(INFO_EXT)
$(buildinfodir)/tramp$(INFO_EXT): ${srcdir}/tramp.texi ${srcdir}/trampver.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ -D emacs ${srcdir}/tramp.texi
tramp.dvi: ${srcdir}/tramp.texi ${srcdir}/trampver.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/tramp.texi
tramp.pdf: ${srcdir}/tramp.texi ${srcdir}/trampver.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/tramp.texi

url : $(buildinfodir)/url$(INFO_EXT)
$(buildinfodir)/url$(INFO_EXT): ${srcdir}/url.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/url.texi
url.dvi: ${srcdir}/url.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/url.texi
url.pdf: ${srcdir}/url.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/url.texi

vip : $(buildinfodir)/vip$(INFO_EXT)
$(buildinfodir)/vip$(INFO_EXT): ${srcdir}/vip.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/vip.texi
vip.dvi: ${srcdir}/vip.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/vip.texi
vip.pdf: ${srcdir}/vip.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/vip.texi

viper : $(buildinfodir)/viper$(INFO_EXT)
$(buildinfodir)/viper$(INFO_EXT): ${srcdir}/viper.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/viper.texi
viper.dvi: ${srcdir}/viper.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/viper.texi
viper.pdf: ${srcdir}/viper.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/viper.texi

widget : $(buildinfodir)/widget$(INFO_EXT)
$(buildinfodir)/widget$(INFO_EXT): ${srcdir}/widget.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/widget.texi
widget.dvi: ${srcdir}/widget.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/widget.texi
widget.pdf: ${srcdir}/widget.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/widget.texi

wisent : $(buildinfodir)/wisent$(INFO_EXT)
$(buildinfodir)/wisent$(INFO_EXT): ${srcdir}/wisent.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/wisent.texi
wisent.dvi: ${srcdir}/wisent.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/wisent.texi
wisent.pdf: ${srcdir}/wisent.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/wisent.texi

woman : $(buildinfodir)/woman$(INFO_EXT)
$(buildinfodir)/woman$(INFO_EXT): ${srcdir}/woman.texi ${gfdl}
	$(mkinfodir)
	$(MAKEINFO) $(MAKEINFO_OPTS) $(INFO_OPTS) -o $@ ${srcdir}/woman.texi
woman.dvi: ${srcdir}/woman.texi ${gfdl}
	$(ENVADD) $(TEXI2DVI) ${srcdir}/woman.texi
woman.pdf: ${srcdir}/woman.texi ${gfdl}
	$(ENVADD) $(TEXI2PDF) ${srcdir}/woman.texi


.PHONY: mostlyclean clean distclean maintainer-clean

mostlyclean:
	rm -f *.aux *.log *.toc *.c[mp] *.c[mp]s *.fn *.fns \
	  *.ky *.kys *.op *.ops *.p[gj] *.p[gj]s *.sc *.scs *.ss \
	  *.t[gp] *.t[gp]s *.vr *.vrs
	rm -f gnustmp.*

clean: mostlyclean
	rm -f $(DVI_TARGETS) $(PDF_TARGETS) $(HTML_TARGETS) emacs-faq.text

distclean: clean
#	rm -f Makefile

## buildinfodir is relative to srcdir.
maintainer-clean: distclean
	cd $(buildinfodir); for file in $(INFO_TARGETS); do \
	  file=`echo $${file} | sed 's/\.info$$//'`${INFO_EXT}; \
	  rm -f $${file} $${file}-[1-9] $${file}-[1-9][0-9]; \
	done

### Makefile ends here
