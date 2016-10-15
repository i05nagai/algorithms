#include "algo/ad_test/UblasUnaryOperatorTest.h"
#include "algo/ad/ublas_unary_operator.hpp"
#include "algo/test_util/TestData.h"
#include "algo/test_util/gtest_helper_macro.h"

namespace algo { namespace ad_test {
    namespace ublas = boost::numeric::ublas;

    UblasUnaryOperatorTest::UblasUnaryOperatorTest() 
    {
    }
    
    UblasUnaryOperatorTest::~UblasUnaryOperatorTest() 
    {
    }

    void UblasUnaryOperatorTest::SetUp()
    {
        //non dual type
        _double = test_util::TestData::getRandomNumbers(1)(0);
        _vectorDouble = test_util::TestData::getRandomNumbers(2);
    }
    
    void UblasUnaryOperatorTest::TearDown()
    {
    }

    TEST_F(UblasUnaryOperatorTest, elementExpTest)
    {
        //double
        {
            auto actual = ublas::element_exp(_double);
            const double expect = std::exp(_double);
            EXPECT_DOUBLE_EQ(expect, actual);
        }
        //ublas::vector<double>
        {
            auto actual = ublas::element_exp(_vectorDouble);
            ublas::vector<double> expect(2); 
            std::transform(
                _vectorDouble.begin(), 
                _vectorDouble.end(), 
                expect.begin(),
                [](const double value) { 
                return std::exp(value);
            });
            EXPECT_VECTOR_DOUBLE_EQ(expect, actual);
        }
    }

    TEST_F(UblasUnaryOperatorTest, elementInverseTest)
    {
        //double
        {
            auto actual = ublas::element_inverse(_double);
            const double expect = 1.0 / _double;
            EXPECT_DOUBLE_EQ(expect, actual);
        }
        //ublas::vector<double>
        {
            auto actual = ublas::element_inverse(_vectorDouble);
            ublas::vector<double> expect(2); 
            std::transform(
                _vectorDouble.begin(), 
                _vectorDouble.end(), 
                expect.begin(),
                [](const double value) { 
                return 1.0 / value;
            });
            EXPECT_VECTOR_DOUBLE_EQ(expect, actual);
        }
    }

    TEST_F(UblasUnaryOperatorTest, elementSinTest)
    {
        //double
        {
            auto actual = ublas::element_sin(_double);
            const double expect = std::sin(_double);
            EXPECT_DOUBLE_EQ(expect, actual);
        }
        //ublas::vector<double>
        {
            auto actual = ublas::element_sin(_vectorDouble);
            ublas::vector<double> expect(2); 
            std::transform(
                _vectorDouble.begin(), 
                _vectorDouble.end(), 
                expect.begin(),
                [](const double value) { 
                return std::sin(value);
            });
            EXPECT_VECTOR_DOUBLE_EQ(expect, actual);
        }
    }

    TEST_F(UblasUnaryOperatorTest, elementCosTest)
    {
        //double
        {
            auto actual = ublas::element_cos(_double);
            const double expect = std::cos(_double);
            EXPECT_DOUBLE_EQ(expect, actual);
        }
        //ublas::vector<double>
        {
            auto actual = ublas::element_cos(_vectorDouble);
            ublas::vector<double> expect(2); 
            std::transform(
                _vectorDouble.begin(), 
                _vectorDouble.end(), 
                expect.begin(),
                [](const double value) { 
                return std::cos(value);
            });
            EXPECT_VECTOR_DOUBLE_EQ(expect, actual);
        }
    }
} } // namespace algo { namespace ad_test {
