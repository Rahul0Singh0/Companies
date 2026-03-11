// https://takeuforward.org/data-structure/find-the-largest-element-in-an-array
#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    // Brute foce solution - O(N log N) Time Complexity and O(1) Space Complexity
    // std::sort(arr.begin(), arr.end()); // accending order
    // std::cout << arr[n-1] << std::endl;

    // Optimal solution - O(N) Time Complexity and O(1) Space Complexity
    int largest = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > largest) {
            largest = arr[i];
        }
    }

    std::cout << largest << std::endl;
    return 0;
}