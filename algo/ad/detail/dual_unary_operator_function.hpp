/**
 * @file dual_unary_operator_function.hpp
 * @brief 
 * @author i05nagai
 * @version 0.0.1
 * @date 2016-07-20
 */

#pragma once
#include "algo/ad/ublas_unary_operator.hpp"
#include "algo/ad/ublas_binary_operator.hpp"

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
     * @note std::exp(e().getValue()) returns r-value so that return value of this 
     *  function must be copied (because of implementation of ublas expression tempalte). 
     *  If we returns decltype(std::exp(e().getValue()) * e().getDerivative()), 
     *  ublas expression templates, r-value vanishs leaving this function.
     *
     * @tparam DE
     * @param e
     *
     * @return 
     */
    template<typename DE>
    inline
    auto expDualDerivative(const dual_expression<DE>& e)
    -> decltype(std::exp(e().getValue()) * e().getDerivative())
    {
        return std::exp(e().getValue()) * e().getDerivative();
    }
    /**
     * @brief 
     *
     * @param e
     *
     * @return 
     */
    inline
    double expDualDerivative(const double e)
    {
        return 0.0;
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
    -> decltype(e().getDerivative() / e().getValue())
    {
        return e().getDerivative() / e().getValue();
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
        return 0.0;
    }
    /*--------------------------------------------------------------------------
     * sinDualDerivative 
     *------------------------------------------------------------------------*/
    /**
     * @brief 
     * @note std::cos(e().getValue()) returns r-value so that return value of this 
     *  function must be copied (because of implementation of ublas expression tempalte). 
     *  If we returns decltype(e().getDerivative() * std::cos(e().getValue())), 
     *  ublas expression templates, r-value vanishs leaving this function.
     *
     * @tparam DE
     * @param e
     *
     * @return 
     */
    template<typename DE>
    auto sinDualDerivative(const dual_expression<DE>& e)
    -> decltype(e().getDerivative() * std::cos(e().getValue()))
    {
        namespace ublas = boost::numeric::ublas;
        return e().getDerivative() * std::cos(e().getValue());
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
        return 0.0;
    }
    /*--------------------------------------------------------------------------
     * cosDualDerivative 
     *------------------------------------------------------------------------*/
    /**
     * @brief 
     * @note std::sin(e().getValue()) returns r-value so that return value of this 
     *  function must be copied (because of implementation of ublas expression tempalte). 
     *  If we returns decltype(-std::sin(e().getValue()) * e().getDerivative()), 
     *  ublas expression templates, r-value vanishs leaving this function.
     *
     * @tparam DE
     * @param e
     *
     * @return type is ublas::vector_binary_scalar2
     */
    template<typename DE>
    auto cosDualDerivative(const dual_expression<DE>& e)
    -> decltype(-std::sin(e().getValue()) * e().getDerivative())
    {
        namespace ublas = boost::numeric::ublas;
        return -std::sin(e().getValue()) * e().getDerivative();
    }
    //template<typename DE>
    //typename DE::derivative_type
    //cosDualDerivative(const dual_expression<DE>& e)
    //{
    //    namespace ublas = boost::numeric::ublas;
    //    return -std::sin(e().getValue()) * e().getDerivative();
    //}
    /**
     * @brief 
     *
     * @param e
     *
     * @return 
     */
    double cosDualDerivative(const double e)
    {
        return 0.0;
    }
} } } // namespace algo { namespace ad { namespace detail {

