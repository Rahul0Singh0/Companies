// https://takeuforward.org/data-structure/reverse-a-given-array
#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }


    // Brute Force Approach
    // Time Complexity: O(n), Space Complexity: O(n)
    // std::vector<int> reversedArr(n);
    // for(int i = 0; i < n; i++) {
    //     reversedArr[i] = arr[n - 1 - i];
    // }

    // Optimal Approach (Two Pointer Approach)
    // Time Complexity: O(n), Space Complexity: O(1)
    int left = 0;
    int right = n - 1;
    while(left < right) {
        std::swap(arr[left++], arr[right--]);
    }

    for(int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }   

    return 0;
}