#pragma once
#include <gtest/gtest.h>	
namespace algo { namespace ad_test {
    class TraitsTest : public ::testing::Test {
    protected:
        //set-up
        TraitsTest();
        //clean-up does not throw exceptions
        virtual ~TraitsTest();
        //called before every test immediately after constructor
        virtual void SetUp();
        //called after every test before destructor
        virtual void TearDown();
        
    }; // class TraitsTest : public ::testing::Test {
} } // namespace algo { namespace ad_test {
