#pragma once
#include "algo/ad/detail/dual_binary_operator_function.hpp"

namespace algo { namespace ad {
    /*--------------------------------------------------------------------------
     * dual_plus
     *------------------------------------------------------------------------*/
    template <typename Dual1, typename Dual2>
    struct dual_plus_value {
    public:
        static
        double apply(const Dual1& e1, const Dual2& e2)
        {
            return detail::getValue(e1) + detail::getValue(e2);
        }
    };

    template <typename Dual1, typename Dual2>
    struct dual_plus_derivative {
    public:
        typedef decltype(detail::plusDualDerivative(Dual1(), Dual2())) 
            result_type;
    public:
        static
        result_type
        apply(const Dual1& e1, const Dual2& e2)
        {
            return detail::plusDualDerivative(e1, e2);
        }
    };
    /*--------------------------------------------------------------------------
     * dual_minus
     *------------------------------------------------------------------------*/
    template <typename Dual1, typename Dual2>
    struct dual_minus_value {
    public:
        static
        double apply(const Dual1& e1, const Dual2& e2)
        {
            return detail::getValue(e1) - detail::getValue(e2);
        }
    };

    template <typename Dual1, typename Dual2>
    struct dual_minus_derivative {
    public:
        typedef decltype(detail::minusDualDerivative(Dual1(), Dual2())) 
            result_type;
    public:
        static
        result_type
        apply(const Dual1& e1, const Dual2& e2)
        {
            return detail::minusDualDerivative(e1, e2);
        }
    };
    /*--------------------------------------------------------------------------
     * dual_multiply
     *------------------------------------------------------------------------*/
    template <typename Dual1, typename Dual2>
    struct dual_multiply_value {
    public:
        static
        double apply(const Dual1& e1, const Dual2& e2)
        {
            return detail::getValue(e1) * detail::getValue(e2);
        }
    };

    template <typename Dual1, typename Dual2>
    struct dual_multiply_derivative {
    public:
        typedef decltype(detail::multiplyDualDerivative(Dual1(), Dual2())) 
            result_type;
    public:
        static
        result_type
        apply(const Dual1& e1, const Dual2& e2)
        {
            return detail::multiplyDualDerivative(e1, e2);
        }
    };
    /*--------------------------------------------------------------------------
     * dual_divide
     *------------------------------------------------------------------------*/
    template <typename Dual1, typename Dual2>
    struct dual_divide_value {
    public:
        static
        double apply(const Dual1& e1, const Dual2& e2)
        {
            assert(e2 != 0.0);
            return detail::getValue(e1) / detail::getValue(e2);
        }
    };

    template <typename Dual1, typename Dual2>
    struct dual_divide_derivative {
    public:
        typedef decltype(detail::divideDualDerivative(Dual1(), Dual2())) 
            result_type;
    public:
        static
        result_type
        apply(const Dual1& e1, const Dual2& e2)
        {
            return detail::divideDualDerivative(e1, e2);
        }
    };
} } // namespace algo { namespace ad {

