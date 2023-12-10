#include <iostream>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        int ans = 0;
        int i = 0;
        int rem = 0;
        
        while( i < 32){
            rem = n & ( 1 << i);
            ans = (ans << 1) | rem;
            i++;
        }
        
        return ans;
        
    }
};


int main(){
    Solution sol;

    cout << sol.reverseBits(43261596) << endl;
}