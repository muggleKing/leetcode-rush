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
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if(!len)return -1;

        int st = 0, end = len - 1;
        while(st <= end){
            int mid = st + (end - st)/2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[st] <= nums[mid]){
                if(target >= nums[st] && target < nums[mid])
                    end = mid - 1;
                else
                    st = mid + 1;
            }else{
                if(target > nums[mid] && target <= nums[end])
                    st = mid + 1;
                else
                    end = mid - 1;
            }
        }
        return -1;
    }
};

