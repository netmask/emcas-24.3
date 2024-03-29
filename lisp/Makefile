# Maintenance productions for the Lisp directory
# Copyright (C) 2000-2013 Free Software Foundation, Inc.

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

srcdir = /Users/netmask/Downloads/emacs-24.3/lisp
top_srcdir = /Users/netmask/Downloads/emacs-24.3
abs_top_builddir = /Users/netmask/Downloads/emacs-24.3
lisp = $(srcdir)
VPATH = $(srcdir)

# You can specify a different executable on the make command line,
# e.g. "make EMACS=../src/emacs ...".

# We sometimes change directory before running Emacs (typically when
# building out-of-tree, we chdir to the source directory), so we need
# to use an absolute file name.
EMACS = ${abs_top_builddir}/src/emacs

# Command line flags for Emacs.

EMACSOPT = -batch --no-site-file --no-site-lisp

# Extra flags to pass to the byte compiler
BYTE_COMPILE_EXTRA_FLAGS =
# For example to not display the undefined function warnings you can use this:
# BYTE_COMPILE_EXTRA_FLAGS = --eval '(setq byte-compile-warnings (quote (not unresolved)))'
# The example above is just for developers, it should not be used by default.

lisptagsfiles1 = $(lisp)/*.el
lisptagsfiles2 = $(lisp)/*/*.el
lisptagsfiles3 = $(lisp)/*/*/*.el
lisptagsfiles4 = $(lisp)/*/*/*/*.el
ETAGS = ../lib-src/etags

# Automatically generated autoload files, apart from lisp/loaddefs.el.
# Note this includes only those files that need special rules to
# build; ie it does not need to include things created via
# generated-autoload-file (eg calc/calc-loaddefs.el).
LOADDEFS = $(lisp)/calendar/cal-loaddefs.el \
	$(lisp)/calendar/diary-loaddefs.el \
	$(lisp)/calendar/hol-loaddefs.el \
	$(lisp)/mh-e/mh-loaddefs.el \
	$(lisp)/net/tramp-loaddefs.el

# Elisp files auto-generated.
AUTOGENEL = loaddefs.el \
	$(LOADDEFS) \
	cus-load.el \
	finder-inf.el \
	subdirs.el \
	calc/calc-loaddefs.el \
	eshell/esh-groups.el \
	cedet/semantic/loaddefs.el \
	cedet/ede/loaddefs.el \
	cedet/srecode/loaddefs.el

# Versioned files that are the value of someone's `generated-autoload-file'.
# Note that update_loaddefs parses this.
AUTOGEN_VCS = \
	ps-print.el \
	emulation/tpu-edt.el \
	emacs-lisp/cl-loaddefs.el \
	mail/rmail.el \
	dired.el \
	ibuffer.el \
	htmlfontify.el \
	emacs-lisp/eieio.el

# Value of max-lisp-eval-depth when compiling initially.
# During bootstrapping the byte-compiler is run interpreted when compiling
# itself, and uses more stack than usual.
#
BIG_STACK_DEPTH = 2200
BIG_STACK_OPTS = --eval "(setq max-lisp-eval-depth $(BIG_STACK_DEPTH))"

BYTE_COMPILE_FLAGS = $(BIG_STACK_OPTS) $(BYTE_COMPILE_EXTRA_FLAGS)

# Files to compile before others during a bootstrap.  This is done to
# speed up the bootstrap process.  They're ordered by size, so we use
# the slowest-compiler on the smallest file and move to larger files as the
# compiler gets faster.  `autoload.elc' comes last because it is not used by
# the compiler (so its compilation does not speed up subsequent compilations),
# it's only placed here so as to speed up generation of the loaddefs.el file.

COMPILE_FIRST = \
	$(lisp)/emacs-lisp/macroexp.elc \
	$(lisp)/emacs-lisp/cconv.elc    \
	$(lisp)/emacs-lisp/byte-opt.elc \
	$(lisp)/emacs-lisp/bytecomp.elc \
	$(lisp)/emacs-lisp/autoload.elc

# The actual Emacs command run in the targets below.

emacs = EMACSLOADPATH=$(lisp) LC_ALL=C $(EMACS) $(EMACSOPT)

# Common command to find subdirectories
setwins=subdirs=`find . -type d -print`; \
	for file in $$subdirs; do \
	   case $$file in */.* | */.*/* | */=* ) ;; \
		*) wins="$$wins $$file" ;; \
	   esac; \
        done

# Find all subdirectories except `obsolete' and `term'.
setwins_almost=subdirs=`find . -type d -print`; \
	for file in $$subdirs; do \
	   case $$file in */.* | */.*/* | */=* | */obsolete | */term ) ;; \
		*) wins="$$wins $$file" ;; \
	   esac; \
        done

# Find all subdirectories in which we might want to create subdirs.el
setwins_for_subdirs=subdirs=`find . -type d -print`; \
	for file in $$subdirs; do \
	   case $$file in */.* | */.*/* | */=* | */cedet* ) ;; \
		*) wins="$$wins $$file" ;; \
	   esac; \
        done

# cus-load and finder-inf are not explicitly requested by anything, so
# we add them here to make sure they get built.
all: compile-main $(lisp)/cus-load.el $(lisp)/finder-inf.el

doit:

.PHONY: all doit custom-deps finder-data autoloads update-subdirs

# custom-deps and finder-data both used to scan _all_ the *.el files.
# This could lead to problems in parallel builds if automatically
# generated *.el files (eg loaddefs etc) were being changed at the same time.
# One solution was to add autoloads as a prerequisite:
# http://lists.gnu.org/archive/html/emacs-pretest-bug/2007-01/msg00469.html
# http://lists.gnu.org/archive/html/bug-gnu-emacs/2007-12/msg00171.html
# However, this meant that running these targets modified loaddefs.el,
# every time (due to time-stamping).  Calling these rules from
# bootstrap-after would modify loaddefs after src/emacs, resulting
# in make install remaking src/emacs for no real reason:
# http://lists.gnu.org/archive/html/emacs-devel/2008-02/msg00311.html
# Nowadays these commands don't scan automatically generated files,
# since they will never contain any useful information
# (see finder-no-scan-regexp and custom-dependencies-no-scan-regexp).
$(lisp)/cus-load.el:
	$(MAKE) $(MFLAGS) custom-deps
custom-deps: doit
	cd $(lisp); $(setwins_almost); \
	echo Directories: $$wins; \
	$(emacs) -l cus-dep --eval '(setq generated-custom-dependencies-file "$(lisp)/cus-load.el")' -f custom-make-dependencies $$wins

$(lisp)/finder-inf.el:
	$(MAKE) $(MFLAGS) finder-data
finder-data: doit
	cd $(lisp); $(setwins_almost); \
	echo Directories: $$wins; \
	$(emacs) -l finder --eval '(setq generated-finder-keywords-file "$(lisp)/finder-inf.el")' -f finder-compile-keywords-make-dist $$wins

# The chmod +w is to handle env var CVSREAD=1.
autoloads: $(LOADDEFS) doit
	cd $(lisp) && chmod +w $(AUTOGEN_VCS)
	cd $(lisp); $(setwins_almost); \
	echo Directories: $$wins; \
	$(emacs) -l autoload --eval '(setq generated-autoload-file "$(lisp)/loaddefs.el")' -f batch-update-autoloads $$wins

# This is required by the bootstrap-emacs target in ../src/Makefile, so
# we know that if we have an emacs executable, we also have a subdirs.el.
$(lisp)/subdirs.el:
	$(MAKE) $(MFLAGS) update-subdirs
update-subdirs: doit
	cd $(lisp); $(setwins_for_subdirs); \
	for file in $$wins; do \
	   $(top_srcdir)/build-aux/update-subdirs $$file; \
	done;

.PHONY: updates bzr-update update-authors

# Some modes of make-dist use this.
updates: update-subdirs autoloads finder-data custom-deps

# This is useful after "bzr up"; but it doesn't do anything that a
# plain "make" at top-level doesn't.
# The only difference between this and this directory's "all" rule
# is that this runs "autoloads" as well (because it uses "compile"
# rather than "compile-main").  In a bootstrap, $(lisp) in src/Makefile
# triggers this directory's autoloads rule.
bzr-update: compile finder-data custom-deps

# Update the AUTHORS file.

update-authors:
	$(emacs) -l authors -f batch-update-authors $(top_srcdir)/etc/AUTHORS $(top_srcdir)

TAGS TAGS-LISP: $(lisptagsfiles1) $(lisptagsfiles2) $(lisptagsfiles3) $(lisptagsfiles4)
	els=`echo $(lisptagsfiles1) $(lisptagsfiles2) $(lisptagsfiles3) $(lisptagsfiles4) | sed -e "s,$(lisp)/[^ ]*loaddefs[^ ]*,," -e "s,$(lisp)/ldefs-boot[^ ]*,,"`; \
	${ETAGS} -o $@ $$els

# The src/Makefile.in has its own set of dependencies and when they decide
# that one Lisp file needs to be re-compiled, we had better recompile it as
# well, otherwise every subsequent make will again call us, until we finally
# end up deciding that yes, the file deserves recompilation.
# One option is to try and reproduce exactly the same dependencies here as
# we have in src/Makefile.in, but it turns out to be painful
# (e.g. src/Makefile.in may have a dependency for ../lisp/foo.elc where we
# only know of $(lisp)/foo.elc).  So instead we provide a direct way for
# src/Makefile.in to rebuild a particular Lisp file, no questions asked.
# Use byte-compile-refresh-preloaded to try and work around some of
# the most common problems of not bootstrapping from a clean state.
.PHONY: compile-onefile
compile-onefile:
	@echo Compiling $(THEFILE)
	@# Use byte-compile-refresh-preloaded to try and work around some of
	@# the most common bootstrapping problems.
	@$(emacs) $(BYTE_COMPILE_FLAGS) \
		-l bytecomp -f byte-compile-refresh-preloaded \
		-f batch-byte-compile $(THEFILE)

# Files MUST be compiled one by one. If we compile several files in a
# row (i.e., in the same instance of Emacs) we can't make sure that
# the compilation environment is clean.  We also set the load-path of
# the Emacs used for compilation to the current directory and its
# subdirectories, to make sure require's and load's in the files being
# compiled find the right files.

.SUFFIXES: .elc .el

# An old-fashioned suffix rule, which, according to the GNU Make manual,
# cannot have prerequisites.
.el.elc:
	@echo Compiling $<
	@# The BIG_STACK_OPTS are only needed to byte-compile the byte-compiler
	@# files, which is normally done in compile-first, but may also be
	@# recompiled via this rule.
	@$(emacs) $(BYTE_COMPILE_FLAGS) \
		-f batch-byte-compile $<

.PHONY: compile-first compile-main compile compile-always

compile-first: $(COMPILE_FIRST)

# In `compile-main' we could directly do
#    ... | xargs $(MAKE) $(MFLAGS) EMACS="$(EMACS)"
# and it works, but it generates a lot of messages like
#    make[2]: « gnus/gnus-mlspl.elc » is up to date.
# so instead, we use "xargs echo" to split the list of file into manageable
# chunks and then use an intermediate `compile-targets' target so the
# actual targets (the .elc files) are not mentioned as targets on the
# make command line.


.PHONY: compile-targets
# TARGETS is set dynamically in the recursive call from `compile-main'.
compile-targets: $(TARGETS)

# Compile all the Elisp files that need it.  Beware: it approximates
# `no-byte-compile', so watch out for false-positives!
compile-main: compile-clean
	@(cd $(lisp); $(setwins); \
	els=`echo "$$wins " | sed -e 's|/\./|/|g' -e 's|/\. | |g' -e 's| |/*.el |g'`; \
	for el in $$els; do \
	  test -f $$el || continue; \
	  test ! -f $${el}c && GREP_OPTIONS= grep '^;.*no-byte-compile: t' $$el > /dev/null && continue; \
	  echo "$${el}c"; \
	done | xargs echo) | \
	while read chunk; do \
	  $(MAKE) $(MFLAGS) compile-targets EMACS="$(EMACS)" TARGETS="$$chunk"; \
	done

.PHONY: compile-clean
# Erase left-over .elc files that do not have a corresponding .el file.
compile-clean:
	@cd $(lisp); $(setwins); \
	elcs=`echo "$$wins " | sed -e 's|/\./|/|g' -e 's|/\. | |g' -e 's| |/*.elc |g'`; \
	for el in `echo $$elcs | sed -e 's/\.elc/\.el/g'`; do \
	  if test -f "$$el" -o \! -f "$${el}c"; then :; else \
	    echo rm "$${el}c"; \
	    rm "$${el}c"; \
	  fi \
	done

# Compile all Lisp files, but don't recompile those that are up to
# date.  Some .el files don't get compiled because they set the
# local variable no-byte-compile.
# Calling make recursively because suffix rule cannot have prerequisites.
# Explicitly pass EMACS (sometimes ../src/bootstrap-emacs) to those
# sub-makes that run rules that use it, for the sake of some non-GNU makes.
compile: $(LOADDEFS) autoloads compile-first
	$(MAKE) $(MFLAGS) compile-main EMACS=$(EMACS)

# Compile all Lisp files.  This is like `compile' but compiles files
# unconditionally.  Some files don't actually get compiled because they
# set the local variable no-byte-compile.
compile-always: doit
	cd $(lisp); rm -f *.elc */*.elc */*/*.elc */*/*/*.elc
	$(MAKE) $(MFLAGS) compile EMACS=$(EMACS)

.PHONY: compile-calc backup-compiled-files compile-after-backup

compile-calc:
	for el in $(lisp)/calc/*.el; do \
	  echo Compiling $$el; \
	  $(emacs) $(BYTE_COMPILE_FLAGS) -f batch-byte-compile $$el || exit 1;\
	done

# Backup compiled Lisp files in elc.tar.gz.  If that file already
# exists, make a backup of it.

backup-compiled-files:
	-mv $(lisp)/elc.tar.gz $(lisp)/elc.tar.gz~
	-tar czf $(lisp)/elc.tar.gz $(lisp)/*.elc $(lisp)/*/*.elc $(lisp)/*/*/*.elc $(lisp)/*/*/*/*.elc

# Compile Lisp files, but save old compiled files first.

compile-after-backup: backup-compiled-files compile-always

# This does the same job as the "compile" rule, but in a different way.
# Rather than spawning a separate Emacs instance to compile each file,
# it uses the same Emacs instance to compile everything.
# This is faster on a single core, since it avoids the overhead of
# starting Emacs many times (it was 33% faster on a test with a
# random 10% of the .el files needing recompilation).
# Unlike compile, this is not parallelizable; so if you have more than
# one core and use make -j#, compile will be (much) faster.
# This rule also produces less accurate compilation warnings.
# The environment of later files is affected by definitions in
# earlier ones, so it does not produce some warnings that it should.
# It can also produces spurious warnings about "invalid byte code" if
# files that use byte-compile-dynamic are updated.
# There is no reason to use this rule unless you only have a single
# core and CPU time is an issue.
.PHONY: compile-one-process
compile-one-process: doit $(LOADDEFS) compile-first $(lisp)/progmodes/cc-mode.elc
	$(emacs) $(BYTE_COMPILE_FLAGS) \
	    --eval "(batch-byte-recompile-directory 0)" $(lisp)

# Update MH-E internal autoloads. These are not to be confused with
# the autoloads for the MH-E entry points, which are already in loaddefs.el.
MH_E_DIR = $(lisp)/mh-e
## MH_E_SRC avoids a circular dependency warning for mh-loaddefs.el.
MH_E_SRC = $(MH_E_DIR)/mh-acros.el $(MH_E_DIR)/mh-alias.el    \
	$(MH_E_DIR)/mh-buffers.el  $(MH_E_DIR)/mh-compat.el   \
	$(MH_E_DIR)/mh-comp.el     $(MH_E_DIR)/mh-e.el        \
	$(MH_E_DIR)/mh-folder.el   $(MH_E_DIR)/mh-funcs.el    \
	$(MH_E_DIR)/mh-gnus.el     $(MH_E_DIR)/mh-identity.el \
	$(MH_E_DIR)/mh-inc.el      $(MH_E_DIR)/mh-junk.el     \
	$(MH_E_DIR)/mh-letter.el   $(MH_E_DIR)/mh-limit.el    \
	$(MH_E_DIR)/mh-mime.el     $(MH_E_DIR)/mh-print.el    \
	$(MH_E_DIR)/mh-scan.el     $(MH_E_DIR)/mh-search.el   \
	$(MH_E_DIR)/mh-seq.el      $(MH_E_DIR)/mh-show.el     \
	$(MH_E_DIR)/mh-speed.el    $(MH_E_DIR)/mh-thread.el   \
	$(MH_E_DIR)/mh-tool-bar.el $(MH_E_DIR)/mh-utils.el    \
	$(MH_E_DIR)/mh-xface.el

.PHONY: mh-autoloads
mh-autoloads: $(MH_E_DIR)/mh-loaddefs.el
$(MH_E_DIR)/mh-loaddefs.el: $(MH_E_SRC)
	$(emacs) -l autoload \
	   --eval "(setq generate-autoload-cookie \";;;###mh-autoload\")" \
	   --eval "(setq generated-autoload-file \"$@\")" \
	   --eval "(setq make-backup-files nil)" \
	   -f batch-update-autoloads $(MH_E_DIR)

# Update TRAMP internal autoloads. Maybe we could move tramp*.el into
# an own subdirectory. OTOH, it does not hurt to keep them in
# lisp/net.
TRAMP_DIR = $(lisp)/net
TRAMP_SRC = $(TRAMP_DIR)/tramp.el  $(TRAMP_DIR)/tramp-cache.el  \
	$(TRAMP_DIR)/tramp-cmds.el $(TRAMP_DIR)/tramp-compat.el \
	$(TRAMP_DIR)/tramp-ftp.el  $(TRAMP_DIR)/tramp-gvfs.el   \
	$(TRAMP_DIR)/tramp-gw.el   $(TRAMP_DIR)/tramp-sh.el	\
	$(TRAMP_DIR)/tramp-smb.el  $(TRAMP_DIR)/tramp-uu.el     \
	$(TRAMP_DIR)/trampver.el

$(TRAMP_DIR)/tramp-loaddefs.el: $(TRAMP_SRC)
	$(emacs) -l autoload \
	   --eval "(setq generate-autoload-cookie \";;;###tramp-autoload\")" \
	   --eval "(setq generated-autoload-file \"$@\")" \
	   --eval "(setq make-backup-files nil)" \
	   -f batch-update-autoloads $(TRAMP_DIR)

CAL_DIR = $(lisp)/calendar
## Those files that may contain internal calendar autoload cookies.
## Avoids circular dependency warning for *-loaddefs.el.
CAL_SRC = $(CAL_DIR)/cal-bahai.el $(CAL_DIR)/cal-china.el  \
	$(CAL_DIR)/cal-coptic.el  $(CAL_DIR)/cal-dst.el    \
	$(CAL_DIR)/cal-french.el  $(CAL_DIR)/cal-hebrew.el \
	$(CAL_DIR)/cal-html.el    $(CAL_DIR)/cal-islam.el  \
	$(CAL_DIR)/cal-iso.el     $(CAL_DIR)/cal-julian.el \
	$(CAL_DIR)/cal-mayan.el   $(CAL_DIR)/cal-menu.el   \
	$(CAL_DIR)/cal-move.el    $(CAL_DIR)/cal-persia.el \
	$(CAL_DIR)/cal-tex.el     $(CAL_DIR)/cal-x.el      \
	$(CAL_DIR)/calendar.el    $(CAL_DIR)/diary-lib.el  \
	$(CAL_DIR)/holidays.el    $(CAL_DIR)/lunar.el      \
	$(CAL_DIR)/solar.el

$(CAL_DIR)/cal-loaddefs.el: $(CAL_SRC)
	$(emacs) -l autoload \
	   --eval "(setq generate-autoload-cookie \";;;###cal-autoload\")" \
	   --eval "(setq generated-autoload-file \"$@\")" \
	   --eval "(setq make-backup-files nil)" \
	   -f batch-update-autoloads $(CAL_DIR)

$(CAL_DIR)/diary-loaddefs.el: $(CAL_SRC)
	$(emacs) -l autoload \
	   --eval "(setq generate-autoload-cookie \";;;###diary-autoload\")" \
	   --eval "(setq generated-autoload-file \"$@\")" \
	   --eval "(setq make-backup-files nil)" \
	   -f batch-update-autoloads $(CAL_DIR)

$(CAL_DIR)/hol-loaddefs.el: $(CAL_SRC)
	$(emacs) -l autoload \
	   --eval "(setq generate-autoload-cookie \";;;###holiday-autoload\")" \
	   --eval "(setq generated-autoload-file \"$@\")" \
	   --eval "(setq make-backup-files nil)" \
	   -f batch-update-autoloads $(CAL_DIR)

.PHONY: bootstrap-clean distclean maintainer-clean

bootstrap-clean:
	cd $(lisp); rm -f *.elc */*.elc */*/*.elc */*/*/*.elc $(AUTOGENEL)

distclean:
	-rm -f ./Makefile

maintainer-clean: distclean bootstrap-clean

.PHONY: check-declare

check-declare:
	$(emacs) -l $(lisp)/emacs-lisp/check-declare \
	  --eval '(check-declare-directory "$(lisp)")'

# Dependencies

# CC Mode uses a compile time macro system which causes a compile time
# dependency in cc-*.elc files on the macros in other cc-*.el and the
# version string in cc-defs.el.
$(lisp)/progmodes/cc-align.elc $(lisp)/progmodes/cc-awk.elc\
 $(lisp)/progmodes/cc-cmds.elc $(lisp)/progmodes/cc-compat.elc\
 $(lisp)/progmodes/cc-engine.elc $(lisp)/progmodes/cc-fonts.elc\
 $(lisp)/progmodes/cc-langs.elc $(lisp)/progmodes/cc-menus.elc\
 $(lisp)/progmodes/cc-mode.elc $(lisp)/progmodes/cc-styles.elc\
 $(lisp)/progmodes/cc-vars.elc: \
   $(lisp)/progmodes/cc-bytecomp.elc $(lisp)/progmodes/cc-defs.elc

$(lisp)/progmodes/cc-align.elc: \
   $(lisp)/progmodes/cc-vars.elc $(lisp)/progmodes/cc-engine.elc

$(lisp)/progmodes/cc-cmds.elc: \
   $(lisp)/progmodes/cc-vars.elc $(lisp)/progmodes/cc-engine.elc

$(lisp)/progmodes/cc-compat.elc: \
   $(lisp)/progmodes/cc-vars.elc $(lisp)/progmodes/cc-styles.elc \
   $(lisp)/progmodes/cc-engine.elc

$(lisp)/progmodes/cc-defs.elc: $(lisp)/progmodes/cc-bytecomp.elc \
   $(lisp)/emacs-lisp/cl.elc $(lisp)/emacs-lisp/regexp-opt.elc

$(lisp)/progmodes/cc-engine.elc: $(lisp)/progmodes/cc-langs.elc \
   $(lisp)/progmodes/cc-vars.elc

$(lisp)/progmodes/cc-fonts.elc: $(lisp)/progmodes/cc-langs.elc \
   $(lisp)/progmodes/cc-vars.elc $(lisp)/progmodes/cc-engine.elc \
   $(lisp)/font-lock.elc

$(lisp)/progmodes/cc-langs.elc: $(lisp)/progmodes/cc-vars.elc \
   $(lisp)/emacs-lisp/cl.elc

$(lisp)/progmodes/cc-mode.elc: $(lisp)/progmodes/cc-langs.elc \
   $(lisp)/progmodes/cc-vars.elc $(lisp)/progmodes/cc-engine.elc \
   $(lisp)/progmodes/cc-styles.elc $(lisp)/progmodes/cc-cmds.elc \
   $(lisp)/progmodes/cc-align.elc $(lisp)/progmodes/cc-menus.elc

$(lisp)/progmodes/cc-styles.elc: $(lisp)/progmodes/cc-vars.elc \
   $(lisp)/progmodes/cc-align.elc

$(lisp)/progmodes/cc-vars.elc: $(lisp)/custom.elc $(lisp)/widget.elc

# MH-E dependencies, mainly to prevent failures with parallel
# compilation, due to race conditions between writing a given FOO.elc
# file and another file being compiled that says "(require FOO)",
# which causes Emacs to try to read FOO.elc.
$(MH_E_DIR)/mh-alias.elc $(MH_E_DIR)/mh-comp.elc $(MH_E_DIR)/mh-folder.elc\
 $(MH_E_DIR)/mh-funcs.elc $(MH_E_DIR)/mh-identity.elc $(MH_E_DIR)/mh-inc.elc\
 $(MH_E_DIR)/mh-junk.elc $(MH_E_DIR)/mh-letter.elc $(MH_E_DIR)/mh-limit.elc\
 $(MH_E_DIR)/mh-mime.elc $(MH_E_DIR)/mh-print.elc $(MH_E_DIR)/mh-scan.elc\
 $(MH_E_DIR)/mh-search.elc $(MH_E_DIR)/mh-seq.elc $(MH_E_DIR)/mh-show.elc\
 $(MH_E_DIR)/mh-speed.elc $(MH_E_DIR)/mh-thread.elc $(MH_E_DIR)/mh-tool-bar.elc\
 $(MH_E_DIR)/mh-utils.elc $(MH_E_DIR)/mh-xface.elc:\
   $(MH_E_DIR)/mh-e.elc

$(MH_E_DIR)/mh-alias.elc $(MH_E_DIR)/mh-e.elc $(MH_E_DIR)/mh-folder.elc\
 $(MH_E_DIR)/mh-inc.elc $(MH_E_DIR)/mh-junk.elc $(MH_E_DIR)/mh-limit.elc\
 $(MH_E_DIR)/mh-search.elc $(MH_E_DIR)/mh-seq.elc $(MH_E_DIR)/mh-speed.elc\
 $(MH_E_DIR)/mh-utils.elc $(MH_E_DIR)/mh-xface.elc:\
   $(lisp)/emacs-lisp/cl.elc

$(MH_E_DIR)/mh-comp.elc $(MH_E_DIR)/mh-folder.elc $(MH_E_DIR)/mh-funcs.elc\
 $(MH_E_DIR)/mh-junk.elc $(MH_E_DIR)/mh-limit.elc $(MH_E_DIR)/mh-print.elc\
 $(MH_E_DIR)/mh-seq.elc $(MH_E_DIR)/mh-show.elc $(MH_E_DIR)/mh-thread.elc:\
   $(MH_E_DIR)/mh-scan.elc

$(MH_E_DIR)/mh-folder.elc $(MH_E_DIR)/mh-letter.elc $(MH_E_DIR)/mh-mime.elc\
 $(MH_E_DIR)/mh-search.elc $(MH_E_DIR)/mh-show.elc $(MH_E_DIR)/mh-speed.elc:\
   $(lisp)/gnus/gnus-util.elc

$(MH_E_DIR)/mh-folder.elc $(MH_E_DIR)/mh-search.elc:\
   $(lisp)/progmodes/which-func.elc

$(MH_E_DIR)/mh-letter.elc $(MH_E_DIR)/mh-seq.elc $(MH_E_DIR)/mh-show.elc\
 $(MH_E_DIR)/mh-utils.elc:\
   $(lisp)/font-lock.elc

$(MH_E_DIR)/mh-alias.elc $(MH_E_DIR)/mh-show.elc: $(lisp)/net/goto-addr.elc

$(MH_E_DIR)/mh-comp.elc: $(lisp)/mail/sendmail.elc

$(MH_E_DIR)/mh-e.elc: $(MH_E_DIR)/mh-buffers.elc $(lisp)/gnus/gnus.elc \
   $(lisp)/cus-face.elc

$(MH_E_DIR)/mh-letter.elc: $(lisp)/gnus/mailcap.elc $(lisp)/gnus/mm-decode.elc \
   $(lisp)/gnus/mm-view.elc  $(lisp)/gnus/mml.elc $(lisp)/gnus/message.elc

$(MH_E_DIR)/mh-print.elc:  $(lisp)/ps-print.elc

$(MH_E_DIR)/mh-search.elc: $(lisp)/imenu.elc

$(MH_E_DIR)/mh-show.elc: $(lisp)/gnus/gnus-cite.elc

$(MH_E_DIR)/mh-speed.elc: $(lisp)/speedbar.elc $(lisp)/emacs-lisp/timer.elc

$(MH_E_DIR)/mh-tool-bar.elc: $(lisp)/tool-bar.elc

# Makefile ends here.
