#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace::std;

class Solution {
public:

    vector<vector<int>> ans{};
    vector<string> generateParenthesis(int n) {
        vector<int> nums{};
        vector<string> sg{};
        if(n == 0)
            return sg;
        dfs(n, 0, nums);
        for(auto v : ans){
            string z = generateString(v);
            sg.push_back(z);
        }
        return sg;
    }

    void dfs(int n, int sum, vector<int>& nums){
        if(sum == n){
            ans.emplace_back(nums);
            return;
        }
        
        for(int i = 1;i<=n-sum;i++){
            nums.push_back(i);
            dfs(n, sum+i, nums);
            nums.pop_back();
        }
    }

    string generateString(vector<int> s){
        string zz{};
        for(auto i : s){
            int z = i;
            while(z--){
                zz += "(";
            }
            while(i--){
                zz += ")";
            }
        }
        return zz;
    }
};