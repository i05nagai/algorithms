#pragma once
#include <gtest/gtest.h>

#define EXPECT_VECTOR_DOUBLE_EQ(expect, actual)                                    \
    {                                                                              \
        auto expectIter = expect.begin();                                          \
        auto actualIter = actual.begin();                                          \
        for(; expectIter != expect.end(); ++expectIter, ++actualIter) {            \
            EXPECT_DOUBLE_EQ(*expectIter, *actualIter);                            \
        }                                                                          \
    }

#define EXPECT_VECTOR_NEAR_EQ(expect, actual, tolerance)                        \
    {                                                                           \
        auto expectIter = expect.begin();                                       \
        auto actualIter = actual.begin();                                       \
        for(; expectIter != expect.end(); ++expectIter, ++actualIter) {         \
            EXPECT_NEAR_EQ(*expectIter, *actualIter, tolerance);                \
        }                                                                       \
    }

#define EXPECT_MATRIX_DOUBLE_EQ(expect, actual)                                    \
    {                                                                              \
        EXPECT_EQ(expect.size1(), actual.size1());                                 \
        EXPECT_EQ(expect.size2(), actual.size2());                                 \
        for (std::size_t ri = 0; ri < expect.size1(); ++ri) {                      \
            for (std::size_t ci = 0; ci < expect.size2(); ++ci) {                  \
                EXPECT_DOUBLE_EQ(expect(ri, ci), actual(ri, ci));                  \
            }                                                                      \
        }                                                                          \
    }

#define EXPECT_MATRIX_NEAR_EQ(expect, actual, tolerance)                        \
    {                                                                           \
        EXPECT_EQ(expect.size1(), actual.size1());                              \
        EXPECT_EQ(expect.size2(), actual.size2());                              \
        for (std::size_t ri = 0; ri < expect.size1(); ++ri) {                   \
            for (std::size_t ci = 0; ci < expect.size2(); ++ci) {               \
                EXPECT_NEAR_EQ(expect(ri, ci), actual(ri, ci), tolerance);      \
            }                                                                   \
        }                                                                       \
    }

