/**
 * Given two integers your goal is to determine how many digits in the binary 
 * number need to be changed to represent the decimal number correctly (either
 * 0 change to 1 or vice versa).
 * For example: if decimal = 56, binary_String = "011000" then your program return 
 * only 1 digit need to be change in the binary number
 * 
 * Input : decimal_value = 56, binary="0010111111001"
 * output: 56 = "111000" ans = 5 bits differ
 * 
 * Input: decimal_value = 44, bianry = "111111"
 * Output: 44 = "101100", ans = 3 bits differ
 * 
 */

#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
struct Solution {
    int fun(int decimal_number, string binary_number) {
        int cnt = 0;
        // you can also use you own defined fun() to convert binary from decimal
        string binary_str = bitset<32>(decimal_number).to_string();
        int n = binary_number.size();
        binary_str.erase(binary_str.begin(), binary_str.end()-n);
        for(int i = 0; i < n; i++) {
            if(binary_number[i] != binary_str[i]) cnt++;
        }
        return cnt;
    }
};
int main() {
    Solution s;
    int decimal_number;
    cin>>decimal_number;
    string binary_number;
    cin>>binary_number;
    cout<<"\n"<<s.fun(decimal_number, binary_number);
    return 0;
}