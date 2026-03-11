/*
    Input: [8 7 1 6 5 9]
    Output: [1 5 6 9 8 7]
    Explanation: First three elements are in the ascending order and next three elements are in the descending order.

    Input: [4 2 8 6 15 5 9 20]
    Output: [2 4 5 6 20 15 9 8]
    Explanation: First four elements are in the ascending order and next four elements are in the descending order.
 */

#include <bits/stdc++.h>
int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::sort(arr.begin(), arr.end());

    int second_half = (n + 1) / 2;

    std::reverse(arr.begin() + second_half, arr.end());
    
    for(int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}