#pragma once
#include "utility/utility.h"
#include <boost/numeric/ublas/vector.hpp>

namespace algo {
    namespace ublas = boost::numeric::ublas;

    class IQuasiNewton : public utility::Object<IQuasiNewton> {
    //private typedef
    private:
    //public typedef
    public:
        typedef std::function<double (
            const ublas::vector<double>& x)> function_type;
        typedef std::function<ublas::vector<double> (
            const ublas::vector<double>& x)> gradient_type;
    //public function
    public:
        virtual ~IQuasiNewton() {}
        /**
         * @brief solve $\\mathrm{argmin}_{x}f(x)
         *
         * @param x0 initial value.
         * @param f objective funciton.
         * @param gradf gradient of objective funciton.
         *
         * @return objective value if it exists.
         */
        ublas::vector<double> operator()(
            const ublas::vector<double>& x0,
            const function_type& f,
            const gradient_type& gradf);
    //private function
    private:
        virtual ublas::vector<double> doOperatorParenthesis(
            const ublas::vector<double>& x0,
            const function_type& f,
            const gradient_type& gradf) = 0;
    //private members
    private:
    }; // class IQuasiNewton {
} // namespace algo { 
