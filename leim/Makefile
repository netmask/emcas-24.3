# Makefile for leim subdirectory in GNU Emacs.

# Copyright (C) 1997-2013 Free Software Foundation, Inc.
# Copyright (C) 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005,
#   2006, 2007, 2008, 2009, 2010, 2011
#   National Institute of Advanced Industrial Science and Technology (AIST)
#   Registration Number H14PRO021

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

# Here are the things that we expect ../configure to edit.
srcdir=/Users/netmask/Downloads/emacs-24.3/leim

# Which Emacs to use to convert TIT files to Emacs Lisp files,
# byte-compile Emacs Lisp files, and generate the file leim-list.el.
EMACS = ../src/emacs

buildlisppath=${srcdir}/../lisp

# How to run Emacs.
RUN_EMACS = EMACSLOADPATH=$(buildlisppath) LC_ALL=C \
	${EMACS} -batch --no-site-file --no-site-lisp

MKDIR_P = /usr/local/bin/gmkdir -p

# Files generated from TIT dictionaries for Chinese GB character set.
TIT_GB=\
	quail/CCDOSPY.el	\
	quail/Punct.el		\
	quail/QJ.el		\
	quail/SW.el		\
	quail/TONEPY.el

# Files generated from TIT dictionaries for Chinese BIG5 character set.
TIT_BIG5=\
	quail/4Corner.el	\
	quail/ARRAY30.el	\
	quail/ECDICT.el	\
	quail/ETZY.el		\
	quail/Punct-b5.el	\
	quail/PY-b5.el		\
	quail/QJ-b5.el		\
	quail/ZOZY.el

CHINESE_TIT=${TIT_GB} ${TIT_BIG5}

MISC= \
	quail/tsang-b5.el	\
	quail/quick-b5.el	\
	quail/tsang-cns.el	\
	quail/quick-cns.el	\
	quail/PY.el		\
	quail/ZIRANMA.el	\
	quail/CTLau.el		\
	quail/CTLau-b5.el

## The generated .el files.
TIT_MISC=${CHINESE_TIT} ${MISC}

.SUFFIXES: .elc .el

.el.elc:
	@echo Compiling $<
	@${RUN_EMACS} -l ${buildlisppath}/international/quail -f batch-byte-compile $<

all: leim-list.el compile-main
.PHONY: all

TIT_SOURCES= \
	${srcdir}/CXTERM-DIC/4Corner.tit \
	${srcdir}/CXTERM-DIC/ARRAY30.tit \
	${srcdir}/CXTERM-DIC/CCDOSPY.tit \
	${srcdir}/CXTERM-DIC/ECDICT.tit \
	${srcdir}/CXTERM-DIC/ETZY.tit \
	${srcdir}/CXTERM-DIC/PY-b5.tit \
	${srcdir}/CXTERM-DIC/Punct-b5.tit \
	${srcdir}/CXTERM-DIC/Punct.tit \
	${srcdir}/CXTERM-DIC/QJ-b5.tit \
	${srcdir}/CXTERM-DIC/QJ.tit \
	${srcdir}/CXTERM-DIC/SW.tit \
	${srcdir}/CXTERM-DIC/TONEPY.tit \
	${srcdir}/CXTERM-DIC/ZOZY.tit

${CHINESE_TIT}: changed.tit
	@true

## The changed.* files act to serialize this part of the build.
## A single Emacs invocation creates all the CHINESE_TIT files.
## Otherwise in a parallel build multiple Emacs instances could
## interfere with each other.  If we used GNU make we could probably
## parallelize this without the need for an explicit rule for each
## file.  Something like the pattern rule:
## quail/%.el: CXTERM-DIC/%.tit
## It doesn't seem possible to do this with VPATH and suffix rules.
changed.tit: ${TIT_SOURCES}
	@${MKDIR_P} quail
	${RUN_EMACS} -l ${buildlisppath}/international/titdic-cnv \
	  -f batch-titdic-convert -dir quail ${srcdir}/CXTERM-DIC; \
	  echo "changed" > $@

MISC_SOURCES= \
	${srcdir}/MISC-DIC/CTLau-b5.html \
	${srcdir}/MISC-DIC/CTLau.html \
	${srcdir}/MISC-DIC/cangjie-table.b5 \
	${srcdir}/MISC-DIC/cangjie-table.cns \
	${srcdir}/MISC-DIC/pinyin.map \
	${srcdir}/MISC-DIC/ziranma.cin

${MISC}: changed.misc
	@true

changed.misc: ${MISC_SOURCES}
	@${MKDIR_P} quail
	${RUN_EMACS} -l ${buildlisppath}/international/titdic-cnv \
	  -f batch-miscdic-convert -dir quail ${srcdir}/MISC-DIC; \
	  echo "changed" > $@

leim-list.el: ${TIT_MISC} ${srcdir}/leim-ext.el
	rm -f leim-list.el
	if [ x`cd ${srcdir} && /bin/pwd` = x`/bin/pwd` ] ; then \
	  ${RUN_EMACS} -l ${buildlisppath}/international/quail \
	    --eval "(update-leim-list-file \".\")" ; \
	else \
	  ${RUN_EMACS} -l ${buildlisppath}/international/quail \
	    --eval "(update-leim-list-file \".\" \"${srcdir}\")" ; \
	fi
	sed -n '/^[^;]/ p' < ${srcdir}/leim-ext.el >> $@

## Following adapted from lisp/Makefile.in.
setwins=wins="${srcdir}/ja-dic quail"; \
	[ `cd ${srcdir} && /bin/pwd` != `/bin/pwd` ] && \
	wins="$$wins ${srcdir}/quail"

.PHONY: compile-targets
# TARGETS is set dynamically in the recursive call from `compile-main'.
compile-targets: $(TARGETS)

# Compile all the Elisp files that need it.  Beware: it approximates
# `no-byte-compile', so watch out for false-positives!
.PHONY: compile-main
compile-main: ${TIT_MISC}
	@($(setwins); \
	els=`echo "$$wins " | sed -e 's| |/*.el |g'`; \
	for el in $$els; do \
	  test -f $$el || continue; \
	  test ! -f $${el}c && GREP_OPTIONS= grep '^;.*no-byte-compile: t' $$el > /dev/null && continue; \
	  echo "$${el}c"; \
	done | xargs echo) | \
	while read chunk; do \
	  $(MAKE) $(MFLAGS) compile-targets EMACS="$(EMACS)" TARGETS="$$chunk"; \
	done

.PHONY: clean mostlyclean bootstrap-clean distclean maintainer-clean extraclean

clean mostlyclean:
	rm -f ${TIT_MISC} ${TIT_MISC:.el=.elc} \
		leim-list.el changed.tit changed.misc

# The following target is needed because the `clean' target only removes
# TIT-generated files and doesn't touch compiled Quail packages.  But
# bootstrapping should not leave non-fresh .elc files behind.
bootstrap-clean: clean
	$(setwins); for w in $$wins; do rm -f $$w/*.elc; done

distclean: clean
	-[ `cd ${srcdir} && /bin/pwd` != `/bin/pwd` ] && rm -rf quail
	rm -f Makefile

maintainer-clean: distclean bootstrap-clean

extraclean: maintainer-clean
	-rm -f *~ \#* */*~ */\#*

.PHONY: check-declare

check-declare:
	$(RUN_EMACS) -l $(buildlisppath)/emacs-lisp/check-declare \
	  --eval '(check-declare-directory "$(srcdir)")'
