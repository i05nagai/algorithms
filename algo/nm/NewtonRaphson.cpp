#include "nm/NewtonRaphson.h"
#include "utility/matrix_operator.h"
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_expression.hpp>

namespace algo { namespace nm {
    namespace ublas = boost::numeric::ublas;

    NewtonRaphson::NewtonRaphson(
        const typename INewtonMethod::function_type& f,
        const typename INewtonMethod::derivative_type& derivative,
        const std::size_t maxIteration)
    : _f(f), _derivative(derivative), _maxIteration(maxIteration)
    {
    }

    ublas::vector<double> NewtonRaphson::doSolve(
        const ublas::vector<double>& x0) const
    {
        ublas::vector<double> x1 = x0;
        ublas::matrix<double> inverseJacobianMatrix(x1.size(), x1.size());

        for (std::size_t i = 0; i < _maxIteration; ++i) {
            const ublas::vector<double>& y = _f(x1);
            const ublas::matrix<double>& jacobianMatrix = _derivative(x1);
            const bool isSuccess 
                = utility::invert(jacobianMatrix, inverseJacobianMatrix);
            if (isSuccess) {
            }
            x1 = x1 - ublas::prod(inverseJacobianMatrix, y);
        }
        return x1;
    }
} } // namespace algo { namespace nm {
