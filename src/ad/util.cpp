#include "algo/ad/dual.hpp"
#include "algo/ad/util.hpp"
#include <boost/numeric/ublas/matrix_proxy.hpp>

namespace algo { namespace ad {
    namespace ublas = boost::numeric::ublas;

    dual<ublas::vector<double> >
    makeDual(
        const double value,
        const ublas::vector<double>& infinitesimal)
    {
        dual<ublas::vector<double>> x(value, infinitesimal);
        return x;
    }

    dual<boost::numeric::ublas::vector<double> >
    make_unit_dual(
        const double value,
        const std::size_t size,
        const std::size_t index)
    {
        namespace ublas = boost::numeric::ublas;

        ublas::vector<double> infinitesimal(size, 0.0);
        infinitesimal(index) = 1.0;
        dual<ublas::vector<double> > x(value, infinitesimal);
        return x;
    }

    ublas::vector<ad::dual<double>>
    makeVectorDual(
        const ublas::vector<double>& value,
        const double derivative)
    {
        namespace ublas = boost::numeric::ublas;
        
        ublas::vector<dual<double>> x(value.size());
        for (std::size_t i = 0; i < x.size(); ++i) {
            x(i) = ad::dual<double>(value(i), derivative);
        }
        return x;
    }

    ublas::vector<dual<ublas::vector<double>>>
    makeVectorDual(
        const ublas::vector<double>& value)
    {
        namespace ublas = boost::numeric::ublas;
        
        ublas::vector<dual<ublas::vector<double>>> x(value.size());
        for (std::size_t i = 0; i < x.size(); ++i) {
            x(i) = make_unit_dual(value(i), x.size(), i);
        }
        return x;
    }

    ublas::vector<dual<double>>
    makeVectorDual(
        const ublas::vector<double>& value,
        const ublas::vector<double>& scalarDerivative)
    {
        namespace ublas = boost::numeric::ublas;
        
        ublas::vector<dual<double>> x(value.size());
        for (std::size_t i = 0; i < x.size(); ++i) {
            x(i) = dual<double>(value(i), scalarDerivative(i));
        }
        return x;
    }

    ublas::vector<dual<ublas::vector<double>>>
    makeVectorDual(
        const ublas::vector<double>& value,
        const ublas::matrix<double>& vectorDerivative)
    {
        namespace ublas = boost::numeric::ublas;
        
        assert(value.size() == vectorDerivative.size1());
        ublas::vector<dual<ublas::vector<double>>> x(value.size());
        for (std::size_t i = 0; i < x.size(); ++i) {
            x(i) = ad::dual<ublas::vector<double>>(
                value(i), ublas::row(vectorDerivative, i));
        }
        return x;
    }
} } // namespace algo { namespace ad {
