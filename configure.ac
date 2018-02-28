#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([libhtsp], [0.4.1], [felix.mellmann@gmail.com])
AC_CONFIG_SRCDIR([htsp/Htsp.cpp])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_HEADERS([htsp/Autoconf.h])

AM_INIT_AUTOMAKE()

# Checks for programs.
AM_PROG_AR
AC_PROG_CXX
AC_PROG_CC
AC_PROG_RANLIB
AX_CXX_COMPILE_STDCXX_11()

LT_INIT

# Checks for libraries.
PKG_CHECK_MODULES([NETWORKING], [networking >= 0.1.2], [], AC_MSG_ERROR([Unable to find networking >= 0.1.2.]))

# Checks for header files.
AC_CHECK_HEADERS([arpa/inet.h fcntl.h float.h limits.h netdb.h])
AC_CHECK_HEADERS([stddef.h sys/socket.h sys/time.h sys/timeb.h wchar.h wctype.h])
AC_CHECK_HEADER_STDBOOL

# Checks for typedefs, structures, and compiler characteristics.
AC_C_INLINE
AC_TYPE_INT64_T
AC_TYPE_SIZE_T
AC_TYPE_PID_T
AC_CHECK_TYPES([ptrdiff_t])

# Checks for library functions.
AC_CHECK_FUNCS([dup2 fchdir getcwd gettimeofday localtime_r memset mkdir munmap regcomp])
AC_CHECK_FUNCS([rmdir socket strcasecmp strchr strdup strerror strrchr strstr strtol strtoull])

AC_FUNC_FORK
AC_FUNC_MALLOC
AC_FUNC_MMAP
AC_FUNC_STRERROR_R

AC_CONFIG_FILES([
    Makefile
    examples/Makefile
    external/googletest/Makefile
    htsp/Makefile
    htsp/htsp.pc
    tests/Makefile
])
AC_OUTPUT
