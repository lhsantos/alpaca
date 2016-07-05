SUBDIRS = googletest googlemock .

@CODE_COVERAGE_RULES@

AM_CPPFLAGS = \
  $(GTEST_CPPFLAGS) \
  -I$(srcdir)/googletest/include \
  -I$(srcdir)/googlemock/include \
  -I$(srcdir)/../lib/include
AM_CXXFLAGS = $(GTEST_CXXFLAGS)
AM_LDFLAGS = $(GTEST_LDFLAGS)
AM_LIBS = $(GTEST_LIBS)

if CODE_COVERAGE_ENABLED
AM_LDFLAGS += $(CODE_COVERAGE_LDFLAGS) --coverage

cov-reset:
	@rm -rf coverage
	@find .. -name "*.gcda" -exec rm {} \;
	@lcov --directory . --zerocounters

cov-report:
	@rm -rf coverage
	@mkdir -p coverage
	@lcov --compat-libtool --capture --directory .. --output-file coverage/alpaca.info  
	@genhtml -o coverage/ coverage/alpaca.info

clean-local:
	@make cov-reset 

check: check-recursive
	@make cov-report
endif

COMMON_LIBS = \
  ../lib/libalpaca.la \
  googletest/lib/libgtest.la \
  googletest/lib/libgtest_main.la

check_PROGRAMS = \
  unit_tests

TESTS = \
  unit_tests

unit_tests_SOURCES = \
  src/ut_error.cpp

unit_tests_LDADD = $(COMMON_LIBS)
