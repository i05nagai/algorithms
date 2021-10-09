#include "algo/util_test/matrix_operator_test.h"
#include "algo/util/matrix_operator.h"
#include "algo/util/debug_macro.h"
#include "algo/test_util/TestData.h"
#include "algo/test_util/gtest_helper_macro.h"
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/detail/matrix_assign.hpp>

namespace algo { namespace util_test {
    namespace ublas = boost::numeric::ublas;

    MatrixOperatorTest::MatrixOperatorTest() 
    {
    }

    MatrixOperatorTest::~MatrixOperatorTest() 
    {
    }

    void MatrixOperatorTest::SetUp()
    {
    }

    void MatrixOperatorTest::TearDown()
    {
    }

    TEST_F(MatrixOperatorTest, invert)
    {
        ublas::matrix<double> matrix 
            = test_util::TestData::getRandomMatrix(2, 2);
        ublas::matrix<double> inverseMatrix(2, 2);
        
        util::invert(matrix, inverseMatrix);
        ublas::matrix<double> identity = ublas::prod(matrix, inverseMatrix);
        
        EXPECT_MATRIX_DOUBLE_EQ(ublas::identity_matrix<double>(2), identity);
    }
} } // namespace algo { namespace util_test {
