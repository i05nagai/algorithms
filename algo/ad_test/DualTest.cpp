#include "algo/ad_test/DualTest.h"
#include "algo/ad/dual.hpp"
#include "algo/test_util/TestData.h"
#include "algo/test_util/gtest_helper_macro.h"

namespace algo { namespace ad_test {
    namespace ublas = boost::numeric::ublas;

    DualTest::DualTest() 
    {
    }
    
    DualTest::~DualTest() 
    {
    }

    void DualTest::SetUp()
    {
        _value = test_util::TestData::getRandomNumbers(1)(0);
    }
    
    void DualTest::TearDown()
    {
    }

    TEST_F(DualTest, constructorTest0)
    {
        //dual<double>()
        {
            ad::dual<double> dualDouble;
            const double actualValue = dualDouble.getValue();
            const double actualDerivative = dualDouble.getDerivative();
            const double expectValue = 0.0;
            const double expectDerivative = 0.0;
            EXPECT_EQ(expectValue, actualValue);
            EXPECT_EQ(expectDerivative, actualDerivative);
        }
        //dual<ublas::vector<double>>()
        {
            ad::dual<ublas::vector<double>> dualVector;
            const double actualValue = dualVector.getValue();
            const ublas::vector<double> actualDerivative 
                = dualVector.getDerivative();
            const double expectValue = 0.0;
            const ublas::vector<double> expectDerivative(0);
            EXPECT_EQ(expectValue, actualValue);
            EXPECT_VECTOR_DOUBLE_EQ(expectDerivative, actualDerivative);
        }
    }

    TEST_F(DualTest, constructorTest1)
    {
        //dual<double>(const double)
        {
            ad::dual<double> dualDouble(_value);
            const double actualValue = dualDouble.getValue();
            const double actualDerivative = dualDouble.getDerivative();
            const double expectValue = _value;
            const double expectDerivative = 0.0;
            EXPECT_EQ(expectValue, actualValue);
            EXPECT_EQ(expectDerivative, actualDerivative);
        }
        //dual<ublas::vector<double>>(const double)
        {
            ad::dual<ublas::vector<double>> dualVector(_value);
            const double actualValue = dualVector.getValue();
            const ublas::vector<double> actualDerivative 
                = dualVector.getDerivative();
            const double expectValue = _value;
            const ublas::vector<double> expectDerivative(0);
            EXPECT_EQ(expectValue, actualValue);
            EXPECT_VECTOR_DOUBLE_EQ(expectDerivative, actualDerivative);
        }
    }

    TEST_F(DualTest, constructorTest2)
    {
        //dual<double>(const dual_expression<AE>& ae)
        //ae = dual<double>
        {
            ad::dual<double> dualDouble(_value);
            const double actualValue = dualDouble.getValue();
            const double actualDerivative = dualDouble.getDerivative();
            const double expectValue = _value;
            const double expectDerivative = 0.0;
            EXPECT_EQ(expectValue, actualValue);
            EXPECT_EQ(expectDerivative, actualDerivative);
        }
        //dual<ublas::vector<double>>(const dual_expression<AE>& ae)
        //ae = dual<ublas::vector<double>>
        {
            ad::dual<ublas::vector<double>> dualVector(_value);
            const double actualValue = dualVector.getValue();
            const ublas::vector<double> actualDerivative 
                = dualVector.getDerivative();
            const double expectValue = _value;
            const ublas::vector<double> expectDerivative(0);
            EXPECT_EQ(expectValue, actualValue);
            EXPECT_VECTOR_DOUBLE_EQ(expectDerivative, actualDerivative);
        }
    }
} } // namespace algo { namespace ad_test {
