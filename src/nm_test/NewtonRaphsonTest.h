#pragma once
#include "algo/nm/NewtonRaphson.h"
#include <gtest/gtest.h>	

namespace algo { namespace nm_test {
    class NewtonRaphsonTest : public ::testing::Test {
    protected:
        //set-up
        NewtonRaphsonTest();
        //clean-up does not throw exceptions
        virtual ~NewtonRaphsonTest();
        //called before every test immediately after constructor
        virtual void SetUp();
        //called after every test before destructor
        virtual void TearDown();
        
        //nm::NewtonRaphson _target;
    }; // class NewtonRaphsonTest : public ::testing::Test {
} } // namespace algo { namespace nm_test {
