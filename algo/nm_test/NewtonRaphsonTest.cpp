#include "algo/nm_test/NewtonRaphsonTest.h"
#include "algo/nm_test/TestData.h"
#include "algo/test_util/TestData.h"
#include "algo/test_util/gtest_helper_macro.h"
#include "algo/nm/NewtonRaphson.h"
#include "algo/util/debug_macro.h"
#include <boost/numeric/ublas/detail/vector_assign.hpp>

namespace algo { namespace nm_test {
    namespace ublas = boost::numeric::ublas;

    NewtonRaphsonTest::NewtonRaphsonTest() 
    {
    }

    NewtonRaphsonTest::~NewtonRaphsonTest() 
    {
    }

    void NewtonRaphsonTest::SetUp()
    {
    }

    void NewtonRaphsonTest::TearDown()
    {
    }

    TEST_F(NewtonRaphsonTest, doSolveTest)
    {
        nm::INewtonMethod::function_type f 
            = TestData::getMultiValuedSeveralVariablesFunction0();
        nm::INewtonMethod::derivative_type derivative 
            = TestData::getMatrixValuedSeveralVariablesDerivative0();
        const std::size_t maxIteration = 50;
        const double tolerance = 2E-32;
        nm::NewtonRaphson target(f, derivative, maxIteration, tolerance);

        ublas::vector<double> initialValue 
            = test_util::TestData::getRandomNumbers(2);
        const ublas::vector<double> actual = target.solve(initialValue);

        ublas::vector<double> expect(2, 0.0);
        EXPECT_VECTOR_NEAR(expect, actual, 2E-15);
    }
} } // namespace algo { namespace nm_test {

