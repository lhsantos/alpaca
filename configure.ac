dnl configure.ac -- Process this file with autoconf to produce configure
dnl Copyright (C) 2016 Luciano Henrique de Oliveira Santos

AC_PREREQ([2.68])
AC_INIT([alpaca], [0.1.0], [lhsantos@kuhp.kyoto-u.ac.jp])

AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIRS([m4])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile])
AC_CONFIG_FILES([lib/Makefile])
AC_CONFIG_FILES([tests/Makefile])
AC_CONFIG_FILES([tests/googletest/Makefile])
AC_CONFIG_FILES([tests/googlemock/Makefile])
AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])

# Checks for programs.
# If code coverage report was requested, ignores the user's compiler options...
if test "$enable_code_coverage" = "yes"; then
  CFLAGS="-g -O0"
  CXXFLAGS="-g -O0"
fi
AC_PROG_CC
AC_PROG_CXX
AC_LANG([C++])
AM_PROG_AR
AM_PROG_LIBTOOL
AX_CODE_COVERAGE 

# Check for C++11
AX_CXX_COMPILE_STDCXX_11([ext])

# Checks for libraries.
AC_LIBTOOL_DLOPEN
AC_LIBTOOL_WIN32_DLL

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

# Configure pthreads.
AC_ARG_WITH([pthreads],
            [AS_HELP_STRING([--with-pthreads],
               [use pthreads (default is yes)])],
            [with_pthreads=$withval],
            [with_pthreads=check])

have_pthreads=no
AS_IF([test "x$with_pthreads" != "xno"],
      [ACX_PTHREAD(
        [],
        [AS_IF([test "x$with_pthreads" != "xcheck"],
               [AC_MSG_FAILURE(
                 [--with-pthreads was specified, but unable to be used])])])
       have_pthreads="$acx_pthread_ok"])
AM_CONDITIONAL([HAVE_PTHREADS],[test "x$have_pthreads" = "xyes"])
AC_SUBST([PTHREAD_CFLAGS])
AC_SUBST([PTHREAD_LIBS])

# Define gtest variables 
GTEST_VERSION="1.7.0"
if test "x$have_pthread" = "xyes"; then
  GTEST_CPPFLAGS="-DGTEST_HAS_PTHREAD=1"
  GTEST_CXXFLAGS="$PTHREAD_CFLAGS"
  GTEST_LDFLAGS=
  GTEST_LIBS="$PTHREAD_LIBS"
else
  GTEST_CPPFLAGS="-DGTEST_HAS_PTHREAD=0"
  GTEST_CXXFLAGS=
  GTEST_LDFLAGS=
  GTEST_LIBS=
fi
AC_SUBST([GTEST_VERSION])
AC_SUBST([GTEST_CPPFLAGS])
AC_SUBST([GTEST_CXXFLAGS])
AC_SUBST([GTEST_LDFLAGS])
AC_SUBST([GTEST_LIBS])

# Finally...
AC_SUBST(srcdir)
AC_SUBST(ac_aux_dir)
AC_OUTPUT
