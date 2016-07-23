/**
 * @file dual_binary_operator_helper.hpp
 * @brief helper functions for binary operators.
 * @author i05nagai
 * @version 0.0.1
 * @date 2016-07-20
 */

#pragma once

namespace algo { namespace ad { namespace detail {
    /*--------------------------------------------------------------------------
     * dual_add_function
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
    auto dual_add_function(const dual_expression<E1>& e1, const dual_expression<E2>& e2)
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
    auto dual_add_function(const double e1, const dual_expression<E2>& e2)
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
    auto dual_add_function(const dual_expression<E1>& e1, const double e2)
    -> decltype(e1().getDerivative())
    {
        return e1().getDerivative();
    }
    /*--------------------------------------------------------------------------
     * dual_minus_function
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
    auto dual_minus_function(const dual_expression<E1>& e1, const dual_expression<E2>& e2)
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
    auto dual_minus_function(const double e1, const dual_expression<E2>& e2)
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
    auto dual_minus_function(const dual_expression<E1>& e1, const double e2)
    -> decltype(e1().getDerivative())
    {
        return e1().getDerivative();
    }
    /*--------------------------------------------------------------------------
     * dual_multiplies_function
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
    auto dual_multiplies_function(
        const dual_expression<E1>& e1, 
        const dual_expression<E2>& e2)
    -> decltype(e1().getDerivative() * e2().getValue() + e1().getValue() * e2().getDerivative())
    {
        return e1().getDerivative() * e2().getValue() + e1().getValue() * e2().getDerivative();
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
    auto dual_multiplies_function(const double e1, const dual_expression<E2>& e2)
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
    auto dual_multiplies_function(const dual_expression<E1>& e1, const double e2)
    -> decltype(e1().getDerivative())
    {
        return e1().getDerivative();
    }
    /*--------------------------------------------------------------------------
     * dual_divide_function
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
    auto dual_divide_function(
        const dual_expression<E1>& e1, 
        const dual_expression<E2>& e2)
    -> decltype((e1().getDerivative() * e2().getValue() - e1().getValue() * e2().getDerivative())
            / (e1().getValue() * e1().getValue()))
    {
        return (e1().getDerivative() * e2().getValue() - e1().getValue() * e2().getDerivative()) 
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
    auto dual_divide_function(const double e1, const dual_expression<E2>& e2)
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
    auto dual_divide_function(const dual_expression<E1>& e1, const double e2)
    -> decltype(e1().getDerivative())
    {
        return e1().getDerivative();
    }
} } } // namespace algo { namespace ad { namespace detail {

