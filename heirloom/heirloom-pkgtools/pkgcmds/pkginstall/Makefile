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
INC = -I../../hdrs -I../../libgendb -I../../libpkg -I../../libinst \
	-I../../libspmizones -I../../libadm -I../pkgadm

.c.o:
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $(INC) $(PATHS) $(WARN) $<

PKGLIBS = -L../../libinst -linst -L../../libpkg -lpkg -L../../libgendb -lgendb \
	-L../../libadm -ladm \
	-L$(CCSDIR)/lib -ll

BIN = pkginstall
OBJ = backup.o check.o cppath.o dockspace.o getinst.o instvol.o main.o \
	merginfo.o pkgenv.o pkgvolume.o predepend.o quit.o reqexec.o \
	sortmap.o special.o ../../version/version.o

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) $(PKGLIBS) $(LIBS) -o $@

install: all
	mkdir -p $(ROOT)$(SADMDIR)/install/bin
	$(INSTALL) -c -m 755 pkginstall $(ROOT)$(SADMDIR)/install/bin/pkginstall
	$(STRIP) $(ROOT)$(SADMDIR)/install/bin/pkginstall

clean:
	rm -f $(BIN) $(OBJ) core log

mrproper: clean

$(BIN): ../../libadm/libadm.a ../../libgendb/libgendb.a \
	../../libinst/libinst.a ../../libpkg/libpkg.a

backup.o: backup.c ../../libpkg/pkglib.h ../../hdrs/pkgdev.h \
  ../../hdrs/pkgstrct.h ../../libpkg/pkgerr.h ../../libpkg/keystore.h \
  ../../libpkg/cfext.h
check.o: check.c ../../hdrs/pkgstrct.h ../../hdrs/pkglocs.h \
  ../../hdrs/install.h ../../libpkg/pkglib.h ../../hdrs/pkgdev.h \
  ../../libpkg/pkgerr.h ../../libpkg/keystore.h ../../libpkg/cfext.h \
  ../../hdrs/libadm.h ../../hdrs/sys/vtoc.h ../../hdrs/sys/dklabel.h \
  ../../hdrs/pkginfo.h ../../hdrs/valtools.h ../../hdrs/install.h \
  ../../hdrs/libinst.h ../../libpkg/cfext.h pkginstall.h
cppath.o: cppath.c ../../hdrs/pkglocs.h ../../libpkg/pkglib.h \
  ../../hdrs/pkgdev.h ../../hdrs/pkgstrct.h ../../libpkg/pkgerr.h \
  ../../libpkg/keystore.h ../../libpkg/cfext.h ../../hdrs/libadm.h \
  ../../hdrs/sys/vtoc.h ../../hdrs/sys/dklabel.h ../../hdrs/pkginfo.h \
  ../../hdrs/valtools.h ../../hdrs/install.h ../../hdrs/libinst.h \
  ../../libpkg/cfext.h ../../hdrs/install.h ../../hdrs/messages.h \
  pkginstall.h
dockspace.o: dockspace.c ../../hdrs/pkgstrct.h ../../hdrs/install.h \
  ../../libpkg/pkglib.h ../../hdrs/pkgdev.h ../../libpkg/pkgerr.h \
  ../../libpkg/keystore.h ../../libpkg/cfext.h ../../hdrs/libadm.h \
  ../../hdrs/sys/vtoc.h ../../hdrs/sys/dklabel.h ../../hdrs/pkginfo.h \
  ../../hdrs/valtools.h ../../hdrs/install.h ../../hdrs/libinst.h \
  ../../libpkg/cfext.h pkginstall.h
getinst.o: getinst.c ../../hdrs/valtools.h ../../hdrs/pkginfo.h \
  ../../hdrs/install.h ../../hdrs/pkgstrct.h ../../libpkg/pkglib.h \
  ../../hdrs/pkgdev.h ../../libpkg/pkgerr.h ../../libpkg/keystore.h \
  ../../libpkg/cfext.h ../../hdrs/libadm.h ../../hdrs/sys/vtoc.h \
  ../../hdrs/sys/dklabel.h ../../hdrs/install.h ../../hdrs/libinst.h \
  ../../libpkg/cfext.h pkginstall.h ../../hdrs/messages.h
instvol.o: instvol.c ../../hdrs/pkgstrct.h ../../hdrs/pkgdev.h \
  ../../hdrs/pkglocs.h ../../hdrs/archives.h \
  ../../libspmizones/spmizones_api.h ../../libpkg/pkglib.h \
  ../../libpkg/pkgerr.h ../../libpkg/keystore.h ../../libpkg/cfext.h \
  ../../libpkg/pkgweb.h ../../libpkg/pkglocale.h ../pkgadm/pkgadm.h \
  ../../libpkg/pkgerr.h ../../libpkg/keystore.h \
  ../../libgendb/genericdb.h ../../hdrs/libinst.h ../../hdrs/pkginfo.h \
  ../../libpkg/cfext.h ../../hdrs/install.h ../../hdrs/install.h \
  ../../hdrs/libinst.h ../../hdrs/libadm.h ../../hdrs/sys/vtoc.h \
  ../../hdrs/sys/dklabel.h ../../hdrs/valtools.h ../../hdrs/dryrun.h \
  ../../hdrs/messages.h pkginstall.h
main.o: main.c ../../hdrs/pkgstrct.h ../../hdrs/pkginfo.h \
  ../../hdrs/pkgdev.h ../../hdrs/pkglocs.h \
  ../../libspmizones/spmizones_api.h ../../libpkg/pkglib.h \
  ../../libpkg/pkgerr.h ../../libpkg/keystore.h ../../libpkg/cfext.h \
  ../../libpkg/pkgweb.h ../../libpkg/pkglocale.h ../../hdrs/install.h \
  ../../hdrs/libinst.h ../../libpkg/cfext.h ../../hdrs/install.h \
  ../../hdrs/libadm.h ../../hdrs/sys/vtoc.h ../../hdrs/sys/dklabel.h \
  ../../hdrs/valtools.h ../../hdrs/dryrun.h ../../hdrs/messages.h \
  pkginstall.h
merginfo.o: merginfo.c ../../libpkg/pkglib.h ../../hdrs/pkgdev.h \
  ../../hdrs/pkgstrct.h ../../libpkg/pkgerr.h ../../libpkg/keystore.h \
  ../../libpkg/cfext.h ../../hdrs/install.h ../../hdrs/libadm.h \
  ../../hdrs/sys/vtoc.h ../../hdrs/sys/dklabel.h ../../hdrs/pkginfo.h \
  ../../hdrs/valtools.h ../../hdrs/install.h ../../hdrs/libinst.h \
  ../../libpkg/pkglib.h ../../libpkg/cfext.h pkginstall.h \
  ../../hdrs/messages.h
pkgenv.o: pkgenv.c ../../hdrs/pkgstrct.h ../../libpkg/pkglib.h \
  ../../hdrs/pkgdev.h ../../libpkg/pkgerr.h ../../libpkg/keystore.h \
  ../../libpkg/cfext.h ../../hdrs/install.h ../../hdrs/libadm.h \
  ../../hdrs/sys/vtoc.h ../../hdrs/sys/dklabel.h ../../hdrs/pkginfo.h \
  ../../hdrs/valtools.h ../../hdrs/install.h ../../hdrs/libinst.h \
  ../../libpkg/cfext.h
pkgvolume.o: pkgvolume.c ../../hdrs/pkgdev.h ../../libpkg/pkglib.h \
  ../../hdrs/pkgstrct.h ../../libpkg/pkgerr.h ../../libpkg/keystore.h \
  ../../libpkg/cfext.h ../../hdrs/libadm.h ../../hdrs/sys/vtoc.h \
  ../../hdrs/sys/dklabel.h ../../hdrs/pkginfo.h ../../hdrs/valtools.h \
  ../../hdrs/install.h ../../hdrs/libinst.h ../../libpkg/cfext.h
predepend.o: predepend.c ../../hdrs/pkglocs.h ../../libpkg/pkglib.h \
  ../../hdrs/pkgdev.h ../../hdrs/pkgstrct.h ../../libpkg/pkgerr.h \
  ../../libpkg/keystore.h ../../libpkg/cfext.h ../../hdrs/libadm.h \
  ../../hdrs/sys/vtoc.h ../../hdrs/sys/dklabel.h ../../hdrs/pkginfo.h \
  ../../hdrs/valtools.h ../../hdrs/install.h
quit.o: quit.c ../../hdrs/pkgdev.h ../../hdrs/pkglocs.h \
  ../../libpkg/pkglib.h ../../hdrs/pkgstrct.h ../../libpkg/pkgerr.h \
  ../../libpkg/keystore.h ../../libpkg/cfext.h ../../hdrs/install.h \
  ../../hdrs/dryrun.h ../../libpkg/cfext.h ../../hdrs/libadm.h \
  ../../hdrs/sys/vtoc.h ../../hdrs/sys/dklabel.h ../../hdrs/pkginfo.h \
  ../../hdrs/valtools.h ../../hdrs/install.h ../../hdrs/libinst.h \
  ../../libpkg/cfext.h pkginstall.h ../../hdrs/messages.h
reqexec.o: reqexec.c ../../libpkg/pkglib.h ../../hdrs/pkgdev.h \
  ../../hdrs/pkgstrct.h ../../libpkg/pkgerr.h ../../libpkg/keystore.h \
  ../../libpkg/cfext.h ../../hdrs/install.h ../../hdrs/libadm.h \
  ../../hdrs/sys/vtoc.h ../../hdrs/sys/dklabel.h ../../hdrs/pkginfo.h \
  ../../hdrs/valtools.h ../../hdrs/install.h ../../hdrs/libinst.h \
  ../../libpkg/cfext.h pkginstall.h ../../hdrs/messages.h
sortmap.o: sortmap.c ../../hdrs/pkgstrct.h ../../hdrs/pkglocs.h \
  ../../hdrs/install.h ../../libpkg/pkglib.h ../../hdrs/pkgdev.h \
  ../../libpkg/pkgerr.h ../../libpkg/keystore.h ../../libpkg/cfext.h \
  ../../hdrs/libadm.h ../../hdrs/sys/vtoc.h ../../hdrs/sys/dklabel.h \
  ../../hdrs/pkginfo.h ../../hdrs/valtools.h ../../hdrs/install.h \
  ../../hdrs/libinst.h ../../libpkg/cfext.h
special.o: special.c ../../hdrs/pkgstrct.h ../../hdrs/pkginfo.h \
  ../../hdrs/pkgdev.h ../../hdrs/pkglocs.h ../../libpkg/pkglib.h \
  ../../libpkg/pkgerr.h ../../libpkg/keystore.h ../../libpkg/cfext.h \
  ../../libpkg/dbsql.h ../../libgendb/genericdb.h ../../hdrs/libadm.h \
  ../../hdrs/sys/vtoc.h ../../hdrs/sys/dklabel.h ../../hdrs/valtools.h \
  ../../hdrs/install.h ../../hdrs/libinst.h ../../libpkg/cfext.h \
  ../../hdrs/dryrun.h pkginstall.h ../../hdrs/messages.h
