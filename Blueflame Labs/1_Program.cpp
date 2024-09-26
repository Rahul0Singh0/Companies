/**
 * Problem Statement: Read the input strings and modify it as per the following algorithm:
 *                    1. Replace every letter by its adjacent letter (a becomes b, b becomes c,.....).
 *                       All special characters remains the same.
 *                    2. Capitalize every vowels(a,e,i,o,u) in this new string.
 *                    
 *                    The function modify_string() accepts the parameters string inp_string. Complete the function
 *                    modify_string() by returning the modified string.
 *                    
 *                    Constraints:
 *                    1 <= length of string <= 100
 *      
 *                    Example 1:  input: "xobin bootcamp",   output: "ypcjO cppUdbnq"
 * 
 * 
 */

#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;
class Solution {
public:
    string modify_string(string inp_string) {
        string modified_string = "";
        unordered_set<char> set = {'a','e','i','o','u'};
        for(char c : inp_string) {
            if(c >= 'a' && c <= 'z') {modified_string += 'a' + (c - 'a' + 1) % 26;}
            else if(c >= 'A' && c <= 'Z') {modified_string += 'A' + (c - 'A' + 1) % 26;}
            else modified_string += c;
        }
        // Captilized every vowels
        for(int i = 0; i < modified_string.length(); i++) {
            if(set.find(modified_string[i]) != set.end()) {
                modified_string[i] = toupper(modified_string[i]);
            }
        }
        return modified_string;
    }
};
int main() {
    string str = "xobin bootcamp";
    Solution s;
    cout<<s.modify_string(str);
    return 0;
}