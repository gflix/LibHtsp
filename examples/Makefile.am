AM_CPPFLAGS = \
    -I$(top_srcdir)

noinst_PROGRAMS = htsp-example-01

htsp_example_01_SOURCES = \
    HtspExample01.cpp

htsp_example_01_CPPFLAGS = \
    $(AM_CPPFLAGS) \
    $(NETWORKING_CFLAGS)

htsp_example_01_LDADD = \
    $(top_builddir)/htsp/libhtsp.la \
    $(NETWORKING_LIBS)

MAINTAINERCLEANFILES = \
    Makefile.in
