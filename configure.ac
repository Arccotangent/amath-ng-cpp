#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([amath-ng], [6-10-2016], [bugs-amath-ng@arccotangent.net])
AM_INIT_AUTOMAKE([-Wall -Wextra])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])

# Options in configure script
AC_ARG_ENABLE([cubic-op], AS_HELP_STRING([--enable-cubic-op], [Enable experimental and probably broken cubic operation]),
[case "${enableval}" in
yes) enablecubicop=true ;;
no) enablecubicop=false ;;
*) AC_MSG_ERROR([bad value '${enableval}' for --enable-cubic-op]) ;;
esac], [enablecubicop=false])
AM_CONDITIONAL([ENABLECUBICOP], [test x$enablecubicop = xtrue])
AM_COND_IF([ENABLECUBICOP], AC_DEFINE([ENABLE_CUBIC_OP], [1], [Define to 1 if cubic operation is enabled]), AC_DEFINE([ENABLE_CUBIC_OP], [0], [Define to 1 if cubic operation is enabled]))

# Checks for programs.
AC_PROG_CXX
AC_PROG_INSTALL

# Checks for libraries.
# FIXME: Replace `main' with a function in `-lboost_random':
#AC_CHECK_LIB([boost_random], [main]) #Check for libboost_random
AX_BOOST_BASE([1.59], [], AC_MSG_ERROR([Could not find Boost libraries >= 1.59.0]))
AC_CHECK_LIB([boost_random], [main]) #Check for libboost_random
AC_CHECK_LIB([gmp], [__gmpz_init]) #Check for libgmp
AC_CHECK_LIB([pthread], [pthread_create]) #Check for libpthread
#AX_PTHREAD() #Check for libpthread

# Checks for header files.
AC_CHECK_HEADERS([unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_CHECK_FUNCS([strtoull])

AC_CONFIG_FILES([
Makefile
src/Makefile
])
AC_OUTPUT

