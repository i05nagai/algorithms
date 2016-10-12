/**
 * @file traits.hpp
 * @brief 
 * @author i05nagai
 * @version 0.0.2
 * @date 2016-10-04
 */
#pragma once

#include "algo/ad/dual.hpp"
#include "algo/ad/fwd.hpp"
#include <type_traits>
#include <boost/numeric/ublas/traits.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/vector_expression.hpp>

namespace algo { namespace ad {
    /*--------------------------------------------------------------------------
     * is_scalar
     *------------------------------------------------------------------------*/
    /**
     * @brief 
     *  TODO: dual<double> is scalar?
     * @tparam T
     */
    template <typename T> 
    struct is_scalar 
    : std::integral_constant<bool, std::is_scalar<T>::value> {
    };
    /*--------------------------------------------------------------------------
     * is_vector
     *------------------------------------------------------------------------*/
    template <typename T> 
    struct is_vector_impl
    : std::integral_constant<
        bool, 
        std::is_base_of<boost::numeric::ublas::vector_expression<T>, T>::value
    > {
    };
    /**
     * @brief Currently, pointer is not allowed.
     *
     * @tparam T
     */
    template <typename T> 
    struct is_vector 
    : is_vector_impl<
        typename std::decay<T>::type
    > {
    };
    /*--------------------------------------------------------------------------
     * is_scalar_dual
     *------------------------------------------------------------------------*/
    template <typename T>
    struct is_scalar_dual_impl
    : std::integral_constant<
        bool,
        std::is_base_of<dual_expression<T>, T>::value
    > {
    };
    /**
     * @brief Currently, pointer is not allowed.
     *
     * @tparam T
     */
    template <typename T>
    struct is_scalar_dual 
    : is_scalar_dual_impl<
        typename std::decay<T>::type
    > {
    };
    /*--------------------------------------------------------------------------
     * is_vector_dual
     *------------------------------------------------------------------------*/
    /**
     * @brief 
     *
     * @tparam T
     */
    template <typename T>
    struct is_vector_dual_impl 
    : std::integral_constant<
        bool,
        is_scalar_dual<typename T::value_type>::value
    > {
    };
    /**
     * @brief 
     *
     * @tparam T
     */
    template <typename T>
    struct is_vector_dual<T, true> 
    : is_vector_dual_impl<
        typename std::decay<T>::type
    > {
    };
    /**
     * @brief 
     *
     * @tparam T
     */
    template <typename T>
    struct is_vector_dual<T, false> : std::false_type {
    };
    /*--------------------------------------------------------------------------
     * is_dual
     *------------------------------------------------------------------------*/
    /**
     * @brief 
     *
     * @tparam T
     */
    template <typename T>
    struct is_dual 
    : std::integral_constant<
        bool,
        boost::mpl::or_<
            is_vector_dual<T>, 
            is_scalar_dual<T>
        >::value
    > {
    };
    /*--------------------------------------------------------------------------
     * has_const_closure_type
     *------------------------------------------------------------------------*/
    struct has_const_closure_type_impl {
    public:
        template <typename T>
        static
        std::true_type check(typename T::const_closure_type*);

        template <typename T>
        static
        std::false_type check(...);
    };
    /**
     * @brief return true_type if T has const_closure_type
     *
     * @tparam T
     */
    template <typename T>
    struct has_const_closure_type 
    : public decltype(has_const_closure_type_impl::check<
        typename std::decay<T>::type
    >(nullptr)) {
    };
    /*--------------------------------------------------------------------------
     * const_closure_type_traits
     *------------------------------------------------------------------------*/
    /**
     * @brief template specification in case of has_const_closure_type<T>::value is false.
     *
     * @tparam T
     */
    template <typename T>
    struct const_closure_type_traits_impl<T, false> {
        typedef T type;
    };
    /**
     * @brief template specification in case of has_const_closure_type<T>::value is true.
     *
     * @tparam T
     */
    template <typename T>
    struct const_closure_type_traits_impl<T, true> {
        typedef typename T::const_closure_type type;
    };
    /**
     * @brief If type has const closure, type is defined as T::const_closure_type.
     *  Otherwise type is defined as T.
     *  Currently, pointer is not allowed.
     *
     * @tparam T
     */
    template <typename T>
    struct const_closure_type_traits 
    : public const_closure_type_traits_impl<
        typename std::decay<T>::type
    > {
    };
} } // namespace algo { namespace ad {

