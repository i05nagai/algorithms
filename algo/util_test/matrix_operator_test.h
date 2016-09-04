#pragma once
#include <gtest/gtest.h>	

namespace algo { namespace util_test {
    class MatrixOperatorTest : public ::testing::Test {
    protected:
        //set-up
        MatrixOperatorTest();
        //clean-up does not throw exceptions
        virtual ~MatrixOperatorTest();
        //called before every test immediately after constructor
        virtual void SetUp();
        //called after every test before destructor
        virtual void TearDown();
    }; // class MatrixOperatorTest : public ::testing::Test {
} } // namespace algo { namespace util_test {
