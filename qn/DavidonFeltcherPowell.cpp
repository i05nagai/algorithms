#include "pre_compiled_header.h"
#include "qn/DavidonFeltcherPowell.h"
#include "qn/ILineSearcher.h"
#include "qn/utility.h"
#include <boost/shared_ptr.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>

namespace algo { namespace qn {
    namespace ublas = boost::numeric::ublas;

    DavidonFeltcherPowell::DavidonFeltcherPowell(
        const double epsilon, 
        const std::size_t maxIteration,
        const boost::shared_ptr<ILineSearcher> searcher)
    : _epsilon(epsilon), _maxIteration(maxIteration), _searcher(searcher)
    {
    }

    ublas::vector<double> DavidonFeltcherPowell::doOperatorParenthesis(
        const ublas::vector<double>& x0,
        const function_type& f,
        const gradient_type& gradf)
    {
        //initialize
        ublas::vector<double> x1 = x0;
        ublas::matrix<double> H 
            = algo::qn::initilizeQuasiNewtonInverseHessian(x0.size());

        for (std::size_t i = 0; i < _maxIteration; ++i) {
            const auto& gradient = gradf(x1);
            const auto& p = -ublas::prod(H, gradient);
            const auto& x2 = (*_searcher)(p, x1);
            const auto& df1 = gradf(x1);
            const auto& df2 = gradf(x2);
            H = this->calculateInverseHessian(x1, x2, df1, df2, H);

            if (this->isConverge(x1, x2)) {
                return x2;
            }

            //preparation for next step
            x1 = x2;
        }

        return x1;
    }

    ublas::matrix<double> DavidonFeltcherPowell::calculateInverseHessian(
        const ublas::vector<double>& x1,
        const ublas::vector<double>& x2,
        const ublas::vector<double>& df1,
        const ublas::vector<double>& df2,
        const ublas::matrix<double>& H)
    {
        assert(H.size1() == H.size2());

        const auto& dx = x2 - x1;
        const auto& y = df2 - df1;
        const auto& Hy = ublas::prod<ublas::vector<double> >(H, y);
        const auto& Hyy = ublas::outer_prod(Hy, y);

        const auto& term1 = ublas::outer_prod(dx, dx) / ublas::inner_prod(dx, y);
        const auto& term2 = ublas::prod(Hyy, H) / ublas::inner_prod(y, Hy);

        return H + term1 - term2;
    }

    bool DavidonFeltcherPowell::isConverge(
        const ublas::vector<double>& x1, 
        const ublas::vector<double>& x2)
    {
        const double error = algo::qn::calculateNormL2(x1, x2);
        if (error < _epsilon) {
            return true;
        } else {
            return false;
        }
    }

} } // namespace algo { namespace qn {

