#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace::std;

#define min(x,y)  (x<y?x:y);
#define max(x,y)  (x<y?y:x);

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string r = strs.size()?strs[0]:"";
        for(auto s:strs){
            while(s.substr(0, r.size())!=r){
                r = r.substr(0, r.size()-1);
                if(r=="")return r;
            }
        }
            return r;
    }
};