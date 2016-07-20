#include "pre_compiled_header.h"
#include "qn/IQuasiNewton.h"

namespace algo { namespace qn {
    ublas::vector<double> IQuasiNewton::operator()(
        const ublas::vector<double>& x0,
        const function_type& f,
        const gradient_type& gradf)
    {
        return this->doOperatorParenthesis(x0, f, gradf);
    }
} } // namespace algo { namespace qn {
