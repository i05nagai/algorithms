#include "algo/ad_test/UtilTest.h"
#include "algo/test_util/TestData.h"
#include "algo/test_util/gtest_helper_macro.h"

namespace algo { namespace ad_test {
    UtilTest::UtilTest() 
    {
    }
    
    UtilTest::~UtilTest() 
    {
    }

    void UtilTest::SetUp()
    {
    }
    
    void UtilTest::TearDown()
    {
    }

    TEST_F(UtilTest, makeDualTest)
    {
        /*
        namespace ublas = boost::numeric::ublas;

        const double value = test_util::TestData::getRandomNumbers(1)(0);
        const boost::numeric::ublas::vector<double> derivative 
            = test_util::TestData::getRandomNumbers(2);
        ad::dual<ublas::vector<double>> actual 
            = ad::makeDual(value, derivative);

        const double actualValue = actual.getValue();
        const ublas::vector<double> actualDerivative = actual.getDerivative();

        EXPECT_DOUBLE_EQ(value, actualValue);
        EXPECT_VECTOR_DOUBLE_EQ(derivative, actualDerivative);
        */
    }
} } // namespace algo { namespace ad_test {
