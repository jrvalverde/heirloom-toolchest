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
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -I../hdrs $(PATHS) $(WARN) $<


OBJ = ckdate.o ckgid.o ckint.o ckitem.o ckkeywd.o ckpath.o ckrange.o \
	ckstr.o cktime.o ckuid.o ckyorn.o data.o devattr.o devreserv.o \
	devtab.o dgrpent.o fulldevnm.o getdev.o getdgrp.o getinput.o \
	getvol.o listdev.o listdgrp.o pkginfo.o pkgnmchk.o pkgparam.o \
	putdev.o putdgrp.o puterror.o puthelp.o putprmpt.o puttext.o \
	rdwr_vtoc.o regexp.o space.o \
	strlcat.o strlcpy.o closefrom.o sigsend.o cftime.o getpass.o \
	mkdirp.o getopt.o

all: libadm.a

libadm.a: $(OBJ)
	$(AR) -rv $@ $(OBJ)
	$(RANLIB) $@

install: all

clean:
	rm -f libadm.a $(OBJ) core log *~

mrproper: clean

ckdate.o: ckdate.c ../hdrs/libadm.h ../hdrs/sys/vtoc.h \
  ../hdrs/sys/dklabel.h ../hdrs/pkgstrct.h ../hdrs/pkginfo.h \
  ../hdrs/valtools.h ../hdrs/install.h
ckgid.o: ckgid.c ../hdrs/libadm.h ../hdrs/sys/vtoc.h \
  ../hdrs/sys/dklabel.h ../hdrs/pkgstrct.h ../hdrs/pkginfo.h \
  ../hdrs/valtools.h ../hdrs/install.h
ckint.o: ckint.c ../hdrs/libadm.h ../hdrs/sys/vtoc.h \
  ../hdrs/sys/dklabel.h ../hdrs/pkgstrct.h ../hdrs/pkginfo.h \
  ../hdrs/valtools.h ../hdrs/install.h
ckitem.o: ckitem.c ../hdrs/valtools.h ../hdrs/libadm.h ../hdrs/sys/vtoc.h \
  ../hdrs/sys/dklabel.h ../hdrs/pkgstrct.h ../hdrs/pkginfo.h \
  ../hdrs/valtools.h ../hdrs/install.h
ckkeywd.o: ckkeywd.c ../hdrs/libadm.h ../hdrs/sys/vtoc.h \
  ../hdrs/sys/dklabel.h ../hdrs/pkgstrct.h ../hdrs/pkginfo.h \
  ../hdrs/valtools.h ../hdrs/install.h
ckpath.o: ckpath.c ../hdrs/valtools.h ../hdrs/libadm.h ../hdrs/sys/vtoc.h \
  ../hdrs/sys/dklabel.h ../hdrs/pkgstrct.h ../hdrs/pkginfo.h \
  ../hdrs/valtools.h ../hdrs/install.h
ckrange.o: ckrange.c ../hdrs/libadm.h ../hdrs/sys/vtoc.h \
  ../hdrs/sys/dklabel.h ../hdrs/pkgstrct.h ../hdrs/pkginfo.h \
  ../hdrs/valtools.h ../hdrs/install.h
ckstr.o: ckstr.c ../hdrs/libadm.h ../hdrs/sys/vtoc.h \
  ../hdrs/sys/dklabel.h ../hdrs/pkgstrct.h ../hdrs/pkginfo.h \
  ../hdrs/valtools.h ../hdrs/install.h
cktime.o: cktime.c ../hdrs/libadm.h ../hdrs/sys/vtoc.h \
  ../hdrs/sys/dklabel.h ../hdrs/pkgstrct.h ../hdrs/pkginfo.h \
  ../hdrs/valtools.h ../hdrs/install.h
ckuid.o: ckuid.c ../hdrs/libadm.h ../hdrs/sys/vtoc.h \
  ../hdrs/sys/dklabel.h ../hdrs/pkgstrct.h ../hdrs/pkginfo.h \
  ../hdrs/valtools.h ../hdrs/install.h
ckyorn.o: ckyorn.c ../hdrs/libadm.h ../hdrs/sys/vtoc.h \
  ../hdrs/sys/dklabel.h ../hdrs/pkgstrct.h ../hdrs/pkginfo.h \
  ../hdrs/valtools.h ../hdrs/install.h
data.o: data.c
devattr.o: devattr.c ../hdrs/devmgmt.h ../hdrs/devtab.h
devreserv.o: devreserv.c ../hdrs/devmgmt.h ../hdrs/devtab.h
devtab.o: devtab.c ../hdrs/devmgmt.h ../hdrs/devtab.h
dgrpent.o: dgrpent.c ../hdrs/devmgmt.h ../hdrs/devtab.h
fulldevnm.o: fulldevnm.c ../hdrs/sys/vfstab.h ../hdrs/libadm.h \
  ../hdrs/sys/vtoc.h ../hdrs/sys/dklabel.h ../hdrs/pkgstrct.h \
  ../hdrs/pkginfo.h ../hdrs/valtools.h ../hdrs/install.h
getdev.o: getdev.c ../hdrs/devmgmt.h ../hdrs/devtab.h
getdgrp.o: getdgrp.c ../hdrs/devmgmt.h ../hdrs/devtab.h
getinput.o: getinput.c ../hdrs/libadm.h ../hdrs/sys/vtoc.h \
  ../hdrs/sys/dklabel.h ../hdrs/pkgstrct.h ../hdrs/pkginfo.h \
  ../hdrs/valtools.h ../hdrs/install.h
getvol.o: getvol.c ../hdrs/devmgmt.h ../hdrs/libadm.h ../hdrs/sys/vtoc.h \
  ../hdrs/sys/dklabel.h ../hdrs/pkgstrct.h ../hdrs/pkginfo.h \
  ../hdrs/valtools.h ../hdrs/install.h
listdev.o: listdev.c ../hdrs/devmgmt.h ../hdrs/devtab.h
listdgrp.o: listdgrp.c ../hdrs/devmgmt.h ../hdrs/devtab.h
pkginfo.o: pkginfo.c ../hdrs/pkginfo.h ../hdrs/pkgstrct.h \
  ../hdrs/pkglocs.h ../hdrs/libadm.h ../hdrs/sys/vtoc.h \
  ../hdrs/sys/dklabel.h ../hdrs/valtools.h ../hdrs/install.h
pkgnmchk.o: pkgnmchk.c ../hdrs/libadm.h ../hdrs/sys/vtoc.h \
  ../hdrs/sys/dklabel.h ../hdrs/pkgstrct.h ../hdrs/pkginfo.h \
  ../hdrs/valtools.h ../hdrs/install.h
pkgparam.o: pkgparam.c ../hdrs/pkgstrct.h ../hdrs/pkginfo.h \
  ../hdrs/pkglocs.h ../hdrs/libadm.h ../hdrs/sys/vtoc.h \
  ../hdrs/sys/dklabel.h ../hdrs/valtools.h ../hdrs/install.h
putdev.o: putdev.c ../hdrs/devmgmt.h ../hdrs/devtab.h
putdgrp.o: putdgrp.c ../hdrs/devmgmt.h ../hdrs/devtab.h
puterror.o: puterror.c ../hdrs/libadm.h ../hdrs/sys/vtoc.h \
  ../hdrs/sys/dklabel.h ../hdrs/pkgstrct.h ../hdrs/pkginfo.h \
  ../hdrs/valtools.h ../hdrs/install.h
puthelp.o: puthelp.c ../hdrs/libadm.h ../hdrs/sys/vtoc.h \
  ../hdrs/sys/dklabel.h ../hdrs/pkgstrct.h ../hdrs/pkginfo.h \
  ../hdrs/valtools.h ../hdrs/install.h
putprmpt.o: putprmpt.c ../hdrs/libadm.h ../hdrs/sys/vtoc.h \
  ../hdrs/sys/dklabel.h ../hdrs/pkgstrct.h ../hdrs/pkginfo.h \
  ../hdrs/valtools.h ../hdrs/install.h
puttext.o: puttext.c ../hdrs/libadm.h ../hdrs/sys/vtoc.h \
  ../hdrs/sys/dklabel.h ../hdrs/pkgstrct.h ../hdrs/pkginfo.h \
  ../hdrs/valtools.h ../hdrs/install.h
rdwr_vtoc.o: rdwr_vtoc.c ../hdrs/sys/vtoc.h ../hdrs/sys/dklabel.h
regexp.o: regexp.c regexp.h
space.o: space.c
