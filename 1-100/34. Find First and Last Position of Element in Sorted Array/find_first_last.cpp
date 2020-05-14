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
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int> ans{-1,-1};
        if(!len)return ans;
        int left = -1, right = -1;

        int st = 0, end = len;
        while(st < end){
            int mid = st + (end - st)/2;
            if(nums[mid] == target){
                end = mid;
            }else if(nums[mid] < target){
                st = mid + 1;
            }else if(nums[mid] > target){
                end = mid;
            }
        }

        if(st == len)
            left = -1;
        else
        {
            left = (nums[st] == target?st:-1);
        }

        st = 0; 
        end = len;
        while(st < end){
            int mid = st + (end - st)/2;
            if(nums[mid] == target){
                st = mid + 1;
            }else if(nums[mid] < target){
                st = mid + 1;
            }else if(nums[mid] > target){
                end = mid;
            }
        }
        if(st == 0)
            right = -1;
        else
        {
            right = (nums[st-1]==target?st-1:-1);
        }

        vector<int> z{};
        z.push_back(left);
        z.push_back(right);

        return z;
            
    }
    
};

