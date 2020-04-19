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
    void swap(vector<int>& nums, int s, int e){
        int tmp = nums[s];
        nums[s] = nums[e];
        nums[e] = tmp;
    }

    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        if(!len)return 0;
        int flag = 0;
        for(int i = 0;i<len;i++){
            if(nums[i]==val)
                continue;
            swap(nums, i, flag);
            flag++;
        }
        return flag;
    }
};