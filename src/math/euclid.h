/**
 * @file euclid.h
 * @brief TODO:some functions copied from qn/utlity.h
 * @author i05nagai
 * @version 0.0.1
 * @date 2016-07-20
 */

#pragma once
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/vector_expression.hpp>

namespace algo { namespace math {
    /**
     * @brief caculates sum of squares.
     *
     * @tparam E expression.
     * @param x vector.
     *
     * @return sum of squares.
     */
    template <typename E>
    double calculateSumOfSquares(const 
        boost::numeric::ublas::vector_expression<E>& x)
    {
        double sum = 0.0;
        for (std::size_t i = 0; i < x().size(); ++i) {
            sum += (x()(i) * x()(i));
        }
        return sum;
    }
    /**
     * @brief calculate distance between x1 and x2.
     *
     * @param x1
     * @param x2
     *
     * @return 
     */
    double calculateDistanceNormL2(
        const boost::numeric::ublas::vector<double>& x1,
        const boost::numeric::ublas::vector<double>& x2);
    /**
     * @brief calculates euclidean norm.
     *
     * @param x1 point.
     * @param x2 point.
     *
     * @return euclidean norm.
     */
    double calculateNormL2(
        const boost::numeric::ublas::vector<double>& x);
} } // namespace algo { namespace math {

