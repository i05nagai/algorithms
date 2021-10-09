/**
 * @file dual_binary_operator_function.hpp
 * @brief helper functions for binary operators.
 * @author i05nagai
 * @version 0.0.2
 * @date 2016-10-02
 */

#pragma once
#include "algo/ad/ublas_binary_operator.hpp"

namespace algo { namespace ad { namespace detail {
    /*--------------------------------------------------------------------------
     * plusDualDerivative
     *------------------------------------------------------------------------*/
    /**
     * @brief 
     *
     * @tparam E1
     * @tparam E2
     * @param e1
     * @param e2
     *
     * @return 
     */
    template<typename E1, typename E2>
    auto plusDualDerivative(
        const dual_expression<E1>& e1, const dual_expression<E2>& e2)
    -> decltype(e1().getDerivative() + e2().getDerivative())
    {
        return e1().getDerivative() + e2().getDerivative();
    }
    /**
     * @brief 
     *
     * @tparam E2
     * @param e1
     * @param e2
     *
     * @return 
     */
    template<typename E2>
    auto plusDualDerivative(
        const double e1, const dual_expression<E2>& e2)
    -> decltype(e2().getDerivative())
    {
        return e2().getDerivative();
    }
    /**
     * @brief 
     *
     * @tparam E1
     * @param e1
     * @param e2
     *
     * @return 
     */
    template<typename E1>
    auto plusDualDerivative(
        const dual_expression<E1>& e1, const double e2)
    -> decltype(e1().getDerivative())
    {
        return e1().getDerivative();
    }
    /*--------------------------------------------------------------------------
    * minusDualDerivative
     *------------------------------------------------------------------------*/
    /**
     * @brief 
     *
     * @tparam E1
     * @tparam E2
     * @param e1
     * @param e2
     *
     * @return 
     */
    template<typename E1, typename E2>
    auto minusDualDerivative(
        const dual_expression<E1>& e1, const dual_expression<E2>& e2)
    -> decltype(e1().getDerivative() - e2().getDerivative())
    {
        return e1().getDerivative() - e2().getDerivative();
    }
    /**
     * @brief 
     *
     * @tparam E2
     * @param e1
     * @param e2
     *
     * @return 
     */
    template<typename E2>
    auto minusDualDerivative(
        const double e1, const dual_expression<E2>& e2)
    -> decltype(e2().getDerivative())
    {
        return e2().getDerivative();
    }
    /**
     * @brief 
     *
     * @tparam E1
     * @param e1
     * @param e2
     *
     * @return 
     */
    template<typename E1>
    auto minusDualDerivative(
        const dual_expression<E1>& e1, const double e2)
    -> decltype(e1().getDerivative())
    {
        return e1().getDerivative();
    }
    /*--------------------------------------------------------------------------
     * multiplyDualDerivative
     *------------------------------------------------------------------------*/
    /**
     * @brief 
     *
     * @tparam E1
     * @tparam E2
     * @param e1
     * @param e2
     *
     * @return 
     */
    template<typename E1, typename E2>
    auto multiplyDualDerivative(
        const dual_expression<E1>& e1, 
        const dual_expression<E2>& e2)
    -> decltype(e1().getDerivative() * e2().getValue() 
        + e1().getValue() * e2().getDerivative())
    {
        return e1().getDerivative() * e2().getValue() 
            + e1().getValue() * e2().getDerivative();
    }
    /**
     * @brief 
     *
     * @tparam E2
     * @param e1
     * @param e2
     *
     * @return 
     */
    template<typename E2>
    auto multiplyDualDerivative(
        const double e1, const dual_expression<E2>& e2)
    -> decltype(e2().getDerivative())
    {
        return e2().getDerivative();
    }
    /**
     * @brief 
     *
     * @tparam E1
     * @param e1
     * @param e2
     *
     * @return 
     */
    template<typename E1>
    auto multiplyDualDerivative(
        const dual_expression<E1>& e1, const double e2)
    -> decltype(e1().getDerivative())
    {
        return e1().getDerivative();
    }
    /*--------------------------------------------------------------------------
     * divideDualDerivative
     *------------------------------------------------------------------------*/
    /**
     * @brief 
     *
     * @note e1().getDerivative() and e1().getDerivative() can be vector_expression or double.
     *
     * @tparam E1
     * @tparam E2
     * @param e1
     * @param e2
     *
     * @return 
     */
    template<typename E1, typename E2>
    auto divideDualDerivative(
        const dual_expression<E1>& e1, 
        const dual_expression<E2>& e2)
    -> decltype((e1().getDerivative() * e2().getValue() 
         - e1().getValue() * e2().getDerivative())
            / (e1().getValue() * e1().getValue()))
    {
        return (e1().getDerivative() * e2().getValue() 
            - e1().getValue() * e2().getDerivative()) 
                / (e1().getValue() * e1().getValue());
    }
    /**
     * @brief 
     *
     * @tparam E2
     * @param e1
     * @param e2
     *
     * @return 
     */
    template<typename E2>
    auto divideDualDerivative(const double e1, const dual_expression<E2>& e2)
    -> decltype(e2().getDerivative())
    {
        return e2().getDerivative();
    }
    /**
     * @brief 
     *
     * @tparam E1
     * @param e1
     * @param e2
     *
     * @return 
     */
    template<typename E1>
    auto divideDualDerivative(const dual_expression<E1>& e1, const double e2)
    -> decltype(e1().getDerivative())
    {
        return e1().getDerivative();
    }
} } } // namespace algo { namespace ad { namespace detail {

