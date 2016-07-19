#include "quasi_newton/pre_compiled_header.h"
#include "quasi_newton/utility.h"

namespace algo {
    namespace ublas = boost::numeric::ublas;

    ublas::matrix<double> initilizeQuasiNewtonHessian(const std::size_t size)
    {
        return ublas::identity_matrix<double>(size);
    }

    ublas::matrix<double> initilizeQuasiNewtonInverseHessian(
        const std::size_t size)
    {
        return ublas::identity_matrix<double>(size);
    }

    double calculateSumOfSquares(
        const ublas::vector<double>& x1,
        const ublas::vector<double>& x2)
    {
        double sum = 0.0;
        for (std::size_t i = 0; i < x1.size(); ++i) {
            sum += (x1(i) - x2(i)) * (x1(i) - x2(i));
        }
        return sum;
    }

    double calculateNormL2(
        const ublas::vector<double>& x1,
        const ublas::vector<double>& x2)
    {
        const double sum = algo::calculateSumOfSquares(x1, x2);
        return std::sqrt(sum);
    }
} // namespace algo

