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
#include <boost/type_traits/is_base_of.hpp>

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
    : boost::mpl::bool_<boost::is_scalar<T>::value> {
    };
    /*--------------------------------------------------------------------------
     * is_vector
     *------------------------------------------------------------------------*/
    /**
     * @brief 
     *
     * @tparam T
     */
    template <typename T> 
    struct is_vector 
    : boost::mpl::bool_<
        boost::is_base_of<boost::numeric::ublas::vector_expression<T>, T>::value> {
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
    struct is_scalar_dual 
    : boost::mpl::bool_<boost::is_base_of<dual_expression<T>, T>::value> 
    {
    };
    /**
     * @brief 
     *
     * @tparam T
     */
    template <typename T>
    struct is_vector_dual<T, true> 
    : boost::mpl::bool_<is_scalar_dual<typename T::value_type>::value> {
    };
    /**
     * @brief 
     *
     * @tparam T
     */
    template <typename T>
    struct is_vector_dual<T, false> : boost::mpl::bool_<false> {
    };
    /**
     * @brief 
     *
     * @tparam T
     */
    template <typename T>
    struct is_dual : boost::mpl::bool_<
         boost::mpl::or_<
             is_vector_dual<T>, 
             is_scalar_dual<T> >::value> {
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

    template <typename T>
    struct has_const_closure_type 
    : public decltype(has_const_closure_type_impl::check<T>(nullptr)) {
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
     * @brief 
     *
     * @tparam T
     */
    template <typename T>
    struct const_closure_type_traits : public const_closure_type_traits_impl<T> {
    };
} } // namespace algo { namespace ad {

