#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <unordered_set>

using namespace::std;

class Solution {
public:
      string longestPalindrome(string s) {
        int ss = s.size();
        if(ss == 0||ss == 1)
            return s;
        int dp[ss][ss];
        int maxl=0, maxlen=1;
        memset(dp, 0, sizeof(dp));
        
        for(int i = 0 ;i<ss;i++){
            dp[i][i] = 1;
            if(i+1<ss && s[i] == s[i+1])
            {
                dp[i][i+1] = 1;
                maxl = i;
                maxlen = 2;
            }
                
        }
        

        for(int len = 3;len<=ss;len++){
            for(int st=0;st+len-1<ss;st++){
                if(s[st] == s[st+len-1] && dp[st+1][st+len-2] == 1){
                    dp[st][st+len-1] = 1;
                    maxl = st;
                    maxlen = len;
                }
            }
        }
        
        return s.substr(maxl, maxlen);
    }
};