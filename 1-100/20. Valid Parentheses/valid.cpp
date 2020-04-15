#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <unordered_set>
#include <stack>

using namespace::std;

#define min(x,y)  (x<y?x:y);
#define max(x,y)  (x<y?y:x);

class Solution {
public:
       map<char,char> pp = {{']','['},{'}','{'},{')','('}};
    bool isValid(string s) {
        int ss = s.size();
        if(!ss)return true;
        if(ss%2==1)return false;
        stack<char> st{};
        map<char,char>::iterator iter;
        for(auto c : s){
            iter = pp.find(c);
            if(iter == pp.end())
                st.push(c);
            else{
                if(st.empty() || st.top()!=pp[c])
                    return false;
                else
                    st.pop();
            }
        }
        if(st.empty())
            return true;
        return false;
    }
};