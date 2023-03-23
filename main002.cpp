#include <cstdio>
#include <cstdint>
#include <vector>

using namespace std;

#ifndef PRINT_LN
#define println(fmt, ...) printf(fmt "\n", ##__VA_ARGS__)
#endif

    bool isAllZero(vector<int>& nums, int& minimum){
        bool isAllZero = true;
        size_t numsSize = nums.size();
        minimum = 0;
        for(int i=0;i<numsSize;i++){
            int item = nums[i];
            if(item != 0){
                isAllZero = false;
                if(minimum == 0){
                    minimum = item;
                }else if(item < minimum){
                    minimum = item;
                }
            }
        }
        return isAllZero;
    }

int minimumOperations(vector<int>& nums) {
    int count = 0;
    int curMinimum = 0;
    size_t numsSize = nums.size();
    while(!isAllZero(nums,curMinimum)){
        for(int i=0;i<numsSize;i++){
            if(nums[i] != 0){
                printf("nums[%d] = %d ", i, nums[i]);
                nums[i] = nums[i] - curMinimum;
            }
        }
        printf("\n");
        count ++;
    }
    return count;
}


int main(int argc, char** argv)
{
    println("main start");
    std::vector<int> arr = {1,5,0,3,5};
    int count = minimumOperations(arr);
    printf("count = %d",count);
    return 0;
}