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
INC = -I. -I../hdrs -I../libgendb

.c.o:
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $(INC) $(PATHS) $(WARN) $<


OBJ = canonize.o ckparam.o ckvolseq.o cvtpath.o dbsql.o devtype.o \
	dstream.o fmkdir.o gpkglist.o gpkgmap.o isdir.o keystore.o \
	logerr.o mappath.o ncgrpw.o nhash.o pkgerr.o \
	pkgexecl.o pkgexecv.o pkgmount.o pkgstr.o pkgtrans.o pkgweb.o \
	pkgxpand.o ppkgmap.o progerr.o putcfile.o rrmdir.o runcmd.o \
	security.o srchcfile.o tputcfent.o verify.o vfpops.o

all: libpkg.a

libpkg.a: $(OBJ)
	$(AR) -rv $@ $(OBJ)
	$(RANLIB) $@

install: all

clean:
	rm -f libpkg.a $(OBJ) core log *~

mrproper: clean

canonize.o: canonize.c
ckparam.o: ckparam.c ./pkglib.h ../hdrs/pkgdev.h ../hdrs/pkgstrct.h \
  ./pkgerr.h ./keystore.h ./cfext.h ./pkglibmsgs.h pkglocale.h
ckvolseq.o: ckvolseq.c ../hdrs/pkgstrct.h ./pkglib.h ../hdrs/pkgdev.h \
  ./pkgerr.h ./keystore.h ./cfext.h ./pkglibmsgs.h pkglocale.h
cvtpath.o: cvtpath.c
dbsql.o: dbsql.c ./pkglib.h ../hdrs/pkgdev.h ../hdrs/pkgstrct.h \
  ./pkgerr.h ./keystore.h ./cfext.h pkglocale.h ../libgendb/genericdb.h \
  dbtables.h dbsql.h cfext.h pkglibmsgs.h ../hdrs/libadm.h
devtype.o: devtype.c ../hdrs/pkgdev.h ./pkglib.h ../hdrs/pkgstrct.h \
  ./pkgerr.h ./keystore.h ./cfext.h
dstream.o: dstream.c ./pkglib.h ../hdrs/pkgdev.h ../hdrs/pkgstrct.h \
  ./pkgerr.h ./keystore.h ./cfext.h ./pkglibmsgs.h pkglocale.h \
  ../hdrs/libadm.h
fmkdir.o: fmkdir.c pkglib.h
gpkglist.o: gpkglist.c ../hdrs/valtools.h ../hdrs/pkginfo.h ./pkglib.h \
  ../hdrs/pkgdev.h ../hdrs/pkgstrct.h ./pkgerr.h ./keystore.h ./cfext.h \
  ./pkglibmsgs.h pkglocale.h
gpkgmap.o: gpkgmap.c ../hdrs/pkgstrct.h pkglib.h ../hdrs/pkgdev.h \
  pkgerr.h keystore.h cfext.h pkglibmsgs.h pkglocale.h ../hdrs/libadm.h
isdir.o: isdir.c ../hdrs/archives.h pkglocale.h pkglibmsgs.h
keystore.o: keystore.c p12lib.h pkgerr.h keystore.h pkglib.h \
  ../hdrs/pkgdev.h ../hdrs/pkgstrct.h cfext.h pkglibmsgs.h
logerr.o: logerr.c pkglocale.h
mappath.o: mappath.c
ncgrpw.o: ncgrpw.c ./pkglib.h ../hdrs/pkgdev.h ../hdrs/pkgstrct.h \
  ./pkgerr.h ./keystore.h ./cfext.h pkglocale.h nhash.h
nhash.o: nhash.c ./pkglib.h ../hdrs/pkgdev.h ../hdrs/pkgstrct.h \
  ./pkgerr.h ./keystore.h ./cfext.h nhash.h pkglocale.h
p12lib.o: p12lib.c p12lib.h
pkgerr.o: pkgerr.c pkgerr.h
pkgexecl.o: pkgexecl.c pkglocale.h pkglibmsgs.h ./pkglib.h \
  ../hdrs/pkgdev.h ../hdrs/pkgstrct.h ./pkgerr.h ./keystore.h ./cfext.h
pkgexecv.o: pkgexecv.c ./pkglib.h ../hdrs/pkgdev.h ../hdrs/pkgstrct.h \
  ./pkgerr.h ./keystore.h ./cfext.h ./pkglibmsgs.h pkglocale.h ../hdrs/libadm.h
pkgmount.o: pkgmount.c ../hdrs/pkgdev.h ../hdrs/pkginfo.h \
  ../hdrs/devmgmt.h ./pkglib.h ../hdrs/pkgstrct.h ./pkgerr.h ./keystore.h \
  ./cfext.h ./pkglibmsgs.h pkglocale.h
pkgstr.o: pkgstr.c ./pkglib.h ../hdrs/pkgdev.h ../hdrs/pkgstrct.h \
  ./pkgerr.h ./keystore.h ./cfext.h pkglocale.h
pkgtrans.o: pkgtrans.c ../hdrs/pkginfo.h ../hdrs/pkgstrct.h \
  ../hdrs/pkgtrans.h ../hdrs/pkgdev.h ../hdrs/devmgmt.h ./pkglib.h \
  ./pkgerr.h ./keystore.h ./cfext.h ./pkglibmsgs.h ./keystore.h \
  pkglocale.h pkgerr.h ../hdrs/libadm.h
pkgweb.o: pkgweb.c ../hdrs/libadm.h
pkgxpand.o: pkgxpand.c ./pkglib.h ../hdrs/pkgdev.h ../hdrs/pkgstrct.h \
  ./pkgerr.h ./keystore.h ./cfext.h pkglocale.h
ppkgmap.o: ppkgmap.c ../hdrs/pkgstrct.h
progerr.o: progerr.c pkglocale.h pkgerr.h
putcfile.o: putcfile.c ../hdrs/pkgstrct.h pkglib.h ../hdrs/pkgdev.h \
  pkgerr.h keystore.h cfext.h ../hdrs/libadm.h
rrmdir.o: rrmdir.c pkglocale.h pkglib.h ../hdrs/pkgdev.h \
  ../hdrs/pkgstrct.h pkgerr.h keystore.h cfext.h
runcmd.o: runcmd.c ./pkglib.h ../hdrs/pkgdev.h ../hdrs/pkgstrct.h \
  ./pkgerr.h ./keystore.h ./cfext.h pkglocale.h pkglibmsgs.h ../hdrs/libadm.h
security.o: security.c ../hdrs/pkgstrct.h ../hdrs/pkginfo.h pkgerr.h \
  pkglib.h ../hdrs/pkgdev.h keystore.h cfext.h pkglibmsgs.h pkglocale.h \
  p12lib.h
srchcfile.o: srchcfile.c ./pkglib.h ../hdrs/pkgdev.h ../hdrs/pkgstrct.h \
  ./pkgerr.h ./keystore.h ./cfext.h pkglocale.h pkglibmsgs.h
tputcfent.o: tputcfent.c ../hdrs/pkgstrct.h pkglocale.h
verify.o: verify.c ../hdrs/pkgstrct.h ./pkglib.h ../hdrs/pkgdev.h \
  ./pkgerr.h ./keystore.h ./cfext.h ./pkglibmsgs.h pkglocale.h
vfpops.o: vfpops.c ./pkglib.h ../hdrs/pkgdev.h ../hdrs/pkgstrct.h \
  ./pkgerr.h ./keystore.h ./cfext.h pkglocale.h
