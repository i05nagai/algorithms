#include "algo/ad/dual.hpp"
#include "algo/ad/utility.hpp"

namespace algo { namespace ad {
    dual<boost::numeric::ublas::vector<double> >
    make_dual(
        const double value,
        const boost::numeric::ublas::vector<double>& infinitesimal)
    {
        dual<boost::numeric::ublas::vector<double> > x(value, infinitesimal);
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

    boost::numeric::ublas::vector<dual<boost::numeric::ublas::vector<double> > >
    make_vector_dual(
        const boost::numeric::ublas::vector<double>& value)
    {
        namespace ublas = boost::numeric::ublas;
        
        ublas::vector<dual<ublas::vector<double> > > x(value.size());
        for (std::size_t i = 0; i < x.size(); ++i) {
            x(i) = make_unit_dual(value(i), x.size(), i);
        }
        return x;
    }
} } // namespace algo { namespace ad {
