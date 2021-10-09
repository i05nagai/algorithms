#include "algo/nm/ConvergenceUtil.h"
#include "algo/math/euclid.h"

namespace algo { namespace nm {
    namespace ublas = boost::numeric::ublas;

    bool ConvergenceUtil::isConvergence(
       const ublas::vector<double>& residual,
       const double tolerance)
    {
        const double error = math::calculateNormL2(residual);
        if (error <  tolerance) {
            return true;
        } else {
            return false;
        }
    }
} } // namespace algo { namespace nm {
