#pragma once
#include "algo/ad/dual.hpp"
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>

namespace algo { namespace ad_test {
    class TestUtil {
    //private typedef
    private:
    //public typedef
    public:
    //public function
    public:
        /**
         * @brief 
         *
         * @param vectorDualScalarDerivative
         *
         * @return 
         */
        static 
        boost::numeric::ublas::vector<double> 
        getValueFromVectorDualScalarDerivative(
            const boost::numeric::ublas::vector<
                ad::dual<double>>& 
                    vectorDualScalarDerivative);
        /**
         * @brief 
         *
         * @param vectorDualVectorDerivative
         *
         * @return 
         */
        static 
        boost::numeric::ublas::vector<double> 
        getValueFromVectorDualVectorDerivative(
            const boost::numeric::ublas::vector<
                ad::dual<boost::numeric::ublas::vector<double>>>& 
                    vectorDualVectorDerivative);
        /**
         * @brief 
         *
         * @param vectorDualScalarDerivative
         *
         * @return 
         */
        static 
        boost::numeric::ublas::vector<double> 
        getDerivativeFromVectorValueScalarDerivative(
            const boost::numeric::ublas::vector<ad::dual<double>>&
                vectorDualScalarDerivative);
        /**
         * @brief 
         *
         * @param vectorDualVectorDerivative
         *
         * @return 
         */
        static 
        boost::numeric::ublas::matrix<double> 
        getDerivativeFromVectorValueVectorDerivative(
            const boost::numeric::ublas::vector<
                ad::dual<boost::numeric::ublas::vector<double>>>&
                    vectorDualVectorDerivative);
    //private function
    private:
    //private members
    private:
    }; // class TestUtil {
} } // namespace algo { namespace ad_test {
