LIST (APPEND ad_SOURCES
    algo/ad/main.cpp
    algo/ad/utility.cpp
)
LIST (APPEND ad_HEADERS
    algo/ad/fwd.h
    algo/ad/concept/ublas_matrix_expression_concept.hpp
    algo/ad/detail/dual_binary_operator_helper.hpp
    algo/ad/detail/dual_helper_function.hpp
    algo/ad/detail/dual_unary_operator_helper.hpp
    algo/ad/detail/jacobian_matrix_adaptor_helper.hpp
    algo/ad/dual.hpp
    algo/ad/dual_binary_operator.hpp
    algo/ad/dual_expression.hpp
    algo/ad/dual_unary_operator.hpp
    algo/ad/helper_macro.hpp
    algo/ad/iterator/ConstMatrixIterator.hpp
    algo/ad/iterator/MatrixIterator.hpp
    algo/ad/jacobian_matrix_adaptor.hpp
    algo/ad/pre_compiled_header.hpp
    algo/ad/traits.hpp
    algo/ad/ublas_unary_operator.hpp
    algo/ad/utility.hpp
)
