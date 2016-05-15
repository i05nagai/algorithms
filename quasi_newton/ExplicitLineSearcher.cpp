#include "quasi_newton/pre_compiled_header.h"
#include "quasi_newton/ExplicitLineSearcher.h"

namespace algo {
    ExplicitLineSearcher::ExplicitLineSearcher(const functor_type& f)
    : _f(f)
    {
    }

    //min f(x + ap)
    ublas::vector<double> ExplicitLineSearcher::doOperatorParenthesis(
        const ublas::vector<double>& p,
        const ublas::vector<double>& x)
    {
        return _f(p, x);
    }

} // namespace algo {
