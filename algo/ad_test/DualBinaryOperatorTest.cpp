#include "algo/ad_test/DualBinaryOperatorTest.h"
#include "algo/ad/dual.hpp"
#include "algo/ad/util.hpp"
#include "algo/ad/dual_binary_operator.hpp"
#include "algo/test_util/TestData.h"

namespace algo { namespace ad_test {
    DualBinaryOperatorTest::DualBinaryOperatorTest() 
    {
    }
    
    DualBinaryOperatorTest::~DualBinaryOperatorTest() 
    {
    }

    void DualBinaryOperatorTest::SetUp()
    {
        //value
        _value1 = test_util::TestData::getRandomNumbers(1)(0);
        _value2 = test_util::TestData::getRandomNumbers(1)(0);
        _vectorValue1 = test_util::TestData::getRandomNumbers(2);
        _vectorValue2 = test_util::TestData::getRandomNumbers(2);
        //derivative
        _scalarDerivative1 = test_util::TestData::getRandomNumbers(1)(0);
        _scalarDerivative2 = test_util::TestData::getRandomNumbers(1)(0); 
        _vectorDerivative1 = test_util::TestData::getRandomNumbers(2);
        _vectorDerivative2 = test_util::TestData::getRandomNumbers(2);
        //derivative for vectorDual
        _vectorValueScalarDerivative1 = test_util::TestData::getRandomNumbers(2);
        _vectorValueScalarDerivative2 = test_util::TestData::getRandomNumbers(2); 
        _vectorValueVectorDerivative1 = test_util::TestData::getRandomMatrix(2, 2);
        _vectorValueVectorDerivative2 = test_util::TestData::getRandomMatrix(2, 2);
        //dual
        _scalarDualScalarDerivative1 
            = scalar_dual_scalar_derivative_type(_value1, _scalarDerivative1);
        _scalarDualScalarDerivative2 
            = scalar_dual_scalar_derivative_type(_value2, _scalarDerivative2);
        _scalarDualVectorDerivative1 
            = scalar_dual_vector_derivative_type(_value1, _vectorDerivative1);
        _scalarDualVectorDerivative2 
            = scalar_dual_vector_derivative_type(_value2, _vectorDerivative2);
        _vectorDualScalarDerivative1 
            = ad::makeVectorDual(_vectorValue1, _vectorValueScalarDerivative1);
        _vectorDualScalarDerivative2 
            = ad::makeVectorDual(_vectorValue2, _vectorValueScalarDerivative2);
        _vectorDualVectorDerivative1 
            = ad::makeVectorDual(_vectorValue1, _vectorValueVectorDerivative1);
        _vectorDualVectorDerivative2 
            = ad::makeVectorDual(_vectorValue2, _vectorValueVectorDerivative2);
    }
    
    void DualBinaryOperatorTest::TearDown()
    {
    }

    TEST_F(DualBinaryOperatorTest, addTest)
    {
        {
            const auto result 
                = _scalarDualScalarDerivative1 + _scalarDualScalarDerivative2;
            const double actualValue = result.getValue();
            const double actualDerivative = result.getDerivative();

            const double expectValue 
                = _value1 + _value2;
            const double expectDerivative
                = _scalarDerivative1 + _scalarDerivative2;
            EXPECT_DOUBLE_EQ(expectValue, actualValue);
            EXPECT_DOUBLE_EQ(expectDerivative, actualDerivative);
        }
        /*
        {
            const auto result 
                = _scalarDualVectorDerivative1 + _scalarDualVectorrDerivative2;
            const double actualValue = result.getValue();
            const double actualDerivative = result.getDerivative();

            const double expectValue 
                = _value1 + _value2;
            const double expectDerivative
                = _scalarDerivative1 + _scalarDerivative2;
            EXPECT_DOUBLE_EQUAL(expectValue, actualValue);
            EXPECT_DOUBLE_EQUAL(expectDerivative, actualDerivative);
        }
        {
            const auto result
                = _vectorDualScalarDerivative1 + _vectorDualScalarDerivative2;
            const double actualValue = result.getValue();
            const double actualDerivative = result.getDerivative();
        }
        {
            const auto result
                = _vectorDualVectorDerivative1 + _vectorDualVectorrDerivative2;
            const double actualValue = result.getValue();
            const double actualDerivative = result.getDerivative();
        }
        */
    }
} } // namespace algo { namespace ad_test {
