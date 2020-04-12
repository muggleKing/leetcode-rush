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
        string  intToRoman(int num) {
        int g,s,b,q;
        string nas{};

        q = num/1000;
        int qq = q;
        while(qq--){
            nas += "M";
        }

        b = (num - q*1000)/100;
        int bb = b;
        if(b == 9){
            nas+="CM";
        }else if(b == 4){
            nas+="CD";
        }else if(b >= 5){
            nas+="D";
            while(bb-- > 5){
                nas+="C";
            }
        } else{
            bb = b;
            while(bb--){
                nas+="C";
            }
        }

        s = (num - q*1000 - b*100)/10;
        int ss = s;
        if(s == 9){
            nas+="XC";
        }else if(s == 4){
            nas+="XL";
        }else if(s >= 5){
            nas+="L";
            while(ss-- > 5){
                nas+="X";
            }
        } else{
            ss = s;
            while(ss--){
                nas+="X";
            }
        }

        g = num%10;
        int gg = g;
        if(g == 9){
            nas+="IX";
        }else if(gg == 4){
            nas+="IV";
        }else if(gg >= 5){
            nas+="V";
            while(gg-- > 5){
                nas+="I";
            }
        } else{
            gg = g;
            while(gg--){
                nas+="I";
            }
        }
        return nas;
    }
};