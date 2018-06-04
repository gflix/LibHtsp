lib_LTLIBRARIES = libhtsp.la

AM_CPPFLAGS = \
    -I$(top_srcdir)

libhtsp_la_SOURCES = \
    GenericHtspClientMethod.cpp \
    GenericHtspClientMethod.h \
    GenericHtspClientMethodAutorecEntry.cpp \
    GenericHtspClientMethodAutorecEntry.h \
    GenericHtspClientMethodChannel.cpp \
    GenericHtspClientMethodChannel.h \
    GenericHtspClientMethodDvrEntry.cpp \
    GenericHtspClientMethodDvrEntry.h \
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
    HtspClientMethodAutorecEntryAdd.cpp \
    HtspClientMethodAutorecEntryAdd.h \
    HtspClientMethodChannelAdd.cpp \
    HtspClientMethodChannelAdd.h \
    HtspClientMethodDvrEntryAdd.cpp \
    HtspClientMethodDvrEntryAdd.h \
    HtspClientMethodDvrEntryUpdate.cpp \
    HtspClientMethodDvrEntryUpdate.h \
    HtspClientMethodInitialSyncCompleted.cpp \
    HtspClientMethodInitialSyncCompleted.h \
    HtspClientMethodTagAdd.cpp \
    HtspClientMethodTagAdd.h \
    HtspClientMethodTagUpdate.cpp \
    HtspClientMethodTagUpdate.h \
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
    $(GLISSEO_CFLAGS)

libhtsp_la_LIBADD = \
    $(GLISSEO_LIBS)

headerdir = $(includedir)/htsp
header_HEADERS = \
    GenericHtspClientMethod.h \
    GenericHtspClientMethodAutorecEntry.h \
    GenericHtspClientMethodChannel.h \
    GenericHtspClientMethodDvrEntry.h \
    GenericHtspClientMethodTag.h \
    GenericHtspMessageField.h \
    GenericHtspMethod.h \
    Htsp.h \
    HtspMessage.h \
    HtspMethodAuthenticate.h \
    HtspMethodEnableAsyncMetadata.h \
    HtspMethodHello.h

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = htsp.pc

MAINTAINERCLEANFILES = \
    Autoconf.h.in \
    Makefile.in
