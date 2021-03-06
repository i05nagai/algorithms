#include "algo/nm/NewtonRaphson.h"
#include "algo/util/matrix_operator.h"
#include "algo/util/debug_macro.h"
#include "algo/math/euclid.h"
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_expression.hpp>

namespace algo { namespace nm {
    namespace ublas = boost::numeric::ublas;

    NewtonRaphson::NewtonRaphson(
        const typename INewtonMethod::function_type& f,
        const typename INewtonMethod::derivative_type& derivative,
        const std::size_t maxIteration,
        const double tolerance)
    : _f(f), _derivative(derivative), _maxIteration(maxIteration),
        _tolerance(tolerance)
    {
    }

    ublas::vector<double> NewtonRaphson::doSolve(
        const ublas::vector<double>& x0) const
    {
        ublas::vector<double> x = x0;
        ublas::vector<double> y = _f(x);
        ublas::matrix<double> inverseJacobianMatrix(x.size(), x.size());

        for (std::size_t i = 0; i < _maxIteration; ++i) {
            const ublas::matrix<double>& jacobianMatrix = _derivative(x);
            const bool isSuccess 
                = util::invert(jacobianMatrix, inverseJacobianMatrix);
            if (!isSuccess) {
                //TODO:error.
            }
            //update
            x = x - ublas::prod(inverseJacobianMatrix, y);
            //error
            const ublas::vector<double>& nextY = _f(x);
            if (isConvergence(y, nextY)) {
                return x;
            }
            //for next step
            y = nextY;
        }
        return x;
    }

    bool NewtonRaphson::isConvergence(
        const ublas::vector<double>& value,
        const ublas::vector<double>& nextValue) const
    {
        const double error = math::calculateDistanceNormL2(value, nextValue);
        return error < _tolerance;
    }
} } // namespace algo { namespace nm {

