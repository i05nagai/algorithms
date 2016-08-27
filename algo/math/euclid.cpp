#include "math/euclid.h"

namespace algo { namespace math {
    namespace ublas = boost::numeric::ublas;

    double calculateDistanceNormL2(
        const ublas::vector<double>& x1,
        const ublas::vector<double>& x2)
    {
        const double sum = math::calculateSumOfSquares(x2 - x1);
        return std::sqrt(sum);
    }

    double calculateNormL2(const ublas::vector<double>& x)
    {
        const double sum = math::calculateSumOfSquares(x);
        return std::sqrt(sum);
    }
} } // namespace algo { namespace math {

