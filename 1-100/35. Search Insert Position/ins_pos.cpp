#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <unordered_set>

using namespace::std;

#define min(x,y)  (x<y?x:y);
#define max(x,y)  (x<y?y:x);

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int st = 0;
        int len = nums.size();
        int end = len - 1;

        while(st <= end){
            int mid = st + (end - st)/2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] < target){
                st = mid + 1;
            }else if(nums[mid] > target){
                end = mid - 1;
            }
        }

        if(st == len)return len;
        if(end == -1)return 0;
        return (nums[end]>target?end:end+1);
    }
};