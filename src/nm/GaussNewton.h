#pragma once
#include "algo/nm/INewtonMethod.h"
#include "algo/util/MixIn.h"
#include <boost/numeric/ublas/vector.hpp>

namespace algo { namespace nm {
    class GaussNewton : public util::MixIn<INewtonMethod, GaussNewton> {
    //private typedef
    private:
    //public typedef
    public:
    //public function
    public:
        GaussNewton(
            typename INewtonMethod::function_type& f,
            typename INewtonMethod::derivative_type& derivative,
            const std::size_t maxIteration,
            const double tolerance);
        GaussNewton(const GaussNewton& other);
    //private function
    private:
        virtual boost::numeric::ublas::vector<double> 
        doSolve(const boost::numeric::ublas::vector<double>& x0) const override;
        bool isConvergence(
            const boost::numeric::ublas::vector<double>& residual) const; 
    //private members
    private:
        typename INewtonMethod::function_type _f;
        typename INewtonMethod::derivative_type _derivative;
        const std::size_t _maxIteration;
        const double _tolerance;
    }; // class GaussNewton : public util::MixIn<INewtonMethod, GaussNewton> {
} } // namespace algo { namespace nm {
