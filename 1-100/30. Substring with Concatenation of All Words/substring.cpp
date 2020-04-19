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
       vector<int> findSubstring(const string& s, vector<string>& words) {
        int ss = words.size();
        vector<int> ans{};
        if(!ss)return ans;
        map<string, int> zz{};
        map<string, int>::iterator itr;
        for(auto w : words){
            itr = zz.find(w);
            if(itr!=zz.end())
                zz[w] += 1;
            else
                zz[w] = 1;
        }
        
        int len = words[0].size();
        int nlen = ss * len;
        ss = s.size();
        for(int i=0;i<=ss-nlen;i++){
            int j = i;
            map<string, int> tt = zz;
            
            while(j+len-1 < ss){
                string tmp = s.substr(j, len);
                itr = tt.find(tmp);
                if(itr == tt.end()){
                    break;
                }else{
                    if(tt[tmp] != 1){
                        tt[tmp]--;
                    }else if(tt[tmp] == 1){
                        tt.erase(tmp);
                    }
                }
                if(tt.empty()){ans.push_back(i);break;}
                j = j+len;
            }
            
        }
        return ans;
    }
};