#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <unordered_set>

using namespace::std;

int binarySearch(vector<int> nums, int target){
    int left = 0;
    int right = sizeof(nums) - 1;

    while (left <= right)
    {
        int mid = left + (right - left)/2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] < target)
            left = mid + 1;
        else if(nums[mid] > target)
            right = mid - 1;
    }
    return -1;
}