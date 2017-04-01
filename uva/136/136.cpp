#include <iostream>
#include <stdint.h>

int main(){
    uint32_t ugly[1500];
    uint32_t factor_2_ptr, factor_3_ptr, factor_5_ptr;

    //The first ugly number
    ugly[0] = 1;

    //All pointers start at the first ugly number
    factor_2_ptr = factor_3_ptr = factor_5_ptr = 0;
    for (int16_t i = 1; i < 1500; i++){
        //Get the next possible 3 numbers
        uint32_t factor_2_next = ugly[factor_2_ptr] * 2;
        uint32_t factor_3_next = ugly[factor_3_ptr] * 3;
        uint32_t factor_5_next = ugly[factor_5_ptr] * 5;

        //Choose the smallest amonst the 3 to be the next ugly number
        //increment the factor pointer by 1 as well
        if (factor_2_next <= factor_3_next && factor_2_next <= factor_5_next){
            ugly[i] = factor_2_next;
            factor_2_ptr ++;
        }
        if (factor_3_next <= factor_2_next && factor_3_next <= factor_5_next){
            ugly[i] = factor_3_next;
            factor_3_ptr ++;
        }
        if (factor_5_next <= factor_2_next && factor_5_next <= factor_3_next){
            ugly[i] = factor_5_next;
            factor_5_ptr ++;
        }
    }
    std::cout << "The 1500'th ugly number is " << ugly[1499] << "." << std::endl;

    return 0;
}
