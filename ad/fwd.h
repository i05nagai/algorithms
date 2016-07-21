/**
 * @file fwd.h
 * @brief forward declarations.
 * @author i05nagai
 * @version 
 * @date 2016-07-20
 */

#pragma once

namespace algo { namespace ad {
    /*--------------------------------------------------------------------------
     * traits.h
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
    //const_closure_type
    template <typename T, bool Condition = is_dual<T>::value >
    struct const_closure_type_traits_impl;
    template <typename T>
    struct const_closure_type_traits;

} } // namespace algo { namespace ad {
