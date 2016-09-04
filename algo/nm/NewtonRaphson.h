#pragma once
#include "algo/nm/INewtonMethod.h"
#include "algo/utility/MixIn.h"
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>

namespace algo { namespace nm_test {
    class NewtonRaphsonTest;
} } // namespace algo { namespace nm_test {

namespace algo { namespace nm {
    class NewtonRaphson : public utility::MixIn<INewtonMethod, NewtonRaphson>  {
        friend class nm_test::NewtonRaphsonTest;
    //private typedef
    private:
    //public typedef
    public:
    //public function
    public:
        NewtonRaphson(
            const typename INewtonMethod::function_type& f,
            const typename INewtonMethod::derivative_type& derivative,
            const std::size_t maxIteration,
            const double tolerance);
    //private function
    private:
        virtual boost::numeric::ublas::vector<double> doSolve(
            const boost::numeric::ublas::vector<double>& x0) const;
        bool isConvergence(
            const boost::numeric::ublas::vector<double>& x1,
            const boost::numeric::ublas::vector<double>& x2) const;
    //private members
    private:
        typename INewtonMethod::function_type _f; 
        typename INewtonMethod::derivative_type _derivative; 
        const std::size_t _maxIteration;
        const double _tolerance;
    }; // class NewtonRaphson : public utilty::MixIn<INewtonMethod, NewtonRaphson>  {
} } // namespace algo { namespace nm {
