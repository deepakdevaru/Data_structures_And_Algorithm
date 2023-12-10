#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        bool neg = false;
        int rem =0;
        char dig[5] = {'a','b','c','d','e'};
    
        std::string ans;
        
        int i = 7;
        
        if (num == -1) return "ffffffff";
        
        while(i>=0){
            rem = 0;
            rem = (num >> (4*i))&0xf;
            
            num = num <<4;
            
            if(rem >=10){
                ans.push_back(dig[rem - 10]);
            }
            
            else{
                ans.push_back('0'+rem);
            }
            
                   i--;
            
        }
        
        return ans;
    }
};

int main(){

    Solution sol;
    cout <<  sol.toHex(26) <<endl;

    


}