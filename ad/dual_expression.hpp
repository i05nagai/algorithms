/**
 * @file dual_expression.h
 * @brief dual_expression class.
 * @author i05nagai
 * @version 0.0.1
 * @date 2016-03-28
 */
#pragma once

#include <boost/numeric/ublas/vector_expression.hpp>

namespace algo { namespace ad {
    /**
     * @brief 
     *
     * @tparam E
     */
    template <typename E> 
    class dual_expression {
    public:
        typedef E expression_type;
        typedef const E& const_reference;
    public:
        /**
         * @brief 
         *
         * @return 
         */
        const_reference operator()() const 
        {
            return static_cast<const expression_type&>(*this);
        }
    };
} } // namespace algo { namespace ad {

