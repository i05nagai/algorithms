#pragma once
#include <gtest/gtest.h>	
namespace algo { namespace ad_test {
    class DualTest : public ::testing::Test {
    protected:
        //set-up
        DualTest();
        //clean-up does not throw exceptions
        virtual ~DualTest();
        //called before every test immediately after constructor
        virtual void SetUp();
        //called after every test before destructor
        virtual void TearDown();
    protected:   
        double _value;
    }; // class DualTest : public ::testing::Test {
} } // namespace algo { namespace ad_test {
