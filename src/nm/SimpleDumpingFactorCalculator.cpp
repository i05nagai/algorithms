#include "algo/nm/SimpleDumpingFactorCalculator.h"
#include "algo/math/euclid.h"

namespace algo { namespace nm {
    namespace ublas = boost::numeric::ublas;

    SimpleDumpingFactorCalculator::SimpleDumpingFactorCalculator(
        const double alpha,
        const double beta)
    : _alpha(alpha),
        _beta(beta)
    {
    }

    double SimpleDumpingFactorCalculator::doOperatorParenthesis(
        const ublas::vector<double>& residual,
        const ublas::matrix<double>& jacobianMatrix) const
    {
        const double error = math::calculateNormL2(residual);
        return _alpha * std::min(error, _beta);
    }
} } // namespace algo { namespace nm {
