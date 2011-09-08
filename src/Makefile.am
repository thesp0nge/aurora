bin_PROGRAMS=mirage
mirage_SOURCES=main.c time.c magic.c
mirage_CPPFLAGS=-I$(top_srcdir)/include
if USE_LIBMAGIC
mirage_LDFLAGS=-lmagic
endif 
mirage_LDADD=$(top_srcdir)/src/libwc/libwc.la $(top_srcdir)/src/libcrawler/libcrawler.la
