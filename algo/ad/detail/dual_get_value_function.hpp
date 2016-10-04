/**
 * @file dual_get_value_function.hpp
 * @brief helper funtions.
 * @author i05nagai
 * @version 0.0.1
 * @date 2016-07-20
 */

#pragma once
#include "algo/ad/fwd.hpp"

namespace algo { namespace ad { namespace detail {
    /**
     * @brief an overloaded function. 
     * If argument is double, value is itself.
     *
     * @param v
     *
     * @return 
     */
    inline
    double getValue(const double value)
    {
        return value;
    }
    /**
     * @brief an overloaded function. 
     * If argument is dual, value can get by getValue member function.
     *
     * @tparam E type of dual.
     * @param e the parameter which will be get value.
     *
     * @return double.
     */
    template <typename E> inline
    double getValue(const dual_expression<E>& e)
    {
        return e().getValue();
    }
} } } // namespace algo { namespace ad { namespace detail {
