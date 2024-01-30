#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "prefix_sum.h"

int test_ary_0[] = {};
int test_ary_1[] = {1, -2};
int test_ary_2[] = {-1};
int test_ary_3[] = {1, -1, 1, -1, 1};
int test_ary_4[] = {-1, 1, -1, 1, 1};
int test_ary_5[] = {-1, 1, -1, 1, -1};
int test_ary_6[] = {1};
int test_ary_7[] = {-1,1,1,-1};
int test_ary_8[] = {1, 1, -1, -1, -1};
int test_ary_9[] = {1, -1, 1, -1}; 
int test_ary_10[] = {-1, 1, -1, 1}; 
int test_ary_11[] = {1, 1, 1, 1};   
int test_ary_12[] = {-1, -1, -1, -1};
int test_ary_13[] = {1, -1, 1, -1}; 
int test_ary_14[] = {-1, 1, -1, 1}; 
int test_ary_15[] = {1, 1, 1, 1};   
int test_ary_16[] = {-1, -1, -1, -1}; 
int test_ary_17[] =  {-1, -1, -1, -1};
int test_ary_18[] = {};
int test_ary_19[] = {1, -1, 1, -1};
int test_ary_20[] = {1, -1, 1, -1};
int test_ary_21[] = {1, -1, 1, -1, 1, -1, 1, -1, 1, -1}; 
int test_ary_22[] = {1, -1, 1, -1, 1, -1, 1, -1, 1, -1};

TEST_CASE("prefix sum") {
    CHECK_EQ(prefix_sum(test_ary_0, 0), 0);
    CHECK_EQ(prefix_sum(test_ary_1, sizeof(test_ary_1) / sizeof(test_ary_1[0])), -1);

    SUBCASE("non-negative") {
        CHECK_FALSE(non_neg_prefix_sum(test_ary_0, 0));
        CHECK_EQ(non_neg_prefix_sum(test_ary_2, sizeof(test_ary_2) / sizeof(test_ary_2[0])), true);
        CHECK_EQ(non_neg_prefix_sum(test_ary_21, sizeof(test_ary_21) / sizeof(test_ary_21[0])), false);
        CHECK_FALSE(non_neg_prefix_sum(test_ary_3, sizeof(test_ary_3) / sizeof(test_ary_3[0])));
        WARN(non_neg_prefix_sum(test_ary_8, sizeof(test_ary_8)/sizeof(test_ary_8[0])) == true);
        WARN(non_neg_prefix_sum(test_ary_18, sizeof(test_ary_18)/sizeof(test_ary_18[0])) == false);
        WARN(non_neg_prefix_sum(test_ary_19,sizeof(test_ary_19)/sizeof(test_ary_19[0])) == false);
        REQUIRE(non_neg_prefix_sum(test_ary_9, sizeof(test_ary_9)/sizeof(test_ary_9[0])) == false);
        REQUIRE(non_neg_prefix_sum(test_ary_10, sizeof(test_ary_10)/sizeof(test_ary_10[0])) == true);
        REQUIRE(non_neg_prefix_sum(test_ary_11, sizeof(test_ary_11)/sizeof(test_ary_11[0])) == false);
        REQUIRE(non_neg_prefix_sum(test_ary_12, sizeof(test_ary_12)/sizeof(test_ary_12[0])) == true);
    }

    SUBCASE("non-positive") {
        CHECK_EQ(non_pos_prefix_sum(test_ary_4, sizeof(test_ary_4) / sizeof(test_ary_4[0])), true);
        CHECK_FALSE(non_pos_prefix_sum(test_ary_5, sizeof(test_ary_5)/sizeof(test_ary_5[0])));
        CHECK_EQ(non_pos_prefix_sum(test_ary_6, sizeof(test_ary_6)/sizeof(test_ary_6[0])), true);
        CHECK_EQ(non_pos_prefix_sum(test_ary_22, sizeof(test_ary_22) / sizeof(test_ary_22[0])), true);
        WARN(non_pos_prefix_sum(test_ary_7, sizeof(test_ary_7)/sizeof(test_ary_7[0])) == true);
        WARN(non_neg_prefix_sum(test_ary_17, sizeof(test_ary_17)/sizeof(test_ary_17[0])) == true);
        WARN(non_pos_prefix_sum(test_ary_20, sizeof(test_ary_20)/sizeof(test_ary_20[0])) == true);
        REQUIRE(non_pos_prefix_sum(test_ary_13, sizeof(test_ary_13)/sizeof(test_ary_13[0])) == true);
        REQUIRE(non_pos_prefix_sum(test_ary_14, sizeof(test_ary_14)/sizeof(test_ary_14[0])) == false);
        REQUIRE(non_pos_prefix_sum(test_ary_15, sizeof(test_ary_15)/sizeof(test_ary_15[0])) == true);
        REQUIRE(non_pos_prefix_sum(test_ary_16, sizeof(test_ary_16)/sizeof(test_ary_16[0])) == false);

    }
}
