/**
 * @file fwd.hpp
 * @brief forward declarations.
 * @author i05nagai
 * @version 0.0.2
 * @date 2016-10-04
 */

#pragma once

namespace algo { namespace ad {
    /*--------------------------------------------------------------------------
     * traits.hpp
     *------------------------------------------------------------------------*/
    //is_scalar
    template <typename T> 
    struct is_scalar;
    //is_vector
    template <typename T> 
    struct is_vector;
    //is_dual
    template <typename T>
    struct is_scalar_dual;
    //vector dual
    template <typename T, bool Condition = is_vector<T>::value>
    struct is_vector_dual;
    //is_dual
    template <typename T>
    struct is_dual;
    //has_const_closure_type
    template <typename T>
    struct has_const_closure_type;
    //const_closure_type
    template <typename T, bool Condition = has_const_closure_type<T>::value>
    struct const_closure_type_traits_impl;
    template <typename T>
    struct const_closure_type_traits;

} } // namespace algo { namespace ad {
