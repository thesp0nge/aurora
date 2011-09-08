lib_LTLIBRARIES = libwc.la
libwc_la_SOURCES = libwcparser.c # libwc.c
libwc_la_CPPFLAGS= -I$(top_srcdir)/include
libwc_la_LDFLAGS=-lfl -release 0.10.0 

libwcparser.c: libwc.l
	$(LEX) -o libwcparser.c libwc.l
