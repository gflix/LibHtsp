#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([libhtsp], [0.1.0], [felix.mellmann@gmail.com])
AC_CONFIG_SRCDIR([htsp/Htsp.cpp])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_HEADERS([htsp/Autoconf.h])

AM_INIT_AUTOMAKE()

# Checks for programs.
AM_PROG_AR
AC_PROG_CXX
AC_PROG_CC
AX_CXX_COMPILE_STDCXX_11()

LT_INIT

# Checks for libraries.
PKG_CHECK_MODULES([NETWORKING], [networking >= 0.1.0], [], AC_MSG_ERROR([Unable to find networking >= 0.1.0.]))

# Checks for header files.
# AC_CHECK_HEADERS([netdb.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
# AC_CHECK_HEADER_STDBOOL

# Checks for library functions.
# AC_CHECK_FUNCS([bzero socket])

AC_CONFIG_FILES([
    Makefile
    external/googletest/Makefile
    htsp/Makefile
    tests/Makefile
])
AC_OUTPUT
