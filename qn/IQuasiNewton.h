/**
 * @file IQuasiNewton.h
 * @brief 
 * @author i05nagai
 * @version 0.0.1
 * @date 2016-07-20
 */

#pragma once
#include "qn/ILineSearcher.h"
#include "utility/utility.h"
#include <boost/numeric/ublas/vector.hpp>

namespace algo { namespace qn {
    namespace ublas = boost::numeric::ublas;

    /**
     * @brief 
     */
    template <typename T>
    class IQuasiNewton : public utility::Object<IQuasiNewton<T> > {
    //private typedef
    private:
    //public typedef
    public:
        typedef std::function<T (
            const ublas::vector<T>& x)> function_type;
    //public function
    public:
        virtual ~IQuasiNewton() {}
        /**
         * @brief solve $\\mathrm{argmin}_{x}f(x)
         *
         * @param x0 initial value.
         * @param f objective funciton.
         *
         * @return objective value if it exists.
         */
        ublas::vector<double> operator()(
            const ublas::vector<double>& x0,
            const function_type& f,
            const boost::shared_ptr<ILineSearcher> searcher);
    //private function
    private:
        virtual ublas::vector<double> doOperatorParenthesis(
            const ublas::vector<double>& x0,
            const function_type& f,
            const boost::shared_ptr<ILineSearcher> searcher) = 0;
    //private members
    private:
    }; // class IQuasiNewton {
} } // namespace algo { namespace qn {
 
