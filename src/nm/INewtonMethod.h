#pragma once
#include "algo/util/Object.h"
#include <functional>
#include <boost/numeric/ublas/vector.hpp>

namespace algo { namespace nm {
    class INewtonMethod : public util::Object<INewtonMethod> {
    //private typedef
    private:
    //public typedef
    public:
        /**
         * @brief In newton method, dimension of domain and dimension of region must be same.
         */
        typedef std::function<
            boost::numeric::ublas::vector<double> 
                (const boost::numeric::ublas::vector<double>& x)> 
                    function_type;
        /**
         * @brief In newton method, matrix must be square matrix.
         */
        typedef std::function<
            boost::numeric::ublas::matrix<double> 
                (const boost::numeric::ublas::vector<double>& x)> 
                    derivative_type;
    //public function
    public:
        virtual ~INewtonMethod(){}
        boost::numeric::ublas::vector<double> solve(
            const boost::numeric::ublas::vector<double>& x0) const;
    //private function
    private:
        virtual boost::numeric::ublas::vector<double> doSolve(
            const boost::numeric::ublas::vector<double>& x0) const = 0;
    //private members
    private:
    }; // class INewtonMethod : public util::Object<INewtonMethod> {
} } // namespace algo { namespace nm {
