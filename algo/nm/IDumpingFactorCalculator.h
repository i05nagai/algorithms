#pragma once
#include "algo/util/Object.h"
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>

namespace algo { namespace nm {
    class IDumpingFactorCalculator 
    : public util::Object<IDumpingFactorCalculator> {
    //private typedef
    private:
    //public typedef
    public:
    //public function
    public:
        double operator()(
            const boost::numeric::ublas::vector<double>& residual,
            const boost::numeric::ublas::matrix<double>& jacobianMatrix) const;
    //private function
    private:
        virtual double doOperatorParenthesis(
            const boost::numeric::ublas::vector<double>& residual,
            const boost::numeric::ublas::matrix<double>& jacobianMatrix) const = 0;
    //private members
    private:
    }; // class IDumpingFactorCalculator : public util::Object<IDumpingFactorCalculator {
} } // namespace algo { namespace nm {
