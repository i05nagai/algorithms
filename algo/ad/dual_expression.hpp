/**
 * @file dual_expression.hpp
 * @brief dual_expression class.
 * @author i05nagai
 * @version 0.0.1
 * @date 2016-03-28
 */
#pragma once

namespace algo { namespace ad {
    /**
     * @brief classes which inherits dual_expression must have following concepts
     *  * type
     *      * derivative_type 
     *      * 
     *  * function
     *      * getValue()
     *      * getValue() const
     *      * getDerivative() 
     *      * getDerivative() const
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

