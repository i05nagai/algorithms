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
    /**
     * @brief specicialization of ublas::scalar_minus for dual - dual operation.
     *
     * @note This specialization is required by ublas functor implementation.
     *  The functors of ublas infer type after applying operation such as 
     *  `-`, `*`, `/`, etc. by ublas::promote_traits.
     *  ublas::prmote_traits tests `x + y` to infer the type. 
     *  Here x and y denotes variable of which type is type of operand. 
     *  Integral types has integral conversions
     *  so that type can be gained as a result of the test.
     *  See ublas::promote_traits for more details.
     *  In other hands, custom type, which is not integral type, need to determine 
     *  the type after applying operation.
     *  You may think that ublas::promote_traits can be specialized as this solution.
     *  But ublas::promote_traits does not have inoformation of operation
     *  so that operator is not determined by specialization of ublas::promote_traits.
     *
     * @tparam Derivative1
     * @tparam Derivative2
     */
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
        /**
         * @brief specify type without promote_traits
         */
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
    /**
     * @brief specicialization of ublas::scalar_minus for dual_binary - dual operation.
     *
     * @note This specialization is required by ublas functor implementation.
     *  The functors of ublas infer type after applying operation such as 
     *  `-`, `*`, `/`, etc. by ublas::promote_traits.
     *  ublas::prmote_traits tests `x + y` to infer the type. 
     *  Here x and y denotes variable of which type is type of operand. 
     *  Integral types has integral conversions
     *  so that type can be gained as a result of the test.
     *  See ublas::promote_traits for more details.
     *  In other hands, custom type, which is not integral type, need to determine 
     *  the type after applying operation.
     *  You may think that ublas::promote_traits can be specialized as this solution.
     *  But ublas::promote_traits does not have inoformation of operation
     *  so that operator is not determined by specialization of ublas::promote_traits.
     *
     * @tparam DE1
     * @tparam DE2
     * @tparam ValueFunctor
     * @tparam DerivativeFunctor
     * @tparam Derivative2
     */
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
        /**
         * @brief specify type without promote_traits
         */
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
    /**
     * @brief specicialization of ublas::scalar_minus for dual - dual_binary operation.
     *
     * @note This specialization is required by ublas functor implementation.
     *  The functors of ublas infer type after applying operation such as 
     *  `-`, `*`, `/`, etc. by ublas::promote_traits.
     *  ublas::prmote_traits tests `x + y` to infer the type. 
     *  Here x and y denotes variable of which type is type of operand. 
     *  Integral types has integral conversions
     *  so that type can be gained as a result of the test.
     *  See ublas::promote_traits for more details.
     *  In other hands, custom type, which is not integral type, need to determine 
     *  the type after applying operation.
     *  You may think that ublas::promote_traits can be specialized as this solution.
     *  But ublas::promote_traits does not have inoformation of operation
     *  so that operator is not determined by specialization of ublas::promote_traits.
     *
     * @tparam Derivative1
     * @tparam DE1
     * @tparam DE2
     * @tparam ValueFunctor
     * @tparam DerivativeFunctor
     */
    template <
        typename Derivative1,
        typename DE1, 
        typename DE2, 
        typename ValueFunctor, 
        typename DerivativeFunctor >
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
        /**
         * @brief specify type without promote_traits
         */
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

