#include <gtest/gtest.h>
#include "task.hpp"

#include <filesystem>
#include <sstream>
#include <iostream>
#include <fstream>

template<size_t N>
struct StringLiteral {
    constexpr StringLiteral(const char (&str)[N]) {
        std::copy_n(str, N, value);
    }

    char value[N];
};

template<StringLiteral lit>
class CodingTest : public ::testing::Test {
public:
    std::string name = lit.value;

    std::string test_dir = CODING_TEST_DIR;
    std::filesystem::path test_path = test_dir;

    std::filesystem::path in = test_path / ( std::string("test") + name + ".in" );
    std::filesystem::path out = test_path / ( std::string("test") + name + ".out" );

    std::stringstream cout_buffer;
    std::streambuf * org_cout_buf;
    std::streambuf * org_cin_buf;

protected:
    void SetUp() override {
        org_cout_buf = std::cout.rdbuf(cout_buffer.rdbuf());
        org_cin_buf = std::cin.rdbuf();
    }

    void TearDown() override {
        std::cout.rdbuf(org_cout_buf);
        std::cin.rdbuf(org_cin_buf);
    }

public:

    void test() {
        // read testXX.out to expected
        std::string expected;
        {
            std::ifstream expectedFStream(out.c_str());
            if(!expectedFStream.is_open()){
                std::cerr << "############################ no file - skipped ############################" << std::endl;
                return;
            }
            std::stringstream expectedSStream;
            expectedSStream << expectedFStream.rdbuf();
            expected = expectedSStream.str();
        }

        // connect testXX.in to std::cin
        std::ifstream inTestFStream(in.c_str());
        std::cin.rdbuf(inTestFStream.rdbuf());

        // run the task
        task();

        std::string actual = cout_buffer.str();
        EXPECT_EQ(actual, expected);
    }
};


class CodingTest01 : public CodingTest<"01"> {};
TEST_F(CodingTest01, test)
{ test(); }

class CodingTest02 : public CodingTest<"02"> {};
TEST_F(CodingTest02, test)
{ test(); }

class CodingTest03 : public CodingTest<"03"> {};
TEST_F(CodingTest03, test)
{ test(); }

// class CodingTest04 : public CodingTest<"04"> {};
// TEST_F(CodingTest04, test)
// { test(); }
//
// class CodingTest05 : public CodingTest<"05"> {};
// TEST_F(CodingTest05, test)
// { test(); }
//
// class CodingTest06 : public CodingTest<"06"> {};
// TEST_F(CodingTest06, test)
// { test(); }
//
// class CodingTest07 : public CodingTest<"07"> {};
// TEST_F(CodingTest07, test)
// { test(); }
//
// class CodingTest08 : public CodingTest<"08"> {};
// TEST_F(CodingTest08, test)
// { test(); }
//
// class CodingTest09 : public CodingTest<"09"> {};
// TEST_F(CodingTest09, test)
// { test(); }
//
// class CodingTest10 : public CodingTest<"10"> {};
// TEST_F(CodingTest10, test)
// { test(); }
//
// class CodingTest11 : public CodingTest<"11"> {};
// TEST_F(CodingTest11, test)
// { test(); }
//
