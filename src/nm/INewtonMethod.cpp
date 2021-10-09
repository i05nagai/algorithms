#include "algo/nm/INewtonMethod.h"
#include <boost/numeric/ublas/vector.hpp>
#include <functional>

namespace algo { namespace nm {
    namespace ublas = boost::numeric::ublas;

    ublas::vector<double> 
    INewtonMethod::solve(const ublas::vector<double>& x0) const
    {
        return this->doSolve(x0);
    }
} } // namespace algo { namespace nm {
