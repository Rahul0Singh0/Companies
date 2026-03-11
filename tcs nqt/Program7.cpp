/* 
Input: N = 5, array[] = {1,2,3,4,5}
Output: 15
Explanation: Sum of all the elements is 1+2+3+4+5 = 15

Input:  N=6, array[] = {1,2,1,1,5,1}
Output: 11
Explanation: Sum of all the elements is 1+2+1+1+5+1 = 11
*/

#include <bits/stdc++.h>
int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }   

    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    std::cout << sum << std::endl;
    return 0;
}
