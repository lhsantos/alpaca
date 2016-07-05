#include "gtest/gtest.h"
#include "alpaca/error.h"
#include <string>
#include <sstream>

using namespace alpaca;

TEST(exception, IsConstructedAndCopiedProperly)
{
    exception e1;
    ASSERT_EQ(e1.msg(), "");
    ASSERT_EQ(e1.function(), "unknown");
    ASSERT_EQ(e1.file(), "unknown");
    ASSERT_EQ(e1.line(), -1);
    ASSERT_EQ(e1.inner().get(), nullptr);

    exception e2("e2", nullptr, "e2_func", "e2_file", 42);
    ASSERT_EQ(e2.msg(), "e2");
    ASSERT_EQ(e2.function(), "e2_func");
    ASSERT_EQ(e2.file(), "e2_file");
    ASSERT_EQ(e2.line(), 42);
    ASSERT_EQ(e2.inner().get(), nullptr);

    exception e3("e3", e2, "e3_func", "e3_file", 43);
    ASSERT_EQ(e3.msg(), "e3");
    ASSERT_EQ(e3.function(), "e3_func");
    ASSERT_EQ(e3.file(), "e3_file");
    ASSERT_EQ(e3.line(), 43);
    ASSERT_NE(e3.inner().get(), nullptr);
    ASSERT_EQ(e3.inner().get()->msg(), "e2");

    int expected_line = 1 + (int)__LINE__;
    try { ALPACA_THROW(exception("thrown")); }
    catch (const exception& ce1)
    {
        ASSERT_EQ(ce1.msg(), "thrown");
        ASSERT_EQ(ce1.function(), __func__);
        ASSERT_EQ(ce1.file(), __FILE__);
        ASSERT_EQ(ce1.line(), expected_line);
        ASSERT_EQ(ce1.inner().get(), nullptr);
    }
}

TEST(exception, CreatesStringsCorrectly)
{
    exception e1("e1", nullptr, "e1_func", "e1_file", 41);
    ASSERT_EQ(strcmp(e1.what(), "e1"), 0);
    ASSERT_EQ(e1.to_str(), "e1_file:41:e1_func: e1");
    std::ostringstream e1_stream;
    e1.trace(e1_stream);
    ASSERT_EQ(e1_stream.str(), "e1_file:41:e1_func: e1\n");

    exception e2("e2", e1, "e2_func", "e2_file", 42);
    ASSERT_EQ(e2.to_str(), "e2_file:42:e2_func: e2");
    std::string e2_expected =
        std::string("e2_file:42:e2_func: e2 caused by\n")
        + "e1_file:41:e1_func: e1\n";
    std::ostringstream e2_stream;
    e2.trace(e2_stream);
    ASSERT_EQ(e2_stream.str(), e2_expected);

    exception e3("e3", e2, "e3_func", "e3_file", 43);
    ASSERT_EQ(e3.to_str(), "e3_file:43:e3_func: e3");
    std::string e3_expected =
        std::string("e3_file:43:e3_func: e3 caused by\n")
        + "e2_file:42:e2_func: e2 caused by\n"
        + "e1_file:41:e1_func: e1\n";
    std::ostringstream e3_stream;
    e3.trace(e3_stream);
    ASSERT_EQ(e3_stream.str(), e3_expected);
}
