#pragma once
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <cassert>

namespace algo { namespace nm_test {
    class TestData {
    //private typedef
    private:
    //public typedef
    public:
    //public function
    public:
        /**
         * @brief 
         *
         * @return 
         */
        static
        std::function<
            boost::numeric::ublas::vector<double>
                (const boost::numeric::ublas::vector<double>& x)>
        getMultiValuedSeveralVariablesFunction0();
        /**
         * @brief 
         *
         * @return 
         */
        static
        std::function<
            boost::numeric::ublas::matrix<double>
                (const boost::numeric::ublas::vector<double>& x)>
        getMatrixValuedSeveralVariablesDerivative0();
        /**
         * @brief 
         *
         * @return 
         */
        static
        boost::numeric::ublas::vector<double> 
        getVector0();
        /**
         * @brief 
         *
         * @return 
         */
        static
        boost::numeric::ublas::matrix<double>
        getRandomMatrix0();
    //private function
    private:
    //private members
    private:
    }; // class TestData {
} } // namespace algo { namespace nm_test {
