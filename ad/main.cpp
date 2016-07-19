#include "ad/dual.h"
#include "ad/dual_binary_operator.h"
#include "ad/dual_unary_operator.h"
#include "ad/helper_macro.h"
#include <boost/numeric/ublas/vector.hpp>

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
    return 0;
}
