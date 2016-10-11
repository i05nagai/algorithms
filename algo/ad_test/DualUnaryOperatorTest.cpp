#include "algo/ad_test/DualUnaryOperatorTest.h"
#include "algo/ad_test/TestUtil.h"
#include "algo/ad/util.hpp"
#include "algo/test_util/TestData.h"
#include "algo/test_util/gtest_helper_macro.h"

namespace algo { namespace ad_test {
    namespace ublas = boost::numeric::ublas;

    DualUnaryOperatorTest::DualUnaryOperatorTest() 
    {
    }
    
    DualUnaryOperatorTest::~DualUnaryOperatorTest() 
    {
    }

    void DualUnaryOperatorTest::SetUp()
    {
        //value
        _value = test_util::TestData::getRandomNumbers(1)(0);
        _vectorValue = test_util::TestData::getRandomNumbers(2);
        //derivative
        _scalarDerivative = test_util::TestData::getRandomNumbers(1)(0);
        _vectorDerivative = test_util::TestData::getRandomNumbers(2);
        //derivative for vectorDual
        _vectorValueScalarDerivative = test_util::TestData::getRandomNumbers(2);
        _vectorValueVectorDerivative = test_util::TestData::getRandomMatrix(2, 2);
        //dual
        _scalarDualScalarDerivative 
            = scalar_dual_scalar_derivative_type(_value, _scalarDerivative);
        _scalarDualVectorDerivative 
            = scalar_dual_vector_derivative_type(_value, _vectorDerivative);
        _vectorDualScalarDerivative 
            = ad::makeVectorDual(_vectorValue, _vectorValueScalarDerivative);
        _vectorDualVectorDerivative 
            = ad::makeVectorDual(_vectorValue, _vectorValueVectorDerivative);
    }
    
    void DualUnaryOperatorTest::TearDown()
    {
    }

    TEST_F(DualUnaryOperatorTest, operatorNegateTest)
    {
        //scalar dual scalar derivative
        {
            const auto result 
                = - _scalarDualScalarDerivative;
            const double actualValue = result.getValue();
            const double actualDerivative = result.getDerivative();

            const double expectValue = -_value;
            const double expectDerivative = -_scalarDerivative;

            EXPECT_DOUBLE_EQ(expectValue, actualValue);
            EXPECT_DOUBLE_EQ(expectDerivative, actualDerivative);
        }
        //scalar dual vector derivative
        {
            const auto result 
                = -_scalarDualVectorDerivative;
            const double actualValue = result.getValue();
            const ublas::vector<double> actualDerivative = result.getDerivative();

            const double expectValue = -_value;
            const ublas::vector<double> expectDerivative = -_vectorDerivative;

            EXPECT_DOUBLE_EQ(expectValue, actualValue);
            EXPECT_VECTOR_DOUBLE_EQ(expectDerivative, actualDerivative);
        }
        //vector dual scalar derivative
        {
            const auto result = -_vectorDualScalarDerivative;
            const ublas::vector<double> actualValue 
                = TestUtil::getValueFromVectorDualScalarDerivative(result);
            const ublas::vector<double> actualDerivative 
                = TestUtil::getDerivativeFromVectorValueScalarDerivative(result);
            
            const ublas::vector<double> expectValue = -_vectorValue;
            const ublas::vector<double> expectDerivative
                = -_vectorValueScalarDerivative;

            EXPECT_VECTOR_DOUBLE_EQ(expectValue, actualValue);
            EXPECT_VECTOR_DOUBLE_EQ(expectDerivative, actualDerivative);
        }
        //vector dual vector derivative
        {
            const auto result = -_vectorDualVectorDerivative;
            const ublas::vector<double> actualValue 
                = TestUtil::getValueFromVectorDualVectorDerivative(result);
            const ublas::matrix<double> actualDerivative 
                = TestUtil::getDerivativeFromVectorValueVectorDerivative(result);

            const ublas::vector<double> expectValue = -_vectorValue;
            const ublas::matrix<double> expectDerivative
                = -_vectorValueVectorDerivative;

            EXPECT_VECTOR_DOUBLE_EQ(expectValue, actualValue);
            EXPECT_MATRIX_DOUBLE_EQ(expectDerivative, actualDerivative);
        }
    }

    TEST_F(DualUnaryOperatorTest, operatorExpTest)
    {
        //scalar dual scalar derivative
        {
            const auto result 
                = ad::exp(_scalarDualScalarDerivative);
            const double actualValue = result.getValue();
            const double actualDerivative = result.getDerivative();

            const double expectValue = std::exp(_value);
            const double expectDerivative 
                = _scalarDerivative * std::exp(_value);

            EXPECT_DOUBLE_EQ(expectValue, actualValue);
            EXPECT_DOUBLE_EQ(expectDerivative, actualDerivative);
        }
        //scalar dual vector derivative
        {
            const auto result 
                = ad::exp(_scalarDualVectorDerivative);
            const double actualValue = result.getValue();
            const ublas::vector<double> actualDerivative = result.getDerivative();

            const double expectValue = std::exp(_value);
            const ublas::vector<double> expectDerivative 
                = ublas::exp(_value) * _vectorDerivative;

            EXPECT_DOUBLE_EQ(expectValue, actualValue);
            EXPECT_VECTOR_DOUBLE_EQ(expectDerivative, actualDerivative);
        }
    }

    TEST_F(DualUnaryOperatorTest, operatorLogTest)
    {
        //scalar dual scalar derivative
        {
            const auto result 
                = ad::log(_scalarDualScalarDerivative);
            const double actualValue = result.getValue();
            const double actualDerivative = result.getDerivative();

            const double expectValue = std::log(_value);
            const double expectDerivative 
                =  _scalarDerivative / _value;

            EXPECT_DOUBLE_EQ(expectValue, actualValue);
            EXPECT_DOUBLE_EQ(expectDerivative, actualDerivative);
        }
        //scalar dual vector derivative
        {
            const auto result 
                = ad::log(_scalarDualVectorDerivative);
            const double actualValue = result.getValue();
            const ublas::vector<double> actualDerivative 
                = result.getDerivative();

            const double expectValue = std::log(_value);
            const ublas::vector<double> expectDerivative 
                =  _vectorDerivative / _value;

            EXPECT_DOUBLE_EQ(expectValue, actualValue);
            EXPECT_VECTOR_DOUBLE_EQ(expectDerivative, actualDerivative);
        }
    }

    TEST_F(DualUnaryOperatorTest, operatorSinTest)
    {
        //scalar dual scalar derivative
        {
            const auto result 
                = ad::sin(_scalarDualScalarDerivative);
            const double actualValue = result.getValue();
            const double actualDerivative = result.getDerivative();

            const double expectValue = std::sin(_value);
            const double expectDerivative 
                =  _scalarDerivative * std::cos(_value);

            EXPECT_DOUBLE_EQ(expectValue, actualValue);
            EXPECT_DOUBLE_EQ(expectDerivative, actualDerivative);
        }
        //scalar dual vector derivative
        {
            const auto result 
                = ad::sin(_scalarDualVectorDerivative);
            const double actualValue = result.getValue();
            const ublas::vector<double> actualDerivative 
                = result.getDerivative();

            const double expectValue = std::sin(_value);
            const ublas::vector<double> expectDerivative 
                =  _vectorDerivative * std::cos(_value);

            EXPECT_DOUBLE_EQ(expectValue, actualValue);
            EXPECT_VECTOR_DOUBLE_EQ(expectDerivative, actualDerivative);
        }
    }

    TEST_F(DualUnaryOperatorTest, operatorCosTest)
    {
        //scalar dual scalar derivative
        {
            const auto result 
                = ad::cos(_scalarDualScalarDerivative);
            const double actualValue = result.getValue();
            const double actualDerivative = result.getDerivative();

            const double expectValue = std::cos(_value);
            const double expectDerivative 
                =  - _scalarDerivative * std::sin(_value);

            EXPECT_DOUBLE_EQ(expectValue, actualValue);
            EXPECT_DOUBLE_EQ(expectDerivative, actualDerivative);
        }
        //scalar dual vector derivative
        {
            const auto result 
                = ad::cos(_scalarDualVectorDerivative);
            const double actualValue = result.getValue();
            const ublas::vector<double> actualDerivative 
                = result.getDerivative();

            const double expectValue = std::cos(_value);
            const ublas::vector<double> expectDerivative 
                =  - _vectorDerivative * std::sin(_value);

            EXPECT_DOUBLE_EQ(expectValue, actualValue);
            EXPECT_VECTOR_DOUBLE_EQ(expectDerivative, actualDerivative);
        }
    }
} } // namespace algo { namespace ad_test {
