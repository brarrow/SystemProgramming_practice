#include <gtest/gtest.h>
#include "../Ex4Array/MyArray.hh"

struct TESTARR: public ::testing::Test{
	MyArray<int> arr1; 
	MyArray<int> arr2;
	void SetUp(){
		arr1.setMat(2,2,1,2,3,4);
	       	arr2.setMat(2,2,4,3,2,1);
	}
};
TEST_F(TESTARR, ALLARIFM){
	MyArray<int> res = (arr1 * arr2 / arr2 + arr1 - arr1) % arr2;
	EXPECT_EQ(1, res(0, 0));
	EXPECT_EQ(2, res(0, 1));
	EXPECT_EQ(1, res(1, 0));
	EXPECT_EQ(0, res(1, 1));
}
TEST_F(TESTARR, MORE){
        MyArray<bool> res = (arr1 > arr2);
        EXPECT_EQ(false, res(0, 0));
        EXPECT_EQ(false, res(0, 1));
        EXPECT_EQ(true, res(1, 0));
        EXPECT_EQ(true, res(1, 1));
}
TEST_F(TESTARR, mask){
        MyArray<bool> Mask(2, 2, true, false, true, false);
	MyMaskedArray<int> maskMat;
	maskMat = arr1(Mask);
	maskMat = 0;
        EXPECT_EQ(0, arr1(0, 0));
        EXPECT_EQ(2, arr1(0, 1));
        EXPECT_EQ(0, arr1(1, 0));
        EXPECT_EQ(4, arr1(1, 1));
}
