/*

Ram is a student who often gets confused with lowercase and uppercase letters. 
He has decided to write an algorithm to resolve this issue. Given a string, you are required
to determine whether it should be converted to all uppercase or all lowercase, depending 
on the count of uppercase and lowercase letters in the string.

Input: A string s(1 <= x <= 1000) consisting of both uppercase and lowercase letters.

Output: Return the corrected string s. If the given strings has more uppercase letters than
        lowercase, return it in all uppercase. Otherwise, return it in all lowercase. 

For example:
    Input: "AbCdEfG"
    Output: "ABCDEFG"

    Input: "xYz"
    Output: "xyz"

    Input: "ABCabcXYZ"
    Output: "ABCABCXYZ" // acc. to que this is right output
    Output: "abcabcxyz" // Accenture give wrong expected output

 */

#include <iostream>
#include <string>
using namespace std;
int main() {
    string str;
    getline(cin, str);
    int l_cnt = 0, u_cnt = 0;
    for(char ch : str) {
        if(ch >= 'A' && ch <= 'Z') u_cnt++;
        else if(ch >= 'a' && ch <= 'z') l_cnt++;
    }
    string res;
    if(u_cnt > l_cnt) {
        for(auto ch : str) res.push_back(toupper(ch));   
    } else {
        for(auto ch : str) res.push_back(tolower(ch));
    }

    cout<<"\n"<<res;
    return 0;
}