#pragma once
#include "algo/nm/GaussNewton.h"
#include <gtest/gtest.h>	

namespace algo { namespace nm_test {
    class GaussNewtonTest : public ::testing::Test {
    protected:
        //set-up
        GaussNewtonTest();
        //clean-up does not throw exceptions
        virtual ~GaussNewtonTest();
        //called before every test immediately after constructor
        virtual void SetUp();
        //called after every test before destructor
        virtual void TearDown();
        
        std::shared_ptr<nm::GaussNewton> _target;
        double _tolerance;
    }; // class GaussNewtonTest : public ::testing::Test {
} } // namespace algo { namespace nm_test {
