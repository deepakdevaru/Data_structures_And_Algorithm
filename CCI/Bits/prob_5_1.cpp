

#include <iostream>
#include <string>


using namespace std;

class Insertion
{
    public:

    string int_to_bin(uint32_t num);

    uint32_t insertion_m_n(uint32_t m , uint32_t n , int i , int j);

    string swap(string a){

        int l = 0 , h = a.size()-1;

        while (l < h){
            char temp = a[l];
            a[l] = a[h];
            a[h] = temp;

            l++;
            h--;

        }

        return a;
    }

    uint8_t flip_bit_to_win(uint32_t num);
     

};


string Insertion::int_to_bin(uint32_t num){
   
   if (num == 0) return "0";

    string result;
    uint8_t temp;

   while (num != 0){
      temp = num % 2;
      result.push_back('0' + temp);
      num = num / 2; 
   }

   return swap(result);

}

uint32_t Insertion::insertion_m_n(uint32_t m , uint32_t n , int i , int j){
       
       n = n | (m << i);

       return n;
}

uint8_t Insertion::flip_bit_to_win(uint32_t num){

    int slow = 0 , fast = 0 , count = 0 , zeros = 0;

    //loop till 31 bits of int 
    while (fast < 31){

        if (zeros > 1){
            if ((num & (1 << slow )) == 0){
                zeros--;
            }
            slow++;
        }

        // bit at fast is 1
        if(num &(1 << fast)){
              fast++;
              continue;
        }
        
        //found zero
        else if ((num &(1<<fast)) == 0){
            zeros++;

            //first zero
            if(zeros == 1 ){
               count  = max(count , (fast-slow+1));
               fast++;
               continue;
            }

            else if (zeros > 1){
                fast++;
                slow++;
            }

        }
    }

    return count;
}


int main(){

    Insertion ins;
    uint32_t n = 1;

    cout << "N is "<<n <<"in binary "<< ins.int_to_bin(n)<<endl;
    cout << " left shifted N is "<< (n << 31 )<<"in binary "<< ins.int_to_bin(n<<31)<<endl;



}