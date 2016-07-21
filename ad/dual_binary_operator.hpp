/**
 * @file dual_binary_operator.h
 * @brief dual binary operators.
 * @author i05nagai
 * @version 0.0.1
 * @date 2016-07-20
 */

#pragma once
#include "fwd.h"
#include "ad/dual.h"
#include "ad/dual_expression.h"
#include "ad/traits.h"
#include "ad/detail/dual_binary_operator_helper.h"
#include "ad/detail/dual_helper_function.h"

namespace algo { namespace ad {
    /*--------------------------------------------------------------------------
     * dual_add
     *------------------------------------------------------------------------*/
    /**
     * @brief 
     *
     * @tparam E1
     * @tparam E2
     */
    template<typename E1, typename E2>
    class dual_add : public dual_expression<dual_add<E1, E2> > {
    //private typedef
    private:
    //public typedef
    public:
        typedef typename const_closure_type_traits<E1>::type const_closure1_type;
        typedef typename const_closure_type_traits<E2>::type const_closure2_type;
    //public function
    public:
        /**
         * @brief the constructor is required by getDerivative.
         */
        dual_add()
        : _e1(0), _e2(0)
        {
        }
        /**
         * @brief 
         *
         * @param e1
         * @param e2
         */
        dual_add(const E1& e1, const E2& e2)
        : _e1(e1), _e2(e2)
        {
        }
        /**
         * @brief 
         *
         * @return 
         */
        double getValue()
        {
            return detail::getValue(_e1) + detail::getValue(_e2);
        }
        /**
         * @brief 
         *
         * @return 
         */
        double getValue() const
        {
            return detail::getValue(_e1) + detail::getValue(_e2);
        }
        /**
         * @brief 
         *
         * @return
         */
        decltype(detail::dual_add_function(E1(), E2()))
        getDerivative()
        {
            return detail::dual_add_function(_e1, _e2);
        }

        /**
         * @brief 
         *
         * @return
         */
        decltype(detail::dual_add_function(E1(), E2()))
        getDerivative() const
        {
            return detail::dual_add_function(_e1, _e2);
        }
    //private function
    private:
    //private members
    private:
        const_closure1_type _e1;
        const_closure2_type _e2;
    };

    /**
     * @brief 
     *
     * @tparam E1
     * @tparam E2
     * @param e1
     * @param e2
     *
     * @return 
     */
    template<typename E1, typename E2>
    dual_add<E1, E2>
    operator +(
        const dual_expression<E1>& e1,
        const dual_expression<E2>& e2)
    {
        return dual_add<E1, E2>(e1(), e2());
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
    template<typename E2>
    dual_add<double, E2>
    operator +(
        const double e1,
        const dual_expression<E2>& e2)
    {
        return dual_add<double, E2>(e1, e2());
    }
    /**
     * @brief 
     *
     * @tparam E1
     * @param e1
     * @param e2
     *
     * @return 
     */
    template<typename E1>
    dual_add<E1, double>
    operator +(
        const dual_expression<E1>& e1,
        const double e2)
    {
        return dual_add<E1, double>(e1(), e2);
    }
    /*--------------------------------------------------------------------------
     * dual_minus
     *------------------------------------------------------------------------*/
    template<typename E1, typename E2>
    class dual_minus : public dual_expression<dual_minus<E1, E2> > {
    //private typedef
    private:
    //public typedef
    public:
        typedef typename const_closure_type_traits<E1>::type const_closure1_type;
        typedef typename const_closure_type_traits<E2>::type const_closure2_type;
    //public function
    public:
        /**
         * @brief the constructor is required by getDerivative.
         */
        dual_minus()
        : _e1(0), _e2(0)
        {
        }
        /**
         * @brief 
         *
         * @param e1
         * @param e2
         */
        dual_minus(const E1& e1, const E2& e2)
        : _e1(e1), _e2(e2)
        {
        }
        /**
         * @brief 
         *
         * @return 
         */
        double getValue()
        {
            return detail::getValue(_e1) - detail::getValue(_e2);
        }
        /**
         * @brief 
         *
         * @return 
         */
        double getValue() const
        {
            return detail::getValue(_e1) - detail::getValue(_e2);
        }
        /**
         * @brief 
         *
         * @return
         */
        decltype(detail::dual_minus_function(E1(), E2()))
        getDerivative() 
        {
            return detail::dual_minus_function(_e1, _e2);
        }
        /**
         * @brief 
         *
         * @return
         */
        decltype(detail::dual_minus_function(E1(), E2()))
        getDerivative() const
        {
            return detail::dual_minus_function(_e1, _e2);
        }
    //private function
    private:
    //private members
    private:
        const_closure1_type _e1;
        const_closure2_type _e2;
    };
    /**
     * @brief 
     *
     * @tparam E1
     * @tparam E2
     * @param e1
     * @param e2
     *
     * @return 
     */
    template<typename E1, typename E2>
    dual_minus<E1, E2>
    operator -(
        const dual_expression<E1>& e1,
        const dual_expression<E2>& e2)
    {
        return dual_minus<E1, E2>(e1(), e2());
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
    template<typename E2>
    dual_minus<double, E2>
    operator -(
        const double e1,
        const dual_expression<E2>& e2)
    {
        return dual_minus<double, E2>(e1, e2());
    }
    /**
     * @brief 
     *
     * @tparam E1
     * @param e1
     * @param e2
     *
     * @return 
     */
    template<typename E1>
    dual_minus<E1, double>
    operator -(
        const dual_expression<E1>& e1,
        const double e2)
    {
        return dual_minus<E1, double>(e1(), e2);
    }
    /*--------------------------------------------------------------------------
     * dual_multiplies
     *------------------------------------------------------------------------*/
    /**
     * @brief 
     *
     * @tparam E1
     * @tparam E2
     */
    template<typename E1, typename E2>
    class dual_multiplies : public dual_expression<dual_multiplies<E1, E2> > {
    //private typedef
    private:
    //public typedef
    public:
        typedef typename const_closure_type_traits<E1>::type const_closure1_type;
        typedef typename const_closure_type_traits<E2>::type const_closure2_type;
    //public function
    public:
        /**
         * @brief the constructor is required by dual_expression.
         */
        dual_multiplies()
        : _e1(0), _e2(0)
        {
        }
        /**
         * @brief 
         *
         * @param e1
         * @param e2
         */
        dual_multiplies(const E1& e1, const E2& e2)
        : _e1(e1), _e2(e2)
        {
        }
        /**
         * @brief 
         *
         * @return 
         */
        double getValue()
        {
            return detail::getValue(_e1) * detail::getValue(_e2);
        }
        /**
         * @brief 
         *
         * @return 
         */
        double getValue() const
        {
            return detail::getValue(_e1) * detail::getValue(_e2);
        }
        /**
         * @brief 
         *
         * @return
         */
        decltype(detail::dual_multiplies_function(E1(), E2()))
        getDerivative()
        {
            return detail::dual_multiplies_function(_e1, _e2);
        }
        /**
         * @brief 
         *
         * @return
         */
        decltype(detail::dual_multiplies_function(E1(), E2()))
        getDerivative() const
        {
            return detail::dual_multiplies_function(_e1, _e2);
        }
    //private function
    private:
    //private members
    private:
        const_closure1_type _e1;
        const_closure2_type _e2;
    };
    /**
     * @brief 
     *
     * @tparam E1
     * @tparam E2
     * @param e1
     * @param e2
     *
     * @return 
     */
    template<typename E1, typename E2>
    dual_multiplies<E1, E2>
    operator *(
        const dual_expression<E1>& e1,
        const dual_expression<E2>& e2)
    {
        return dual_multiplies<E1, E2>(e1(), e2());
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
    template<typename E2>
    dual_multiplies<double, E2>
    operator *(
        const double e1,
        const dual_expression<E2>& e2)
    {
        return dual_multiplies<double, E2>(e1, e2());
    }
    /**
     * @brief 
     *
     * @tparam E1
     * @param e1
     * @param e2
     *
     * @return 
     */
    template<typename E1>
    dual_multiplies<E1, double>
    operator *(
        const dual_expression<E1>& e1,
        const double e2)
    {
        return dual_multiplies<E1, double>(e1(), e2);
    }
    /*--------------------------------------------------------------------------
     * dual_divide
     *------------------------------------------------------------------------*/
    /**
     * @brief 
     *
     * @tparam E1
     * @tparam E2
     */
    template<typename E1, typename E2>
    class dual_divide : public dual_expression<dual_divide<E1, E2> > {
    //private typedef
    private:
    //public typedef
    public:
        typedef typename const_closure_type_traits<E1>::type const_closure1_type;
        typedef typename const_closure_type_traits<E2>::type const_closure2_type;
    //public function
    public:
        /**
         * @brief the constructor is required.
         */
        dual_divide()
        : _e1(0), _e2(0)
        {
        }
        /**
         * @brief 
         *
         * @param e1
         * @param e2
         */
        dual_divide(const E1& e1, const E2& e2)
        : _e1(e1), _e2(e2)
        {
        }
        /**
         * @brief 
         *
         * @return 
         */
        double getValue()
        {
            return detail::getValue(_e1) / detail::getValue(_e2);
        }
        /**
         * @brief 
         *
         * @return 
         */
        double getValue() const
        {
            return detail::getValue(_e1) / detail::getValue(_e2);
        }
        /**
         * @brief 
         *
         * @return
         */
        decltype(detail::dual_divide_function(E1(), E2()))
        getDerivative()
        {
            return detail::dual_divide_function(_e1, _e2);
        }
        /**
         * @brief 
         *
         * @return
         */
        decltype(detail::dual_divide_function(E1(), E2()))
        getDerivative() const
        {
            return detail::dual_divide_function(_e1, _e2);
        }
    //private function
    private:
    //private members
    private:
        const_closure1_type _e1;
        const_closure2_type _e2;
    };
    /**
     * @brief 
     *
     * @tparam E1
     * @tparam E2
     * @param e1
     * @param e2
     *
     * @return 
     */
    template<typename E1, typename E2>
    dual_divide<E1, E2>
    operator /(
        const dual_expression<E1>& e1,
        const dual_expression<E2>& e2)
    {
        return dual_divide<E1, E2>(e1(), e2());
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
    template<typename E2>
    dual_divide<double, E2>
    operator /(
        const double e1,
        const dual_expression<E2>& e2)
    {
        return dual_divide<double, E2>(e1, e2());
    }
    /**
     * @brief 
     *
     * @tparam E1
     * @param e1
     * @param e2
     *
     * @return 
     */
    template<typename E1>
    dual_divide<E1, double>
    operator /(
        const dual_expression<E1>& e1,
        const double e2)
    {
        return dual_divide<E1, double>(e1(), e2);
    }
} } // namespace algo { namespace ad {
