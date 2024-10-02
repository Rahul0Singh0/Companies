/*
You are given a function.
int CheckPassword(char str[], int n);
The function accepts string str of size n as an argument. 
Implement the function which returns 1 if given string str is valid password else 0.
str is a valid password if it satisfies the below conditions.

– At least 4 characters
– At least one numeric digit
– At Least one Capital Letter
– Must not have space or slash (/)
– Starting character must not be a number
Assumption:
Input string will not be empty.

Example:

Input 1:
aA1_67
Input 2:
a987 abC012

Output 1:
1
Output 2:
0
*/

#include<iostream>
#include<cstring>
#include<set>
using namespace std;
bool CheckPassword(char *str, int n) {
    set<char> s{'0','1','2','3','4','5','6','7','8','9'};
    if(n < 4) return 0; // base cond.
    if(s.find(str[0]) != s.end()) return 0; // starting char is number
    int dcnt = 0, Ccnt = 0;
    for(int i = 0; i < n; i++) {
        if(str[i] == ' ' || str[i] == ' ') return 0;
        if(s.find(str[i]) != s.end()) dcnt++;
        if(str[i] >= 'A' && str[i] <= 'Z') Ccnt++;
    }
    if(dcnt == 0 || Ccnt == 0) return 0;
    return 1;
}
int main() {
    char *str = new char;
    gets(str);
    int n = strlen(str);
    cout<<"\n"<<CheckPassword(str, n);
    return 0;
}