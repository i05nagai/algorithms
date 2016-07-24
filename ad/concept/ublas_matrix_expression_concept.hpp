#pragma once
#include <boost/concept_check.hpp>
#include <boost/concept/detail/concept_def.hpp>

namespace algo { namespace ad {
    BOOST_concept(UblasMatrixExpression, (M))
    {
        typedef typename M::difference_type difference_type;
        typedef typename M::const_iterator1 const_iterator1;
        typedef typename M::const_iterator2 const_iterator2;
        typedef typename M::const_closure_type const_closure_type;
        typedef typename M::orientation_category orientation_category;
        BOOST_CONCEPT_USAGE(UblasMatrixExpression)
        {
        }
    private:
    };
/*
    template <typename M>
    struct UblasMatrixExpressionConcepts {
        void constraints() {
            typename M::difference_type d;
        }
    private:
    };
    */
} } // namespace algo { namespace ad {

