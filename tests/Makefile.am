AUTOMAKE_OPTIONS = subdir-objects

AM_CPPFLAGS = \
    -I$(top_srcdir)

TESTS = gtest
check_PROGRAMS = $(TESTS)

gtest_SOURCES = \
    TestHtsp.cpp \
    TestHtspMessage.cpp \
    TestHtspMethodHello.cpp

gtest_LDADD = \
    $(top_builddir)/htsp/libhtsp.la \
    $(top_builddir)/external/googletest/libgtest.la

gtest_CPPFLAGS = \
    $(AM_CPPFLAGS) \
    -I$(top_srcdir)/external/googletest/include \
    $(GLISSEO_CFLAGS)

MAINTAINERCLEANFILES = \
    Makefile.in
