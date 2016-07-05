@CODE_COVERAGE_RULES@
if CODE_COVERAGE_ENABLED
  AM_CPPFLAGS = $(CODE_COVERAGE_CPPFLAGS)
  AM_CXXFLAGS = $(CODE_COVERAGE_CXXFLAGS) --coverage
  AM_CFLAGS = $(CODE_COVERAGE_CFLAGS) --coverage
  AM_LDFLAGS = $(CODE_COVERAGE_LDFLAGS) --coverage
endif

include_HEADERS = $(srcdir)/include

# Build rules for libraries.
lib_LTLIBRARIES = libalpaca.la

libalpaca_la_CPPFLAGS = \
  $(AM_CPPFLAGS) \
	-I$(srcdir)/include \
  -I$(srcdir)/include/alpaca

libalpaca_la_SOURCES = \
  src/parser.cpp \
  src/error.cpp
