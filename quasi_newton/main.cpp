#include "quasi_newton/pre_compiled_header.h"
#include "quasi_newton/ExplicitLineSearcher.h"
#include "quasi_newton/DavidonFeltcherPowell.h"
#include "quasi_newton/BroydenFletcherGoldfarbShanno.h"
#include <boost/shared_ptr.hpp>

namespace ublas = boost::numeric::ublas;
struct SampleFunction {
    double operator()(const ublas::vector<double>& x)
    {
        assert(x.size() == 2);
        return x(0) * x(0) + x(0) * x(1) + x(1) * x(1) + 1.5;
    }
};

struct SampleGradientFunction {
    ublas::vector<double> operator()(const ublas::vector<double>& x)
    {
        assert(x.size() == 2);

        ublas::vector<double> gradient(2);
        gradient(0) = 2.0 * x(0) + x(1);
        gradient(1) = x(0) + 2.0 * x(1);

        return gradient;
    }
};

struct LineSearcherFunction {
    ublas::vector<double> operator()(
        const ublas::vector<double>& p,
        const ublas::vector<double>& x)
    {
        const double alpha = 
            - ((2.0 * p(1) + p(0)) * x(1) + (p(1) + 2.0 * p(0)) * x(0)) 
            / (2.0 * p(1) * p(1) + 2.0 * p(0) * p(1) + 2.0 * p(0) * p(0));
        return x + alpha * p;
    }
};

int main(int argc, char const* argv[])
{
    const double epsilon = 1E-10;
    const std::size_t maxIteration = 50;
    const LineSearcherFunction lineSearcherFunction;
    boost::shared_ptr<algo::ExplicitLineSearcher> searcher(
        new algo::ExplicitLineSearcher(lineSearcherFunction));

    //boost::shared_ptr<algo::DavidonFeltcherPowell> quasiNewton(
    //    new algo::DavidonFeltcherPowell(epsilon, maxIteration, searcher));
    boost::shared_ptr<algo::BroydenFletcherGoldfarbShanno> quasiNewton(
        new algo::BroydenFletcherGoldfarbShanno(
            epsilon, maxIteration, searcher));
    
    ublas::vector<double> x0(2);
    x0(0) = -10.0;
    x0(1) = 10.342;
    const typename algo::IQuasiNewton::function_type func = SampleFunction();
    const typename algo::IQuasiNewton::gradient_type gradient 
        = SampleGradientFunction();
    ublas::vector<double> x = (*quasiNewton)(x0, func, gradient);
    std::cout << x(0) << std::endl;
    std::cout << x(1) << std::endl;
    return 0;
}

