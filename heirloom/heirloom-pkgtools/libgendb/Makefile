#
# Path to the Heirloom Bourne shell. It is used during compilation
# as well as by the package commands.
#
#SHELL = /sbin/sh
SHELL = /home/jr/contrib/heirloom/usr/5bin/sh

#
# A BSD-compatible install command.
#
INSTALL=/usr/ucb/install
INSTALL=install

#
# Where the Heirloom Development Tools package has been placed.
# $(CCSDIR)/bin must also be in the PATH setting when building.
#
CCSDIR=/home/jr/contrib/heirloom/usr/ccs

#
# Prefixes.
#
PREFIX=/home/jr/contrib/heirloom/usr
VAR=/home/jr/contrib/heirloom/var

#
# Where to place binaries. This must be the same place
# where the Heirloom Toolchest binaries are installed.
#
BINDIR=$(PREFIX)/5bin

#
# Where to place superuser-only binaries. This may be
# the same place as the binary directory.
#
SBINDIR=$(PREFIX)/5bin

#
# Where to place configuration files.
#
ETCDIR=$(PREFIX)/etc

#
# Where to place (read-only) helper files.
#
SADMDIR=$(PREFIX)/sadm

#
# Where to place the database of installed packages.
#
VSADMDIR=$(VAR)/sadm

#
# Where to place manual pages.
#
MANDIR=$(PREFIX)/share/man/5man

#
# Binaries are stripped with this command after installation.
#
STRIP=strip -s -R .comment -R .note

#
# Compiler flags.
#
CFLAGS=-O

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
# Use this if you prefer hard links between installed files.
#
LNS = ln -s

#
# Do not modify anything below here.
#
PATHS = \
	-DSHELL='"$(SHELL)"' \
	-DETCDIR='"$(ETCDIR)"' \
	-DBINDIR='"$(BINDIR)"' \
	-DSBINDIR='"$(SBINDIR)"' \
	-DSADMDIR='"$(SADMDIR)"' \
	-DVSADMDIR='"$(VSADMDIR)"' \
	-DVSADMREL='"$(VSADMDIR:/%=%)"'
.c.o:
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -I../libpkgdb $(PATHS) $(WARN) $<


OBJ = genericdb.o

all: libgendb.a

libgendb.a: $(OBJ)
	$(AR) -rv $@ $(OBJ)
	$(RANLIB) $@

install: all

clean:
	rm -f libgendb.a $(OBJ) core log *~

mrproper: clean

genericdb.o: genericdb.c genericdb.h genericdb_private.h
