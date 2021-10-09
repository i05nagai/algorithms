LIST (APPEND nm_test_SOURCES
    algo/nm_test/ConvergenceUtilTest.cpp
    algo/nm_test/GaussNewtonTest.cpp
    algo/nm_test/IDumpingFactorCalculatorTest.cpp
    algo/nm_test/LevenbergMarquardtTest.cpp
    algo/nm_test/NewtonRaphsonTest.cpp
    algo/nm_test/SimpleDumpingFactorCalculatorTest.cpp
    algo/nm_test/TestData.cpp
    algo/nm_test/main.cpp
)
LIST (APPEND nm_test_HEADERS
    algo/nm_test/ConvergenceUtilTest.h
    algo/nm_test/GaussNewtonTest.h
    algo/nm_test/IDumpingFactorCalculatorTest.h
    algo/nm_test/LevenbergMarquardtTest.h
    algo/nm_test/NewtonRaphsonTest.h
    algo/nm_test/SimpleDumpingFactorCalculatorTest.h
    algo/nm_test/TestData.h
    algo/nm_test/mock/IDumpingFactorCalculatorMock.h
)
