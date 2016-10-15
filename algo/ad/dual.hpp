/**
 * @file dual.hpp
 * @brief 
 * @author i05nagai
 * @version 0.0.2
 * @date 2016-10-04
 */
#pragma once
#include "algo/ad/dual_expression.hpp"
#include <boost/numeric/ublas/vector.hpp>

namespace algo { namespace ad {
    /**
     * @brief 
     *
     * @tparam Derivative
     */
    template <typename Derivative = boost::numeric::ublas::vector<double>>
    class dual : public dual_expression<dual<Derivative>> {
    private:
        typedef dual<Derivative> self_type;
    public:
        //closure
        typedef const self_type& const_closure_type;
        typedef Derivative derivative_type;

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
        : _value(ae().getValue()), 
            _derivative(ae().getDerivative())
        {
        }
        /**
         * @brief 
         *
         * @param value
         */
        dual(const double value) 
        : _value(value), _derivative(0)
        {
        }
        /**
         * @brief 
         *
         * @TODO need to check inf_type is same size.
         *
         * @param v
         * @param d
         */
        dual(
            const double v, 
            const Derivative& d) 
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
        Derivative& getDerivative()
        {
            return _derivative;
        }
        /**
         * @brief 
         *
         * @return 
         */
        const Derivative& getDerivative() const
        {
            return _derivative;
        }
    private:
        double _value;
        Derivative _derivative;
    };
} } // namespace algo { namespace ad {
