#pragma once
#include <gtest/gtest.h>	

namespace algo { namespace nm_test {
    class SimpleDumpingFactorCalculatorTest : public ::testing::Test {
    protected:
        //set-up
        SimpleDumpingFactorCalculatorTest();
        //clean-up does not throw exceptions
        virtual ~SimpleDumpingFactorCalculatorTest();
        //called before every test immediately after constructor
        virtual void SetUp();
        //called after every test before destructor
        virtual void TearDown();
        
        //target::Target _target;
    }; // class SimpleDumpingFactorCalculatorTest : public ::testing::Test {
} } // namespace algo { namespace nm_test {
