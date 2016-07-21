/**
 * @file dual_unary_operator.h
 * @brief dual unary operators.
 * @author i05nagai
 * @version 0.0.1
 * @date 2016-07-20
 */

#pragma once
#include "fwd.h"
#include "ad/dual_expression.h"
#include "ad/traits.h"
#include "ad/detail/dual_unary_operator_helper.h"
#include "ad/detail/dual_helper_function.h"

namespace algo { namespace ad {
    /*--------------------------------------------------------------------------
     * dual_negate
     *------------------------------------------------------------------------*/
    /**
     * @brief 
     *
     * @tparam E
     */
    template<typename E>
    class dual_negate : public dual_expression<dual_negate<E> > {
    //private typedef
    private:
    //public typedef
    public:
        typedef typename const_closure_type_traits<E>::type const_closure_type;
    //public function
    public:
        /**
         * @brief the constructor is required.
         */
        dual_negate()
        : _e(0)
        {
        }
        /**
         * @brief 
         *
         * @param e
         */
        dual_negate(const E& e)
        : _e(e)
        {
        }
        /**
         * @brief 
         *
         * @return
         */
        double getValue()
        {
            return -detail::getValue(_e);
        }
        /**
         * @brief 
         *
         * @return
         */
        double getValue() const
        {
            return -detail::getValue(_e);
        }
        /**
         * @brief 
         *
         * @return
         */
        decltype(detail::dual_negate_helper(E()))
        getDerivative()
        {
            return detail::dual_negate_helper(_e);
        }
        /**
         * @brief 
         *
         * @return
         */
        decltype(detail::dual_negate_helper(E()))
        getDerivative() const
        {
            return detail::dual_negate_helper(_e);
        }
    //private function
    private:
    //private members
    private:
        const_closure_type _e;
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
    dual_negate<E> operator -(const dual_expression<E>& e)
    {
        return dual_negate<E>(e());
    }
    /*--------------------------------------------------------------------------
     * dual_exp
     *------------------------------------------------------------------------*/
    /**
     * @brief 
     *
     * @tparam E
     */
    template<typename E>
    class dual_exp : public dual_expression<dual_exp<E> > {
    //private typedef
    private:
    //public typedef
    public:
        typedef typename const_closure_type_traits<E>::type const_closure_type;
    //public function
    public:
        /**
         * @brief requires.
         */
        dual_exp()
        : _e(0)
        {
        }
        /**
         * @brief 
         *
         * @param e
         */
        dual_exp(const E& e)
        : _e(e)
        {
        }
        /**
         * @brief 
         *
         * @return 
         */
        double getValue()
        {
            return std::exp(detail::getValue(_e));
        }
        /**
         * @brief 
         *
         * @return 
         */
        double getValue() const
        {
            return std::exp(detail::getValue(_e));
        }
        /**
         * @brief 
         *
         * @return
         */
        decltype(detail::dual_exp_helper(E()))
        getDerivative()
        {
            return detail::dual_exp_helper(_e);
        }
        /**
         * @brief 
         *
         * @return
         */
        decltype(detail::dual_exp_helper(E()))
        getDerivative() const
        {
            return detail::dual_exp_helper(_e);
        }
    //private function
    private:
    //private members
    private:
        const_closure_type _e;
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
    dual_exp<E> exp(const dual_expression<E>& e)
    {
        return dual_exp<E>(e());
    }
    /*--------------------------------------------------------------------------
     * dual_log
     *------------------------------------------------------------------------*/
    /**
     * @brief 
     *
     * @tparam E
     */
    template<typename E>
    class dual_log : public dual_expression<dual_log<E> > {
    //private typedef
    private:
    //public typedef
    public:
        typedef typename const_closure_type_traits<E>::type const_closure_type;
    //public function
    public:
        /**
         * @brief the constructor is required.
         */
        dual_log()
        : _e(0)
        {
        }
        /**
         * @brief 
         *
         * @param e
         */
        dual_log(const E& e)
        : _e(e)
        {
        }
        /**
         * @brief 
         *
         * @return 
         */
        double getValue()
        {
            return std::log(detail::getValue(_e));
        }
        /**
         * @brief 
         *
         * @return 
         */
        double getValue() const
        {
            return std::log(detail::getValue(_e));
        }
        /**
         * @brief 
         *
         * @return
         */
        decltype(detail::dual_log_helper(E()))
        getDerivative()
        {
            return detail::dual_log_helper(_e);
        }
        /**
         * @brief 
         *
         * @return
         */
        decltype(detail::dual_log_helper(E()))
        getDerivative() const
        {
            return detail::dual_log_helper(_e);
        }
    //private function
    private:
    //private members
    private:
        const_closure_type _e;
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
    dual_log<E> log(const dual_expression<E>& e)
    {
        return dual_log<E>(e());
    }
    /*--------------------------------------------------------------------------
     * dual_sin
     *------------------------------------------------------------------------*/
    /**
     * @brief 
     *
     * @tparam E
     */
    template<typename E>
    class dual_sin : public dual_expression<dual_sin<E> > {
    //private typedef
    private:
    //public typedef
    public:
        typedef typename const_closure_type_traits<E>::type const_closure_type;
    //public function
    public:
        /**
         * @brief the constructor is required.
         */
        dual_sin()
        : _e(0)
        {
        }
        /**
         * @brief 
         *
         * @param e
         */
        dual_sin(const E& e)
        : _e(e)
        {
        }
        /**
         * @brief 
         *
         * @return 
         */
        double getValue()
        {
            return std::sin(detail::getValue(_e));
        }
        /**
         * @brief 
         *
         * @return 
         */
        double getValue() const
        {
            return std::sin(detail::getValue(_e));
        }
        /**
         * @brief 
         *
         * @return
         */
        decltype(detail::dual_sin_helper(E()))
        getDerivative()
        {
            return detail::dual_sin_helper(_e);
        }
        /**
         * @brief 
         *
         * @return
         */
        decltype(detail::dual_sin_helper(E()))
        getDerivative() const
        {
            return detail::dual_sin_helper(_e);
        }
    //private function
    private:
    //private members
    private:
        const_closure_type _e;
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
    dual_sin<E> sin(const dual_expression<E>& e)
    {
        return dual_sin<E>(e());
    }
    /*--------------------------------------------------------------------------
     * dual_cos
     *------------------------------------------------------------------------*/
    /**
     * @brief 
     *
     * @tparam E
     */
    template<typename E>
    class dual_cos : public dual_expression<dual_cos<E> > {
    //private typedef
    private:
    //public typedef
    public:
        typedef typename const_closure_type_traits<E>::type const_closure_type;
    //public function
    public:
        /**
         * @brief the constructor is required.
         */
        dual_cos()
        : _e(0)
        {
        }
        /**
         * @brief 
         *
         * @param e
         */
        dual_cos(const E& e)
        : _e(e)
        {
        }
        /**
         * @brief 
         *
         * @return 
         */
        double getValue()
        {
            return std::cos(detail::getValue(_e));
        }
        /**
         * @brief 
         *
         * @return 
         */
        double getValue() const
        {
            return std::cos(detail::getValue(_e));
        }
        /**
         * @brief 
         *
         * @return
         */
        decltype(detail::dual_cos_helper(E()))
        getDerivative()
        {
            return detail::dual_cos_helper(_e);
        }
        /**
         * @brief 
         *
         * @return
         */
        decltype(detail::dual_cos_helper(E()))
        getDerivative() const
        {
            return detail::dual_cos_helper(_e);
        }
    //private function
    private:
    //private members
    private:
        const_closure_type _e;
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
    dual_cos<E> cos(const dual_expression<E>& e)
    {
        return dual_cos<E>(e());
    }
} } // namespace algo { namespace ad {
