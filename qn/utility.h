#pragma once

namespace algo {
    namespace ublas = boost::numeric::ublas;

    /**
     * @brief 
     *
     * @param size
     *
     * @return 
     */
    ublas::matrix<double> 
    initilizeQuasiNewtonHessian(const std::size_t size);

    /**
     * @brief 
     *
     * @param size
     *
     * @return 
     */
    ublas::matrix<double> 
    initilizeQuasiNewtonInverseHessian(const std::size_t size);

    /**
     * @brief calculate square of euclidean norm.
     *
     * @param x1 point.
     * @param x2 point.
     *
     * @return square of euclidean norm.
     */
    double calculateSumOfSquares(
        const ublas::vector<double>& x1,
        const ublas::vector<double>& x2);

    /**
     * @brief calculates euclidean norm.
     *
     * @param x1 point.
     * @param x2 point.
     *
     * @return euclidean norm.
     */
    double calculateNormL2(
        const ublas::vector<double>& x1,
        const ublas::vector<double>& x2);
} // namespace algo

