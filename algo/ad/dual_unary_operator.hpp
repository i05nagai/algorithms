/**
 * @file dual_unary_operator.hpp
 * @brief 
 * @author i05nagai
 * @version 0.0.2
 * @date 2016-10-04
 */
#pragma once
#include "algo/ad/detail/dual_get_value_function.hpp"
#include "algo/ad/dual_unary_operator_functor.hpp"
#include "algo/ad/dual_expression.hpp"
#include "algo/ad/fwd.hpp"
#include "algo/ad/traits.hpp"

namespace algo { namespace ad {
    /*--------------------------------------------------------------------------
     * dual_unary
     *------------------------------------------------------------------------*/
    template <
        typename DE, 
        typename ValueFunctor,
        typename DerivativeFunctor
    >
    class dual_unary
    : public dual_expression<dual_unary<DE, ValueFunctor, DerivativeFunctor>> {
    //private typedef
    private:
        typedef typename const_closure_type_traits<DE>::type const_closure_type;
        typedef dual_unary<DE, ValueFunctor, DerivativeFunctor> self_type;
    //public typedef
    public:
    //public function
    public:
        //required
        dual_unary()
        : _e()
        {
        }

        dual_unary(const DE& e)
        : _e(e)
        {
        }

        double getValue()
        {
            return ValueFunctor::apply(_e);
        }

        double getValue() const
        {
            return ValueFunctor::apply(_e);
        }

        decltype(DerivativeFunctor::apply(DE()))
        getDerivative()
        {
            return DerivativeFunctor::apply(_e);
        }

        decltype(DerivativeFunctor::apply(DE()))
        getDerivative() const
        {
            return DerivativeFunctor::apply(_e);
        }
    //private function
    private:
    //private members
    private:
        const_closure_type _e;
    };
    /*--------------------------------------------------------------------------
     * negate
     *------------------------------------------------------------------------*/
    /**
     * @brief 
     *
     * @tparam DE
     * @param e
     *
     * @return 
     */
    template<typename DE>
    dual_unary<
        DE,
        dual_negate_value<DE>, 
        dual_negate_derivative<DE>
    > 
    operator -(const dual_expression<DE>& e)
    {
        return dual_unary<
            DE,
            dual_negate_value<DE>, 
            dual_negate_derivative<DE>
        >(e());
    }
    /*--------------------------------------------------------------------------
     * exp
     *------------------------------------------------------------------------*/
    /**
     * @brief 
     *
     * @tparam DE
     * @param e
     *
     * @return 
     */
    template<typename DE>
    dual_unary<
        DE,
        dual_exp_value<DE>, 
        dual_exp_derivative<DE>
    > 
    exp(const dual_expression<DE>& e)
    {
        return dual_unary<
            DE,
            dual_exp_value<DE>, 
            dual_exp_derivative<DE>
        >(e());
    }
    /*--------------------------------------------------------------------------
     * log
     *------------------------------------------------------------------------*/
    /**
     * @brief 
     *
     * @tparam DE
     * @param e
     *
     * @return 
     */
    template<typename DE>
    dual_unary<
        DE,
        dual_log_value<DE>, 
        dual_log_derivative<DE>
    > 
    log(const dual_expression<DE>& e)
    {
        return dual_unary<
            DE,
            dual_log_value<DE>, 
            dual_log_derivative<DE>
        >(e());
    }
    /*--------------------------------------------------------------------------
     * sin
     *------------------------------------------------------------------------*/
    /**
     * @brief 
     *
     * @tparam DE
     * @param e
     *
     * @return 
     */
    template<typename DE>
    dual_unary<
        DE,
        dual_sin_value<DE>, 
        dual_sin_derivative<DE>
    > 
    sin(const dual_expression<DE>& e)
    {
        return dual_unary<
            DE,
            dual_sin_value<DE>, 
            dual_sin_derivative<DE>
        >(e());
    }
    /*--------------------------------------------------------------------------
     * cos
     *------------------------------------------------------------------------*/
    /**
     * @brief 
     *
     * @tparam DE
     * @param e
     *
     * @return 
     */
    template<typename DE>
    dual_unary<
        DE,
        dual_cos_value<DE>, 
        dual_cos_derivative<DE>
    > 
    cos(const dual_expression<DE>& e)
    {
        return dual_unary<
            DE,
            dual_cos_value<DE>, 
            dual_cos_derivative<DE>
        >(e());
    }
} } // namespace algo { namespace ad {
