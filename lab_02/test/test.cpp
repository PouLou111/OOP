#include <gtest/gtest.h>
#include "../include/chocolate.h"

TEST(Test_01, positive){
    ASSERT_TRUE(chocolate(1, 1) == 0);
}

TEST(Test_02, positive){
    ASSERT_TRUE(chocolate(0, 0) == 0);
}

TEST(Test_03, positive){
    ASSERT_TRUE(chocolate(2, 2) == 3);
}

TEST(Test_04, positive){
    ASSERT_TRUE(chocolate(3, 5) == 14);
}

TEST(Test_05, positive){
    ASSERT_TRUE(chocolate(5, 3) == 14);
}

TEST(Test_06, positive){
    ASSERT_TRUE(chocolate(11, 10) == 109);
}

TEST(Test_07, negative){
    ASSERT_TRUE(chocolate(-7, 2) == 0);
}

TEST(Test_08, negative){
    ASSERT_TRUE(chocolate(-5, -2) == 0);
}

TEST(Test_09, negative){
    ASSERT_TRUE(chocolate(3, -4) == 0);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}