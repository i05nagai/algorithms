/**
 * @file dual.hpp
 * @brief dual class.
 * @author i05nagai
 * @version 0.0.1
 * @date 2016-07-20
 */

#pragma once
#include "dual_expression.hpp"

namespace algo { namespace ad {
    /**
     * @brief 
     *
     * @tparam I
     */
    template <typename I = boost::numeric::ublas::vector<double> >
    class dual : public dual_expression<dual<I> > {
    private:
        typedef dual<I> self_type;
    public:
        //closure
        typedef const self_type& const_closure_type;
        //inf
        typedef I infinitesimal_type;
        typedef I& infinitesimal_reference;
        typedef const I& const_infinitesimal_reference;

    public:
        /**
         * @brief 
         */
        explicit dual() 
        : _value(0), _derivative(0)
        {
        }
        /**
         * @brief 
         *
         * @tparam AE
         * @param ae
         */
        template <typename AE>
        dual(const dual_expression<AE>& ae) 
        : _value(ae().getValue()), _derivative(ae().getDerivative())
        {
        }
        /**
         * @brief 
         *
         * @param v
         */
        dual(const double v) 
        : _value(v), _derivative(0)
        {
        }
        /**
         * @brief 
         *  TODO:need to check inf_type is same size.
         * @param v
         * @param d
         */
        dual(
            const double& v, 
            const infinitesimal_type& d) 
        : _value(v), _derivative(d)
        {
        }
        /**
         * @brief 
         *
         * @return 
         */
        double& getValue()
        {
            return _value;
        }
        /**
         * @brief 
         *
         * @return 
         */
        const double& getValue() const
        {
            return _value;
        }
        /**
         * @brief 
         *
         * @return 
         */
        infinitesimal_reference getDerivative()
        {
            return _derivative;
        }
        /**
         * @brief 
         *
         * @return 
         */
        const_infinitesimal_reference getDerivative() const
        {
            return _derivative;
        }
    private:
        double _value;
        infinitesimal_type _derivative;
    };
} } // namespace algo { namespace ad {
