/**
 * @file ublas_unary_operator.hpp
 * @brief 
 * @author i05nagai
 * @version 0.0.2
 * @date 2016-10-04
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
     * @tparam Scalar
     */
    template <typename Scalar>
    struct scalar_exp : public scalar_unary_functor<Scalar> {
        typedef typename scalar_unary_functor<Scalar>::value_type value_type;
        typedef typename scalar_unary_functor<Scalar>::argument_type argument_type;
        typedef typename scalar_unary_functor<Scalar>::result_type result_type;

        static result_type apply(argument_type t)
        {
            return std::exp(t);
        }
    };
    /**
     * @brief This function takes elment-wise exponential to ublas::vector_expression.
     *
     * @note This function currently does not support vector of which value_type is dual.
     *
     * @tparam VectorExpression
     * @param e
     *
     * @return ublas::vector_unary it denotes unary-operated vector.
     */
    template<typename VectorExpression>
    inline
    typename boost::numeric::ublas::vector_unary_traits<
        VectorExpression, 
        scalar_exp<typename VectorExpression::value_type>
    >::result_type
    element_exp(const vector_expression<VectorExpression>& e)
    {
        typedef typename boost::numeric::ublas::vector_unary_traits<
            VectorExpression, 
            scalar_exp<typename VectorExpression::value_type>
        >::expression_type expression_type;
        return expression_type(e());
    }
    /**
     * @overload 
     *
     * @brief 
     *
     * @param e
     *
     * @return 
     */
    inline
    double element_exp(const double e)
    {
        return std::exp(e);
    }
    /*--------------------------------------------------------------------------
     * element_inverse
     *------------------------------------------------------------------------*/
    /**
     * @brief 
     *
     * @tparam Scalar
     */
    template <typename Scalar>
    struct scalar_inverse : public scalar_unary_functor<Scalar> {
        typedef typename scalar_unary_functor<Scalar>::value_type value_type;
        typedef typename scalar_unary_functor<Scalar>::argument_type argument_type;
        typedef typename scalar_unary_functor<Scalar>::result_type result_type;

        static result_type apply(argument_type t)
        {
            assert(t != 0);
            return 1.0 / t;
        }
    };
    /**
     * @brief This function takes elment-wise reciprocal to ublas::vector_expression.
     *
     * @note This function currently does not support vector of which value_type is dual.
     *
     * @tparam VectorExpression
     * @param e
     *
     * @return 
     */
    template<typename VectorExpression>
    inline
    typename boost::numeric::ublas::vector_unary_traits<
        VectorExpression, 
        scalar_inverse<typename VectorExpression::value_type> 
    >::result_type
    element_inverse(const vector_expression<VectorExpression>& e)
    {
        typedef typename boost::numeric::ublas::vector_unary_traits<
            VectorExpression, 
            scalar_inverse<typename VectorExpression::value_type> 
        >::expression_type expression_type;
        return expression_type(e());
    }
    /**
     * @overload
     *
     * @brief 
     *
     * @param e
     *
     * @return 
     */
    inline
    double element_inverse(const double e)
    {
        assert(e != 0);
        return 1.0 / e;
    }
    /*--------------------------------------------------------------------------
     * sin
     *------------------------------------------------------------------------*/
    /**
     * @brief 
     *
     * @tparam Scalar
     */
    template <typename Scalar>
    struct scalar_sin : public scalar_unary_functor<Scalar> {
        typedef typename scalar_unary_functor<Scalar>::value_type value_type;
        typedef typename scalar_unary_functor<Scalar>::argument_type argument_type;
        typedef typename scalar_unary_functor<Scalar>::result_type result_type;

        static result_type apply(argument_type t)
        {
            return std::sin(t);
        }
    };
    /**
     * @brief This function takes elment-wise sin to ublas::vector_expression.
     *
     * @note This function currently does not support vector of which value_type is dual.
     *
     * @tparam VectorExpression
     * @param e
     *
     * @return 
     */
    template<typename VectorExpression>
    inline
    typename boost::numeric::ublas::vector_unary_traits<
        VectorExpression, 
        scalar_sin<typename VectorExpression::value_type> 
    >::result_type
    element_sin(const vector_expression<VectorExpression>& e)
    {
        typedef typename boost::numeric::ublas::vector_unary_traits<
            VectorExpression, 
            scalar_sin<typename VectorExpression::value_type> 
        >::expression_type expression_type;
        return expression_type(e());
    }
    /**
     * @overload
     *
     * @brief 
     *
     * @param e
     *
     * @return 
     */
    inline
    double element_sin(const double e)
    {
        return std::sin(e);
    }
    /*--------------------------------------------------------------------------
     * cos
     *------------------------------------------------------------------------*/
    /**
     * @brief 
     *
     * @tparam Scalar
     */
    template <typename Scalar>
    struct scalar_cos : public scalar_unary_functor<Scalar> {
        typedef typename scalar_unary_functor<Scalar>::value_type value_type;
        typedef typename scalar_unary_functor<Scalar>::argument_type argument_type;
        typedef typename scalar_unary_functor<Scalar>::result_type result_type;

        static result_type apply(argument_type t)
        {
            return std::cos(t);
        }
    };
    /**
     * @brief This function takes elment-wise cos to ublas::vector_expression.
     *
     * @note This function currently does not support vector of which value_type is dual.
     *
     * @tparam VectorExpression
     * @param e
     *
     * @return 
     */
    template<typename VectorExpression>
    inline
    typename boost::numeric::ublas::vector_unary_traits<
        VectorExpression, 
        scalar_cos<typename VectorExpression::value_type> 
    >::result_type
    element_cos(const vector_expression<VectorExpression>& e)
    {
        typedef typename boost::numeric::ublas::vector_unary_traits<
            VectorExpression, 
            scalar_cos<typename VectorExpression::value_type> 
        >::expression_type expression_type;
        return expression_type(e());
    }
    /**
     * @overload
     *
     * @brief 
     *
     * @param e
     *
     * @return 
     */
    inline
    double element_cos(const double e)
    {
        return std::cos(e);
    }
} } } // namespace boost { namespace numeric { namespace ublas {

