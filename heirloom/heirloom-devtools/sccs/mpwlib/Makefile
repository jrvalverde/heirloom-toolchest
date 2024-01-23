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


OBJ = abspath.o any.o cat.o dname.o fatal.o fdfopen.o fmalloc.o \
	had.o imatch.o index.o lockit.o patoi.o repl.o satoi.o \
	setsig.o sname.o strend.o trnslat.o userexit.o xcreat.o \
	xlink.o xmsg.o xopen.o xpipe.o xunlink.o zero.o getopt.o

all: libmpw.a

libmpw.a: $(OBJ)
	$(AR) -rv $@ $(OBJ)
	$(RANLIB) $@

install: all

clean:
	rm -f libmpw.a $(OBJ) core log *~

mrproper: clean

abspath.o: abspath.c
any.o: any.c
cat.o: cat.c
dname.o: dname.c ../hdr/macros.h
fatal.o: fatal.c ../hdr/defines.h ../hdr/macros.h ../hdr/fatal.h \
  ../hdr/fatal.h ../hdr/had.h
fdfopen.o: fdfopen.c ../hdr/macros.h
fmalloc.o: fmalloc.c ../hdr/defines.h ../hdr/macros.h ../hdr/fatal.h \
  ../hdr/fatal.h
had.o: had.c ../hdr/had.h
imatch.o: imatch.c
index.o: index.c
lockit.o: lockit.c ../hdr/defines.h ../hdr/macros.h ../hdr/fatal.h \
  ../hdr/fatal.h ../hdr/i18n.h ../hdr/ccstypes.h
patoi.o: patoi.c
repl.o: repl.c ../hdr/defines.h
satoi.o: satoi.c ../hdr/macros.h
setsig.o: setsig.c ../hdr/defines.h ../hdr/macros.h ../hdr/fatal.h \
  ../hdr/fatal.h ../hdr/i18n.h
sname.o: sname.c
strend.o: strend.c
trnslat.o: trnslat.c
userexit.o: userexit.c
xcreat.o: xcreat.c ../hdr/defines.h ../hdr/macros.h ../hdr/fatal.h \
  ../hdr/fatal.h ../hdr/i18n.h ../hdr/ccstypes.h
xlink.o: xlink.c ../hdr/i18n.h ../hdr/defines.h ../hdr/macros.h \
  ../hdr/fatal.h ../hdr/fatal.h
xmsg.o: xmsg.c ../hdr/defines.h ../hdr/macros.h ../hdr/fatal.h \
  ../hdr/fatal.h
xopen.o: xopen.c ../hdr/i18n.h ../hdr/ccstypes.h ../hdr/defines.h \
  ../hdr/macros.h ../hdr/fatal.h ../hdr/fatal.h
xpipe.o: xpipe.c ../hdr/i18n.h ../hdr/defines.h ../hdr/macros.h \
  ../hdr/fatal.h ../hdr/fatal.h
xunlink.o: xunlink.c ../hdr/i18n.h ../hdr/defines.h ../hdr/macros.h \
  ../hdr/fatal.h ../hdr/fatal.h
zero.o: zero.c
