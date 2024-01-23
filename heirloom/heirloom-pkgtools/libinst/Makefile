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
INC = -I../hdrs -I../libpkg -I../libgendb -I../libspmizones

.c.o:
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $(INC) $(PATHS) $(WARN) $<


OBJ = copyf.o cvtpath.o depchk.o dockdeps.o doulimit.o dryrun.o echo.o \
	eptstat.o finalck.o findscripts.o fixpath.o flex_dev.o \
	is_local_host.o isreloc.o listmgr.o lockinst.o log.o mntinfo.o \
	nblk.o ocfile.o open_package_datastream.o pathdup.o pkgdbmerg.o \
	pkgobjmap.o pkgops.o pkgpatch.o procmap.o psvr4ck.o ptext.o \
	putparam.o qreason.o qstrdup.o setadmin.o setlist.o \
	setup_temporary_directory.o sml.o srcpath.o stub.o \
	unpack_package_from_stream.o scriptvfy.o \
	getvfsent.o resolvepath.o

all: libinst.a

libinst.a: $(OBJ)
	$(AR) -rv $@ $(OBJ)
	$(RANLIB) $@

install: all

scriptvfy.c: scriptvfy.l

clean:
	rm -f libinst.a $(OBJ) scriptvfy.c core log *~

mrproper: clean

copyf.o: copyf.c ../libpkg/pkglib.h ../hdrs/pkgdev.h ../hdrs/pkgstrct.h \
  ../libpkg/pkgerr.h ../libpkg/keystore.h ../libpkg/cfext.h \
  ../hdrs/libinst.h ../hdrs/pkginfo.h ../libpkg/pkglib.h \
  ../libpkg/cfext.h ../hdrs/install.h ../hdrs/libadm.h ../hdrs/sys/vtoc.h \
  ../hdrs/sys/dklabel.h ../hdrs/valtools.h ../hdrs/messages.h
cvtpath.o: cvtpath.c
depchk.o: depchk.c ../hdrs/libinst.h ../hdrs/pkgstrct.h ../hdrs/pkginfo.h \
  ../libpkg/pkglib.h ../hdrs/pkgdev.h ../libpkg/pkgerr.h \
  ../libpkg/keystore.h ../libpkg/cfext.h ../libpkg/cfext.h \
  ../hdrs/install.h ../hdrs/messages.h
dockdeps.o: dockdeps.c ../hdrs/pkgstrct.h ../hdrs/pkginfo.h \
  ../libpkg/pkglib.h ../hdrs/pkgdev.h ../libpkg/pkgerr.h \
  ../libpkg/keystore.h ../libpkg/cfext.h ../hdrs/libinst.h \
  ../libpkg/cfext.h ../hdrs/install.h ../hdrs/libadm.h ../hdrs/sys/vtoc.h \
  ../hdrs/sys/dklabel.h ../hdrs/valtools.h ../hdrs/messages.h
doulimit.o: doulimit.c ../libpkg/pkglib.h ../hdrs/pkgdev.h \
  ../hdrs/pkgstrct.h ../libpkg/pkgerr.h ../libpkg/keystore.h \
  ../libpkg/cfext.h ../hdrs/libinst.h ../hdrs/pkginfo.h ../libpkg/cfext.h \
  ../hdrs/install.h
dryrun.o: dryrun.c ../hdrs/pkgstrct.h ../libpkg/pkglib.h ../hdrs/pkgdev.h \
  ../libpkg/pkgerr.h ../libpkg/keystore.h ../libpkg/cfext.h \
  ../hdrs/libadm.h ../hdrs/sys/vtoc.h ../hdrs/sys/dklabel.h \
  ../hdrs/pkginfo.h ../hdrs/valtools.h ../hdrs/install.h \
  ../hdrs/libinst.h ../libpkg/cfext.h ../hdrs/dryrun.h
echo.o: echo.c ../libpkg/pkglib.h ../hdrs/pkgdev.h ../hdrs/pkgstrct.h \
  ../libpkg/pkgerr.h ../libpkg/keystore.h ../libpkg/cfext.h
eptstat.o: eptstat.c ../hdrs/pkgstrct.h ../hdrs/pkginfo.h \
  ../libpkg/pkglib.h ../hdrs/pkgdev.h ../libpkg/pkgerr.h \
  ../libpkg/keystore.h ../libpkg/cfext.h ../hdrs/install.h \
  ../hdrs/libinst.h ../libpkg/cfext.h ../hdrs/install.h ../hdrs/libadm.h \
  ../hdrs/sys/vtoc.h ../hdrs/sys/dklabel.h ../hdrs/valtools.h
finalck.o: finalck.c ../hdrs/pkgstrct.h ../libpkg/pkglib.h \
  ../hdrs/pkgdev.h ../libpkg/pkgerr.h ../libpkg/keystore.h \
  ../libpkg/cfext.h ../hdrs/install.h ../hdrs/libinst.h ../hdrs/pkginfo.h \
  ../libpkg/cfext.h ../hdrs/install.h ../hdrs/libadm.h ../hdrs/sys/vtoc.h \
  ../hdrs/sys/dklabel.h ../hdrs/valtools.h ../hdrs/messages.h
findscripts.o: findscripts.c ../hdrs/pkglocs.h ../libpkg/pkglib.h \
  ../hdrs/pkgdev.h ../hdrs/pkgstrct.h ../libpkg/pkgerr.h \
  ../libpkg/keystore.h ../libpkg/cfext.h ../hdrs/libinst.h \
  ../hdrs/pkginfo.h ../libpkg/cfext.h ../hdrs/install.h
fixpath.o: fixpath.c ../libpkg/pkglib.h ../hdrs/pkgdev.h \
  ../hdrs/pkgstrct.h ../libpkg/pkgerr.h ../libpkg/keystore.h \
  ../libpkg/cfext.h ../hdrs/install.h ../hdrs/libadm.h ../hdrs/sys/vtoc.h \
  ../hdrs/sys/dklabel.h ../hdrs/pkginfo.h ../hdrs/valtools.h \
  ../hdrs/install.h ../hdrs/libinst.h ../libpkg/cfext.h \
  ../libspmizones/spmizones_api.h
flex_dev.o: flex_dev.c ../libpkg/pkglib.h ../hdrs/pkgdev.h \
  ../hdrs/pkgstrct.h ../libpkg/pkgerr.h ../libpkg/keystore.h \
  ../libpkg/cfext.h ../hdrs/libadm.h ../hdrs/sys/vtoc.h \
  ../hdrs/sys/dklabel.h ../hdrs/pkginfo.h ../hdrs/valtools.h \
  ../hdrs/install.h
getvfsent.o: getvfsent.c ../hdrs/sys/vfstab.h
is_local_host.o: is_local_host.c
isreloc.o: isreloc.c ../libpkg/pkglib.h ../hdrs/pkgdev.h \
  ../hdrs/pkgstrct.h ../libpkg/pkgerr.h ../libpkg/keystore.h \
  ../libpkg/cfext.h ../hdrs/libinst.h ../hdrs/pkginfo.h ../libpkg/cfext.h \
  ../hdrs/install.h ../hdrs/install.h
listmgr.o: listmgr.c ../libpkg/pkglib.h ../hdrs/pkgdev.h \
  ../hdrs/pkgstrct.h ../libpkg/pkgerr.h ../libpkg/keystore.h \
  ../libpkg/cfext.h
lockinst.o: lockinst.c ../hdrs/pkglocs.h ../libpkg/pkglib.h \
  ../hdrs/pkgdev.h ../hdrs/pkgstrct.h ../libpkg/pkgerr.h \
  ../libpkg/keystore.h ../libpkg/cfext.h ../hdrs/libadm.h \
  ../hdrs/sys/vtoc.h ../hdrs/sys/dklabel.h ../hdrs/pkginfo.h \
  ../hdrs/valtools.h ../hdrs/install.h
log.o: log.c ../libpkg/pkglib.h ../hdrs/pkgdev.h ../hdrs/pkgstrct.h \
  ../libpkg/pkgerr.h ../libpkg/keystore.h ../libpkg/cfext.h \
  ../hdrs/install.h ../hdrs/libinst.h ../hdrs/pkginfo.h \
  ../libpkg/pkglib.h ../libpkg/cfext.h ../hdrs/install.h ../hdrs/libadm.h \
  ../hdrs/sys/vtoc.h ../hdrs/sys/dklabel.h ../hdrs/valtools.h \
  ../hdrs/messages.h
mntinfo.o: mntinfo.c ../hdrs/pkgstrct.h ../hdrs/pkginfo.h \
  ../hdrs/sys/mnttab.h ../hdrs/sys/mntent.h ../hdrs/sys/vfstab.h \
  ../libpkg/pkglib.h ../hdrs/pkgdev.h ../libpkg/pkgerr.h \
  ../libpkg/keystore.h ../libpkg/cfext.h ../hdrs/install.h \
  ../hdrs/libinst.h ../libpkg/cfext.h ../hdrs/install.h ../hdrs/libadm.h \
  ../hdrs/sys/vtoc.h ../hdrs/sys/dklabel.h ../hdrs/valtools.h \
  ../hdrs/messages.h
nblk.o: nblk.c
ocfile.o: ocfile.c ../hdrs/pkglocs.h ../libpkg/pkglib.h ../hdrs/pkgdev.h \
  ../hdrs/pkgstrct.h ../libpkg/pkgerr.h ../libpkg/keystore.h \
  ../libpkg/cfext.h ../hdrs/libinst.h ../hdrs/pkginfo.h ../libpkg/cfext.h \
  ../hdrs/install.h ../hdrs/libadm.h ../hdrs/sys/vtoc.h \
  ../hdrs/sys/dklabel.h ../hdrs/valtools.h
open_package_datastream.o: open_package_datastream.c ../hdrs/pkgstrct.h \
  ../hdrs/pkginfo.h ../hdrs/pkgdev.h ../hdrs/pkglocs.h ../libpkg/pkglib.h \
  ../libpkg/pkgerr.h ../libpkg/keystore.h ../libpkg/cfext.h \
  ../hdrs/libinst.h ../libpkg/cfext.h ../hdrs/install.h ../hdrs/libadm.h \
  ../hdrs/sys/vtoc.h ../hdrs/sys/dklabel.h ../hdrs/valtools.h \
  ../hdrs/messages.h
pathdup.o: pathdup.c ../libpkg/pkglib.h ../hdrs/pkgdev.h \
  ../hdrs/pkgstrct.h ../libpkg/pkgerr.h ../libpkg/keystore.h \
  ../libpkg/cfext.h ../hdrs/libadm.h ../hdrs/sys/vtoc.h \
  ../hdrs/sys/dklabel.h ../hdrs/pkginfo.h ../hdrs/valtools.h \
  ../hdrs/install.h
pkgdbmerg.o: pkgdbmerg.c ../hdrs/pkgstrct.h ../hdrs/pkginfo.h \
  ../libspmizones/spmizones_api.h ../libpkg/pkglib.h ../hdrs/pkgdev.h \
  ../libpkg/pkgerr.h ../libpkg/keystore.h ../libpkg/cfext.h \
  ../hdrs/libinst.h ../libpkg/cfext.h ../hdrs/install.h \
  ../hdrs/messages.h ../hdrs/libadm.h
pkgobjmap.o: pkgobjmap.c ../hdrs/pkgstrct.h ../libpkg/pkglib.h \
  ../hdrs/pkgdev.h ../libpkg/pkgerr.h ../libpkg/keystore.h \
  ../libpkg/cfext.h ../hdrs/install.h ../hdrs/libinst.h ../hdrs/pkginfo.h \
  ../libpkg/cfext.h ../hdrs/install.h ../hdrs/libadm.h
pkgops.o: pkgops.c ../hdrs/pkgdev.h ../hdrs/pkginfo.h ../hdrs/pkglocs.h \
  ../libspmizones/spmizones_api.h ../libpkg/pkglib.h ../hdrs/pkgstrct.h \
  ../libpkg/pkgerr.h ../libpkg/keystore.h ../libpkg/cfext.h \
  ../hdrs/install.h ../hdrs/libinst.h ../libpkg/cfext.h ../hdrs/install.h \
  ../hdrs/libadm.h ../hdrs/sys/vtoc.h ../hdrs/sys/dklabel.h \
  ../hdrs/valtools.h ../hdrs/messages.h
pkgpatch.o: pkgpatch.c ../hdrs/pkgstrct.h ../libpkg/pkglib.h \
  ../hdrs/pkgdev.h ../libpkg/pkgerr.h ../libpkg/keystore.h \
  ../libpkg/cfext.h ../hdrs/install.h ../libgendb/genericdb.h \
  ../hdrs/libinst.h ../hdrs/pkginfo.h ../libpkg/pkglib.h \
  ../libpkg/cfext.h ../hdrs/install.h ../hdrs/libadm.h ../hdrs/sys/vtoc.h \
  ../hdrs/sys/dklabel.h ../hdrs/valtools.h ../libpkg/dbsql.h \
  ../libgendb/genericdb.h
procmap.o: procmap.c ../hdrs/pkgstrct.h ../libpkg/pkglib.h \
  ../hdrs/pkgdev.h ../libpkg/pkgerr.h ../libpkg/keystore.h \
  ../libpkg/cfext.h ../hdrs/install.h ../hdrs/libinst.h ../hdrs/pkginfo.h \
  ../libpkg/cfext.h ../hdrs/install.h
psvr4ck.o: psvr4ck.c ../libpkg/pkglib.h ../hdrs/pkgdev.h \
  ../hdrs/pkgstrct.h ../libpkg/pkgerr.h ../libpkg/keystore.h \
  ../libpkg/cfext.h ../hdrs/libinst.h ../hdrs/pkginfo.h ../libpkg/cfext.h \
  ../hdrs/install.h ../hdrs/libadm.h ../hdrs/sys/vtoc.h \
  ../hdrs/sys/dklabel.h ../hdrs/valtools.h
ptext.o: ptext.c ../hdrs/libadm.h ../hdrs/sys/vtoc.h \
  ../hdrs/sys/dklabel.h ../hdrs/pkgstrct.h ../hdrs/pkginfo.h \
  ../hdrs/valtools.h ../hdrs/install.h
putparam.o: putparam.c ../hdrs/pkgdev.h ../hdrs/pkginfo.h \
  ../hdrs/pkglocs.h ../libspmizones/spmizones_api.h ../libpkg/pkglib.h \
  ../hdrs/pkgstrct.h ../libpkg/pkgerr.h ../libpkg/keystore.h \
  ../libpkg/cfext.h ../hdrs/install.h ../hdrs/libinst.h ../libpkg/cfext.h \
  ../hdrs/install.h ../hdrs/libadm.h ../hdrs/sys/vtoc.h \
  ../hdrs/sys/dklabel.h ../hdrs/valtools.h ../hdrs/messages.h
qreason.o: qreason.c ../hdrs/libinst.h ../hdrs/pkgstrct.h \
  ../hdrs/pkginfo.h ../libpkg/pkglib.h ../hdrs/pkgdev.h \
  ../libpkg/pkgerr.h ../libpkg/keystore.h ../libpkg/cfext.h \
  ../libpkg/cfext.h ../hdrs/install.h ../hdrs/messages.h
qstrdup.o: qstrdup.c ../libpkg/pkglib.h ../hdrs/pkgdev.h \
  ../hdrs/pkgstrct.h ../libpkg/pkgerr.h ../libpkg/keystore.h \
  ../libpkg/cfext.h ../hdrs/libinst.h ../hdrs/pkginfo.h ../libpkg/cfext.h \
  ../hdrs/install.h
resolvepath.o: resolvepath.c
scriptvfy.o: scriptvfy.c ../libpkg/pkglib.h
setadmin.o: setadmin.c ../hdrs/pkglocs.h ../libpkg/pkglib.h \
  ../hdrs/pkgdev.h ../hdrs/pkgstrct.h ../libpkg/pkgerr.h \
  ../libpkg/keystore.h ../libpkg/cfext.h ../libpkg/pkgerr.h \
  ../libpkg/pkgweb.h ../hdrs/install.h ../hdrs/libinst.h \
  ../hdrs/pkginfo.h ../libpkg/cfext.h ../hdrs/install.h ../hdrs/libadm.h \
  ../hdrs/sys/vtoc.h ../hdrs/sys/dklabel.h ../hdrs/valtools.h \
  ../hdrs/messages.h
setlist.o: setlist.c ../hdrs/pkglocs.h ../libpkg/pkglib.h \
  ../hdrs/pkgdev.h ../hdrs/pkgstrct.h ../libpkg/pkgerr.h \
  ../libpkg/keystore.h ../libpkg/cfext.h ../hdrs/libinst.h \
  ../hdrs/pkginfo.h ../libpkg/cfext.h ../hdrs/install.h
setup_temporary_directory.o: setup_temporary_directory.c \
  ../libpkg/pkglib.h ../hdrs/pkgdev.h ../hdrs/pkgstrct.h \
  ../libpkg/pkgerr.h ../libpkg/keystore.h ../libpkg/cfext.h \
  ../hdrs/install.h ../hdrs/libinst.h ../hdrs/pkginfo.h ../libpkg/cfext.h \
  ../hdrs/install.h ../hdrs/libadm.h ../hdrs/sys/vtoc.h \
  ../hdrs/sys/dklabel.h ../hdrs/valtools.h ../hdrs/messages.h
sml.o: sml.c ../hdrs/libinst.h ../hdrs/pkgstrct.h ../hdrs/pkginfo.h \
  ../libpkg/pkglib.h ../hdrs/pkgdev.h ../libpkg/pkgerr.h \
  ../libpkg/keystore.h ../libpkg/cfext.h ../libpkg/cfext.h \
  ../hdrs/install.h ../hdrs/messages.h
srcpath.o: srcpath.c
stub.o: stub.c
unpack_package_from_stream.o: unpack_package_from_stream.c \
  ../hdrs/pkgstrct.h ../hdrs/pkginfo.h ../hdrs/pkgdev.h ../hdrs/pkglocs.h \
  ../libpkg/pkglib.h ../libpkg/pkgerr.h ../libpkg/keystore.h \
  ../libpkg/cfext.h ../hdrs/libinst.h ../libpkg/cfext.h ../hdrs/install.h \
  ../hdrs/libadm.h ../hdrs/sys/vtoc.h ../hdrs/sys/dklabel.h \
  ../hdrs/valtools.h ../hdrs/messages.h
