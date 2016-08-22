#pragma once
#include <boost/numeric/ublas/matrix.hpp>

namespace algo { namespace utility {
    template <typename Value>
    bool invert(
        const boost::numeric::ublas::matrix<Value>& matrix, 
        boost::numeric::ublas::matrix<Value>& inverseMatrix);
} } // namespace algo { namespace utility {
