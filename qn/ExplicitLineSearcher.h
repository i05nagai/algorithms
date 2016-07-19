#pragma once
#include "utility/utility.h"
#include "quasi_newton/ILineSearcher.h"

namespace algo {
    /**
     * @brief 
     */
    class ExplicitLineSearcher 
    : public utility::MixIn<ILineSearcher, ExplicitLineSearcher> {
    //private typedef
    private:
        /**
         * @typedef type of explicit formula.
         */
        typedef std::function<ublas::vector<double> (
            const ublas::vector<double>& p,
            const ublas::vector<double>& x)> functor_type;
    //public typedef
    public:
    //public function
    public:
        /**
         * @brief Line search by using explicit formula.
         *
         * @param f explicit formula.
         */
        ExplicitLineSearcher(const functor_type& f);
    //private function
    private:
        ublas::vector<double> doOperatorParenthesis(
            const ublas::vector<double>& p,
            const ublas::vector<double>& x);
    //private members
    private:
        functor_type _f;
    }; // class ExplicitLineSearcher : public ILineSearcher {
} // namespace algo { 

