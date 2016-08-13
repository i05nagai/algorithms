/**
 * @file dual_unary_operator_helper.hpp
 * @brief 
 * @author i05nagai
 * @version 0.0.1
 * @date 2016-07-20
 */

#pragma once
#include "ad/ublas_unary_operator.hpp"

namespace algo { namespace ad { namespace detail {
    /*--------------------------------------------------------------------------
     * dual_negate_helper
     *------------------------------------------------------------------------*/
    /**
     * @brief 
     *
     * @tparam E
     * @param e
     *
     * @return 
     */
    template<typename E>
    auto dual_negate_helper(const dual_expression<E>& e)
    -> decltype(-e().getDerivative())
    {
        return -e().getDerivative();
    }
    /**
     * @brief 
     *
     * @param e
     *
     * @return 
     */
    double dual_negate_helper(const double e)
    {
        return -e;
    }
    /*--------------------------------------------------------------------------
     * dual_exp_helper
     *------------------------------------------------------------------------*/
    /**
     * @brief 
     *
     * @tparam E
     * @param e
     *
     * @return 
     */
    template<typename E>
    auto dual_exp_helper(const dual_expression<E>& e)
    -> decltype(boost::numeric::ublas::exp(e().getDerivative()))
    {
        return boost::numeric::ublas::exp(e().getDerivative());
    }
    /**
     * @brief 
     *
     * @param e
     *
     * @return 
     */
    double dual_exp_helper(const double e)
    {
        return std::exp(e);
    }
    /*--------------------------------------------------------------------------
     * dual_log_helper
     *------------------------------------------------------------------------*/
    /**
     * @brief 
     *
     * @tparam E
     * @param e
     *
     * @return 
     */
    template<typename E>
    auto dual_log_helper(const dual_expression<E>& e)
    -> decltype(boost::numeric::ublas::element_inverse(e().getDerivative()))
    {
        return boost::numeric::ublas::element_inverse(e().getDerivative());
    }
    /**
     * @brief 
     *
     * @param e
     *
     * @return 
     */
    double dual_log_helper(const double e)
    {
        return 1.0 / e;
    }
    /*--------------------------------------------------------------------------
     * dual_sin_helper
     *------------------------------------------------------------------------*/
    /**
     * @brief 
     *
     * @tparam E
     * @param e
     *
     * @return 
     */
    template<typename E>
    auto dual_sin_helper(const dual_expression<E>& e)
    -> decltype(boost::numeric::ublas::cos(e().getDerivative()))
    {
        return boost::numeric::ublas::cos(e().getDerivative());
    }
    /**
     * @brief 
     *
     * @param e
     *
     * @return 
     */
    double dual_sin_helper(const double e)
    {
        return std::cos(e);
    }
    /*--------------------------------------------------------------------------
     * dual_cos_helper
     *------------------------------------------------------------------------*/
    /**
     * @brief 
     *
     * @tparam E
     * @param e
     *
     * @return 
     */
    template<typename E>
    auto dual_cos_helper(const dual_expression<E>& e)
    -> decltype(-boost::numeric::ublas::sin(e().getDerivative()))
    {
        return -boost::numeric::ublas::sin(e().getDerivative());
    }
    /**
     * @brief 
     *
     * @param e
     *
     * @return 
     */
    double dual_cos_helper(const double e)
    {
        return -std::sin(e);
    }
} } } // namespace algo { namespace ad { namespace detail {
