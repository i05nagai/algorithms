#pragma once
#include <gtest/gtest.h>	
namespace algo { namespace ad_test {
    class dual_test : public ::testing::Test {
    protected:
        //set-up
        dual_test();
        //clean-up does not throw exceptions
        virtual ~dual_test();
        //called before every test immediately after constructor
        virtual void SetUp();
        //called after every test before destructor
        virtual void TearDown();
        
        //target::Target _target;
    }; // class dual_test : public ::testing::Test {
} } // namespace algo { namespace ad_test {
