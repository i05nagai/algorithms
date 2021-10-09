#include "algo/nm_test/SimpleDumpingFactorCalculatorTest.h"
#include "algo/test_util/TestData.h"
#include "algo/nm/SimpleDumpingFactorCalculator.h"
#include "algo/math/euclid.h"

namespace algo { namespace nm_test {
    namespace ublas = boost::numeric::ublas;

    SimpleDumpingFactorCalculatorTest::SimpleDumpingFactorCalculatorTest() 
    {
    }
    
    SimpleDumpingFactorCalculatorTest::~SimpleDumpingFactorCalculatorTest() 
    {
    }

    void SimpleDumpingFactorCalculatorTest::SetUp()
    {
    }
    
    void SimpleDumpingFactorCalculatorTest::TearDown()
    {
    }

    TEST_F(SimpleDumpingFactorCalculatorTest, doOperatorParenthesisTest)
    {
        const ublas::vector<double>& data 
            = test_util::TestData::getRandomNumbers(2);
        const double alpha = data[0];
        const double beta = data[1];

        nm::SimpleDumpingFactorCalculator target(alpha, beta);

        const ublas::vector<double> residual
            = test_util::TestData::getRandomNumbers(2);
        const ublas::matrix<double>& jacobianMatrix
            = test_util::TestData::getRandomMatrix(2, 2);
        const double actual = target(residual, jacobianMatrix);

        const double error = math::calculateNormL2(residual);
        double expect = alpha * std::min(error, beta);
        EXPECT_DOUBLE_EQ(expect, actual);
    }
} } // namespace algo { namespace nm_test {
