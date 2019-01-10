#include <gtest/gtest.h>
#include <vector>
#include "../Ex9AllTogether/Ex8ThreadSort/ThreadSort.hh"
#include "../Ex9AllTogether/Ex5IterMerge/MergeSort.hh"

TEST(SORTTHREAD, WITHNOTTHREADEDEQ){
    std::vector<int> vecNorm{9,8,7,6,5,4,3,2,1,0};
    std::vector<int> vecThread{9,8,7,6,5,4,3,2,1,0};

    mergeSort(vecNorm.begin(), vecNorm.end());
    mergeSortThread(vecThread.begin(), vecThread.end());

    for(int i=0; i<10; i++)
        EXPECT_EQ(vecNorm[i], vecThread[i]);   
}