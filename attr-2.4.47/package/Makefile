#
# Copyright (c) 2000-2002 Silicon Graphics, Inc.  All Rights Reserved.
# Copyright (C) 2009  Andreas Gruenbacher <agruen@suse.de>
#
# This program is free software: you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

TOPDIR = ..
include $(TOPDIR)/include/builddefs

MANIFEST=src-manifest
SRCTAR=$(PKG_NAME)-$(PKG_VERSION).src.tar.gz

LDIRT = *-manifest *.gz $(TOPDIR)/$(PKG_NAME)-*

# for clean and clobber
SUBDIRS = tar rpm

# nothing to build here (it's all packaging)
default install install-dev install-lib:

include $(BUILDRULES)

# Symlink in the TOPDIR is used to pack files relative to
# product-version directory.
$(MANIFEST) : $(_FORCE)
	@if [ ! -L $(TOPDIR)/$(PKG_NAME)-$(PKG_VERSION) ] ; then \
	    $(LN_S) . $(TOPDIR)/$(PKG_NAME)-$(PKG_VERSION) ; \
	fi
	@CDIR=`pwd`; cd $(TOPDIR); \
	$(MAKE) --no-print-directory source | \
	    sed -e 's/^\./$(PKG_NAME)-$(PKG_VERSION)/' > $$CDIR/$@ ;\
	if [ $$? -ne 0 ] ; then  \
	    exit 1; \
	else \
	    unset TAPE; \
	    $(TAR) -T $$CDIR/$@ -cf - | $(ZIP) --best > $$CDIR/$(SRCTAR); \
	    echo Wrote: $$CDIR/$(SRCTAR); \
	fi

dist : default $(MANIFEST)
	@DIST_MANIFEST=`pwd`/bin-manifest; DIST_ROOT=/tmp/$$$$; \
	export DIST_MANIFEST DIST_ROOT; \
	rm -f $$DIST_MANIFEST; \
	echo === install === && $(MAKE) -C $(TOPDIR) install || exit $$?; \
	if [ -x $(TAR) ]; then \
	    ( echo "=== tar ===" && $(MAKEF) -C tar $@ || exit $$? ); \
	fi; \
	if [ -x $(RPMBUILD) ]; then \
	    ( echo "=== rpm ===" && $(MAKEF) -C rpm $@ || exit $$? ); \
	fi; \
	test -z "$$KEEP_DIST_ROOT" || rm -rf $$DIST_ROOT; echo Done
