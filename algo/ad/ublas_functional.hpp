/**
 * @file ublas_functional.hpp
 * @brief 
 * @author i05nagai
 * @version 0.0.2
 * @date 2016-10-04
 */
#pragma once
#include "algo/ad/dual.hpp"
#include "algo/ad/dual_binary_operator.hpp"
#include <boost/numeric/ublas/functional.hpp>
#include <boost/numeric/ublas/traits.hpp>

namespace boost { namespace numeric { namespace ublas {
    /*--------------------------------------------------------------------------
     * scalar_minus
     *------------------------------------------------------------------------*/
    template <typename Derivative1, typename Derivative2>
    struct scalar_minus<
        algo::ad::dual<Derivative1>, 
        algo::ad::dual<Derivative2>
    > {
    private:
        typedef algo::ad::dual<Derivative1> dual1_type;
        typedef algo::ad::dual<Derivative2> dual2_type;
    public:
        typedef typename type_traits<dual1_type>::const_reference argument1_type;
        typedef typename type_traits<dual2_type>::const_reference argument2_type;
        typedef algo::ad::dual_binary<
                dual1_type,
                dual2_type,
                algo::ad::dual_minus_value<
                    dual1_type,
                    dual2_type
                >,
                algo::ad::dual_minus_derivative<
                    dual1_type,
                    dual2_type
                >
            > result_type;
    public:
        static
        result_type apply(argument1_type t1, argument2_type t2)
        {
            return t1 - t2;
        }
    };

    //dual_binary - dual
    template <
        typename DE1, 
        typename DE2, 
        typename ValueFunctor, 
        typename DerivativeFunctor,
        typename Derivative2
    >
    struct scalar_minus<
        algo::ad::dual_binary<
            DE1,
            DE2,
            ValueFunctor, 
            DerivativeFunctor
        >,
        algo::ad::dual<Derivative2>
    > {
    public:
        typedef algo::ad::dual_binary<
                DE1,
                DE2,
                ValueFunctor, 
                DerivativeFunctor
            > dual1_type;
        typedef algo::ad::dual<Derivative2> dual2_type;
    public:
        typedef typename type_traits<dual1_type>::const_reference argument1_type;
        typedef typename type_traits<dual2_type>::const_reference argument2_type;
        typedef algo::ad::dual_binary<
                dual1_type,
                dual2_type,
                algo::ad::dual_minus_value<
                    dual1_type,
                    dual2_type
                >,
                algo::ad::dual_minus_derivative<
                    dual1_type,
                    dual2_type
                >
            > result_type;
    public:
        static
        result_type apply(argument1_type t1, argument2_type t2)
        {
            return t1 - t2;
        }
    };

    //dual - dual_binary
    template <
        typename Derivative1,
        typename DE1, 
        typename DE2, 
        typename ValueFunctor, 
        typename DerivativeFunctor
    >
    struct scalar_minus<
        algo::ad::dual<Derivative1>,
        algo::ad::dual_binary<
            DE1,
            DE2,
            ValueFunctor, 
            DerivativeFunctor
        >
    > {
    public:
        typedef algo::ad::dual<Derivative1> dual1_type;
        typedef algo::ad::dual_binary<
                DE1,
                DE2,
                ValueFunctor, 
                DerivativeFunctor
            > dual2_type;
    public:
        typedef typename type_traits<dual1_type>::const_reference argument1_type;
        typedef typename type_traits<dual2_type>::const_reference argument2_type;
        typedef algo::ad::dual_binary<
                dual1_type,
                dual2_type,
                algo::ad::dual_minus_value<
                    dual1_type,
                    dual2_type
                >,
                algo::ad::dual_minus_derivative<
                    dual1_type,
                    dual2_type
                >
            > result_type;
    public:
        static
        result_type apply(argument1_type t1, argument2_type t2)
        {
            return t1 - t2;
        }
    };
    /*--------------------------------------------------------------------------
     * scalar_multiplies
     *------------------------------------------------------------------------*/
    template <typename Derivative1, typename Derivative2>
    struct scalar_multiplies<
        algo::ad::dual<Derivative1>, 
        algo::ad::dual<Derivative2>
    > {
    private:
        typedef algo::ad::dual<Derivative1> dual1_type;
        typedef algo::ad::dual<Derivative2> dual2_type;
    public:
        typedef typename type_traits<dual1_type>::const_reference argument1_type;
        typedef typename type_traits<dual2_type>::const_reference argument2_type;
        typedef algo::ad::dual_binary<
                dual1_type,
                dual2_type,
                algo::ad::dual_multiply_value<
                    dual1_type,
                    dual2_type
                >,
                algo::ad::dual_multiply_derivative<
                    dual1_type,
                    dual2_type
                >
            > result_type;
    public:
        static
        result_type apply(argument1_type t1, argument2_type t2)
        {
            return t1 * t2;
        }
    };

    //dual_binary - dual
    template <
        typename DE1, 
        typename DE2, 
        typename ValueFunctor, 
        typename DerivativeFunctor,
        typename Derivative2
    >
    struct scalar_multiplies<
        algo::ad::dual_binary<
            DE1,
            DE2,
            ValueFunctor, 
            DerivativeFunctor
        >,
        algo::ad::dual<Derivative2>
    > {
    public:
        typedef algo::ad::dual_binary<
                DE1,
                DE2,
                ValueFunctor, 
                DerivativeFunctor
            > dual1_type;
        typedef algo::ad::dual<Derivative2> dual2_type;
    public:
        typedef typename type_traits<dual1_type>::const_reference argument1_type;
        typedef typename type_traits<dual2_type>::const_reference argument2_type;
        typedef algo::ad::dual_binary<
                dual1_type,
                dual2_type,
                algo::ad::dual_multiply_value<
                    dual1_type,
                    dual2_type
                >,
                algo::ad::dual_multiply_derivative<
                    dual1_type,
                    dual2_type
                >
            > result_type;
    public:
        static
        result_type apply(argument1_type t1, argument2_type t2)
        {
            return t1 * t2;
        }
    };

    //dual - dual_binary
    template <
        typename Derivative1,
        typename DE1, 
        typename DE2, 
        typename ValueFunctor, 
        typename DerivativeFunctor
    >
    struct scalar_multiplies<
        algo::ad::dual<Derivative1>,
        algo::ad::dual_binary<
            DE1,
            DE2,
            ValueFunctor, 
            DerivativeFunctor
        >
    > {
    public:
        typedef algo::ad::dual<Derivative1> dual1_type;
        typedef algo::ad::dual_binary<
                DE1,
                DE2,
                ValueFunctor, 
                DerivativeFunctor
            > dual2_type;
    public:
        typedef typename type_traits<dual1_type>::const_reference argument1_type;
        typedef typename type_traits<dual2_type>::const_reference argument2_type;
        typedef algo::ad::dual_binary<
                dual1_type,
                dual2_type,
                algo::ad::dual_multiply_value<
                    dual1_type,
                    dual2_type
                >,
                algo::ad::dual_multiply_derivative<
                    dual1_type,
                    dual2_type
                >
            > result_type;
    public:
        static
        result_type apply(argument1_type t1, argument2_type t2)
        {
            return t1 * t2;
        }
    };
    /*--------------------------------------------------------------------------
     * scalar_divides
     *------------------------------------------------------------------------*/    
    template <typename Derivative1, typename Derivative2>
    struct scalar_divides<
        algo::ad::dual<Derivative1>, 
        algo::ad::dual<Derivative2>
    > {
    private:
        typedef algo::ad::dual<Derivative1> dual1_type;
        typedef algo::ad::dual<Derivative2> dual2_type;
    public:
        typedef typename type_traits<dual1_type>::const_reference argument1_type;
        typedef typename type_traits<dual2_type>::const_reference argument2_type;
        typedef algo::ad::dual_binary<
                dual1_type,
                dual2_type,
                algo::ad::dual_divide_value<
                    dual1_type,
                    dual2_type
                >,
                algo::ad::dual_divide_derivative<
                    dual1_type,
                    dual2_type
                >
            > result_type;
    public:
        static
        result_type apply(argument1_type t1, argument2_type t2)
        {
            assert(t2 != 0);
            return t1 / t2;
        }
    };

    //dual_binary - dual
    template <
        typename DE1, 
        typename DE2, 
        typename ValueFunctor, 
        typename DerivativeFunctor,
        typename Derivative2
    >
    struct scalar_divides<
        algo::ad::dual_binary<
            DE1,
            DE2,
            ValueFunctor, 
            DerivativeFunctor
        >,
        algo::ad::dual<Derivative2>
    > {
    public:
        typedef algo::ad::dual_binary<
                DE1,
                DE2,
                ValueFunctor, 
                DerivativeFunctor
            > dual1_type;
        typedef algo::ad::dual<Derivative2> dual2_type;
    public:
        typedef typename type_traits<dual1_type>::const_reference argument1_type;
        typedef typename type_traits<dual2_type>::const_reference argument2_type;
        typedef algo::ad::dual_binary<
                dual1_type,
                dual2_type,
                algo::ad::dual_divide_value<
                    dual1_type,
                    dual2_type
                >,
                algo::ad::dual_divide_derivative<
                    dual1_type,
                    dual2_type
                >
            > result_type;
    public:
        static
        result_type apply(argument1_type t1, argument2_type t2)
        {
            assert(t2 != 0);
            return t1 / t2;
        }
    };

    //dual - dual_binary
    template <
        typename Derivative1,
        typename DE1, 
        typename DE2, 
        typename ValueFunctor, 
        typename DerivativeFunctor
    >
    struct scalar_divides<
        algo::ad::dual<Derivative1>,
        algo::ad::dual_binary<
            DE1,
            DE2,
            ValueFunctor, 
            DerivativeFunctor
        >
    > {
    public:
        typedef algo::ad::dual<Derivative1> dual1_type;
        typedef algo::ad::dual_binary<
                DE1,
                DE2,
                ValueFunctor, 
                DerivativeFunctor
            > dual2_type;
    public:
        typedef typename type_traits<dual1_type>::const_reference argument1_type;
        typedef typename type_traits<dual2_type>::const_reference argument2_type;
        typedef algo::ad::dual_binary<
                dual1_type,
                dual2_type,
                algo::ad::dual_divide_value<
                    dual1_type,
                    dual2_type
                >,
                algo::ad::dual_divide_derivative<
                    dual1_type,
                    dual2_type
                >
            > result_type;
    public:
        static
        result_type apply(argument1_type t1, argument2_type t2)
        {
            assert(t2 != 0);
            return t1 / t2;
        }
    };
} } } // namespace boost { namespace numeric { namespace ublas {

