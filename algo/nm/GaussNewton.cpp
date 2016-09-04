#include "algo/nm/GaussNewton.h"
#include "algo/math/euclid.h"
#include "algo/util/matrix_operator.h"
#include <boost/numeric/ublas/matrix.hpp>

namespace algo { namespace nm {
    namespace ublas = boost::numeric::ublas;

    GaussNewton::GaussNewton(
        typename INewtonMethod::function_type& f,
        typename INewtonMethod::derivative_type& derivative,
        const std::size_t maxIteration,
        const double tolerance)
    : _f(f), _derivative(derivative), _maxIteration(maxIteration), 
        _tolerance(tolerance)
    {
    }

    GaussNewton::GaussNewton(const GaussNewton& other)
    : _f(other._f),
        _derivative(other._derivative),
        _maxIteration(other._maxIteration),
        _tolerance(other._tolerance)
    {
    }

    ublas::vector<double> 
    GaussNewton::doSolve(const ublas::vector<double>& x0) const
    {
        const std::size_t size = x0.size();
        ublas::vector<double> x = x0;
        ublas::matrix<double> inverseMatrix(size, size);
        for (std::size_t i = 0; i < _maxIteration; ++i) {
            const ublas::vector<double> residual = _f(x);
            const ublas::matrix<double> jacobianMatrix = _derivative(x);
            const ublas::matrix<double> tempMatrix 
                = ublas::prod(ublas::trans(jacobianMatrix), jacobianMatrix);
            const bool isSuccess 
                = util::invert(tempMatrix, inverseMatrix);
            const ublas::vector<double> tempVector1 
                = ublas::prod(ublas::trans(jacobianMatrix), residual);
            const ublas::vector<double> tempVector2
                = ublas::prod(inverseMatrix, tempVector1);

            //update 
            x = x - tempVector2;
            if (this->isConvergence(residual)) {
                return x;
            }
        }
        return x;
    }

    bool GaussNewton::isConvergence(const ublas::vector<double>& x) const
    {
        const double error = math::calculateNormL2(x);
        if (error < _tolerance) {
            return true;
        } else {
            return false;
        }
    }
} } // namespace algo { namespace nm {
