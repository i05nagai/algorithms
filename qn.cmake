LIST (APPEND qn_SOURCES
    algo/qn/BroydenFletcherGoldfarbShanno.cpp
    algo/qn/DavidonFeltcherPowell.cpp
    algo/qn/ExplicitLineSearcher.cpp
    algo/qn/ILineSearcher.cpp
    algo/qn/IQuasiNewton.cpp
    algo/qn/main.cpp
    algo/qn/utility.cpp
)
LIST (APPEND qn_HEADERS
    algo/qn/BroydenFletcherGoldfarbShanno.h
    algo/qn/DavidonFeltcherPowell.h
    algo/qn/ExplicitLineSearcher.h
    algo/qn/ILineSearcher.h
    algo/qn/IQuasiNewton.h
    algo/qn/pre_compiled_header.h
    algo/qn/utility.h
    algo/qn/detail/helper_function.hpp
)
