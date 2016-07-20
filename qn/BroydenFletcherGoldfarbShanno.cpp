#include "pre_compiled_header.h"
#include "qn/BroydenFletcherGoldfarbShanno.h"
#include "qn/ILineSearcher.h"
#include "qn/utility.h"
#include "utility/debug_macro.h"
#include <boost/shared_ptr.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>

namespace algo { namespace qn {
    namespace ublas = boost::numeric::ublas;

    BroydenFletcherGoldfarbShanno::BroydenFletcherGoldfarbShanno(
        const double epsilon,
        const std::size_t maxIteration,
        const boost::shared_ptr<ILineSearcher> searcher)
    : _epsilon(epsilon), _maxIteration(maxIteration), _searcher(searcher)
    {
    }

    ublas::vector<double> BroydenFletcherGoldfarbShanno::doOperatorParenthesis(
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

    ublas::matrix<double> 
    BroydenFletcherGoldfarbShanno::calculateInverseHessian(
        const ublas::vector<double>& x1,
        const ublas::vector<double>& x2,
        const ublas::vector<double>& df1,
        const ublas::vector<double>& df2,
        const ublas::matrix<double>& H)
    {
        assert(H.size1() == H.size2());
        
        const auto& dx = x2 - x1;
        const auto& y = df2 - df1;
        const double scalar1 = ublas::inner_prod(y, dx);
        const double scalar2 = ublas::inner_prod(y, ublas::prod(H, y));
        const auto& matrix1 = ublas::outer_prod(dx, dx);
        const auto& term1 = ((scalar1 + scalar2) * matrix1) / (scalar1 * scalar1);

        const auto& matrix2 = ublas::outer_prod(y, dx);
        const auto& matrix3 = ublas::prod(H, matrix2);
        const auto& matrix4 = ublas::outer_prod(dx, y);
        const auto& matrix5 = ublas::prod(matrix4, H);
        const auto& term2 = (matrix3 + matrix5) / scalar1;

        return H + term1 - term2;
    }

    bool BroydenFletcherGoldfarbShanno::isConverge(
        const ublas::vector<double>& x1, 
        const ublas::vector<double>& x2)
    {
        const double error = algo::qn::calculateDistanceNormL2(x1, x2);
        if (error < _epsilon) {
            return true;
        } else {
            return false;
        }
    }

} } // namespace algo { namespace qn {

