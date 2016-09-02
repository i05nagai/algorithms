#include "nm_test/GaussNewtonTest.h"
#include "nm_test/TestData.h"
#include "test_util/TestData.h"
#include "test_util/gtest_helper_macro.h"
#include "nm/GaussNewton.h"
#include <memory>

namespace algo { namespace nm_test {
    namespace ublas = boost::numeric::ublas;

    GaussNewtonTest::GaussNewtonTest() 
    {
    }
    
    GaussNewtonTest::~GaussNewtonTest() 
    {
    }

    void GaussNewtonTest::SetUp()
    {
        nm::INewtonMethod::function_type f 
            = TestData::getMultiValuedSeveralVariablesFunction0();
        nm::INewtonMethod::derivative_type derivative 
            = TestData::getMatrixValuedSeveralVariablesDerivative0();
        const std::size_t maxIteration = 50;
        _tolerance = 2E-32;
        _target = std::make_shared<nm::GaussNewton>(
            f, derivative, maxIteration, _tolerance);
    }
    
    void GaussNewtonTest::TearDown()
    {
    }

    TEST_F(GaussNewtonTest, doSolveTest)
    {
        ublas::vector<double> initialValue 
            = test_util::TestData::getRandomNumbers(2);
        const ublas::vector<double> actual = _target->solve(initialValue);

        ublas::vector<double> expect(2, 0.0);
        EXPECT_VECTOR_NEAR(expect, actual, 1E-15);
    }
} } // namespace algo { namespace nm_test {
