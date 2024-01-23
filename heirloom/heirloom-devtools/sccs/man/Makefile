#
# This is the shell used for the compilation phase and the default shell
# for the traditional variant of the "make" utility built. It needs not
# conform to POSIX. The system shell should work fine; for maximum
# compatibility with traditional tools, the Heirloom Bourne shell is
# recommended. It then must obviously be compiled and installed first.
#
#SHELL = /sbin/sh
SHELL = /home/jr/contrib/heirloom/usr/5bin/sh

#
# Specify the path name for a POSIX-conforming shell here. For example,
# Solaris users should insert /usr/xpg4/bin/sh. This shell is used as
# default shell for the POSIX variant of the "make" utility built.
#
#POSIX_SHELL = /bin/sh
POSIX_SHELL = sh

#
# A BSD-compatible install command.
#
#INSTALL=/usr/ucb/install
INSTALL=install

#
# Prefix.
#
PREFIX=/home/jr/contrib/heirloom/usr/ccs

#
# Where to place binaries.
#
BINDIR=$(PREFIX)/bin

#
# Where to place additional binaries that aim at POSIX conformance.
#
SUSBIN=$(PREFIX)/usr/5bin/posix

#
# Where to place libraries.
#
LIBDIR=$(PREFIX)/lib

#
# Where to place manual pages.
#
MANDIR=$(PREFIX)/share/man

#
# Binaries are stripped with this command after installation.
#
STRIP=strip -s -R .comment -R .note

#
# C++ compiler.
#
CXX = c++ -ansi

#
# Compiler flags.
#
CFLAGS=-O
CXXFLAGS=-O

#
# C preprocessor flags.
#
# Use -D_GNU_SOURCE for Linux with GNU libc.
# Use -D_INCLUDE__STDC_A1_SOURCE for HP-UX.
#
CPPFLAGS=-D_GNU_SOURCE

#
# Warning flags for the compiler.
#
#WARN=

#
# Linker flags.
#
LDFLAGS=

#
# Additional libraries to link with.
#
LIBS=

#
# It may be necessary to define AR on some systems, e.g. on HP-UX.
#
#AR=ar

#
# Run ranlib if it is in the current path. This should take care
# of most situations. On Mac OS X, you need to uncomment "ranlib -c".
#
RANLIB=(hash ranlib) >/dev/null 2>&1 || exit 0; ranlib
#RANLIB=ranlib -c

#
# Use the generated yacc to process .y files. You can set this to another
# value for cross-compiling.
#
YACC=`test -x ../yacc/yacc && echo ../yacc/yacc -P../yacc/yaccpar || echo yacc`

#
# Use this if you prefer hard links between installed files.
#
LNS = ln -s
all:

install: all
	test -d $(ROOT)$(MANDIR)/man1 || mkdir -p $(ROOT)$(MANDIR)/man1
	$(INSTALL) -c -m 644 admin.1 $(ROOT)$(MANDIR)/man1/admin.1
	$(INSTALL) -c -m 644 cdc.1 $(ROOT)$(MANDIR)/man1/cdc.1
	$(INSTALL) -c -m 644 comb.1 $(ROOT)$(MANDIR)/man1/comb.1
	$(INSTALL) -c -m 644 delta.1 $(ROOT)$(MANDIR)/man1/delta.1
	$(INSTALL) -c -m 644 get.1 $(ROOT)$(MANDIR)/man1/get.1
	$(INSTALL) -c -m 644 help.1 $(ROOT)$(MANDIR)/man1/help.1
	$(INSTALL) -c -m 644 prs.1 $(ROOT)$(MANDIR)/man1/prs.1
	$(INSTALL) -c -m 644 rmdel.1 $(ROOT)$(MANDIR)/man1/rmdel.1
	$(INSTALL) -c -m 644 sact.1 $(ROOT)$(MANDIR)/man1/sact.1
	$(INSTALL) -c -m 644 sccsdiff.1 $(ROOT)$(MANDIR)/man1/sccsdiff.1
	$(INSTALL) -c -m 644 unget.1 $(ROOT)$(MANDIR)/man1/unget.1
	$(INSTALL) -c -m 644 val.1 $(ROOT)$(MANDIR)/man1/val.1
	$(INSTALL) -c -m 644 vc.1 $(ROOT)$(MANDIR)/man1/vc.1
	$(INSTALL) -c -m 644 what.1 $(ROOT)$(MANDIR)/man1/what.1
	test -d $(ROOT)$(MANDIR)/man1b || mkdir -p $(ROOT)$(MANDIR)/man1b
	$(INSTALL) -c -m 644 prt.1b $(ROOT)$(MANDIR)/man1b/prt.1b
	$(INSTALL) -c -m 644 sccs.1b $(ROOT)$(MANDIR)/man1b/sccs.1b
	test -d $(ROOT)$(MANDIR)/man5 || mkdir -p $(ROOT)$(MANDIR)/man5
	$(INSTALL) -c -m 644 sccsfile.5 $(ROOT)$(MANDIR)/man5/sccsfile.5

clean:

mrproper: clean
