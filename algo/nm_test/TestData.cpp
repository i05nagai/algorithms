#include "algo/nm_test/TestData.h"

namespace algo { namespace nm_test {
    namespace ublas = boost::numeric::ublas;

    std::function<
        ublas::vector<double>
            (const ublas::vector<double>& x)>
    TestData::getMultiValuedSeveralVariablesFunction0()
    {
        return [](const ublas::vector<double>& x)
        {
            assert(x.size() == 2);
            ublas::vector<double> y(x.size());
            y(0) = x(0) * x(0);
            y(1) = x(1) * x(1);
            return y;
        };
    }

    std::function<
        ublas::matrix<double>
            (const ublas::vector<double>& x)>
    TestData::getMatrixValuedSeveralVariablesDerivative0()
    {
        namespace ublas = boost::numeric::ublas;
        return [](const ublas::vector<double>& x)
        {
            assert(x.size() == 2);
            ublas::matrix<double> y(x.size(), x.size());
            y(0, 0) = 2.0 * x(0);
            y(0, 1) = 0.0;
            y(1, 0) = 0.0;
            y(1, 1) = 2.0 * x(1);
            return y;
        };
    }

    boost::numeric::ublas::vector<double> 
    TestData::getVector0()
    {
        ublas::vector<double> x(2);

        return x;
    }

    ublas::matrix<double>
    TestData::getRandomMatrix0()
    {
        ublas::matrix<double> matrix(2, 2);

        return matrix;
    }
} } // namespace algo { namespace nm_test {
