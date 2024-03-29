#
# CDDL HEADER START
#
# The contents of this file are subject to the terms of the
# Common Development and Distribution License (the "License").
# You may not use this file except in compliance with the License.
#
# You can obtain a copy of the license at src/OPENSOLARIS.LICENSE
# or http://www.opensolaris.org/os/licensing.
# See the License for the specific language governing permissions
# and limitations under the License.
#
# When distributing Covered Code, include this CDDL HEADER in each
# file and include the License file at src/OPENSOLARIS.LICENSE.
# If applicable, add the following below this CDDL HEADER, with the
# fields enclosed by brackets "[]" replaced with your own identifying
# information: Portions Copyright [yyyy] [name of copyright owner]
#
# CDDL HEADER END
#

#
# Copyright 2002 Sun Microsystems, Inc.  All rights reserved.
# Use is subject to license terms.
#
# from OpenSolaris r.sed	1.6	06/02/27 SMI
#
# Portions Copyright (c) 2007 Gunnar Ritter, Freiburg i. Br., Germany
#
# Sccsid @(#)r.sed.in	1.3 (gritter) 2/24/07
#

error=no
while read dest
do
	if [ -d $dest ]
	then
		echo "$dest"
		rmdir $dest || error=yes
	elif [ -f $dest ]
	then
		echo "Modifying $dest"

		# Strip PKG_INSTALL_ROOT from dest if installation is to an
		# alternate root.

		if [ -n "$PKG_INSTALL_ROOT" -a "$PKG_INSTALL_ROOT" != "/" ]; then
			client_dest=`echo $dest | \
				/home/jr/contrib/heirloom/usr/5bin/nawk -v rootdir="$PKG_INSTALL_ROOT" '{
				    { print substr($0, length(rootdir)+1)} }'`
			savepath=$PKGSAV/sed${client_dest}
		else
			savepath=$PKGSAV/sed${dest}
		fi

		/home/jr/contrib/heirloom/usr/sadm/install/scripts/cmdexec /bin/sed remove $savepath $dest ||
			error=yes
	else
		[ -r $dest ] && echo "$dest"
		rm -f $dest || error=yes
	fi
done
[ "$error" = yes ] &&
	exit 2
exit 0
