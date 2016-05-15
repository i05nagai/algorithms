#pragma once
#include "quasi_newton/pre_compiled_header.h"
#include "quasi_newton/IQuasiNewton.h"
#include "quasi_newton/ILineSearcher.h"
#include "quasi_newton/utility.h"
#include "utility/utility.h"

namespace algo {
    namespace ublas = boost::numeric::ublas;

    /**
     * @class BroydenFletcherGoldfarbShanno
     */
    class BroydenFletcherGoldfarbShanno 
    : public utility::MixIn<IQuasiNewton, BroydenFletcherGoldfarbShanno> {
    //private typedef
    private:
    //public typedef
    public:
        /**
         * @typedef 
         */
        typedef std::function<double (
            const ublas::vector<double>& x)> function_type;
        /**
         * @typedef 
         */
        typedef std::function<ublas::vector<double> (
            const ublas::vector<double>& x)> gradient_type;
    //public function
    public:
        /**
         * @brief 
         *
         * @param epsilon algorithm is converged if error is less 
         *  than epsilon.
         * @param maxIteration algorithm is iterated until 
         *  converged or number of maxInteration.
         * @param searcher Line searcher.
         */
        BroydenFletcherGoldfarbShanno(
            const double epsilon,
            const std::size_t maxIteration,
            const boost::shared_ptr<ILineSearcher> searcher);
    //private function
    private:
        ublas::vector<double> doOperatorParenthesis(
            const ublas::vector<double>& x0,
            const function_type& f,
            const gradient_type& gradf);
        /**
         * @brief calculates inverse hessian by follwoing formula:
         * $$
         * B_{k+1}^{-1} := \\left(I - \\frac{dx_{k} y_{k}^{T}}{y_{k}^{T}dx_{k}} \\right) B_{k}^{-1} \\left( I - \\frac{y_{k}dx_{k}^{T}}{y_{k}^{T}dx_{k}}\\right) + \\frac{dx_{k}dx^{T}}{y_{k}^{T}s_{k}}.
         * $$
         * Here $B_{k}$ is $k$-th hessian, $dx_{k} := x_{k+1} - x_{k}$, $I$ is identity matrix, $y_{k} := df_{k+1} - df_{k}.$
         * Following formula is derived from above equation.
         * $$
         * B_{k+1}^{-1} = \\frac{B_{k}^{-1} + (dx_{k}^{T}y_{k} + y_{k}^{T}B_{k}^{-1}y_{k})(dx_{k}dx_{k}^{T})}{(dx_{k}^{T}y_{k})^{2}} - \\frac{B_{k}^{-1}y_{k}dx_{k}^{T} + dx_{k}y_{k}^{T}B_{k}^{-1}}{dx_{k}^{T}y_{k}}.
         * $$
         * @todo check the first equation is correct or not.
         *
         * @param x1 previous value.
         * @param x2 current value.
         * @param df1 
         * @param df2 
         * @param H previous inverse hessian.
         *
         * @return inverse hessian.
         */
        ublas::matrix<double> calculateInverseHessian(
            const ublas::vector<double>& x1,
            const ublas::vector<double>& x2,
            const ublas::vector<double>& df1,
            const ublas::vector<double>& df2,
            const ublas::matrix<double>& H);
        /**
         * @brief Check whether algorithm is converged or not.
         *
         * @param x1 previous value.
         * @param x2 current value.
         *
         * @return true if algorithm is converged.
         */
        bool isConverge(
            const ublas::vector<double>& x1,
            const ublas::vector<double>& x2);
    //private members
    private:
        const double _epsilon;
        const std::size_t _maxIteration;
        boost::shared_ptr<ILineSearcher> _searcher;
    }; // class BroydenFletcherGoldfarbShanno : public IQuasiNewton {
} // namespace algo {

