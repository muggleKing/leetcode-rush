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
    vector<string> ans; // 设为全局变量，方便helper函数引用
    vector<string> sList={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"}; //字符表，注意不能用括号声明

    vector<string> letterCombinations(string digits) {
        if(!digits.size())return {};
        helper(digits, {}, 0);
        return ans;
    }

    void helper(string digits, string s, int idx){
        if(idx == digits.size())
            ans.emplace_back(s);
        else{
            int pos = digits[idx] - '0';
            string tmpStr = sList[pos];
            for(int i=0;i<tmpStr.size();i++){
                helper(digits, s+tmpStr[i], idx+1);
            }
        }
    }
};