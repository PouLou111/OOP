#include <gtest/gtest.h>
#include "../include/figure.h"
#include "../include/triangle.h"
#include "../include/hexagon.h"
#include "../include/octagon.h"

TEST(Trian, area_trian){
    Triangle triangle(1, 1, 2, 2, 2, 1);
    float t = triangle.Area();
    ASSERT_TRUE(t ==  0.5);
}
TEST(Trian, sravn){
    Triangle triangle1(1, 1, 2, 2, 2, 1);
    Triangle triangle2(1, 1, 2, 2, 2, 1);
    ASSERT_TRUE(triangle1 == triangle2);
}
TEST(Trian, prisv){
    Triangle triangle1(1, 1, 2, 2, 2, 1);
    Triangle triangle2 = triangle1;
    ASSERT_TRUE(triangle1 == triangle2);
}
TEST(Trian, vert){
    Triangle triangle1(1, 1, 2, 2, 2, 1);
    int i = triangle1.VertexesNumber();
    ASSERT_TRUE(i == 3);
}
TEST(Hexag, sravn){
    Hexagon hexagon1(1, 1, 2, 2, 3, 3, 4, 4, 5,5 ,6 ,6);
    Hexagon hexagon2(1, 1, 2, 2, 3, 3, 4, 4, 5,5 ,6 ,6);
    ASSERT_TRUE(hexagon1 == hexagon2);
}
TEST(Hexag, prisv){
    Hexagon hexagon1(1, 1, 2, 2, 3, 3, 4, 4, 5,5 ,6 ,6);
    Hexagon hexagon2 = hexagon1;
    ASSERT_TRUE(hexagon1 == hexagon2);
}
TEST(Hexag, vert){
    Hexagon hexagon1(1, 1, 2, 2, 3, 3, 4, 4, 5,5 ,6 ,6);
    int i = hexagon1.VertexesNumber();
    ASSERT_TRUE(i == 6);
}
TEST(Octag, sravn){
    Octagon octagon1(1, 1, 2, 2, 3, 3, 4, 4, 5,5 ,6 ,6,7, 7, 8, 8);
    Octagon octagon2(1, 1, 2, 2, 3, 3, 4, 4, 5,5 ,6 ,6,7, 7, 8, 8);
    ASSERT_TRUE(octagon1 == octagon2);
}
TEST(Octag, prisv){
    Octagon octagon1(1, 1, 2, 2, 3, 3, 4, 4, 5,5 ,6 ,6,7, 7, 8, 8);
    Octagon octagon2 = octagon1;
    ASSERT_TRUE(octagon1 == octagon2);
}
TEST(Octag, vert){
    Octagon octagon1(1, 1, 2, 2, 3, 3, 4, 4, 5,5 ,6 ,6,7, 7, 8, 8);
    int i = octagon1.VertexesNumber();
    ASSERT_TRUE(i == 8);
}



int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}