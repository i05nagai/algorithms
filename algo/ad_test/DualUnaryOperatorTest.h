#pragma once
#include "algo/ad/dual.hpp"
#include "algo/ad/dual_unary_operator.hpp"
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <gtest/gtest.h>	

namespace algo { namespace ad_test {
    class DualUnaryOperatorTest : public ::testing::Test {
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
        DualUnaryOperatorTest();
        //clean-up does not throw exceptions
        virtual ~DualUnaryOperatorTest();
        //called before every test immediately after constructor
        virtual void SetUp();
        //called after every test before destructor
        virtual void TearDown();
    protected: 
        //value
        double _value;
        boost::numeric::ublas::vector<double> _vectorValue;
        //derivative
        double _scalarDerivative;
        boost::numeric::ublas::vector<double> _vectorDerivative;
        //derivative for vectorDual
        boost::numeric::ublas::vector<double> _vectorValueScalarDerivative;
        boost::numeric::ublas::matrix<double> _vectorValueVectorDerivative;
        //dual
        scalar_dual_scalar_derivative_type _scalarDualScalarDerivative;
        scalar_dual_vector_derivative_type _scalarDualVectorDerivative;
        vector_dual_scalar_derivative_type _vectorDualScalarDerivative;
        vector_dual_vector_derivative_type _vectorDualVectorDerivative;
    }; // class DualUnaryOperatorTest : public ::testing::Test {
} } // namespace algo { namespace ad_test {
