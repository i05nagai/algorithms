#pragma once
#include "algo/nm/INewtonMethod.h"
#include "algo/nm/IDumpingFactorCalculator.h"
#include "algo/utility/MixIn.h"
#include <memory>

namespace algo { namespace nm_test {
    class LevenbergMarquardtTest;
} } // namespace algo { namespace nm_test {

namespace algo { namespace nm {
    /**
     * @brief This class solves following equation.
     * $$
     *  \| f(x) \|^{2} = 0
     * $$
     * 
     * Levenberg Marquardt method updates $x$ by the following equation each iteration.
     * $$
     *  x = x - (J_{f}^{T}(x)J_{f}(x) + \mathrm{diag}(J_{f}^{T}(x)J_{f}(x)))^{-1}J_{f}^{T}(x) f(x)
     * $$
     */
    class LevenbergMarquardt 
    : public utility::MixIn<INewtonMethod, LevenbergMarquardt> {
        friend class nm_test::LevenbergMarquardtTest;
    //private typedef
    private:
    //public typedef
    public:
    //public function
    public:
        /**
         * @brief 
         *
         * @param f     $f:\mathbb{R}^{N} \rightarrow \mathbb{R}^{M}$
         * @param derivative    Derivative of $f$. That is jacobian matrix$J_{f}(\cdot)$.
         * @param maxIteration  Maximum number of iteration.
         * @param tolerance Tolerance of convergence.
         * @param lambda    Initial value of damping factor.
         */
        LevenbergMarquardt(
            const typename INewtonMethod::function_type& f,
            const typename INewtonMethod::derivative_type& derivative,
            const std::size_t maxIteration,
            const double tolerance,
            const std::shared_ptr<IDumpingFactorCalculator>& 
                dumpingFactorCalculator);
    //private function
    private:
        /**
         * @brief 
         *
         * @param   initialValue initial guess of this algorithm
         *
         * @return  $x$ such that $\| f(x) \| = 0$
         */
        virtual boost::numeric::ublas::vector<double> 
        doSolve(
            const boost::numeric::ublas::vector<double>& initialValue) const override;
        /**
         * @brief 
         *
         * @param inverseMatrix cache to save memory allocaiton cost.
         *
         * @return 
         */
        boost::numeric::ublas::vector<double>
        calculateUpdateVector(
            const boost::numeric::ublas::vector<double>& x,
            boost::numeric::ublas::matrix<double>& inverseMatrix) const;
        /**
         * @brief 
         *
         * @param residual
         * @param jacobianMatrix
         * @param inverseMatrix
         */
        void calculateInverseMatrix(
            const boost::numeric::ublas::vector<double>& residual,
            const boost::numeric::ublas::matrix<double>& jacobianMatrix,
            boost::numeric::ublas::matrix<double>& inverseMatrix) const;
    //private members
    private:
        typename INewtonMethod::function_type _f;
        typename INewtonMethod::derivative_type _derivative;
        const std::size_t _maxIteration;
        const double _tolerance;
        std::shared_ptr<IDumpingFactorCalculator> _dumpingFactorCalculator;
    }; // class LevenbergMarquardt : public utility::MixIn<INewtonMethod, LevenbergMarquardt> {
} } // namespace algo { namespace nm {
