/*
Remove Duplicates in-place from Sorted Array

Problem Statement: Given an integer array sorted in non-decreasing order, remove the duplicates in place such that each unique element appears only once. The relative order of the elements should be kept the same.

If there are k elements after removing the duplicates, then the first k elements of the array should hold the final result. It does not matter what you leave beyond the first k elements.

Input: arr[]=[1,1,2,2,2,3,3]
Output: [1,2,3,_,_,_,_]
Explanation: Total number of unique elements are 3, i.e[1,2,3] and Therefore return 3 after assigning [1,2,3] in the beginning of the array.
Input: arr[]=[1,1,1,2,2,3,3,3,3,4,4]
Output: [1,2,3,4,_,_,_,_,_,_,_]
Explanation: Total number of unique elements are 4, i.e[1,2,3,4] and Therefore return 4 after assigning [1,2,3,4] in the beginning of the array.
*/
#include <bits/stdc++.h>
// Bruteforce solution
// Time complexity - O(N), Space complexity - O(N)
int removeDuplicates(int arr[], const int n) {
    std::unordered_set<int> seen;
    int index = 0;
    for (int i = 0; i < n; i++) {
        // If not seen yet
        if (seen.find(arr[i]) == seen.end()) {
            seen.insert(arr[i]);
            arr[index++] = arr[i];
        }
    }
    return index;
}

// optimal solution using two pointers
int removeDuplicates1(int nums[], const int n) {
    int i = 0;
    for (int j = 1; j < n; j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i+1;
}
int main() {
    int n;
    std::cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    const int index = removeDuplicates1(arr, n);

    for(int i = 0; i < index; i++) {
        std::cout << arr[i] << " ";
    }
    return 0;
}