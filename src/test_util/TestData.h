#pragma once
#include "algo/test_util/RandomNumber.h"
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <cassert>

namespace algo { namespace test_util {
    /**
     * @brief Common test data. Only random valued data is acceptable.
     */
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
         * @param size
         *
         * @return 
         */
        static
        boost::numeric::ublas::vector<double> 
        getRandomNumbers(const std::size_t size)
        {
            namespace ublas = boost::numeric::ublas;
            static test_util::RandomNumber generator;

            ublas::vector<double> x(size);
            std::generate(x.begin(), x.end(), generator);
            return x;
        }
        /**
         * @brief 
         *
         * @param rowSize
         * @param colSize
         *
         * @return 
         */
        static
        boost::numeric::ublas::matrix<double>
        getRandomMatrix(const std::size_t rowSize, const std::size_t colSize)
        {
            namespace ublas = boost::numeric::ublas;
            ublas::vector<double> data
                = TestData::getRandomNumbers(rowSize * colSize);

            ublas::matrix<double> matrix(rowSize, colSize);
            for (std::size_t ri = 0; ri < matrix.size1(); ++ri) {
                for (std::size_t ci = 0; ci < matrix.size2(); ++ci) {
                    matrix(ri, ci) = data(rowSize * ri + ci);
                }
            }
            return matrix;
        }
    //private function
    private:
    //private members
    private:
    }; // class TestData {
} } // namespace algo { namespace test_util {
