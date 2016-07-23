/**
 * @file utility.hpp
 * @brief 
 * @author i05nagai
 * @version 0.0.1
 * @date 2016-07-21
 */
#pragma once
#include "ad/dual.hpp"
#include <boost/numeric/ublas/vector.hpp>

namespace algo { namespace ad {
    /**
     * @brief 
     *
     * @tparam V
     * @param functions
     * @param x
     *
     * @return 
     */
    template <typename V>
    boost::numeric::ublas::vector<V>
    apply_element(
        const std::vector<std::function<
            V (const boost::numeric::ublas::vector<V>&)> >& functions,
        const boost::numeric::ublas::vector<V>& x)
    {
        namespace ublas = boost::numeric::ublas;
        typedef std::function<V (const ublas::vector<V>&)> function_type;

        ublas::vector<V> result(functions.size());
        auto transformer = [&x](const function_type& f) {
            return f(x);
        };
        std::transform(
            functions.begin(), functions.end(), result.begin(), transformer);
        return result;
    }
    /**
     * @brief 
     *
     * @param value
     * @param infinitesimal
     *
     * @return 
     */
    dual<boost::numeric::ublas::vector<double> >
    make_dual(
        const double value,
        const boost::numeric::ublas::vector<double>& infinitesimal);
    /**
     * @brief 
     *
     * @param value
     * @param size
     * @param index Index starts from 0. Index should be less than size.
     *
     * @return 
     */
    dual<boost::numeric::ublas::vector<double> >
    make_unit_dual(
        const double value,
        const std::size_t size,
        const std::size_t index);
    /**
     * @brief 
     *
     * @param value
     *
     * @return 
     */
    boost::numeric::ublas::vector<dual<boost::numeric::ublas::vector<double> > >
    make_vector_dual(const boost::numeric::ublas::vector<double>& value);
} } // namespace algo { namespace ad {
