#pragma once
#include "algo/ad/detail/dual_helper_function.hpp"
#include "algo/ad/dual_expression.hpp"
#include <boost/numeric/ublas/vector_expression.hpp>

namespace algo { namespace ad { namespace detail {
    /**
     * @brief 
     *
     * @tparam E
     * @param e
     * @param j
     *
     * @return 
     */
    template <typename E>
    double jacobian_matrix_accessor(
        const boost::numeric::ublas::vector_expression<E>& e,
        const std::size_t j)
    {
        assert(j < e().size() && j >= 0);
        return e()(j);
    }

    template <typename E>
    double jacobian_matrix_accessor(
        const double e,
        const std::size_t j)
    {
        assert(j == 0);
        return e;
    }
    /**
     * @brief 
     *
     * @tparam E
     * @param e
     * @param i
     * @param j
     *
     * @return 
     */
    template <typename E> 
    double jacobian_matrix_accessor(
        const dual_expression<E>& e,
        const std::size_t i,
        const std::size_t j)
    {
        assert(i == 0);
        return jacobian_matrix_accessor(e()(i).getDerivative(), j);
    }
    /**
     * @brief 
     *
     * @tparam E
     * @param e
     * @param i
     * @param j
     *
     * @return 
     */
    template <typename E> 
    double jacobian_matrix_accessor(
        const boost::numeric::ublas::vector_expression<E>& e,
        const std::size_t i,
        const std::size_t j)
    {
        assert(i < e().size() && i >= 0);
        return jacobian_matrix_accessor(e()(i).getDerivative(), j);
    }
} } } // namespace algo { namespace ad { namespace detail {
