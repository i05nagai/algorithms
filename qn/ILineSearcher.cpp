#include "quasi_newton/pre_compiled_header.h"
#include "quasi_newton/ILineSearcher.h"

namespace algo {
    namespace ublas = boost::numeric::ublas;

    ublas::vector<double> ILineSearcher::operator()(
        const ublas::vector<double>& p,
        const ublas::vector<double>& x)
    {
        return this->doOperatorParenthesis(p, x);
    }
} // namespace algo {
