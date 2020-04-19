#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <unordered_set>
#include <queue>

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
    struct cmp{
        bool operator() (ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue< ListNode*, vector<ListNode*>, cmp> priorityQueue{};
        for(auto i : lists){
            if(i)priorityQueue.push(i);
        }

        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;
        while(!priorityQueue.empty()){
            ListNode* tmp = priorityQueue.top();
            priorityQueue.pop();
            dummy->next = tmp;
            dummy = tmp;
            if(tmp->next)
                priorityQueue.push(tmp->next);
        }

        return head->next;
    }
};