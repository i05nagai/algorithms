#include "nm_test/ConvergenceUtilTest.h"
#include "test_util/TestData.h"
#include "nm/ConvergenceUtil.h"
#include "math/euclid.h"

namespace algo { namespace nm_test {
    namespace ublas = boost::numeric::ublas;

    ConvergenceUtilTest::ConvergenceUtilTest() 
    {
    }
    
    ConvergenceUtilTest::~ConvergenceUtilTest() 
    {
    }

    void ConvergenceUtilTest::SetUp()
    {
    }
    
    void ConvergenceUtilTest::TearDown()
    {
    }

    TEST_F(ConvergenceUtilTest, isConvergenceTest0)
    {
        const ublas::vector<double> residual 
            = test_util::TestData::getRandomNumbers(2);
        const double tolerance = test_util::TestData::getRandomNumbers(2)[0];
        const bool actual 
            = nm::ConvergenceUtil::isConvergence(residual, tolerance);

        const double error = math::calculateNormL2(residual);
        const bool expect =  error < tolerance; 

        EXPECT_EQ(expect, actual);
    }
} } // namespace algo { namespace nm_test {
