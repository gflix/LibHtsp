lib_LTLIBRARIES = libhtsp.la

libhtsp_la_SOURCES = \
    GenericHtspMessageField.cpp \
    GenericHtspMessageField.h \
    GenericHtspMessageFieldBlob.cpp \
    GenericHtspMessageFieldBlob.h \
    Htsp.cpp \
    Htsp.h \
    HtspMessage.cpp \
    HtspMessage.h \
    HtspMessageFieldBinary.cpp \
    HtspMessageFieldBinary.h \
    HtspMessageFieldList.cpp \
    HtspMessageFieldList.h \
    HtspMessageFieldSigned64.cpp \
    HtspMessageFieldSigned64.h \
    HtspMessageFieldString.cpp \
    HtspMessageFieldString.h

libhtsp_la_CPPFLAGS = \
    $(AM_CPPFLAGS) \
    $(NETWORKING_CFLAGS)

libhtsp_la_LIBADD = \
    $(NETWORKING_LIBS)

headerdir = $(includedir)/htsp
header_HEADERS = \
    Htsp.h

#pkgconfigdir = $(libdir)/pkgconfig
#pkgconfig_DATA = htsp.pc

MAINTAINERCLEANFILES = \
    Autoconf.h.in \
    Makefile.in
