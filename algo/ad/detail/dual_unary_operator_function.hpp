/**
 * @file dual_unary_operator_function.hpp
 * @brief 
 * @author i05nagai
 * @version 0.0.1
 * @date 2016-07-20
 */

#pragma once
#include "algo/ad/ublas_unary_operator.hpp"

namespace algo { namespace ad { namespace detail {
    /*--------------------------------------------------------------------------
     * negateDualDerivative
     *------------------------------------------------------------------------*/
    /**
     * @brief 
     *
     * @tparam DE
     * @param e
     *
     * @return 
     */
    template<typename DE>
    auto negateDualDerivative(const dual_expression<DE>& e)
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
    double negateDualDerivative(const double e)
    {
        return -e;
    }
    /*--------------------------------------------------------------------------
     * expDualDerivative
     *------------------------------------------------------------------------*/
    /**
     * @brief 
     *
     * @tparam DE
     * @param e
     *
     * @return 
     */
    template<typename DE>
    auto expDualDerivative(const dual_expression<DE>& e)
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
    double expDualDerivative(const double e)
    {
        return std::exp(e);
    }
    /*--------------------------------------------------------------------------
     * logDualDerivative 
     *------------------------------------------------------------------------*/
    /**
     * @brief 
     *
     * @tparam DE
     * @param e
     *
     * @return 
     */
    template<typename DE>
    auto logDualDerivative(const dual_expression<DE>& e)
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
    double logDualDerivative(const double e)
    {
        return 1.0 / e;
    }
    /*--------------------------------------------------------------------------
     * sinDualDerivative 
     *------------------------------------------------------------------------*/
    /**
     * @brief 
     *
     * @tparam DE
     * @param e
     *
     * @return 
     */
    template<typename DE>
    auto sinDualDerivative(const dual_expression<DE>& e)
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
    double sinDualDerivative(const double e)
    {
        return std::cos(e);
    }
    /*--------------------------------------------------------------------------
     * cosDualDerivative 
     *------------------------------------------------------------------------*/
    /**
     * @brief 
     *
     * @tparam DE
     * @param e
     *
     * @return 
     */
    template<typename DE>
    auto cosDualDerivative(const dual_expression<DE>& e)
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
    double cosDualDerivative(const double e)
    {
        return -std::sin(e);
    }
} } } // namespace algo { namespace ad { namespace detail {
