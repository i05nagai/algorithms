#pragma once
#include <boost/numeric/ublas/vector.hpp>

namespace algo { namespace nm {
    class ConvergenceUtil {
    //private typedef
    private:
    //public typedef
    public:
    //public function
    public:
        static bool isConvergence(
            const boost::numeric::ublas::vector<double>& residual,
            const double tolerance);
    //private function
    private:
    //private members
    private:
    }; // class ConvergenceUtil {
} } // namespace algo { namespace nm {

