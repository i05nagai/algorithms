#include "nm/IDumpingFactorCalculator.h"

namespace algo { namespace nm {
   double IDumpingFactorCalculator::operator()( 
       const boost::numeric::ublas::vector<double>& residual,
       const boost::numeric::ublas::matrix<double>& jacobianMatrix) const
   {
       return this->doOperatorParenthesis(residual, jacobianMatrix);
   }
} } // namespace algo { namespace nm {
