/**
 *  9900880077
 *  88007700
 *  770066
 *  6600
 *  55
 * 
 *  break down above pattern
 *  90807
 *  8070
 *  706
 *  60
 *  5
 */

#include<iostream>
int main() {
    int n = 5;
    int row = 9;
    for(int i = 1; i <= n; i++) {
        int col = row;
        for(int j = n; j >= i; j--) {
            if(j%2) {
                std::cout<<col;
                std::cout<<col;
                col--;
            }
            else {
                std::cout<<0;
                std::cout<<0;
            }
        }
        row--;
        std::cout<<std::endl;
    }
}