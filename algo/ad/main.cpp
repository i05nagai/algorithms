#include "ad/dual.hpp"
#include "ad/dual_binary_operator.hpp"
#include "ad/dual_unary_operator.hpp"
#include "ad/helper_macro.hpp"
#include "ad/utility.hpp"
#include "ad/jacobian_matrix_adaptor.hpp"
#include "ad/concept/ublas_matrix_expression_concept.hpp"
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/concept_check.hpp>

template <typename V>
struct Functor0 {
    V operator()(const boost::numeric::ublas::vector<V>& e) const
    {
        return e(0) * e(1);
    }
};

template <typename V>
struct Functor1 {
    V operator()(const boost::numeric::ublas::vector<V>& e) const
    {
        return e(0) + e(1) * e(2);
    }
};

template <typename V>
struct Functor2 {
    V operator()(const boost::numeric::ublas::vector<V>& e) const
    {
        return e(0) - e(1);
    }
};

template <typename M>
void jacobian_matrix_adaptor_concept_check(const M& m)
{
    boost::function_requires<algo::ad::UblasMatrixExpressionConcept<M> >();
}

int main(int argc, char const* argv[])
{
    namespace ublas = boost::numeric::ublas;
    ublas::vector<double> i1(2);
    i1(0) = 1.0;
    i1(1) = 2.0;
    ublas::vector<double> i2(2);
    i2(0) = 3.0;
    i2(1) = 5.0;
    algo::ad::dual<ublas::vector<double> > d1(7.0, i1);
    algo::ad::dual<ublas::vector<double> > d2(11.0, i2);
    DISPLAY_DUAL(d1);
    DISPLAY_DUAL(d2);
    std::cout << "add" << std::endl;
    {
        auto z = d1 + d2;
        DISPLAY_DUAL(z);
    }
    {
        auto z = d1 + 1.0;
        DISPLAY_DUAL(z);
    }
    std::cout << "minus" << std::endl;
    {
        auto z = d1 - d2;
        DISPLAY_DUAL(z);
    }
    {
        auto z = d1 - 1.0;
        DISPLAY_DUAL(z);
    }
    std::cout << "multiplies" << std::endl;
    {
        auto z = d1 * d2;
        DISPLAY_DUAL(z);
    }
    {
        auto z = d1 * 1.0;
        //const std::type_info& info = typeid(z); 
        DISPLAY_DUAL(z);
    }
    std::cout << "divide" << std::endl;
    {
        auto z = d1 / d2;
        DISPLAY_DUAL(z);
    }
    {
        auto z = d1 / 2.0;
        DISPLAY_DUAL(z);
    }
    std::cout << "negate" << std::endl;
    {
        auto z = -d1;
        DISPLAY_DUAL(z);
    }
    {
        auto z = -(d1 + d2);
        DISPLAY_DUAL(z);
    }
    std::cout << "exp" << std::endl;
    {
        auto z = algo::ad::exp(d1);
        DISPLAY_DUAL(z);
    }
    {
        auto z = algo::ad::exp(d1 + d2);
        DISPLAY_DUAL(z);
    }
    std::cout << "log" << std::endl;
    {
        auto z = algo::ad::log(d1);
        DISPLAY_DUAL(z);
    }
    {
        auto z = algo::ad::log(d1 + d2);
        DISPLAY_DUAL(z);
    }
    std::cout << "sin" << std::endl;
    {
        auto z = algo::ad::sin(d1);
        DISPLAY_DUAL(z);
    }
    {
        auto z = algo::ad::sin(d1 + d2);
        DISPLAY_DUAL(z);
    }
    std::cout << "cos" << std::endl;
    {
        auto z = algo::ad::cos(d1);
        DISPLAY_DUAL(z);
    }
    {
        auto z = algo::ad::cos(d1 + d2);
        DISPLAY_DUAL(z);
    }

    std::cout << "make_unit_dual" << std::endl;
    {
        namespace ublas = boost::numeric::ublas;

        algo::ad::dual<ublas::vector<double> > unitDual
            = algo::ad::make_unit_dual(3.0, 3, 1);
        DISPLAY_DUAL(unitDual);
    }
    std::cout << "make_vector_dual" << std::endl;
    {
        namespace ublas = boost::numeric::ublas;

        ublas::vector<double> value(3, 1.0);
        ublas::vector<algo::ad::dual<ublas::vector<double> > > vectorDual 
            = algo::ad::make_vector_dual(value);
        DISPLAY_VECTOR_DUAL(vectorDual);
    }
    std::cout << "apply_element" << std::endl;
    {
        typedef algo::ad::dual<ublas::vector<double> > dual_type;
        typedef ublas::vector<dual_type> argument_type;
        typedef std::function<dual_type (const argument_type&)> functor_type;

        ublas::vector<double> values(3);
        values(0) = 1.0;
        values(1) = 2.0;
        values(2) = 3.0;
        ublas::vector<dual_type> x = algo::ad::make_vector_dual(values);

        std::vector<functor_type> functors;
        Functor0<algo::ad::dual<ublas::vector<double> > > functor0;
        Functor1<algo::ad::dual<ublas::vector<double> > > functor1;
        
        functors.push_back(functor0);
        functors.push_back(functor1);

        DISPLAY_VECTOR_DUAL(x);
        auto y = algo::ad::apply_element(functors, x);
        DISPLAY_VECTOR_DUAL(y);
    }
    
    std::cout << "jacobian_matrix_adaptor" << std::endl;
    {
        typedef algo::ad::dual<ublas::vector<double> > dual_type;
        typedef ublas::vector<dual_type> argument_type;

        ublas::vector<double> values(3);
        values(0) = 1.0;
        values(1) = 2.0;
        values(2) = 3.0;
        ublas::vector<dual_type> x = algo::ad::make_vector_dual(values);
        algo::ad::jacobian_matrix_adaptor<argument_type> jacobianMatrix(x);
        DISPLAY_JACOBIAN_DUAL(jacobianMatrix);
    }
    std::cout << "jacobian_matrix_adaptor concept_check" << std::endl;
    {
        typedef algo::ad::dual<ublas::vector<double> > dual_type;
        typedef ublas::vector<dual_type> argument_type;

        ublas::vector<double> values(3);
        values(0) = 1.0;
        values(1) = 2.0;
        values(2) = 3.0;
        ublas::vector<dual_type> x = algo::ad::make_vector_dual(values);
        algo::ad::jacobian_matrix_adaptor<argument_type> jacobianMatrix(x);
        jacobian_matrix_adaptor_concept_check(jacobianMatrix);
    }
    std::cout << "jacobian_matrix_adaptor operators" << std::endl;
    {
        typedef algo::ad::dual<ublas::vector<double> > dual_type;
        typedef ublas::vector<dual_type> argument_type;

        ublas::vector<double> values(3);
        values(0) = 1.0;
        values(1) = 2.0;
        values(2) = 3.0;
        ublas::vector<dual_type> x = algo::ad::make_vector_dual(values);
        algo::ad::jacobian_matrix_adaptor<argument_type> jacobianMatrix(x);
        ublas::matrix<double> A(3, 3, 1.1);

        {
            auto B1 = A + jacobianMatrix;
            auto B2 = jacobianMatrix + A;
            auto B3 = A - jacobianMatrix;
            auto B4 = jacobianMatrix - A;
            DISPLAY_JACOBIAN_DUAL(B1);
            DISPLAY_JACOBIAN_DUAL(B2);
            DISPLAY_JACOBIAN_DUAL(B3);
            DISPLAY_JACOBIAN_DUAL(B4);
        }
        {
            auto B1 = 2.0 * jacobianMatrix;
            auto B2 = jacobianMatrix * 2.0;
            auto B3 = jacobianMatrix / 2.0;
            DISPLAY_JACOBIAN_DUAL(B1);
            DISPLAY_JACOBIAN_DUAL(B2);
            DISPLAY_JACOBIAN_DUAL(B3);
        }
        {
            auto B = ublas::prod(A, jacobianMatrix);
            DISPLAY_JACOBIAN_DUAL(B);
        }
        {
            auto b1 = ublas::norm_1(jacobianMatrix);
            auto b2 = ublas::norm_frobenius(jacobianMatrix);
            auto b3 = ublas::norm_inf(jacobianMatrix);
            DISPLAY_INTEGRAL(b1);
            DISPLAY_INTEGRAL(b2);
            DISPLAY_INTEGRAL(b3);
        }
        std::cout << "  prod" << std::endl;
        {
            auto vec1 = ublas::prod(jacobianMatrix, values);
            auto vec2 = ublas::prod(values, jacobianMatrix);
            DISPLAY_VECTOR(vec1);
            DISPLAY_VECTOR(vec2);
        }
    }
    return 0;
}
