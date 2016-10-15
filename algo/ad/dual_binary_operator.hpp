/**
 * @file dual_binary_operator.hpp
 * @brief dual binary operators.
 * @author i05nagai
 * @version 0.0.2
 * @date 2016-10-03
 */

#pragma once
#include "algo/ad/detail/dual_binary_operator_function.hpp"
#include "algo/ad/detail/dual_get_value_function.hpp"
#include "algo/ad/dual.hpp"
#include "algo/ad/dual_expression.hpp"
#include "algo/ad/dual_binary_operator_functor.hpp"
#include "algo/ad/fwd.hpp"
#include "algo/ad/traits.hpp"

namespace algo { namespace ad {
    /*--------------------------------------------------------------------------
     * dual_binary
     *------------------------------------------------------------------------*/
    template <
        typename DE1, 
        typename DE2, 
        typename ValueFunctor,
        typename DerivativeFunctor
    >
    class dual_binary
    : public dual_expression<
        dual_binary<
            DE1, DE2, ValueFunctor, DerivativeFunctor
        >
    > {
    //private typedef
    private:
        typedef typename const_closure_type_traits<DE1>::type expression1_closure_type;
        typedef typename const_closure_type_traits<DE2>::type expression2_closure_type;
        typedef dual_binary<DE1, DE2, ValueFunctor, DerivativeFunctor> self_type;
    //public typedef
    public:
        typedef self_type const_closure_type;
        typedef typename DE1::derivative_type derivative_type;
    //public function
    public:
        //required
        dual_binary()
        : _e1(), _e2()
        {
        }

        dual_binary(const DE1& e1, const DE2& e2)
        : _e1(e1), _e2(e2)
        {
        }

        double getValue()
        {
            return ValueFunctor::apply(_e1, _e2);
        }

        double getValue() const
        {
            return ValueFunctor::apply(_e1, _e2);
        }

        decltype(DerivativeFunctor::apply(DE1(), DE2()))
        getDerivative()
        {
            return DerivativeFunctor::apply(_e1, _e2);
        }

        decltype(DerivativeFunctor::apply(DE1(), DE2()))
        getDerivative() const
        {
            return DerivativeFunctor::apply(_e1, _e2);
        }
    //private function
    private:
    //private members
    private:
        expression1_closure_type _e1;
        expression2_closure_type _e2;
    };
    /*--------------------------------------------------------------------------
     * operator +
     *------------------------------------------------------------------------*/
    /**
     * @brief 
     *
     * @tparam DE1
     * @tparam DE2
     * @param e1
     * @param e2
     *
     * @return 
     */
    template<typename DE1, typename DE2>
    dual_binary<
        DE1, 
        DE2,
        dual_plus_value<DE1, DE2>,
        dual_plus_derivative<DE1, DE2>
    >
    operator +(
        const dual_expression<DE1>& e1,
        const dual_expression<DE2>& e2)
    {
        return dual_binary<
            DE1,
            DE2,
            dual_plus_value<DE1, DE2>,
            dual_plus_derivative<DE1, DE2>
        >(e1(), e2());
    }
    /**
     * @brief 
     *
     * @tparam DE2
     * @param e1
     * @param e2
     *
     * @return 
     */
    template<typename DE2>
    dual_binary<
        double, 
        DE2,
        dual_plus_value<double, DE2>,
        dual_plus_derivative<double, DE2>
    >
    operator +(
        const double e1,
        const dual_expression<DE2>& e2)
    {
        return dual_binary<
            double,
            DE2,
            dual_plus_value<double, DE2>,
            dual_plus_derivative<double, DE2>
        >(e1, e2());
    }
    /**
     * @brief 
     *
     * @tparam DE1
     * @param e1
     * @param e2
     *
     * @return 
     */
    template<typename DE1>
    dual_binary<
        DE1, 
        double,
        dual_plus_value<DE1, double>,
        dual_plus_derivative<DE1, double>
    >
    operator +(
        const dual_expression<DE1>& e1,
        const double e2)
    {
        return dual_binary<
            DE1,
            double,
            dual_plus_value<DE1, double>,
            dual_plus_derivative<DE1, double>
        >(e1(), e2);
    }
    /*--------------------------------------------------------------------------
     * operator -
     *------------------------------------------------------------------------*/
    /**
     * @brief 
     *
     * @tparam DE1
     * @tparam DE2
     * @param e1
     * @param e2
     *
     * @return 
     */
    template<typename DE1, typename DE2>
    dual_binary<
        DE1, 
        DE2,
        dual_minus_value<DE1, DE2>,
        dual_minus_derivative<DE1, DE2>
    >
    operator -(
        const dual_expression<DE1>& e1,
        const dual_expression<DE2>& e2)
    {
        return dual_binary<
            DE1,
            DE2,
            dual_minus_value<DE1, DE2>,
            dual_minus_derivative<DE1, DE2>
        >(e1(), e2());
    }
    /**
     * @brief 
     *
     * @tparam E2
     * @param e1
     * @param e2
     *
     * @return 
     */
    template<typename DE2>
    dual_binary<
        double, 
        DE2,
        dual_minus_value<double, DE2>,
        dual_minus_derivative<double, DE2>
    >
    operator -(
        const double e1,
        const dual_expression<DE2>& e2)
    {
        return dual_binary<
            double,
            DE2,
            dual_minus_value<double, DE2>,
            dual_minus_derivative<double, DE2>
        >(e1, e2());
    }
    /**
     * @brief 
     *
     * @tparam DE1
     * @param e1
     * @param e2
     *
     * @return 
     */
    template<typename DE1>
    dual_binary<
        DE1, 
        double,
        dual_minus_value<DE1, double>,
        dual_minus_derivative<DE1, double>
    >
    operator -(
        const dual_expression<DE1>& e1,
        const double e2)
    {
        return dual_binary<
            DE1,
            double,
            dual_minus_value<DE1, double>,
            dual_minus_derivative<DE1, double>
        >(e1(), e2);
    }
    /*--------------------------------------------------------------------------
     * operator *
     *------------------------------------------------------------------------*/
    /**
     * @brief 
     *
     * @tparam DE1
     * @tparam DE2
     * @param e1
     * @param e2
     *
     * @return 
     */
    template<typename DE1, typename DE2>
    dual_binary<
        DE1, 
        DE2,
        dual_multiply_value<DE1, DE2>,
        dual_multiply_derivative<DE1, DE2>
    >
    operator *(
        const dual_expression<DE1>& e1,
        const dual_expression<DE2>& e2)
    {
        return dual_binary<
            DE1,
            DE2,
            dual_multiply_value<DE1, DE2>,
            dual_multiply_derivative<DE1, DE2>
        >(e1(), e2());
    }
    /**
     * @brief 
     *
     * @tparam E2
     * @param e1
     * @param e2
     *
     * @return 
     */
    template<typename DE2>
    dual_binary<
        double, 
        DE2,
        dual_multiply_value<double, DE2>,
        dual_multiply_derivative<double, DE2>
    >
    operator *(
        const double e1,
        const dual_expression<DE2>& e2)
    {
        return dual_binary<
            double,
            DE2,
            dual_multiply_value<double, DE2>,
            dual_multiply_derivative<double, DE2>
        >(e1, e2());
    }
    /**
     * @brief 
     *
     * @tparam DE1
     * @param e1
     * @param e2
     *
     * @return 
     */
    template<typename DE1>
    dual_binary<
        DE1, 
        double,
        dual_multiply_value<DE1, double>,
        dual_multiply_derivative<DE1, double>
    >
    operator *(
        const dual_expression<DE1>& e1,
        const double e2)
    {
        return dual_binary<
            DE1,
            double,
            dual_multiply_value<DE1, double>,
            dual_multiply_derivative<DE1, double>
        >(e1(), e2);
    }
    /*--------------------------------------------------------------------------
     * operator /
     *------------------------------------------------------------------------*/
    /**
     * @brief 
     *
     * @tparam DE1
     * @tparam DE2
     * @param e1
     * @param e2
     *
     * @return 
     */
    template<typename DE1, typename DE2>
    dual_binary<
        DE1, 
        DE2,
        dual_divide_value<DE1, DE2>,
        dual_divide_derivative<DE1, DE2>
    >
    operator /(
        const dual_expression<DE1>& e1,
        const dual_expression<DE2>& e2)
    {
        return dual_binary<
            DE1,
            DE2,
            dual_divide_value<DE1, DE2>,
            dual_divide_derivative<DE1, DE2>
        >(e1(), e2());
    }
    /**
     * @brief 
     *
     * @tparam E2
     * @param e1
     * @param e2
     *
     * @return 
     */
    template<typename DE2>
    dual_binary<
        double, 
        DE2,
        dual_divide_value<double, DE2>,
        dual_divide_derivative<double, DE2>
    >
    operator /(
        const double e1,
        const dual_expression<DE2>& e2)
    {
        return dual_binary<
            double,
            DE2,
            dual_divide_value<double, DE2>,
            dual_divide_derivative<double, DE2>
        >(e1, e2());
    }
    /**
     * @brief 
     *
     * @tparam DE1
     * @param e1
     * @param e2
     *
     * @return 
     */
    template<typename DE1>
    dual_binary<
        DE1, 
        double,
        dual_divide_value<DE1, double>,
        dual_divide_derivative<DE1, double>
    >
    operator /(
        const dual_expression<DE1>& e1,
        const double e2)
    {
        return dual_binary<
            DE1,
            double,
            dual_divide_value<DE1, double>,
            dual_divide_derivative<DE1, double>
        >(e1(), e2);
    }
} } // namespace algo { namespace ad {
