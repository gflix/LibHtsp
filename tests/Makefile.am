AUTOMAKE_OPTIONS = subdir-objects

AM_CPPFLAGS = \
    -I$(top_srcdir)

TESTS = gtest
check_PROGRAMS = $(TESTS)

gtest_SOURCES = \
    TestHtsp.cpp

gtest_LDADD = \
    $(top_builddir)/htsp/libhtsp.la \
    $(top_builddir)/external/googletest/libgtest.la

MAINTAINERCLEANFILES = \
    Makefile.in
