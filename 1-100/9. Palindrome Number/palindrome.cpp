#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <unordered_set>

using namespace::std;

class Solution {
public:
      bool isPalindrome(int x) {
        if(x < 0)
            return false;

        string s = to_string(x);
        int ss = s.size();

        if(ss == 1)
            return true;
            
        int left = 0, right = ss-1;
        while(left<=right){
            if(s[left]!=s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};