/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <stdio.h>
#include <vector>
#include <map>

using namespace::std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    /* brute solution*/
    ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) { 
        int tmp = 0;
        int res = 0;
        ListNode *head = new ListNode(0);
        ListNode *root = head;
        
        while(l1 || l2 || tmp>0){
            res = 0;
            if(l1){
                res += l1->val;
                l1 = l1->next;
            }
            if(l2){
                res += l2->val;
                l2 = l2->next;
            }
            res += tmp;
            tmp = res / 10;
            res = res % 10;

            ListNode *cur = new ListNode(res);
            head->next = cur;
            head = cur;
        }
        return root->next;
    }
};