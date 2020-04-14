#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace::std;

#define min(x,y)  (x<y?x:y);
#define max(x,y)  (x<y?y:x);

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
         sort(nums.begin(), nums.end());
            int len = nums.size();
            int minn = nums[0] + nums[1] + nums[2], maxn = nums[len-1] + nums[len-2] + nums[len-3];
            if(minn > target)return minn;
            if(maxn < target)return maxn;
            if(len == 3)return minn;
            int left,right;
            int ans  =INT_MAX, bias = INT_MAX;
            for(int i = 0;i<len-2;i++){
                left = i+1, right = len - 1;
                while(left<right){
                    if(nums[i] + nums[left] + nums[right] == target)
                        return target;
                    else{
                        while(nums[i] + nums[left] + nums[right] < target && left<right){
                            int b = abs(nums[i] + nums[left] + nums[right] - target);
                            if(b < bias){
                                bias = b;
                                ans = nums[i] + nums[left] + nums[right];
                            }
                            left++;
                        }
                        while(nums[i] + nums[left] + nums[right] > target && left<right){
                            int b = abs(nums[i] + nums[left] + nums[right] - target);
                            if(b < bias){
                                bias = b;
                                ans = nums[i] + nums[left] + nums[right];
                            }
                            right--;
                        }
                    }
                }
        }
            return ans;
    }
};