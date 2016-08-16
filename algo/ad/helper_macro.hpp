#pragma once

#define DISPLAY_DUAL(x)                                                                            \
    std::cout << #x << std::endl;                                                                  \
    std::cout << "  " << x.getValue() << std::endl;                                                \
    std::cout << "  ";                                                                             \
    for (auto iter = std::begin(x.getDerivative()); iter != std::end(x.getDerivative()); ++iter) { \
       std::cout << *iter << " ";                                                                  \
    }                                                                                              \
    std::cout << std::endl;

#define DISPLAY_VECTOR_DUAL(vector)                                    \
    std::cout << #vector << std::endl;                                 \
    for (std::size_t i = 0; i < vector.size(); ++i) {                  \
        std::cout << "  "  << #vector << "(" << i << ")" << std::endl; \
        std::cout << "    " << vector(i).getValue() << std::endl;      \
        std::cout << "    ";                                           \
        for (auto& derivative : vector(i).getDerivative()) {           \
           std::cout << derivative << " ";                             \
        }                                                              \
        std::cout << std::endl;                                        \
    }                                                                  \
    std::cout << std::endl;

#define DISPLAY_JACOBIAN_DUAL(jac)                         \
    std::cout << #jac << std::endl;                        \
    for (std::size_t ri = 0; ri < jac.size1(); ++ri) {     \
        for (std::size_t ci = 0; ci < jac.size2(); ++ci) { \
            std::cout << jac(ri, ci) <<  "  ";             \
        }                                                  \
        std::cout << std::endl;                            \
    }                                                      \
    std::cout << std::endl; 

#define DISPLAY_INTEGRAL(x)                         \
    std::cout << #x << std::endl;                   \
    std::cout << "  " << x << std::endl;

#define DISPLAY_VECTOR(vector)                        \
    std::cout << #vector << std::endl;                \
    std::cout << "  ";                                \
    for (std::size_t i = 0; i < vector.size(); ++i) { \
        std::cout << vector(i) << " ";                \
    }                                                 \
    std::cout << std::endl;
