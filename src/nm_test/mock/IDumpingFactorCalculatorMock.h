#pragma once

#include "algo/nm/IDumpingFactorCalculator.h"
#include <gmock/gmock.h>

namespace algo { namespace nm_test { 
    using ::testing::_;
    using ::testing::Invoke;
    using ::testing::Return;
    class IDumpingFactorCalculatorMock : public nm::IDumpingFactorCalculator {
    //private typedef
    private:
    //public typedef
    public:
    //public function
    public:
        MOCK_CONST_METHOD2(doOperatorParenthesis, double(
            const boost::numeric::ublas::vector<double>& residual,
            const boost::numeric::ublas::matrix<double>& jacobianMatrix));
        MOCK_CONST_METHOD1(doEqual, bool(const nm::IDumpingFactorCalculator& other));
        MOCK_CONST_METHOD0(doClone, nm::IDumpingFactorCalculator*());

        void delegateToDefault()
        {
            ON_CALL(*this, doClone())
                .WillByDefault(Invoke(this, &IDumpingFactorCalculatorMock::doCloneMock));
            ON_CALL(*this, doEqual(_))
                .WillByDefault(Invoke(this, &IDumpingFactorCalculatorMock::doEqualeMock));
        }

        IDumpingFactorCalculatorMock* doCloneMock()
        {
            return new IDumpingFactorCalculatorMock();
        }

        bool doEqualeMock(const nm::IDumpingFactorCalculator& other)
        {
            return true;
        }
    //private function
    private:
    //private members
    private:
    };
} } // namespace algo { namespace nm_test {
