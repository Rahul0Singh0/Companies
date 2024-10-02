// 10 aug 2012
/*
Problem Description :
The Binary number system only uses two digits, 0 and 1 and number system can be called 
binary string. 
You are required to implement the following function:

    int OperationsBinaryString(char* str);

The function accepts a string str as its argument. The string str consists of 
binary digits separated with an alphabet as follows:

– A denotes AND operation
– B denotes OR operation
– C denotes XOR Operation
You are required to calculate the result of the string str, 
scanning the string to right taking one opearation at a time, and return the same.

Note:
No order of priorities of operations is required
Length of str is odd
If str is NULL or None (in case of Python), return -1

Input:
str: 1C0C1C1A0B1

Output:
1

Explanation:
The alphabets in str when expanded becomes “1 XOR 0 XOR 1 XOR 1 AND 0 OR 1”, result of the expression becomes 1, hence 1 is returned.

Sample Input:
0C1A1B1C1C1B0A0

Output:
0
*/

#include <iostream>
#include <string>
#include <cstring>
// #include <bits/stdc++.h>
using namespace std;
int OperationsBinaryString(char* str) {
    if (str == nullptr) return -1;
    int res = *str - '0'; // str[0] - '0'
    for(int i = 1; str[i] != '\0'; i += 2) {
        char ch = str[i];
        int digit = str[i+1] - '0';
        switch(ch) {
            case 'A': 
                res &= digit; 
                break; 
            case 'B': 
                res |= digit; 
                break; 
            case 'C': 
                res ^= digit; 
                break; 
        }
    }
    return res;
}

int main() {
    char *str = new char;
    // int n; cin>>n; // no of character in a string
    // fgets(str, n, stdin); // c function
    gets(str); // c function
    // cout<<str;
    
    // string s;
    // cin>>s;
    // char *str = &s[0];
    
    cout<<"\n"<<OperationsBinaryString(str);
    return 0;
}