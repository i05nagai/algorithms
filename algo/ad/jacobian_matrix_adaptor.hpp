#pragma once
#include "algo/ad/detail/jacobian_matrix_adaptor_helper.hpp"
#include "algo/ad/iterator/ConstMatrixIterator.hpp"
#include "algo/ad/iterator/MatrixIterator.hpp"
#include "algo/ad/traits.hpp"
#include <boost/numeric/ublas/fwd.hpp>
#include <boost/numeric/ublas/matrix_expression.hpp>
#include <boost/numeric/ublas/matrix_expression.hpp>

namespace algo { namespace ad {
    /**
     * @brief must be const.
     *
     * @tparam T T shoud be ublas::vector_expression<dual_expression<E>>
     */
    template <typename E>
    class jacobian_matrix_adaptor
    : public boost::numeric::ublas::matrix_expression<jacobian_matrix_adaptor<E> > {
    //private typedef
    private:
        typedef jacobian_matrix_adaptor<E> self_type;
        typedef typename E::const_closure_type expression_const_closure_type;
    //public typedef
    public:
        typedef std::size_t size_type;
        typedef double value_type;
        typedef std::ptrdiff_t difference_type;
        typedef const self_type const_closure_type;
        typedef ConstMatrixIterator<self_type> const_iterator1;
        typedef ConstMatrixIterator<self_type> const_iterator2;
        typedef boost::numeric::ublas::unknown_orientation_tag orientation_category;
    //public function
    public:
        explicit jacobian_matrix_adaptor(const E& e)
        : _e(e)
        {
        }
        /**
         * @brief row size.
         *
         * @return 
         */
        size_type size1() const
        {
            return _e.size();
        }
        /**
         * @brief col size. Currently, we assume _e is vecor.
         *
         * @return 
         */
        size_type size2() const
        {
            return _e(0).getDerivative().size();
        }
        /**
         * @brief 
         *
         * @param i row index.
         * @param j col index.
         *
         * @return 
         */
        const double operator()(size_type i, size_type j) const
        {
            return detail::jacobian_matrix_accessor(_e, i, j);
        }
    //private function
    private:
    //private members
    private:
        expression_const_closure_type _e;
    };
} } // namespace algo { namespace ad {

