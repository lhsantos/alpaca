# Nonstandard package files for distribution.
EXTRA_DIST = \
  LICENSE \
  src/gmock-cardinalities.cc \
  src/gmock-internal-utils.cc \
  src/gmock-matchers.cc \
  src/gmock-spec-builders.cc \
  src/gmock.cc \
  include/gmock/gmock-actions.h \
  include/gmock/gmock-cardinalities.h \
  include/gmock/gmock-generated-actions.h \
  include/gmock/gmock-generated-function-mockers.h \
  include/gmock/gmock-generated-matchers.h \
  include/gmock/gmock-generated-nice-strict.h \
  include/gmock/gmock-matchers.h \
  include/gmock/gmock-more-actions.h \
  include/gmock/gmock-more-matchers.h \
  include/gmock/gmock-spec-builders.h \
  include/gmock/gmock.h \
  include/gmock/internal/gmock-generated-internal-utils.h \
  include/gmock/internal/gmock-internal-utils.h \
  include/gmock/internal/gmock-port.h \
  include/gmock/internal/custom/gmock-generated-actions.h \
  include/gmock/internal/custom/gmock-matchers.h \
  include/gmock/internal/custom/gmock-port.h \
  include/gmock/gmock-generated-actions.h.pump \
  include/gmock/gmock-generated-function-mockers.h.pump \
  include/gmock/gmock-generated-matchers.h.pump \
  include/gmock/gmock-generated-nice-strict.h.pump \
  include/gmock/internal/gmock-generated-internal-utils.h.pump \
  include/gmock/internal/custom/gmock-generated-actions.h.pump

AM_CPPFLAGS = $(GTEST_CPPFLAGS) -I$(srcdir)/include -I$(srcdir)/../googletest/include
AM_CXXFLAGS = $(GTEST_CXXFLAGS)
AM_LDFLAGS = $(GTEST_LDFLAGS)
AM_LIBS = $(GTEST_LIBS)

# Build rules for libraries.
check_LTLIBRARIES = lib/libgmock.la lib/libgmock_main.la
lib_libgmock_la_SOURCES = src/gmock-all.cc
lib_libgmock_la_LIBADD = ../googletest/lib/libgtest.la
lib_libgmock_main_la_SOURCES = src/gmock_main.cc
lib_libgmock_main_la_LIBADD = lib/libgmock.la
