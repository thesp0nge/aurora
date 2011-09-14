#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.65])
AC_INIT([aurora], m4_esyscmd([build-aux/version.sh]), [thesp0nge@gmail.com])
AC_CONFIG_SRCDIR([src/main.c])
AC_CONFIG_HEADERS([config.h])

AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
LT_INIT

#defines 
AC_DEFINE(IS_DEBUG, 1, [aurora is in debug mode])

# Checks for programs.
AC_PROG_INSTALL
AC_PROG_CC
AC_PROG_LEX
AC_PROG_YACC
AC_PROG_LIBTOOL

AC_CHECK_LIB([magic], [magic_open])
AS_IF([test "$ac_cv_lib_magic_magic_open" = yes], [HAVE_LIBMAGIC=1], [HAVE_LIBMAGIC=0])
AM_CONDITIONAL([USE_LIBMAGIC], [test "$ac_cv_lib_magic_magic_open" = yes])

AC_CHECK_LIB([fl], [main])

AC_CHECK_HEADERS([inttypes.h stdlib.h string.h unistd.h magic.h memory.h getopt.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_INT16_T
AC_TYPE_INT32_T
AC_TYPE_INT8_T
AC_TYPE_SIZE_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT8_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_CHECK_FUNCS([memset getopt_long])


# Enable/Disable aurora features

AC_ARG_ENABLE([crawling],
              [ --disable-crawling disable source code string crawling ],
              [crawling=${enableval}], 
              [crawling=yes])


AC_CONFIG_FILES([Makefile
                 src/Makefile
                 src/libwc/Makefile
                 src/libcrawler/Makefile])
AC_OUTPUT
echo \ 
  "-------------------------------------------------
    ${PACKAGE_NAME} Version ${PACKAGE_VERSION}
    
    Prefix: '${prefix}'. 
    Compiler: '${CC} ${CFLAGS} ${CPPFLAGS}'
    
    Package features: 
      Crawling source code: ${crawling}

    Now type 'make @<:@<target>@:>@'
     where the optional <target> is:
      all	- build all binaries
      install	- install everything
  --------------------------------------------------"

