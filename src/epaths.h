/* Hey Emacs, this is -*- C -*- code!  */
/*
Copyright (C) 1993, 1995, 1997, 1999, 2001-2013 Free Software
Foundation, Inc.

This file is part of GNU Emacs.

GNU Emacs is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

GNU Emacs is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GNU Emacs.  If not, see <http://www.gnu.org/licenses/>.  */


/* Together with PATH_SITELOADSEARCH, this gives the default value of
   load-path, which is the search path for the Lisp function "load".
   Configure (using "make epaths-force") sets this to
   ${standardlisppath}, which typically has a value like:
   <datadir>/emacs/VERSION/lisp:<datadir>/emacs/VERSION/leim
   where datadir is eg /usr/local/share.
*/
#define PATH_LOADSEARCH "/usr/local/share/emacs/24.3/lisp:/usr/local/share/emacs/24.3/leim"


/* Like PATH_LOADSEARCH, but contains the non-standard pieces.
   These are the site-lisp directories, typically something like
   <datadir>/emacs/VERSION/site-lisp:<datadir>/emacs/site-lisp
   Configure prepends any $locallisppath, as set by the
   --enable-locallisppath argument.
   This is combined with PATH_LOADSEARCH to make the default load-path.
   If the --no-site-lisp option is used, this piece is excluded.
*/
#define PATH_SITELOADSEARCH "/usr/local/share/emacs/24.3/site-lisp:/usr/local/share/emacs/site-lisp"


/* Like PATH_LOADSEARCH, but used only during the build process
   when Emacs is dumping.  Configure (using "make epaths-force") sets
   this to $buildlisppath, which normally has the value: <srcdir>/lisp.
*/
#define PATH_DUMPLOADSEARCH "/Users/netmask/Downloads/emacs-24.3/lisp"

/* The extra search path for programs to invoke.  This is appended to
   whatever the PATH environment variable says to set the Lisp
   variable exec-path and the first file name in it sets the Lisp
   variable exec-directory.  exec-directory is used for finding
   executables and other architecture-dependent files.  */
#define PATH_EXEC "/usr/local/libexec/emacs/24.3/x86_64-apple-darwin12.2.0"

/* Where Emacs should look for its architecture-independent data
   files, like the NEWS file.  The lisp variable data-directory
   is set to this value.  */
#define PATH_DATA "/usr/local/share/emacs/24.3/etc"

/* Where Emacs should look for X bitmap files.
   The lisp variable x-bitmap-file-path is set based on this value.  */
#define PATH_BITMAPS "/usr/include/X11/bitmaps"

/* Where Emacs should look for its docstring file.  The lisp variable
   doc-directory is set to this value.  */
#define PATH_DOC "/usr/local/share/emacs/24.3/etc"

/* Where the configuration process believes the info tree lives.  The
   lisp variable configure-info-directory gets its value from this
   macro, and is then used to set the Info-default-directory-list.  */
#define PATH_INFO "/usr/local/share/info"

/* Where Emacs should store game score files.  */
#define PATH_GAME "/usr/local/var/games/emacs"

/* Where Emacs should look for the application default file. */
#define PATH_X_DEFAULTS "/usr/X11/share/X11/%L/%T/%N%C%S:/usr/X11/share/X11/%l/%T/%N%C%S:/usr/X11/share/X11/%T/%N%C%S:/usr/X11/share/X11/%L/%T/%N%S:/usr/X11/share/X11/%l/%T/%N%S:/usr/X11/share/X11/%T/%N%S:/usr/X11/lib/X11/%L/%T/%N%C%S:/usr/X11/lib/X11/%l/%T/%N%C%S:/usr/X11/lib/X11/%T/%N%C%S:/usr/X11/lib/X11/%L/%T/%N%S:/usr/X11/lib/X11/%l/%T/%N%S:/usr/X11/lib/X11/%T/%N%S"

