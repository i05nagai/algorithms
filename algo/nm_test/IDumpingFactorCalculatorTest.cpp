#include "nm_test/IDumpingFactorCalculatorTest.h"
#include "nm_test/mock/IDumpingFactorCalculatorMock.h"
#include "test_util/TestData.h"
#include "nm/IDumpingFactorCalculator.h"
#include <memory>

namespace algo { namespace nm_test {
    namespace ublas = boost::numeric::ublas;

    IDumpingFactorCalculatorTest::IDumpingFactorCalculatorTest() 
    {
    }
    
    IDumpingFactorCalculatorTest::~IDumpingFactorCalculatorTest() 
    {
    }

    void IDumpingFactorCalculatorTest::SetUp()
    {
    }
    
    void IDumpingFactorCalculatorTest::TearDown()
    {
    }

    TEST_F(IDumpingFactorCalculatorTest, operatorParenthesisTest)
    {
        const double data = test_util::TestData::getRandomNumbers(1)[0];
        std::shared_ptr<IDumpingFactorCalculatorMock> mock
            = std::make_shared<IDumpingFactorCalculatorMock>();

        EXPECT_CALL(*mock, doOperatorParenthesis(_, _))
            .Times(1)
            .WillOnce(Return(data));
        const ublas::vector<double> residual 
            = test_util::TestData::getRandomNumbers(2);
        const ublas::matrix<double> jacobianMatrix
            = test_util::TestData::getRandomMatrix(2, 2);
        const double actual = (*mock)(residual, jacobianMatrix);

        EXPECT_DOUBLE_EQ(data, actual);
    }
} } // namespace algo { namespace nm_test {
