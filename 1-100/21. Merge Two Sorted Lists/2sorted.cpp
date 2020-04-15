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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* ans = head;
        while(l1!=NULL&&l2!=NULL){
            if(l1->val < l2->val){
                head->next = l1;
                head = l1;
                l1 = l1->next;
            }else{
                head->next = l2;
                head = l2;
                l2 = l2->next;
            }
        }
        if(l1!=NULL){
            head->next = l1;
        }
        if(l2!=NULL){
            head->next = l2;
        }
        return ans->next;
    }
};