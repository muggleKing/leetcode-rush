#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <unordered_set>

using namespace::std;

#define min(x,y)  (x<y?x:y);
#define max(x,y)  (x<y?y:x);

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

 class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
        int flag = 0;
        int len = nums.size();
        if(!len)return 0;
        int ma = nums[0];
        for(int i = 1;i<len;i++){
            if(nums[i] == nums[i-1] || nums[i]<=ma)
                continue;
            flag++;
            ma = nums[i];
            swap(nums, i, flag);
        }
        return flag+1;
    }

    void swap(vector<int>& nums, int s, int e){
        int tmp = nums[s];
        nums[s] = nums[e];
        nums[e] = tmp;
    }
};