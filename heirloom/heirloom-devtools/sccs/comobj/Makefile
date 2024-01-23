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
.c.o:
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -I../hdr $(WARN) $<


OBJ = auxf.o chkid.o chksid.o cmpdate.o date_ab.o date_ba.o \
	del_ab.o del_ba.o dodelt.o dofile.o dohist.o doie.o \
	dolist.o encode.o eqsid.o flushto.o fmterr.o getline.o \
	getser.o logname.o newsid.o newstats.o permiss.o pf_ab.o \
	putline.o rdmod.o setup.o sid_ab.o sid_ba.o sidtoser.o \
	sinit.o stats_ab.o strptim.o

all: libcomobj.a

libcomobj.a: $(OBJ)
	$(AR) -rv $@ $(OBJ)
	$(RANLIB) $@

install: all

clean:
	rm -f libcomobj.a $(OBJ) core log *~

mrproper: clean

auxf.o: auxf.c ../hdr/defines.h ../hdr/macros.h ../hdr/fatal.h \
  ../hdr/fatal.h
chkid.o: chkid.c ../hdr/defines.h ../hdr/macros.h ../hdr/fatal.h \
  ../hdr/fatal.h
chksid.o: chksid.c ../hdr/defines.h ../hdr/macros.h ../hdr/fatal.h \
  ../hdr/fatal.h
cmpdate.o: cmpdate.c
date_ab.o: date_ab.c ../hdr/macros.h ../hdr/defines.h
date_ba.o: date_ba.c ../hdr/defines.h ../hdr/macros.h ../hdr/fatal.h \
  ../hdr/fatal.h
del_ab.o: del_ab.c ../hdr/defines.h ../hdr/macros.h ../hdr/fatal.h \
  ../hdr/fatal.h
del_ba.o: del_ba.c ../hdr/defines.h ../hdr/macros.h ../hdr/fatal.h \
  ../hdr/fatal.h
dodelt.o: dodelt.c ../hdr/defines.h ../hdr/macros.h ../hdr/fatal.h \
  ../hdr/fatal.h
dofile.o: dofile.c ../hdr/defines.h ../hdr/macros.h ../hdr/fatal.h \
  ../hdr/fatal.h
dohist.o: dohist.c ../hdr/defines.h ../hdr/macros.h ../hdr/fatal.h \
  ../hdr/fatal.h ../hdr/had.h ../hdr/i18n.h
doie.o: doie.c ../hdr/defines.h ../hdr/macros.h ../hdr/fatal.h \
  ../hdr/fatal.h
dolist.o: dolist.c ../hdr/defines.h ../hdr/macros.h ../hdr/fatal.h \
  ../hdr/fatal.h
encode.o: encode.c ../hdr/defines.h ../hdr/macros.h ../hdr/fatal.h \
  ../hdr/fatal.h
eqsid.o: eqsid.c ../hdr/defines.h ../hdr/macros.h ../hdr/fatal.h \
  ../hdr/fatal.h
flushto.o: flushto.c ../hdr/defines.h ../hdr/macros.h ../hdr/fatal.h \
  ../hdr/fatal.h
fmterr.o: fmterr.c ../hdr/defines.h ../hdr/macros.h ../hdr/fatal.h \
  ../hdr/fatal.h
getline.o: getline.c ../hdr/defines.h ../hdr/macros.h ../hdr/fatal.h \
  ../hdr/fatal.h
getser.o: getser.c ../hdr/defines.h ../hdr/macros.h ../hdr/fatal.h \
  ../hdr/fatal.h ../hdr/had.h
logname.o: logname.c ../hdr/defines.h ../hdr/macros.h ../hdr/fatal.h \
  ../hdr/fatal.h
newsid.o: newsid.c ../hdr/defines.h ../hdr/macros.h ../hdr/fatal.h \
  ../hdr/fatal.h
newstats.o: newstats.c ../hdr/defines.h ../hdr/macros.h ../hdr/fatal.h \
  ../hdr/fatal.h
permiss.o: permiss.c ../hdr/defines.h ../hdr/macros.h ../hdr/fatal.h \
  ../hdr/fatal.h ../hdr/i18n.h
pf_ab.o: pf_ab.c ../hdr/defines.h ../hdr/macros.h ../hdr/fatal.h \
  ../hdr/fatal.h
putline.o: putline.c ../hdr/defines.h ../hdr/macros.h ../hdr/fatal.h \
  ../hdr/fatal.h ../hdr/i18n.h
rdmod.o: rdmod.c ../hdr/defines.h ../hdr/macros.h ../hdr/fatal.h \
  ../hdr/fatal.h
setup.o: setup.c ../hdr/defines.h ../hdr/macros.h ../hdr/fatal.h \
  ../hdr/fatal.h
sid_ab.o: sid_ab.c ../hdr/defines.h ../hdr/macros.h ../hdr/fatal.h \
  ../hdr/fatal.h
sid_ba.o: sid_ba.c ../hdr/defines.h ../hdr/macros.h ../hdr/fatal.h \
  ../hdr/fatal.h
sidtoser.o: sidtoser.c ../hdr/defines.h ../hdr/macros.h ../hdr/fatal.h \
  ../hdr/fatal.h
sinit.o: sinit.c ../hdr/defines.h ../hdr/macros.h ../hdr/fatal.h \
  ../hdr/fatal.h
stats_ab.o: stats_ab.c ../hdr/defines.h ../hdr/macros.h ../hdr/fatal.h \
  ../hdr/fatal.h
strptim.o: strptim.c ../hdr/defines.h ../hdr/macros.h ../hdr/fatal.h \
  ../hdr/fatal.h
