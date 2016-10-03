#include "algo/ad_test/TestUtil.h"
#include <algorithm>
#include <boost/numeric/ublas/matrix_proxy.hpp>

namespace algo { namespace ad_test {
    namespace ublas = boost::numeric::ublas;

    ublas::vector<double> 
    TestUtil::getValueFromVectorDualScalarDerivative(
        const ublas::vector<ad::dual<double>>& vectorDualScalarDerivative)
    {
        ublas::vector<double> result(vectorDualScalarDerivative.size());

        std::back_inserter(result);
        std::transform(
            vectorDualScalarDerivative.begin(), 
            vectorDualScalarDerivative.end(), 
            result.begin(),
            [](const ad::dual<double>& dual) -> double {
                return dual.getValue();
            });
        return result;
    }

    ublas::vector<double> 
    TestUtil::getValueFromVectorDualVectorDerivative(
        const ublas::vector<
            ad::dual<ublas::vector<double>>>& vectorDualVectorDerivative)
    {
        ublas::vector<double> result(vectorDualVectorDerivative.size());

        std::transform(
            vectorDualVectorDerivative.begin(), 
            vectorDualVectorDerivative.end(), 
            result.begin(),
            [](const ad::dual<ublas::vector<double>>& dual) -> double {
                return dual.getValue();
            });
        return result;
    }

    ublas::vector<double> 
    TestUtil::getDerivativeFromVectorValueScalarDerivative(
        const ublas::vector<ad::dual<double>>& vectorDualScalarDerivative)
    {
        ublas::vector<double> result(vectorDualScalarDerivative.size());

        std::transform(
            vectorDualScalarDerivative.begin(), 
            vectorDualScalarDerivative.end(), 
            result.begin(),
            [](const ad::dual<double>& dual) {
                return dual.getDerivative();
            });
        return result;
    }

    ublas::matrix<double> 
    TestUtil::getDerivativeFromVectorValueVectorDerivative(
        const ublas::vector<ad::dual<ublas::vector<double>>>&
            vectorDualVectorDerivative)
    {
        assert(vectorDualVectorDerivative.size() > 0);

        const std::size_t valueSize = vectorDualVectorDerivative.size();
        const std::size_t derivativeSize 
            = vectorDualVectorDerivative(0).getDerivative().size();
        ublas::matrix<double> result(valueSize, derivativeSize);

        for (std::size_t ri = 0; ri < valueSize; ++ri) {
            ublas::row(result, ri) 
                = vectorDualVectorDerivative(ri).getDerivative();
        }

        return result;
    }
} } // namespace algo { namespace ad_test {
