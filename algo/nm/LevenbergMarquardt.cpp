#include "algo/nm/LevenbergMarquardt.h"
#include "algo/nm/ConvergenceUtil.h"
#include "algo/math/euclid.h"
#include "algo/utility/matrix_operator.h"
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/banded.hpp>
#include <memory>

namespace algo { namespace nm {
    namespace ublas = boost::numeric::ublas;

    LevenbergMarquardt::LevenbergMarquardt(
        const typename INewtonMethod::function_type& f,
        const typename INewtonMethod::derivative_type& derivative,
        const std::size_t maxIteration,
        const double tolerance,
        const std::shared_ptr<IDumpingFactorCalculator>& dumpingFactorCalculator)
    : _f(f),
        _derivative(derivative),
        _maxIteration(maxIteration),
        _tolerance(tolerance),
        _dumpingFactorCalculator(dumpingFactorCalculator->clone())
    {
    }

    ublas::vector<double>
    LevenbergMarquardt::doSolve(
        const ublas::vector<double>& initialValue) const
    {
        const std::size_t size = initialValue.size();
        ublas::vector<double> x = initialValue;
        ublas::matrix<double> inverseMatrix(size, size);
        for (std::size_t i = 0; i < _maxIteration; ++i) {
            const ublas::vector<double> updateVector 
                = this->calculateUpdateVector(x, inverseMatrix);
            if (ConvergenceUtil::isConvergence(x, _tolerance)) {
                return x;
            }

            //prepare to next step
            x = x - updateVector;
            inverseMatrix.clear();
        }
        return x;
    }

    ublas::vector<double>
    LevenbergMarquardt::calculateUpdateVector(
        const ublas::vector<double>& x,
        ublas::matrix<double>& inverseMatrix) const
    {
        const ublas::vector<double> residual = _f(x);
        const ublas::matrix<double> jacobianMatrix = _derivative(x);
        this->calculateInverseMatrix(
            residual, jacobianMatrix, inverseMatrix);
        const ublas::vector<double> tempVector1
            = ublas::prod(ublas::trans(jacobianMatrix), residual);
        const ublas::vector<double> updateVector
            = ublas::prod(inverseMatrix, tempVector1);
        return updateVector;
    }        

    void LevenbergMarquardt::calculateInverseMatrix(
        const ublas::vector<double>& residual,
        const ublas::matrix<double>& jacobianMatrix,
        ublas::matrix<double>& inverseMatrix) const
    {
        //symetric
        const ublas::matrix<double> tempMatrix1
            = ublas::prod(ublas::trans(jacobianMatrix), jacobianMatrix);
        const ublas::banded_adaptor<const ublas::matrix<double>> 
            diagonalMatrix(tempMatrix1);
        const double dumpingFactor 
            = (*_dumpingFactorCalculator)(residual, jacobianMatrix);
        const ublas::matrix<double> tempMatrix2
            = tempMatrix1 + dumpingFactor * diagonalMatrix;
        const bool isSuccess = utility::invert(tempMatrix2, inverseMatrix);
            
        if (!isSuccess) {
            //TODO:error
        }
    }
} } // namespace algo { namespace nm {

