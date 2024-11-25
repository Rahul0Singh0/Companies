// Balanced Strings
/**
 * You are given a string S that consists  only of lowercase English alphabets. 
 * A string is called a balanced string if it contains an equal number of unique vowels
 * and unique consonants.
 * Task: Determine the number of substrings of S that are balanced substrings.
 * example: S = 'ada'
 *          Substrings          unique vowels       unique conso.       Balanced String
 *              a                     1                   0                  no
 *              ad                    1                   1                  yes
 *              ada                   1                   1                  yes
 *              d                     0                   1                  no
 *              da                    1                   1                  yes
 *              a                     1                   0                  no
 *  Output: 3 substrings that are balanced.
 * 
 * Constraints:
 * 1 <= t <= 10
 * 1 <= |S| <= 10^5
 * |S| denotes length of string S
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// O(N^3)  TLE
// vector<string> substrings(string& str) {
//     vector<string> res;
//     for (int i = 0; i < str.size(); i++) {
//         for(int j = i; j < str.size(); j++) {
//         string s = "";
//             // for(int k = i; k <= j; k++) {
//             //     s += str[k];
//             // } 
//         s = str.substr(i, j);
//         res.push_back(s);
//         }
//     }
//     return res;
// }

// Time : O(N^2)
vector<string> substrings(string& str) {
    vector<string> res;
    for (int i = 0; i < str.size(); i++) {
        string s = "";
        for(int j = i; j < str.size(); j++) {
            s += str[j];
            res.push_back(s);
        }
    }
    return res;
}


int f(string& str) {
    int res = 0;
    unordered_set<char> vowel{'a','e','i','o','u'};
    unordered_set<char> vowelCount, consoCount;
    vector<string> substr = substrings(str);
    for(auto s : substr) {
        vowelCount.clear();
        consoCount.clear();
        for(auto ch : s) {
            if(vowel.count(ch)) {
                vowelCount.insert(ch);
            } else {
                consoCount.insert(ch);
            }
        }
        if(vowelCount.size() == consoCount.size()) {
                res++;
        }
    }
    return res;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        string str;
        cin>>str;
        cout<<f(str)<<endl;
    }
    return 0;
}