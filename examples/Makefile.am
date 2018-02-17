AM_CPPFLAGS = \
    -I$(top_srcdir)

noinst_PROGRAMS = \
    htsp-example-01 \
    htsp-example-02 \
    htsp-example-03

htsp_example_01_SOURCES = \
    HtspExample01.cpp

htsp_example_01_CPPFLAGS = \
    $(AM_CPPFLAGS) \
    $(NETWORKING_CFLAGS)

htsp_example_01_LDADD = \
    $(top_builddir)/htsp/libhtsp.la \
    $(NETWORKING_LIBS)

htsp_example_02_SOURCES = \
    HtspExample02.cpp

htsp_example_02_CPPFLAGS = \
    $(AM_CPPFLAGS) \
    $(NETWORKING_CFLAGS)

htsp_example_02_LDADD = \
    $(top_builddir)/htsp/libhtsp.la \
    $(NETWORKING_LIBS)

htsp_example_03_SOURCES = \
    HtspExample03.cpp

htsp_example_03_CPPFLAGS = \
    $(AM_CPPFLAGS) \
    $(NETWORKING_CFLAGS)

htsp_example_03_LDADD = \
    $(top_builddir)/htsp/libhtsp.la \
    $(NETWORKING_LIBS)

MAINTAINERCLEANFILES = \
    Makefile.in
