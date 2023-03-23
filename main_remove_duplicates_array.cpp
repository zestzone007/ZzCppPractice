#include <cstdio>
#include <cstdint>
#include <vector>

using namespace std;

#ifndef PRINT_LN
#define println(fmt, ...) printf(fmt "\n", ##__VA_ARGS__)
#endif

void removeDuplicatesFromSortedArray(std::vector<int>& sortedArray){

    int arraySize = sortedArray.size();
    if(arraySize == 1){
        return;
    }
    int comparedPos = 0;
    int singleCount = 1;
    int duplicateCount = 0;
    while((singleCount + duplicateCount) < arraySize){
        if(sortedArray[comparedPos] == sortedArray[comparedPos+1]){
            sortedArray.erase(sortedArray.begin()+comparedPos +1);
            duplicateCount++;
        }else{
            singleCount++;
            comparedPos++;
        }
    }
}

int main(int argc, char** argv)
{
    println("main start");
    std::vector<int> arr = {1,2,2,4,5};
    removeDuplicatesFromSortedArray(arr);
    for(auto i= 0; i<arr.size();i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}