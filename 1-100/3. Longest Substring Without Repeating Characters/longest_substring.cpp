#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <unordered_set>

using namespace::std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ss = s.size();
        int left = 0;
        int maxlen = 0;
        if(ss == 0)
            return 0;

        unordered_set<int> win;
        for(int i = 0;i < ss;i++){
            while(win.find(s[i]) != win.end()){
                win.erase(s[left]);
                left++;
            }
            win.insert(s[i]);
            maxlen = (maxlen<i-left+1?i-left+1:maxlen);
        }
        return maxlen;
    }
};