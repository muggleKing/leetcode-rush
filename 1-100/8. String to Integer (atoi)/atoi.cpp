#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <unordered_set>

using namespace::std;

class Solution {
public:
         int myAtoi(string str) {
        int pos=0;
        int max = 0x7fffffff, min = 0x80000000;
        while(str[pos] == ' ')pos++;

        bool neg = false;
        if(str[pos] == '-' || str[pos] == '+'){
            neg = (str[pos] == '-');
            pos++;
        }

        long long res = 0;
        if(str[pos] < '0' || str[pos] > '9'){
            return 0;
        }else{
            while((str[pos] >= '0' && str[pos] <= '9')){
                res = res * 10 + (str[pos] - '0');
                pos++;
                if(-res < min && neg)
                    return INT_MIN;
                if(res > max && !neg)
                    return INT_MAX;

            }
        }

        if(neg)
            res = 0 - res;

        return res;
    }
};
  
