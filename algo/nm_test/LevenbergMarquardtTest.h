#pragma once
#include "algo/nm_test/mock/IDumpingFactorCalculatorMock.h"
#include "algo/nm/LevenbergMarquardt.h"
#include <gtest/gtest.h>	
#include <memory>

namespace algo { namespace nm_test {
    class LevenbergMarquardtTest : public ::testing::Test {
    protected:
        //set-up
        LevenbergMarquardtTest();
        //clean-up does not throw exceptions
        virtual ~LevenbergMarquardtTest();
        //called before every test immediately after constructor
        virtual void SetUp();
        //called after every test before destructor
        virtual void TearDown();

        std::shared_ptr<nm::LevenbergMarquardt> _target;
        std::shared_ptr<IDumpingFactorCalculatorMock> _dumpingFactorCalculator;
        double _tolerance;
    }; // class LevenbergMarquardtTest : public ::testing::Test {
} } // namespace algo { namespace nm_test {
