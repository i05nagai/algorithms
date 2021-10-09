#pragma once
#include <gtest/gtest.h>	
namespace algo { namespace ad_test {
    class UtilTest : public ::testing::Test {
    protected:
        //set-up
        UtilTest();
        //clean-up does not throw exceptions
        virtual ~UtilTest();
        //called before every test immediately after constructor
        virtual void SetUp();
        //called after every test before destructor
        virtual void TearDown();
        
        //target::Target _target;
    }; // class UtilTest : public ::testing::Test {
} } // namespace algo { namespace ad_test {
