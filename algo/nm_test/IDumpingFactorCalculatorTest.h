#pragma once
#include <gtest/gtest.h>	
namespace algo { namespace nm_test {
    class IDumpingFactorCalculatorTest : public ::testing::Test {
    protected:
        //set-up
        IDumpingFactorCalculatorTest();
        //clean-up does not throw exceptions
        virtual ~IDumpingFactorCalculatorTest();
        //called before every test immediately after constructor
        virtual void SetUp();
        //called after every test before destructor
        virtual void TearDown();
        
        //target::Target _target;
    }; // class IDumpingFactorCalculatorTest : public ::testing::Test {
} } // namespace algo { namespace nm_test {
