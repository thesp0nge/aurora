bin_PROGRAMS=aurora
aurora_SOURCES=main.c time.c magic.c
aurora_CPPFLAGS=-I$(top_srcdir)/include
if USE_LIBMAGIC
aurora_LDFLAGS=-lmagic
endif 
aurora_LDADD=$(top_srcdir)/src/libwc/libwc.la $(top_srcdir)/src/libcrawler/libcrawler.la
