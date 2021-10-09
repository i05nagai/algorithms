#pragma once
#include "algo/nm/IDumpingFactorCalculator.h"
#include "algo/util/MixIn.h"

namespace algo { namespace nm {
    class SimpleDumpingFactorCalculator 
    : public util::MixIn<
        IDumpingFactorCalculator, SimpleDumpingFactorCalculator> {
    //private typedef
    private:
    //public typedef
    public:
    //public function
    public:
        SimpleDumpingFactorCalculator(
            const double alpha, const double beta);
    //private function
    private:
        virtual double doOperatorParenthesis(
            const boost::numeric::ublas::vector<double>& residual,
            const boost::numeric::ublas::matrix<double>& jacobianMatrix
        ) const override;
    //private members
    private:
        double _alpha;
        double _beta;
    }; // class SimpleDumpingFactorCalculator : public util::MixIn<IDumpingFactorCalculator, SimpleDumpingFactorCalculator> {
} } // namespace algo { namespace nm {
