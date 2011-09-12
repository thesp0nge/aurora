SUBDIRS = src/libwc src/libcrawler src 
ACLOCAL_AMFLAGS= -I m4

log:
	git log '--pretty=format:%ad %s (%cn)' --date=short > ChangeLog

BUILT_SOURCES = $(top_srcdir)/.version
$(top_srcdir)/.version:
	echo $(VERSION) > $@-t && mv $@-t $@
dist-hook:
	echo $(VERSION) > $(distdir)/.tarball-version
