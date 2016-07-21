/**
 * @file ublas_unary_operator.h
 * @brief 
 * @author 
 * @version i05nagai
 * @date 2016-07-20
 */

#pragma once
#include <boost/numeric/ublas/functional.hpp>
#include <boost/numeric/ublas/vector_expression.hpp>

namespace boost { namespace numeric { namespace ublas {
    /*--------------------------------------------------------------------------
     * exp
     *------------------------------------------------------------------------*/
    /**
     * @brief 
     *
     * @tparam T
     */
    template <typename T>
    struct scalar_exp : public scalar_unary_functor<T> {
        typedef typename scalar_unary_functor<T>::value_type value_type;
        typedef typename scalar_unary_functor<T>::argument_type argument_type;
        typedef typename scalar_unary_functor<T>::result_type result_type;

        static result_type apply(argument_type t)
        {
            return std::exp(t);
        }
    };
    /**
     * @brief 
     *
     * @tparam E
     * @param e
     *
     * @return 
     */
    template<typename E>
    typename boost::numeric::ublas::vector_unary_traits<
        E, 
        scalar_exp<typename E::value_type> >::result_type
    exp(const vector_expression<E>& e)
    {
        typedef typename boost::numeric::ublas::vector_unary_traits<
            E, 
            scalar_exp<typename E::value_type> >::expression_type expression_type;
        return expression_type(e());
    }
    /**
     * @brief 
     *
     * @param e
     *
     * @return 
     */
    double exp(const double e)
    {
        return std::exp(e);
    }
    /*--------------------------------------------------------------------------
     * element_inverse
     *------------------------------------------------------------------------*/
    /**
     * @brief 
     *
     * @tparam T
     */
    template <typename T>
    struct scalar_inverse : public scalar_unary_functor<T> {
        typedef typename scalar_unary_functor<T>::value_type value_type;
        typedef typename scalar_unary_functor<T>::argument_type argument_type;
        typedef typename scalar_unary_functor<T>::result_type result_type;

        static result_type apply(argument_type t)
        {
            return 1.0 / t;
        }
    };
    /**
     * @brief 
     *
     * @tparam E
     * @param e
     *
     * @return 
     */
    template<typename E>
    typename boost::numeric::ublas::vector_unary_traits<
        E, 
        scalar_inverse<typename E::value_type> >::result_type
    element_inverse(const vector_expression<E>& e)
    {
        typedef typename boost::numeric::ublas::vector_unary_traits<
            E, 
            scalar_inverse<typename E::value_type> >::expression_type expression_type;
        return expression_type(e());
    }
    /**
     * @brief 
     *
     * @param e
     *
     * @return 
     */
    double element_inverse(const double e)
    {
        return 1.0 / e;
    }
    /*--------------------------------------------------------------------------
     * sin
     *------------------------------------------------------------------------*/
    /**
     * @brief 
     *
     * @tparam T
     */
    template <typename T>
    struct scalar_sin : public scalar_unary_functor<T> {
        typedef typename scalar_unary_functor<T>::value_type value_type;
        typedef typename scalar_unary_functor<T>::argument_type argument_type;
        typedef typename scalar_unary_functor<T>::result_type result_type;

        static result_type apply(argument_type t)
        {
            return std::sin(t);
        }
    };
    /**
     * @brief 
     *
     * @tparam E
     * @param e
     *
     * @return 
     */
    template<typename E>
    typename boost::numeric::ublas::vector_unary_traits<
        E, 
        scalar_sin<typename E::value_type> >::result_type
    sin(const vector_expression<E>& e)
    {
        typedef typename boost::numeric::ublas::vector_unary_traits<
            E, 
            scalar_sin<typename E::value_type> >::expression_type expression_type;
        return expression_type(e());
    }
    /**
     * @brief 
     *
     * @param e
     *
     * @return 
     */
    double sin(const double e)
    {
        return std::sin(e);
    }
    /*--------------------------------------------------------------------------
     * cos
     *------------------------------------------------------------------------*/
    /**
     * @brief 
     *
     * @tparam T
     */
    template <typename T>
    struct scalar_cos : public scalar_unary_functor<T> {
        typedef typename scalar_unary_functor<T>::value_type value_type;
        typedef typename scalar_unary_functor<T>::argument_type argument_type;
        typedef typename scalar_unary_functor<T>::result_type result_type;

        static result_type apply(argument_type t)
        {
            return std::cos(t);
        }
    };
    /**
     * @brief 
     *
     * @tparam E
     * @param e
     *
     * @return 
     */
    template<typename E>
    typename boost::numeric::ublas::vector_unary_traits<
        E, 
        scalar_cos<typename E::value_type> >::result_type
    cos(const vector_expression<E>& e)
    {
        typedef typename boost::numeric::ublas::vector_unary_traits<
            E, 
            scalar_cos<typename E::value_type> >::expression_type expression_type;
        return expression_type(e());
    }
    /**
     * @brief 
     *
     * @param e
     *
     * @return 
     */
    double cos(const double e)
    {
        return std::cos(e);
    }
} } } // namespace boost { namespace numeric { namespace ublas {

