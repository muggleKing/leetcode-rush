#include <stdio.h>
#include <vector>
#include <map>

using namespace::std;


class Solution {
public:
    /*------ brute solution ------*/
    vector<int> twoSum1(vector<int>& nums, int target) {
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

    /*------ hashmap solution ------*/
    vector<int> twoSum2(vector<int>& nums, int target) {
        int ss = nums.size();
        map<int, int> hashmap;
        vector<int> res{};
        for(int i = 0;i<ss;i++)
            hashmap[nums[i]] = i;
        map<int, int>::iterator iter;  
        for(int i = 0;i<ss;i++)
        {
            iter = hashmap.find(target - nums[i]);
            if(iter!=hashmap.end() && iter->second!=i){
                res.push_back(i);
                res.push_back(iter->second);
                return res;
            }
        }
        
        return res;
    }
};