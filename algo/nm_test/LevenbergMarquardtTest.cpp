#include "nm_test/LevenbergMarquardtTest.h"
#include "nm_test/TestData.h"
#include "nm_test/mock/IDumpingFactorCalculatorMock.h"
#include "test_util/TestData.h"
#include "test_util/gtest_helper_macro.h"
#include "nm/LevenbergMarquardt.h"
#include "nm/SimpleDumpingFactorCalculator.h"
#include "math/euclid.h"
#include <memory>

namespace algo { namespace nm_test {
    namespace ublas = boost::numeric::ublas;

    LevenbergMarquardtTest::LevenbergMarquardtTest() 
    {
    }
    
    LevenbergMarquardtTest::~LevenbergMarquardtTest() 
    {
    }

    void LevenbergMarquardtTest::SetUp()
    {
        nm::INewtonMethod::function_type f 
            = TestData::getMultiValuedSeveralVariablesFunction0();
        nm::INewtonMethod::derivative_type derivative 
            = TestData::getMatrixValuedSeveralVariablesDerivative0();
        const std::size_t maxIteration = 2;
        _tolerance = 1E-32;

        //dumping factor
        _dumpingFactorCalculator 
            = std::make_shared<IDumpingFactorCalculatorMock>();
        _dumpingFactorCalculator->delegateToDefault();
        EXPECT_CALL(*_dumpingFactorCalculator, doClone());
        _target = std::make_shared<nm::LevenbergMarquardt>(
            f, derivative, maxIteration, _tolerance, _dumpingFactorCalculator);
        _target->_dumpingFactorCalculator = _dumpingFactorCalculator;
    }
    
    void LevenbergMarquardtTest::TearDown()
    {
        _dumpingFactorCalculator.reset();
        _target.reset();
    }

    //model test
    TEST_F(LevenbergMarquardtTest, doSolveTest0)
    {
        nm::INewtonMethod::function_type f 
            = TestData::getMultiValuedSeveralVariablesFunction0();
        nm::INewtonMethod::derivative_type derivative 
            = TestData::getMatrixValuedSeveralVariablesDerivative0();
        const std::size_t maxIteration = 50;
        const double tolerance = 1E-32;
        //dumping factor
        std::shared_ptr<nm::SimpleDumpingFactorCalculator> 
            dumpingFactorCalculator(
                new nm::SimpleDumpingFactorCalculator(1.0, 0.5));
        //target
        nm::LevenbergMarquardt target(
            f, derivative, maxIteration, tolerance, dumpingFactorCalculator);

        const ublas::vector<double> initialValue 
            = test_util::TestData::getRandomNumbers(2);
        const ublas::vector<double> actual = target.solve(initialValue);

        const ublas::vector<double> expect(2, 0.0);
        EXPECT_VECTOR_NEAR(expect, actual, 1E-14);
    }
} } // namespace algo { namespace nm_test {
