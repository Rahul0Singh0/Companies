/*
Input : N = 5, array[] = {1, 2, 3, 4, 5}, K = 2
Output (Left Rotation) : {3, 4, 5, 1, 2}
Explanation : After rotating left by 2, the first two elements move to the end.

Input : N = 5, array[] = {1, 2, 3, 4, 5}, K = 2
Output (Right Rotation) : {4, 5, 1, 2, 3}
Explanation : After rotating right by 2, the last two elements move to the start.
*/

// Bruteforce solution - Time Complexity: O(N*K)  
// Optimal Solution - Time Complexity: O(N)
#include <bits/stdc++.h>

void rotate(std::vector<int>& arr, int n, int k) {
    // right rotation
    std::reverse(arr.begin(), arr.begin() + (n - k));
    std::reverse(arr.begin() + (n - k), arr.end());
    std::reverse(arr.begin(), arr.end());

    // left rotation
    // std::reverse(arr.begin(), arr.begin() + k);
    // std::reverse(arr.begin() + k, arr.end());
    // std::reverse(arr.begin(), arr.end());
}

int main() {
    int n;
    std::cin>>n;
    std::vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        std::cin>>arr[i];
    }

    int k;
    std::cin>>k;

    k = k % n; // Handle cases where k >= n

    rotate(arr, n, k);

    // while (k--) {
    //     int temp = arr[0];
    //     for(int i = 0; i < n - 1; i++) {
    //         arr[i] = arr[i+1];
    //     }

    //     arr[n-1] = temp;
    // }

    for(int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    return 0;
}