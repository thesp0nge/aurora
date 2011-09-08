lib_LTLIBRARIES = libcrawler.la
libcrawler_la_SOURCES = libcrawlerparser.c ../list.c
libcrawler_la_CPPFLAGS= -I$(top_srcdir)/include
libcrawler_la_LDFLAGS=-lfl -release 0.10.0 

libcrawlerparser.c: libcrawler.l
	$(LEX) -o libcrawlerparser.c libcrawler.l
