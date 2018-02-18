lib_LTLIBRARIES = libhtsp.la

AM_CPPFLAGS = \
    -I$(top_srcdir)

libhtsp_la_SOURCES = \
    GenericHtspClientMethod.cpp \
    GenericHtspClientMethod.h \
    GenericHtspClientMethodTag.cpp \
    GenericHtspClientMethodTag.h \
    GenericHtspMessageField.cpp \
    GenericHtspMessageField.h \
    GenericHtspMessageFieldArray.cpp \
    GenericHtspMessageFieldArray.h \
    GenericHtspMessageFieldBlob.cpp \
    GenericHtspMessageFieldBlob.h \
    GenericHtspMethod.cpp \
    GenericHtspMethod.h \
    Htsp.cpp \
    Htsp.h \
    HtspClientMethodChannelAdd.cpp \
    HtspClientMethodChannelAdd.h \
    HtspClientMethodTagAdd.cpp \
    HtspClientMethodTagAdd.h \
    HtspMessage.cpp \
    HtspMessage.h \
    HtspMessageFieldBinary.cpp \
    HtspMessageFieldBinary.h \
    HtspMessageFieldList.cpp \
    HtspMessageFieldList.h \
    HtspMessageFieldMap.cpp \
    HtspMessageFieldMap.h \
    HtspMessageFieldSigned64.cpp \
    HtspMessageFieldSigned64.h \
    HtspMessageFieldString.cpp \
    HtspMessageFieldString.h \
    HtspMethodAuthenticate.cpp \
    HtspMethodAuthenticate.h \
    HtspMethodEnableAsyncMetadata.cpp \
    HtspMethodEnableAsyncMetadata.h \
    HtspMethodHello.cpp \
    HtspMethodHello.h \
    HtspTags.h

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
