#include "utility_test/matrix_operator_test.h"
#include "utility/matrix_operator.h"
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/detail/matrix_assign.hpp>

namespace algo { namespace utility_test {
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
        ublas::matrix<double> matrix(2, 2);
        ublas::matrix<double> inverseMatrix(2, 2);
        
        utility::invert(matrix, inverseMatrix);
        ublas::matrix<double> identity = ublas::prod(matrix, inverseMatrix);
        ASSERT_TRUE(ublas::detail::expression_type_check(
            ublas::identity_matrix<double>(2),
            identity));
    }
} } // namespace algo { namespace utility_test {
