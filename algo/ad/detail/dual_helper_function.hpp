/**
 * @file dual_helper_function.hpp
 * @brief helper funtions.
 * @author i05nagai
 * @version 0.0.1
 * @date 2016-07-20
 */

#pragma once
#include "ad/fwd.h"

namespace algo { namespace ad { namespace detail {
    /**
     * @brief an overloaded function. 
     * If argument is double, value is itself.
     *
     * @param v
     *
     * @return 
     */
    double getValue(const double v)
    {
        return v;
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
    template <typename E> 
    double getValue(const dual_expression<E>& e)
    {
        return e().getValue();
    }
} } } // namespace algo { namespace ad { namespace detail {