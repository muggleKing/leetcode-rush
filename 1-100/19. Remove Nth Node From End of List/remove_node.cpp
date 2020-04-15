#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <unordered_set>

using namespace::std;

#define min(x,y)  (x<y?x:y);
#define max(x,y)  (x<y?y:x);

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 1;
        ListNode *tmp = head, *pre;
        while(tmp->next){
            len++;
            tmp = tmp->next;
        }
                if(len == 1)
            return NULL;
                    if(n == len)
            return head->next;
        tmp = head;
        int pos = len - n +1;
        while(--pos){
            if(pos == 1)
                pre = tmp;
            tmp = tmp->next;
        }
        if(tmp->next){
            pre->next = tmp->next;
            tmp->next = nullptr;
        }else{
            pre->next = NULL;
        }

        return head;
    }
};