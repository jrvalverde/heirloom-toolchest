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
HDRSDIR = $(PREFIX)/share/lib/make

OBJ = ar.o depvar.o dist.o dmake.o doname.o dosys.o files.o globals.o \
	implicit.o macro.o main.o make.o misc.o nse.o nse_printdep.o \
	parallel.o pmake.o read.o read2.o rep.o state.o getopt.o version.o

XFLAGS = -I../include -D_GNU_SOURCE -DSUNOS4_AND_AFTER \
	-DHDRSDIR='"$(HDRSDIR)"' \
	-DSHELL='"$(SHELL)"' -DPOSIX_SHELL='"$(POSIX_SHELL)"'

.c.o:
	$(CC) $(CFLAGS) $(WARN) $(CPPFLAGS) $(XFLAGS) -c $<

.cc.o:
	$(CXX) $(CXXFLAGS) $(WARN) $(CPPFLAGS) $(XFLAGS) -c $<


MAKELIBS = -L../bsd -lbsd -L../makestate -lmakestate \
	-L../mksh -lmksh -L../vroot -lvroot \
	-L../mksdmsi18n -lmksdmsi18n

MAKEARCHIVES = ../bsd/libbsd.a ../makestate/libmakestate.a \
	../mksdmsi18n/libmksdmsi18n.a ../mksh/libmksh.a ../vroot/libvroot.a

all: make make_sus

make: $(OBJ) $(MAKEARCHIVES)
	$(CXX) $(LDFLAGS) $(OBJ) $(MAKELIBS) $(LIBS) -o $@

make_sus: $(OBJ) posix.o $(MAKEARCHIVES)
	$(CXX) $(LDFLAGS) $(OBJ) posix.o $(MAKELIBS) $(LIBS) -o $@

install: all
	mkdir -p $(ROOT)$(BINDIR) $(ROOT)$(HDRSDIR)
	$(INSTALL) -c make $(ROOT)$(BINDIR)/make
	$(STRIP) $(ROOT)$(BINDIR)/make
	rm -f $(ROOT)$(LIBDIR)/svr4.make
	ln -s ../bin/make $(ROOT)$(LIBDIR)/svr4.make
	$(INSTALL) -c make_sus $(ROOT)$(SUSBIN)/make
	$(STRIP) $(ROOT)$(SUSBIN)/make
	$(INSTALL) -c -m 644 make.rules.file $(ROOT)$(HDRSDIR)/make.rules
	$(INSTALL) -c -m 644 svr4.make.rules.file $(ROOT)$(HDRSDIR)/svr4.make.rules
	test -d $(ROOT)$(MANDIR)/man1 || mkdir -p $(ROOT)$(MANDIR)/man1
	$(INSTALL) -c -m 644 make.1 $(ROOT)$(MANDIR)/man1/make.1

clean:
	rm -f make make_sus $(OBJ) posix.o core log *~

mrproper: clean

ar.o: ar.cc ../include/avo/avo_alloca.h ../include/mk/defs.h \
  ../include/mksh/defs.h ../include/avo/intl.h ../include/vroot/vroot.h \
  ../include/mksh/misc.h
depvar.o: depvar.cc ../include/mk/defs.h ../include/mksh/defs.h \
  ../include/avo/intl.h ../include/vroot/vroot.h ../include/mksh/misc.h
dist.o: dist.cc
dmake.o: dmake.cc
doname.o: doname.cc ../include/avo/avo_alloca.h ../include/mk/defs.h \
  ../include/mksh/defs.h ../include/avo/intl.h ../include/vroot/vroot.h \
  ../include/mksh/i18n.h ../include/mksh/macro.h ../include/mksh/misc.h
dosys.o: dosys.cc ../include/mk/defs.h ../include/mksh/defs.h \
  ../include/avo/intl.h ../include/vroot/vroot.h ../include/mksh/dosys.h \
  ../include/mksh/misc.h
files.o: files.cc ../include/mk/defs.h ../include/mksh/defs.h \
  ../include/avo/intl.h ../include/vroot/vroot.h ../include/mksh/macro.h \
  ../include/mksh/misc.h
globals.o: globals.cc ../include/mk/defs.h ../include/mksh/defs.h \
  ../include/avo/intl.h ../include/vroot/vroot.h
implicit.o: implicit.cc ../include/mk/defs.h ../include/mksh/defs.h \
  ../include/avo/intl.h ../include/vroot/vroot.h ../include/mksh/macro.h \
  ../include/mksh/misc.h
macro.o: macro.cc ../include/mk/defs.h ../include/mksh/defs.h \
  ../include/avo/intl.h ../include/vroot/vroot.h ../include/mksh/macro.h \
  ../include/mksh/misc.h
main.o: main.cc ../include/bsd/bsd.h ../include/mk/copyright.h \
  ../include/mk/defs.h ../include/mksh/defs.h ../include/avo/intl.h \
  ../include/vroot/vroot.h ../include/mksdmsi18n/mksdmsi18n.h \
  ../include/mksh/macro.h ../include/mksh/misc.h \
  ../include/vroot/report.h
make.o: make.cc
misc.o: misc.cc ../include/mk/defs.h ../include/mksh/defs.h \
  ../include/avo/intl.h ../include/vroot/vroot.h ../include/mksh/macro.h \
  ../include/mksh/misc.h ../include/vroot/report.h
nse.o: nse.cc
nse_printdep.o: nse_printdep.cc ../include/mk/defs.h \
  ../include/mksh/defs.h ../include/avo/intl.h ../include/vroot/vroot.h \
  ../include/mksh/misc.h
parallel.o: parallel.cc
pmake.o: pmake.cc
read.o: read.cc ../include/avo/avo_alloca.h ../include/mk/defs.h \
  ../include/mksh/defs.h ../include/avo/intl.h ../include/vroot/vroot.h \
  ../include/mksh/macro.h ../include/mksh/misc.h ../include/mksh/read.h
read2.o: read2.cc ../include/mk/defs.h ../include/mksh/defs.h \
  ../include/avo/intl.h ../include/vroot/vroot.h ../include/mksh/dosys.h \
  ../include/mksh/macro.h ../include/mksh/misc.h
rep.o: rep.cc ../include/mk/defs.h ../include/mksh/defs.h \
  ../include/avo/intl.h ../include/vroot/vroot.h ../include/mksh/misc.h \
  ../include/vroot/report.h
state.o: state.cc ../include/mk/defs.h ../include/mksh/defs.h \
  ../include/avo/intl.h ../include/vroot/vroot.h ../include/mksh/misc.h
