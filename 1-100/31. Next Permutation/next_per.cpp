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
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if(!len||len==1)return;
        int min = nums.back();
        int flag = len-1;
        int max = -1;
        for(int i = len-1;i>=0;i--){
            int min = INT_MAX;
            if(nums[i]<max){
                for(int j = i+1;j<len;j++){
                    if(nums[j]>nums[i] && nums[j]<min){
                        flag = j;
                        min = nums[j];
                    }
                }
                swap(nums, i , flag);
                sort(nums.begin()+i+1, nums.end());
                return;
            }
            max = (nums[i]>max?nums[i]:max);
        }
        sort(nums.begin(), nums.end());
        return;
    }

    void swap(vector<int>& nums, int s, int e){
        int tmp = nums[s];
        nums[s] = nums[e];
        nums[e] = tmp;
    }
};