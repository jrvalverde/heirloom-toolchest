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
OBJ = bsd.o

.c.o:
	$(CC) $(CFLAGS) $(WARN) $(CPPFLAGS) -I../include -c $<

.cc.o:
	$(CXX) $(CXXFLAGS) $(WARN) $(CPPFLAGS) -I../include -c $<

all: libbsd.a

libbsd.a: $(OBJ)
	$(AR) -rv $@ $(OBJ)
	$(RANLIB) $@

install: all

clean:
	rm -f libbsd.a $(OBJ) core log *~

mrproper: clean

bsd.o: bsd.cc ../include/bsd/bsd.h
