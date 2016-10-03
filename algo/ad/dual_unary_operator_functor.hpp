/**
 * @file dual_unary_operator_functor.hpp
 * @brief 
 * @author i05nagai
 * @version 0.0.2
 * @date 2016-10-04
 */
#pragma once
#include "algo/ad/detail/dual_unary_operator_function.hpp"

namespace algo { namespace ad {
    /*--------------------------------------------------------------------------
     * dual_negate
     *------------------------------------------------------------------------*/
    template <typename Dual>
    struct dual_negate_value {
    public:
    public:
        static
        double apply(const Dual& e)
        {
            return -detail::getValue(e);
        }
    };

    template <typename Dual>
    struct dual_negate_derivative {
    public:
        typedef decltype(detail::negateDualDerivative(Dual())) result_type;
    public:
        static result_type apply(const Dual& e)
        {
            return detail::negateDualDerivative(e);
        }
    };
    /*--------------------------------------------------------------------------
     * dual_exp
     *------------------------------------------------------------------------*/
    template <typename Dual>
    struct dual_exp_value {
    public:
    public:
        static
        double apply(const Dual& e)
        {
            return std::exp(detail::getValue(e));
        }
    };

    template <typename Dual>
    struct dual_exp_derivative {
    public:
        typedef decltype(detail::expDualDerivative(Dual())) result_type;
    public:
        static result_type apply(const Dual& e)
        {
            return detail::expDualDerivative(e);
        }
    };
    /*--------------------------------------------------------------------------
     * dual_log
     *------------------------------------------------------------------------*/
    template <typename Dual>
    struct dual_log_value {
    public:
    public:
        static
        double apply(const Dual& e)
        {
            return std::log(detail::getValue(e));
        }
    };

    template <typename Dual>
    struct dual_log_derivative {
    public:
        typedef decltype(detail::logDualDerivative(Dual())) result_type;
    public:
        static result_type apply(const Dual& e)
        {
            return detail::logDualDerivative(e);
        }
    };
    /*--------------------------------------------------------------------------
     * dual_sin
     *------------------------------------------------------------------------*/
    template <typename Dual>
    struct dual_sin_value {
    public:
    public:
        static
        double apply(const Dual& e)
        {
            return std::sin(detail::getValue(e));
        }
    };

    template <typename Dual>
    struct dual_sin_derivative {
    public:
        typedef decltype(detail::sinDualDerivative(Dual())) result_type;
    public:
        static result_type apply(const Dual& e)
        {
            return detail::sinDualDerivative(e);
        }
    };
    /*--------------------------------------------------------------------------
     * dual_cos
     *------------------------------------------------------------------------*/
    template <typename Dual>
    struct dual_cos_value {
    public:
    public:
        static
        double apply(const Dual& e)
        {
            return std::cos(detail::getValue(e));
        }
    };

    template <typename Dual>
    struct dual_cos_derivative {
    public:
        typedef decltype(detail::cosDualDerivative(Dual())) result_type;
    public:
        static result_type apply(const Dual& e)
        {
            return detail::cosDualDerivative(e);
        }
    };
} } // namespace algo { namespace ad {
