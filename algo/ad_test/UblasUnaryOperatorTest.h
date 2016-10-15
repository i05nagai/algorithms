#pragma once
#include <gtest/gtest.h>	
#include <boost/numeric/ublas/vector.hpp>

namespace algo { namespace ad_test {
    class UblasUnaryOperatorTest : public ::testing::Test {
    protected:
        //set-up
        UblasUnaryOperatorTest();
        //clean-up does not throw exceptions
        virtual ~UblasUnaryOperatorTest();
        //called before every test immediately after constructor
        virtual void SetUp();
        //called after every test before destructor
        virtual void TearDown();
    protected:
        //integral type
        double _double;
        boost::numeric::ublas::vector<double> _vectorDouble;
    }; // class UblasUnaryOperatorTest : public ::testing::Test {
} } // namespace algo { namespace ad_test {
