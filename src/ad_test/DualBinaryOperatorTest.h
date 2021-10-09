#pragma once
#include "algo/ad/dual.hpp"
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <gtest/gtest.h>	

namespace algo { namespace ad_test {
    class DualBinaryOperatorTest : public ::testing::Test {
    private:
        typedef ad::dual<double> 
            scalar_dual_scalar_derivative_type;
        typedef ad::dual<boost::numeric::ublas::vector<double>> 
            scalar_dual_vector_derivative_type;
        typedef boost::numeric::ublas::vector<scalar_dual_scalar_derivative_type>
            vector_dual_scalar_derivative_type;
        typedef boost::numeric::ublas::vector<scalar_dual_vector_derivative_type>
            vector_dual_vector_derivative_type;
    protected:
        //set-up
        DualBinaryOperatorTest();
        //clean-up does not throw exceptions
        virtual ~DualBinaryOperatorTest();
        //called before every test immediately after constructor
        virtual void SetUp();
        //called after every test before destructor
        virtual void TearDown();
    protected:
        //value
        double _value1;
        double _value2;
        boost::numeric::ublas::vector<double> _vectorValue1;
        boost::numeric::ublas::vector<double> _vectorValue2;
        //derivative
        double _scalarDerivative1;
        double _scalarDerivative2;
        boost::numeric::ublas::vector<double> _vectorDerivative1;
        boost::numeric::ublas::vector<double> _vectorDerivative2;
        //derivative for vectorDual
        boost::numeric::ublas::vector<double> _vectorValueScalarDerivative1;
        boost::numeric::ublas::vector<double> _vectorValueScalarDerivative2;
        boost::numeric::ublas::matrix<double> _vectorValueVectorDerivative1;
        boost::numeric::ublas::matrix<double> _vectorValueVectorDerivative2;
        //dual
        scalar_dual_scalar_derivative_type _scalarDualScalarDerivative1;
        scalar_dual_scalar_derivative_type _scalarDualScalarDerivative2;
        scalar_dual_vector_derivative_type _scalarDualVectorDerivative1;
        scalar_dual_vector_derivative_type _scalarDualVectorDerivative2;
        vector_dual_scalar_derivative_type _vectorDualScalarDerivative1;
        vector_dual_scalar_derivative_type _vectorDualScalarDerivative2;
        vector_dual_vector_derivative_type _vectorDualVectorDerivative1;
        vector_dual_vector_derivative_type _vectorDualVectorDerivative2;
    }; // class DualBinaryOperatorTest : public ::testing::Test {
} } // namespace algo { namespace ad_test {
