#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <unordered_set>

using namespace::std;

#define min(x,y)  (x<y?x:y);
#define max(x,y)  (x<y?y:x);
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ss,left,right;
        ss = height.size();
        left = 0;
        right = ss-1;
        int down = min(height[left], height[right]);
        int res = down * (right - left);
        while(left < right){
            while(height[left]<=down && left < right){
                left++;
            }
            down = min(height[left], height[right]);
            res = max(res, down * (right - left));


            while(height[right]<=down && left < right){
                right--;
            }
            down = min(height[left], height[right]);
            res = max(res, down * (right - left));
        }
        return res;
    }
};