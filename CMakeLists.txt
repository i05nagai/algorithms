cmake_minimum_required(VERSION 2.8.6)

project(algo CXX)

#compiler option with accordance to compiler
SET (CMAKE_CXX_FLAGS "-g ${CMAKE_CXX_FLAGS}")
IF ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	SET (CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
ELSEIF ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	SET (CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
ELSEIF ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	IF (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 19)
		MESSAGE ( FATAL_ERROR "MSVC doesn't support C++11.")
	ENDIF ()
ENDIF ()

#GTEST and GMOCK build
SET(BUILD_GTEST ON CACHE BOOL "Use some expat option")
add_subdirectory(${CMAKE_SOURCE_DIR}/submodule/googletest)

# include directory
include_directories(
	${CMAKE_SOURCE_DIR}/
	${CMAKE_SOURCE_DIR}/submodule/boost/numeric/ublas/include
	${CMAKE_SOURCE_DIR}/submodule/boost/config/include
	${CMAKE_SOURCE_DIR}/submodule/boost/serialization/include
	${CMAKE_SOURCE_DIR}/submodule/boost/type_traits/include
	${CMAKE_SOURCE_DIR}/submodule/boost/mpl/include
	${CMAKE_SOURCE_DIR}/submodule/boost/preprocessor/include
	${CMAKE_SOURCE_DIR}/submodule/boost/static_assert/include
	${CMAKE_SOURCE_DIR}/submodule/boost/utility/include
	${CMAKE_SOURCE_DIR}/submodule/boost/array/include
	${CMAKE_SOURCE_DIR}/submodule/boost/assert/include
	${CMAKE_SOURCE_DIR}/submodule/boost/core/include
	${CMAKE_SOURCE_DIR}/submodule/boost/throw_exception/include
	${CMAKE_SOURCE_DIR}/submodule/boost/typeof/include
	${CMAKE_SOURCE_DIR}/submodule/boost/concept_check/include
	${CMAKE_SOURCE_DIR}/submodule/boost/random/include
	${CMAKE_SOURCE_DIR}/submodule/boost/integer/include
	${CMAKE_SOURCE_DIR}/submodule/boost/range/include
	${CMAKE_SOURCE_DIR}/submodule/boost/iterator/include
	${CMAKE_SOURCE_DIR}/submodule/boost/math/include
	${CMAKE_SOURCE_DIR}/submodule/boost/predef/include
	${CMAKE_SOURCE_DIR}/submodule/googletest/googlemock/include
	${CMAKE_SOURCE_DIR}/submodule/googletest/googletest/include
)

#inclue sources
include(cmake/ad.cmake)
include(cmake/qn.cmake)
include(cmake/nm.cmake)
include(cmake/utility.cmake)
include(cmake/math.cmake)
include(cmake/ad_test.cmake)
include(cmake/qn_test.cmake)
include(cmake/nm_test.cmake)
include(cmake/utility_test.cmake)

#add library
add_library(ad ${ad_SOURCES})
add_library(qn ${qn_SOURCES})
add_library(nm ${nm_SOURCES})
target_link_libraries(nm utility)
target_link_libraries(nm math)
add_library(utility ${utility_SOURCES})
add_library(math ${math_SOURCES})

# test
enable_testing()

#add_executable(ad_test ${ad_test_SOURCES})
#target_link_libraries(ad_test ad)
#target_link_libraries(ad_test gmock)
#target_link_libraries(ad_test gtest)
#add_test(ad_test ad_test)
#
#add_executable(qn_test ${qn_test_SOURCES})
#target_link_libraries(qn_test qn)
#target_link_libraries(qn_test gmock)
#target_link_libraries(qn_test gtest)
#add_test(qn_test qn_test)

add_executable(nm_test ${nm_test_SOURCES})
target_link_libraries(nm_test nm)
target_link_libraries(nm_test gmock)
target_link_libraries(nm_test gtest)
add_test(nm_test nm_test)

add_executable(utility_test ${utility_test_SOURCES})
target_link_libraries(utility_test utility)
target_link_libraries(utility_test gmock)
target_link_libraries(utility_test gtest)
add_test(utility_test utility_test)

