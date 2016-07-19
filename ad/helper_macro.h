#pragma once

#define DISPLAY_DUAL(x)                                                                            \
    std::cout << #x << std::endl;                                                                  \
    std::cout << "  " << x.getValue() << std::endl;                                                \
    std::cout << "  ";                                                                             \
    for (auto iter = std::begin(x.getDerivative()); iter != std::end(x.getDerivative()); ++iter) { \
       std::cout << *iter << " ";                                                                  \
    }                                                                                              \
    std::cout << std::endl;

