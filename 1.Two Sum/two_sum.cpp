#include <stdio.h>
#include <vector>

using namespace::std;


class Solution {
public:
    /*------ brute solution ------*/
    vector<int> twoSum(vector<int>& nums, int target) {
        int ss = nums.size();
        vector<int> res{};
        for(int i = 0;i<ss;i++)
            for(int j=i+1;j<ss;j++)
                if(nums[i] + nums[j] == target){
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
        return res;
    }

    /*------ brute solution ------*/
    vector<int> twoSum(vector<int>& nums, int target) {
        int ss = nums.size();
        vector<int> res{};
        for(int i = 0;i<ss;i++)
            for(int j=i+1;j<ss;j++)
                if(nums[i] + nums[j] == target){
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
        return res;
    }
};