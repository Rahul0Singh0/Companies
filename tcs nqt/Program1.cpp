// https://takeuforward.org/data-structure/find-the-smallest-element-in-an-array
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
    // std::cout << arr[0] << std::endl;

    // Optimal solution - O(N) Time Complexity and O(1) Space Complexity
    int smallest = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] < smallest) {
            smallest = arr[i];
        }
    }

    std::cout << smallest << std::endl;
    return 0;
}