#pragma once
#include "nm/INewtonMethod.h"
#include "utility/MixIn.h"
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>

namespace algo { namespace nm {
    class NewtonRaphson : public utility::MixIn<INewtonMethod, NewtonRaphson>  {
    //private typedef
    private:
    //public typedef
    public:
    //public function
    public:
        NewtonRaphson(
            const typename INewtonMethod::function_type& f,
            const typename INewtonMethod::derivative_type& derivative,
            const std::size_t maxIteration);
    //private function
    private:
        virtual boost::numeric::ublas::vector<double> doSolve(
            const boost::numeric::ublas::vector<double>& x0) const override;
    //private members
    private:
        typename INewtonMethod::function_type _f; 
        typename INewtonMethod::derivative_type _derivative; 
        const std::size_t _maxIteration;
    }; // class NewtonRaphson : public utilty::MixIn<INewtonMethod, NewtonRaphson>  {
} } // namespace algo { namespace nm {
