#pragma once
#include <gtest/gtest.h>	

namespace algo { namespace nm_test {
    class ConvergenceUtilTest : public ::testing::Test {
    protected:
        //set-up
        ConvergenceUtilTest();
        //clean-up does not throw exceptions
        virtual ~ConvergenceUtilTest();
        //called before every test immediately after constructor
        virtual void SetUp();
        //called after every test before destructor
        virtual void TearDown();
        
        //target::Target _target;
    }; // class ConvergenceUtilTest : public ::testing::Test {
} } // namespace algo { namespace nm_test {
