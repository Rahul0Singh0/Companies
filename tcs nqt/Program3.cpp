// https://takeuforward.org/data-structure/find-second-smallest-and-second-largest-element-in-an-array
#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int smallest = INT_MAX, secondSmallest = INT_MAX;
    int largest = INT_MIN, secondLargest = INT_MIN;

    for(int i = 0; i < n; i++) {
        if(arr[i] < smallest) {
            secondSmallest = smallest;
            smallest = arr[i];
        }

        if(arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        }

        if(arr[i] > smallest && arr[i] < secondSmallest) {
            secondSmallest = arr[i];
        }

        if(arr[i] < largest && arr[i] > secondLargest) {
            secondLargest = arr[i];
        }
    }

    if(secondSmallest == INT_MAX) {
        std::cout << "No second smallest element" << std::endl;
    } else {
        std::cout << "Second smallest element: " << secondSmallest << std::endl;
    }

    if(secondLargest == INT_MIN) {
        std::cout << "No second largest element" << std::endl;
    } else {
        std::cout << "Second largest element: " << secondLargest << std::endl;
    }

    return 0;
}