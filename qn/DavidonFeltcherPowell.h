#pragma once
#include "utility/utility.h"
#include "quasi_newton/ILineSearcher.h"
#include "quasi_newton/IQuasiNewton.h"

namespace algo {
    namespace ublas = boost::numeric::ublas;

    /**
     * @brief 
     */
    class DavidonFeltcherPowell 
    : public utility::MixIn<IQuasiNewton, DavidonFeltcherPowell> {
    //private typedef
    private:
    //public typedef
    public:
        /**
         * @brief 
         */
        typedef std::function<double (
            const ublas::vector<double>& x)> function_type;
        /**
         * @brief 
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
        DavidonFeltcherPowell(
            const double epsilon, 
            const std::size_t maxIteration,
            const boost::shared_ptr<ILineSearcher> searcher);
    //private function
    private:
        /**
         * @brief 
         *
         * @param x0
         * @param f
         * @param gradf
         *
         * @return 
         */
        ublas::vector<double> doOperatorParenthesis(
            const ublas::vector<double>& x0,
            const function_type& f,
            const gradient_type& gradf);
        /**
         * @brief 
         *
         * @param x1
         * @param x2
         * @param df1
         * @param df2
         * @param H
         *
         * @return 
         */
        ublas::matrix<double> calculateInverseHessian(
            const ublas::vector<double>& x1,
            const ublas::vector<double>& x2,
            const ublas::vector<double>& df1,
            const ublas::vector<double>& df2,
            const ublas::matrix<double>& H);
        /**
         * @brief 
         *
         * @param x1
         * @param x2
         *
         * @return 
         */
        bool isConverge(
            const ublas::vector<double>& x1, 
            const ublas::vector<double>& x2);
    //private members
    private:
        const double _epsilon;
        const std::size_t _maxIteration;
        boost::shared_ptr<ILineSearcher> _searcher;
    }; // class DavidonFeltcherPowell : public IQuasiNewton {
} // namespace algo {
