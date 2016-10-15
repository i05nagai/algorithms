#include "algo/ad_test/TraitsTest.h"
#include "algo/ad/traits.hpp"

namespace algo { namespace ad_test {
    namespace ublas = boost::numeric::ublas;

    TraitsTest::TraitsTest() 
    {
    }
    
    TraitsTest::~TraitsTest() 
    {
    }

    void TraitsTest::SetUp()
    {
    }
    
    void TraitsTest::TearDown()
    {
    }

    TEST_F(TraitsTest, isVectorTest)
    {
        //double
        {
            const bool actual = ad::is_vector<double>::value;
            const bool expect = false;
            EXPECT_EQ(expect, actual);
        }
        //const double
        {
            const bool actual = ad::is_vector<const double>::value;
            const bool expect = false;
            EXPECT_EQ(expect, actual);
        }
        //double&
        {
            const bool actual = ad::is_vector<double&>::value;
            const bool expect = false;
            EXPECT_EQ(expect, actual);
        }
        //const double&
        {
            const bool actual = ad::is_vector<const double&>::value;
            const bool expect = false;
            EXPECT_EQ(expect, actual);
        }
        //ublas::vector<double>
        {
            const bool actual = ad::is_vector<ublas::vector<double>>::value;
            const bool expect = true;
            EXPECT_EQ(expect, actual);
        }
        //const ublas::vector<double>
        {
            const bool actual 
                = ad::is_vector<const ublas::vector<double>>::value;
            const bool expect = true;
            EXPECT_EQ(expect, actual);
        }
        //ublas::vector<double>&
        {
            const bool actual 
                = ad::is_vector<ublas::vector<double>&>::value;
            const bool expect = true;
            EXPECT_EQ(expect, actual);
        }
        //const ublas::vector<double>&
        {
            const bool actual 
                = ad::is_vector<const ublas::vector<double>&>::value;
            const bool expect = true;
            EXPECT_EQ(expect, actual);
        }
        //dual<ublas::vector<double>>
        {
            const bool actual 
                = ad::is_vector<ad::dual<ublas::vector<double>>>::value;
            const bool expect = false;
            EXPECT_EQ(expect, actual);
        }
        //const ublas::vector<double>&
        //omit other cv cases
        {
            const bool actual 
                = ad::is_vector<const ad::dual<ublas::vector<double>>&>::value;
            const bool expect = false;
            EXPECT_EQ(expect, actual);
        }
    }

    TEST_F(TraitsTest, isScalarDualTest)
    {
        //double
        {
            const bool actual = ad::is_scalar_dual<double>::value;
            const bool expect = false;
            EXPECT_EQ(expect, actual);
        }
        //const double
        {
            const bool actual = ad::is_scalar_dual<const double>::value;
            const bool expect = false;
            EXPECT_EQ(expect, actual);
        }
        //double&
        {
            const bool actual = ad::is_scalar_dual<double&>::value;
            const bool expect = false;
            EXPECT_EQ(expect, actual);
        }
        //const double&
        {
            const bool actual = ad::is_scalar_dual<const double&>::value;
            const bool expect = false;
            EXPECT_EQ(expect, actual);
        }
        //ublas::vector<double>
        {
            const bool actual = ad::is_scalar_dual<ublas::vector<double>>::value;
            const bool expect = false;
            EXPECT_EQ(expect, actual);
        }
        //const ublas::vector<double>
        {
            const bool actual 
                = ad::is_scalar_dual<const ublas::vector<double>>::value;
            const bool expect = false;
            EXPECT_EQ(expect, actual);
        }
        //ublas::vector<double>&
        {
            const bool actual 
                = ad::is_scalar_dual<ublas::vector<double>&>::value;
            const bool expect = false;
            EXPECT_EQ(expect, actual);
        }
        //const ublas::vector<double>&
        {
            const bool actual 
                = ad::is_scalar_dual<const ublas::vector<double>&>::value;
            const bool expect = false;
            EXPECT_EQ(expect, actual);
        }
        //dual<double>
        {
            const bool actual 
                = ad::is_scalar_dual<ad::dual<double>>::value;
            const bool expect = true;
            EXPECT_EQ(expect, actual);
        }
        //const dual<double>&
        //omit other cv cases
        {
            const bool actual 
                = ad::is_scalar_dual<const ad::dual<double>&>::value;
            const bool expect = true;
            EXPECT_EQ(expect, actual);
        }
        //dual<ublas::vector<double>>
        {
            const bool actual 
                = ad::is_scalar_dual<ad::dual<ublas::vector<double>>>::value;
            const bool expect = true;
            EXPECT_EQ(expect, actual);
        }
        //const dual<ublas::vector<double>>&
        //omit other cv cases
        {
            const bool actual 
                = ad::is_scalar_dual<
                    const ad::dual<ublas::vector<double>>&>::value;
            const bool expect = true;
            EXPECT_EQ(expect, actual);
        }
        //ublas::vector<dual<double>>
        {
            typedef ad::dual<double> dual_type;
            typedef ublas::vector<dual_type> test_type;
            const bool actual = ad::is_scalar_dual<test_type>::value;
            const bool expect = false;
            EXPECT_EQ(expect, actual);
        }
        //const ublas::vector<dual<double>>&
        //omit other cv cases
        {
            typedef ad::dual<double> dual_type;
            typedef const ublas::vector<dual_type>& test_type;
            const bool actual = ad::is_scalar_dual<test_type>::value;
            const bool expect = false;
            EXPECT_EQ(expect, actual);
        }
        //ublas::vector<dual<ublas::vector<double>>>
        {
            typedef ad::dual<ublas::vector<double>> dual_type;
            typedef ublas::vector<dual_type> test_type;
            const bool actual = ad::is_scalar_dual<test_type>::value;
            const bool expect = false;
            EXPECT_EQ(expect, actual);
        }
        //const ublas::vector<dual<ublas::vector<double>>>&
        //omit other cv cases
        {
            typedef ad::dual<ublas::vector<double>> dual_type;
            typedef const ublas::vector<dual_type>& test_type;
            const bool actual = ad::is_scalar_dual<test_type>::value;
            const bool expect = false;
            EXPECT_EQ(expect, actual);
        }
    } // TEST_F(TraitsTest, isScalarDualTest)

    TEST_F(TraitsTest, isVectorDualTest)
    {
        //double
        {
            const bool actual = ad::is_vector_dual<double>::value;
            const bool expect = false;
            EXPECT_EQ(expect, actual);
        }
        //const double
        {
            const bool actual = ad::is_vector_dual<const double>::value;
            const bool expect = false;
            EXPECT_EQ(expect, actual);
        }
        //double&
        {
            const bool actual = ad::is_vector_dual<double&>::value;
            const bool expect = false;
            EXPECT_EQ(expect, actual);
        }
        //const double&
        {
            const bool actual = ad::is_vector_dual<const double&>::value;
            const bool expect = false;
            EXPECT_EQ(expect, actual);
        }
        //ublas::vector<double>
        {
            const bool actual = ad::is_vector_dual<ublas::vector<double>>::value;
            const bool expect = false;
            EXPECT_EQ(expect, actual);
        }
        //const ublas::vector<double>
        {
            const bool actual 
                = ad::is_vector_dual<const ublas::vector<double>>::value;
            const bool expect = false;
            EXPECT_EQ(expect, actual);
        }
        //ublas::vector<double>&
        {
            const bool actual 
                = ad::is_vector_dual<ublas::vector<double>&>::value;
            const bool expect = false;
            EXPECT_EQ(expect, actual);
        }
        //const ublas::vector<double>&
        {
            const bool actual 
                = ad::is_vector_dual<const ublas::vector<double>&>::value;
            const bool expect = false;
            EXPECT_EQ(expect, actual);
        }
        //dual<double>
        {
            const bool actual 
                = ad::is_vector_dual<ad::dual<double>>::value;
            const bool expect = false;
            EXPECT_EQ(expect, actual);
        }
        //const dual<double>&
        //omit other cv cases
        {
            const bool actual 
                = ad::is_vector_dual<const ad::dual<double>&>::value;
            const bool expect = false;
            EXPECT_EQ(expect, actual);
        }
        //dual<ublas::vector<double>>
        {
            const bool actual 
                = ad::is_vector_dual<ad::dual<ublas::vector<double>>>::value;
            const bool expect = false;
            EXPECT_EQ(expect, actual);
        }
        //const dual<ublas::vector<double>>&
        //omit other cv cases
        {
            const bool actual 
                = ad::is_vector_dual<
                    const ad::dual<ublas::vector<double>>&>::value;
            const bool expect = false;
            EXPECT_EQ(expect, actual);
        }
        //ublas::vector<dual<double>>
        {
            typedef ad::dual<double> dual_type;
            typedef ublas::vector<dual_type> test_type;
            const bool actual = ad::is_vector_dual<test_type>::value;
            const bool expect = true;
            EXPECT_EQ(expect, actual);
        }
        //const ublas::vector<dual<double>>&
        //omit other cv cases
        {
            typedef ad::dual<double> dual_type;
            typedef const ublas::vector<dual_type>& test_type;
            const bool actual = ad::is_vector_dual<test_type>::value;
            const bool expect = true;
            EXPECT_EQ(expect, actual);
        }
        //ublas::vector<dual<ublas::vector<double>>>
        {
            typedef ad::dual<ublas::vector<double>> dual_type;
            typedef ublas::vector<dual_type> test_type;
            const bool actual = ad::is_vector_dual<test_type>::value;
            const bool expect = true;
            EXPECT_EQ(expect, actual);
        }
        //const ublas::vector<dual<ublas::vector<double>>>&
        //omit other cv cases
        {
            typedef ad::dual<ublas::vector<double>> dual_type;
            typedef const ublas::vector<dual_type>& test_type;
            const bool actual = ad::is_vector_dual<test_type>::value;
            const bool expect = true;
            EXPECT_EQ(expect, actual);
        }
    }

    TEST_F(TraitsTest, isDualTest)
    {
        //double
        {
            const bool actual = ad::is_dual<double>::value;
            const bool expect = false;
            EXPECT_EQ(expect, actual);
        }
        //const double
        {
            const bool actual = ad::is_dual<const double>::value;
            const bool expect = false;
            EXPECT_EQ(expect, actual);
        }
        //double&
        {
            const bool actual = ad::is_dual<double&>::value;
            const bool expect = false;
            EXPECT_EQ(expect, actual);
        }
        //const double&
        {
            const bool actual = ad::is_dual<const double&>::value;
            const bool expect = false;
            EXPECT_EQ(expect, actual);
        }
        //ublas::vector<double>
        {
            const bool actual = ad::is_dual<ublas::vector<double>>::value;
            const bool expect = false;
            EXPECT_EQ(expect, actual);
        }
        //const ublas::vector<double>
        {
            const bool actual 
                = ad::is_dual<const ublas::vector<double>>::value;
            const bool expect = false;
            EXPECT_EQ(expect, actual);
        }
        //ublas::vector<double>&
        {
            const bool actual 
                = ad::is_dual<ublas::vector<double>&>::value;
            const bool expect = false;
            EXPECT_EQ(expect, actual);
        }
        //const ublas::vector<double>&
        {
            const bool actual 
                = ad::is_dual<const ublas::vector<double>&>::value;
            const bool expect = false;
            EXPECT_EQ(expect, actual);
        }
        //dual<double>
        {
            const bool actual 
                = ad::is_dual<ad::dual<double>>::value;
            const bool expect = true;
            EXPECT_EQ(expect, actual);
        }
        //const dual<double>&
        //omit other cv cases
        {
            const bool actual 
                = ad::is_dual<const ad::dual<double>&>::value;
            const bool expect = true;
            EXPECT_EQ(expect, actual);
        }
        //dual<ublas::vector<double>>
        {
            const bool actual 
                = ad::is_dual<ad::dual<ublas::vector<double>>>::value;
            const bool expect = true;
            EXPECT_EQ(expect, actual);
        }
        //const dual<ublas::vector<double>>&
        //omit other cv cases
        {
            const bool actual 
                = ad::is_dual<
                    const ad::dual<ublas::vector<double>>&>::value;
            const bool expect = true;
            EXPECT_EQ(expect, actual);
        }
        //ublas::vector<dual<double>>
        {
            typedef ad::dual<double> dual_type;
            typedef ublas::vector<dual_type> test_type;
            const bool actual = ad::is_dual<test_type>::value;
            const bool expect = true;
            EXPECT_EQ(expect, actual);
        }
        //const ublas::vector<dual<double>>&
        //omit other cv cases
        {
            typedef ad::dual<double> dual_type;
            typedef const ublas::vector<dual_type>& test_type;
            const bool actual = ad::is_dual<test_type>::value;
            const bool expect = true;
            EXPECT_EQ(expect, actual);
        }
        //ublas::vector<dual<ublas::vector<double>>>
        {
            typedef ad::dual<ublas::vector<double>> dual_type;
            typedef ublas::vector<dual_type> test_type;
            const bool actual = ad::is_dual<test_type>::value;
            const bool expect = true;
            EXPECT_EQ(expect, actual);
        }
        //const ublas::vector<dual<ublas::vector<double>>>&
        //omit other cv cases
        {
            typedef ad::dual<ublas::vector<double>> dual_type;
            typedef const ublas::vector<dual_type>& test_type;
            const bool actual = ad::is_dual<test_type>::value;
            const bool expect = true;
            EXPECT_EQ(expect, actual);
        }
    } // TEST_F(TraitsTest, isDualTest)

    TEST_F(TraitsTest, hasConstClosureTypeTest)
    {
        // const_closure_type
        {
            typedef struct {
                typedef double const_closure_type;
            } test_type;
            const bool actual = ad::has_const_closure_type<test_type>::value;
            const bool expect = true;
            EXPECT_EQ(expect, actual);
        }
        // const_closure_type with reference
        {
            typedef struct {
                typedef double const_closure_type;
            }& test_type;
            const bool actual = ad::has_const_closure_type<test_type>::value;
            const bool expect = true;
            EXPECT_EQ(expect, actual);
        }
        // const_closure_type with const reference
        {
            typedef const struct {
                typedef double const_closure_type;
            }& test_type;
            const bool actual = ad::has_const_closure_type<test_type>::value;
            const bool expect = true;
            EXPECT_EQ(expect, actual);
        }
        // no const_closure_type
        {
            typedef struct {
            } test_type;
            const bool actual = ad::has_const_closure_type<test_type>::value;
            const bool expect = false;
            EXPECT_EQ(expect, actual);
        }
        // no const closure type with reference
        {
            typedef struct {
            }& test_type;
            const bool actual = ad::has_const_closure_type<test_type>::value;
            const bool expect = false;
            EXPECT_EQ(expect, actual);
        }
        // no const closure type with const reference
        {
            typedef const struct {
            }& test_type;
            const bool actual = ad::has_const_closure_type<test_type>::value;
            const bool expect = false;
            EXPECT_EQ(expect, actual);
        }
    } // TEST_F(TraitsTest, hasConstClosureTypeTest)

    TEST_F(TraitsTest, constClosureTypeTraitsTest)
    {
        // const_closure_type
        {
            typedef struct {
                typedef double const_closure_type;
            } test_type;
            typedef ad::const_closure_type_traits<test_type>::type actual_type;
            typedef double expect_type;

            const bool condition = std::is_same<expect_type, actual_type>::value;
            EXPECT_TRUE(condition);
        }
        // const_closure_type with reference
        {
            typedef struct {
                typedef double const_closure_type;
            }& test_type;
            typedef ad::const_closure_type_traits<test_type>::type actual_type;
            typedef double expect_type;

            const bool condition = std::is_same<expect_type, actual_type>::value;
            EXPECT_TRUE(condition);
        }
        // const_closure_type with const reference
        {
            typedef const struct {
                typedef double const_closure_type;
            }& test_type;
            typedef ad::const_closure_type_traits<test_type>::type actual_type;
            typedef double expect_type;

            const bool condition = std::is_same<expect_type, actual_type>::value;
            EXPECT_TRUE(condition);
        }
        // no const_closure_type
        {
            typedef struct {
            } test_type;
            typedef ad::const_closure_type_traits<test_type>::type actual_type;
            typedef double expect_type;

            const bool condition = std::is_same<expect_type, actual_type>::value;
            EXPECT_FALSE(condition);
        }
        // no const closure type with reference
        {
            typedef struct {
            }& test_type;
            typedef ad::const_closure_type_traits<test_type>::type actual_type;
            typedef double expect_type;

            const bool condition = std::is_same<expect_type, actual_type>::value;
            EXPECT_FALSE(condition);
        }
        // no const closure type with const reference
        {
            typedef const struct {
            }& test_type;
            typedef ad::const_closure_type_traits<test_type>::type actual_type;
            typedef double expect_type;

            const bool condition = std::is_same<expect_type, actual_type>::value;
            EXPECT_FALSE(condition);
        }
    } // TEST_F(TraitsTest, constClosureTypeTraitsTest)
} } // namespace algo { namespace ad_test {
