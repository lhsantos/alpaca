## Makefile.am -- Process this file with automake to produce Makefile.in
## Copyright (C) 2016 Luciano Henrique de Oliveira Santos

@CODE_COVERAGE_RULES@
if CODE_COVERAGE_ENABLED
  AM_CPPFLAGS = $(CODE_COVERAGE_CPPFLAGS)
  AM_CXXFLAGS = $(CODE_COVERAGE_CXXFLAGS) --coverage
  AM_CFLAGS = $(CODE_COVERAGE_CFLAGS) --coverage
  AM_LDFLAGS = $(CODE_COVERAGE_LDFLAGS) --coverage
endif

auxdir		= @ac_aux_dir@
ACLOCAL_AMFLAGS = -I m4
ACLOCAL		= aclocal -I $(auxdir)

AUX_DIST = \
	$(auxdir)/config.guess $(auxdir)/config.sub \
	$(auxdir)/install-sh $(auxdir)/ltconfig \
	$(auxdir)/ltmain.sh $(auxdir)/mdate-sh \
	$(auxdir)/missing $(auxdir)/mkinstalldirs

SUBDIRS = lib . tests

bin_PROGRAMS = alpaca

alpaca_SOURCES = \
	src/main.cpp

alpaca_CPPFLAGS = \
	$(AM_CPPFLAGS) \
	-I$(srcdir)/lib/include

alpaca_LDADD = \
	lib/libalpaca.la

MAINTAINERCLEANFILES = Makefile.in aclocal.m4 configure config-h.in stamp-h.in $(AUX_DIST)

## Make changelog on demand
dist-hook:
	if test -d .git; then				\
	  $(top_srcdir)/build-aux/gitlog-to-changelog --since 2015-11-28	\
	    > $(distdir)/cl-t;				\
	  rm -f $(distdir)/ChangeLog;			\
	  mv $(distdir)/cl-t $(distdir)/ChangeLog;	\
	fi
