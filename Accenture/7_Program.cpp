#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
int rev(int n) {
    string s = to_string(n);
    bool flag = false;
    if(s[0] == '-') {
        flag =true;
    }
    string str(s.rbegin(), s.rend());
    int rev = stoi(str);
    if(rev > INT_MAX || rev < INT_MIN) return 0;
    return flag == true ? -rev : rev;
}
int main() {
    int n;
    cin>>n;
    cout<<rev(n);
    return 0;
}