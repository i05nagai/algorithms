#include "pre_compiled_header.h"
#include "qn/IQuasiNewton.h"

namespace algo { namespace qn {
    template <typename T>
    ublas::vector<double> IQuasiNewton<T>::operator()(
        const ublas::vector<double>& x0,
        const function_type& f,
        const boost::shared_ptr<ILineSearcher> searcher)
    {
        return this->doOperatorParenthesis(x0, f, searcher);
    }
} } // namespace algo { namespace qn {

namespace algo { namespace qn {
    typedef std::function<double (
        const ublas::vector<double>& x)> double_function_type;

    template
    ublas::vector<double> IQuasiNewton<double>::operator()(
        const ublas::vector<double>& x0,
        const double_function_type& f,
        const boost::shared_ptr<ILineSearcher> searcher);
} } // namespace algo { namespace qn {
