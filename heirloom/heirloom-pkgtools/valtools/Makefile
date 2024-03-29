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
INC = -I../hdrs

.c.o:
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $(INC) $(PATHS) $(WARN) $<

PKGLIBS = -L../libadm -ladm

all: ckdate ckgid ckint ckitem ckkeywd ckpath ckrange ckstr \
	cktime ckuid ckyorn puttext

ckdate: ckdate.o ../version/version.o
	$(CC) $(LDFLAGS) ckdate.o ../version/version.o $(PKGLIBS) $(LIBS) -o $@

ckgid: ckgid.o ../version/version.o
	$(CC) $(LDFLAGS) ckgid.o ../version/version.o $(PKGLIBS) $(LIBS) -o $@

ckint: ckint.o ../version/version.o
	$(CC) $(LDFLAGS) ckint.o ../version/version.o $(PKGLIBS) $(LIBS) -o $@

ckitem: ckitem.o ../version/version.o
	$(CC) $(LDFLAGS) ckitem.o ../version/version.o $(PKGLIBS) $(LIBS) -o $@

ckkeywd: ckkeywd.o ../version/version.o
	$(CC) $(LDFLAGS) ckkeywd.o ../version/version.o $(PKGLIBS) $(LIBS) -o $@

ckpath: ckpath.o ../version/version.o
	$(CC) $(LDFLAGS) ckpath.o ../version/version.o $(PKGLIBS) $(LIBS) -o $@

ckrange: ckrange.o ../version/version.o
	$(CC) $(LDFLAGS) ckrange.o ../version/version.o $(PKGLIBS) $(LIBS) -o $@

ckstr: ckstr.o ../version/version.o
	$(CC) $(LDFLAGS) ckstr.o ../version/version.o $(PKGLIBS) $(LIBS) -o $@

cktime: cktime.o ../version/version.o
	$(CC) $(LDFLAGS) cktime.o ../version/version.o $(PKGLIBS) $(LIBS) -o $@

ckuid: ckuid.o ../version/version.o
	$(CC) $(LDFLAGS) ckuid.o ../version/version.o $(PKGLIBS) $(LIBS) -o $@

ckyorn: ckyorn.o ../version/version.o
	$(CC) $(LDFLAGS) ckyorn.o ../version/version.o $(PKGLIBS) $(LIBS) -o $@

puttext: puttext.o ../version/version.o
	$(CC) $(LDFLAGS) puttext.o ../version/version.o $(PKGLIBS) $(LIBS) -o $@

ckdate ckgid ckint ckitem ckkeywd ckpath ckrange ckstr: ../libadm/libadm.a
cktime ckuid ckyorn puttext: ../libadm/libadm.a

crossln: crossln.sh
	<crossln.sh >crossln sed 's,@LNS@,ln -s,g'
	chmod 755 crossln

install: all crossln
	mkdir -p $(ROOT)$(BINDIR) $(ROOT)$(SADMDIR)/bin
	$(INSTALL) -c -m 755 ckdate $(ROOT)$(BINDIR)/ckdate
	$(STRIP) $(ROOT)$(BINDIR)/ckdate
	rm -f $(ROOT)$(BINDIR)/getdate
	ln -s ckdate $(ROOT)$(BINDIR)/getdate
	for i in errdate helpdate valdate; \
	do \
		rm -f $(ROOT)$(SADMDIR)/bin/$$i; \
		$(SHELL) ./crossln $(ROOT)$(BINDIR)/ckdate \
			$(ROOT)$(SADMDIR)/bin/$$i || exit; \
	done
	$(INSTALL) -c -m 755 ckgid $(ROOT)$(BINDIR)/ckgid
	$(STRIP) $(ROOT)$(BINDIR)/ckgid
	rm -f $(ROOT)$(BINDIR)/getgid
	ln -s ckgid $(ROOT)$(BINDIR)/getgid
	for i in dispgid errgid helpgid valgid; \
	do \
		rm -f $(ROOT)$(SADMDIR)/bin/$$i; \
		$(SHELL) ./crossln $(ROOT)$(BINDIR)/ckgid \
			$(ROOT)$(SADMDIR)/bin/$$i || exit; \
	done
	$(INSTALL) -c -m 755 ckint $(ROOT)$(BINDIR)/ckint
	$(STRIP) $(ROOT)$(BINDIR)/ckint
	rm -f $(ROOT)$(BINDIR)/getint
	ln -s ckint $(ROOT)$(BINDIR)/getint
	for i in errint helpint valint; \
	do \
		rm -f $(ROOT)$(SADMDIR)/bin/$$i; \
		$(SHELL) ./crossln $(ROOT)$(BINDIR)/ckint \
			$(ROOT)$(SADMDIR)/bin/$$i || exit; \
	done
	$(INSTALL) -c -m 755 ckitem $(ROOT)$(BINDIR)/ckitem
	$(STRIP) $(ROOT)$(BINDIR)/ckitem
	$(INSTALL) -c -m 755 ckkeywd $(ROOT)$(BINDIR)/ckkeywd
	$(STRIP) $(ROOT)$(BINDIR)/ckkeywd
	rm -f $(ROOT)$(BINDIR)/getkeywd
	ln -s ckkeywd $(ROOT)$(BINDIR)/getkeywd
	for i in errkeywd helpkeywd valkeywd; \
	do \
		rm -f $(ROOT)$(SADMDIR)/bin/$$i; \
		$(SHELL) ./crossln $(ROOT)$(BINDIR)/ckkeywd \
			$(ROOT)$(SADMDIR)/bin/$$i || exit; \
	done
	$(INSTALL) -c -m 755 ckpath $(ROOT)$(BINDIR)/ckpath
	$(STRIP) $(ROOT)$(BINDIR)/ckpath
	rm -f $(ROOT)$(BINDIR)/getpath
	ln -s ckpath $(ROOT)$(BINDIR)/getpath
	for i in errpath helppath valpath; \
	do \
		rm -f $(ROOT)$(SADMDIR)/bin/$$i; \
		$(SHELL) ./crossln $(ROOT)$(BINDIR)/ckpath \
			$(ROOT)$(SADMDIR)/bin/$$i || exit; \
	done
	$(INSTALL) -c -m 755 ckrange $(ROOT)$(BINDIR)/ckrange
	$(STRIP) $(ROOT)$(BINDIR)/ckrange
	rm -f $(ROOT)$(BINDIR)/getrange
	ln -s ckrange $(ROOT)$(BINDIR)/getrange
	for i in errange helprange valrange; \
	do \
		rm -f $(ROOT)$(SADMDIR)/bin/$$i; \
		$(SHELL) ./crossln $(ROOT)$(BINDIR)/ckrange \
			$(ROOT)$(SADMDIR)/bin/$$i || exit; \
	done
	$(INSTALL) -c -m 755 ckstr $(ROOT)$(BINDIR)/ckstr
	$(STRIP) $(ROOT)$(BINDIR)/ckstr
	rm -f $(ROOT)$(BINDIR)/getstr
	ln -s ckstr $(ROOT)$(BINDIR)/getstr
	for i in errstr helpstr valstr; \
	do \
		rm -f $(ROOT)$(SADMDIR)/bin/$$i; \
		$(SHELL) ./crossln $(ROOT)$(BINDIR)/ckstr \
			$(ROOT)$(SADMDIR)/bin/$$i || exit; \
	done
	$(INSTALL) -c -m 755 cktime $(ROOT)$(BINDIR)/cktime
	$(STRIP) $(ROOT)$(BINDIR)/cktime
	rm -f $(ROOT)$(BINDIR)/gettime
	ln -s cktime $(ROOT)$(BINDIR)/gettime
	for i in errtime helptime valtime; \
	do \
		rm -f $(ROOT)$(SADMDIR)/bin/$$i; \
		$(SHELL) ./crossln $(ROOT)$(BINDIR)/cktime \
			$(ROOT)$(SADMDIR)/bin/$$i || exit; \
	done
	$(INSTALL) -c -m 755 ckuid $(ROOT)$(BINDIR)/ckuid
	$(STRIP) $(ROOT)$(BINDIR)/ckuid
	rm -f $(ROOT)$(BINDIR)/getuid
	ln -s ckuid $(ROOT)$(BINDIR)/getuid
	for i in dispuid erruid helpuid valuid; \
	do \
		rm -f $(ROOT)$(SADMDIR)/bin/$$i; \
		$(SHELL) ./crossln $(ROOT)$(BINDIR)/ckuid \
			$(ROOT)$(SADMDIR)/bin/$$i || exit; \
	done
	$(INSTALL) -c -m 755 ckyorn $(ROOT)$(BINDIR)/ckyorn
	$(STRIP) $(ROOT)$(BINDIR)/ckyorn
	rm -f $(ROOT)$(BINDIR)/getyorn
	ln -s ckyorn $(ROOT)$(BINDIR)/getyorn
	for i in erryorn helpyorn valyorn; \
	do \
		rm -f $(ROOT)$(SADMDIR)/bin/$$i; \
		$(SHELL) ./crossln $(ROOT)$(BINDIR)/ckyorn \
			$(ROOT)$(SADMDIR)/bin/$$i || exit; \
	done
	$(INSTALL) -c -m 755 puttext $(ROOT)$(SADMDIR)/bin/puttext
	$(STRIP) $(ROOT)$(SADMDIR)/bin/puttext

clean:
	rm -f ckdate ckgid ckint ckitem ckkeywd ckpath ckrange ckstr \
		cktime ckuid ckyorn puttext ckdate.o ckgid.o ckint.o \
		ckitem.o ckkeywd.o ckpath.o ckrange.o ckstr.o cktime.o \
		ckuid.o ckyorn.o puttext.o crossln core log

mrproper: clean

ckdate.o: ckdate.c usage.h ../hdrs/libadm.h ../hdrs/sys/vtoc.h \
  ../hdrs/sys/dklabel.h ../hdrs/pkgstrct.h ../hdrs/pkginfo.h \
  ../hdrs/valtools.h ../hdrs/install.h
ckgid.o: ckgid.c usage.h ../hdrs/libadm.h ../hdrs/sys/vtoc.h \
  ../hdrs/sys/dklabel.h ../hdrs/pkgstrct.h ../hdrs/pkginfo.h \
  ../hdrs/valtools.h ../hdrs/install.h
ckint.o: ckint.c usage.h ../hdrs/libadm.h ../hdrs/sys/vtoc.h \
  ../hdrs/sys/dklabel.h ../hdrs/pkgstrct.h ../hdrs/pkginfo.h \
  ../hdrs/valtools.h ../hdrs/install.h
ckitem.o: ckitem.c ../hdrs/valtools.h usage.h ../hdrs/libadm.h \
  ../hdrs/sys/vtoc.h ../hdrs/sys/dklabel.h ../hdrs/pkgstrct.h \
  ../hdrs/pkginfo.h ../hdrs/install.h
ckkeywd.o: ckkeywd.c usage.h ../hdrs/libadm.h ../hdrs/sys/vtoc.h \
  ../hdrs/sys/dklabel.h ../hdrs/pkgstrct.h ../hdrs/pkginfo.h \
  ../hdrs/valtools.h ../hdrs/install.h
ckpath.o: ckpath.c ../hdrs/valtools.h usage.h ../hdrs/libadm.h \
  ../hdrs/sys/vtoc.h ../hdrs/sys/dklabel.h ../hdrs/pkgstrct.h \
  ../hdrs/pkginfo.h ../hdrs/install.h
ckrange.o: ckrange.c usage.h ../hdrs/libadm.h ../hdrs/sys/vtoc.h \
  ../hdrs/sys/dklabel.h ../hdrs/pkgstrct.h ../hdrs/pkginfo.h \
  ../hdrs/valtools.h ../hdrs/install.h
ckstr.o: ckstr.c usage.h ../hdrs/libadm.h ../hdrs/sys/vtoc.h \
  ../hdrs/sys/dklabel.h ../hdrs/pkgstrct.h ../hdrs/pkginfo.h \
  ../hdrs/valtools.h ../hdrs/install.h
cktime.o: cktime.c usage.h ../hdrs/libadm.h ../hdrs/sys/vtoc.h \
  ../hdrs/sys/dklabel.h ../hdrs/pkgstrct.h ../hdrs/pkginfo.h \
  ../hdrs/valtools.h ../hdrs/install.h
ckuid.o: ckuid.c usage.h ../hdrs/libadm.h ../hdrs/sys/vtoc.h \
  ../hdrs/sys/dklabel.h ../hdrs/pkgstrct.h ../hdrs/pkginfo.h \
  ../hdrs/valtools.h ../hdrs/install.h
ckyorn.o: ckyorn.c usage.h ../hdrs/libadm.h ../hdrs/sys/vtoc.h \
  ../hdrs/sys/dklabel.h ../hdrs/pkgstrct.h ../hdrs/pkginfo.h \
  ../hdrs/valtools.h ../hdrs/install.h
puttext.o: puttext.c ../hdrs/libadm.h ../hdrs/sys/vtoc.h \
  ../hdrs/sys/dklabel.h ../hdrs/pkgstrct.h ../hdrs/pkginfo.h \
  ../hdrs/valtools.h ../hdrs/install.h
