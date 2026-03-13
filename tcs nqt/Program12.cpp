/*
Remove Duplicates From an Unsorted Array
Input: arr[]={2,3,1,9,3,1,3,9}
Output: {2,3,1,9}
Explanation: Removed all the duplicate elements.
Input: arr[]={4,3,9,2,4,1,10,89,34}
Output: {4,3,9,2,1,10,89,34}
Explanation: Removed all the duplicate elements.
*/
#include <bits/stdc++.h>
std::vector<int> removeDuplicates(std::vector<int>& arr) {
    std::vector<int> result;

    for (int i = 0; i < arr.size(); i++) {
        bool isFound = false;
        for (int j = 0; j < result.size(); j++) {
            if(arr[i] == result[j]) {
                isFound = true;
                break;
            }
        }
        
        // If not found
        if (!isFound) {
            result.push_back(arr[i]);
        }
    }

    return result;
}

std::vector<int> removeDuplicates1(std::vector<int>& arr) {
    std::unordered_map<int, bool> seen;
    std::vector<int> result;

    for (int i = 0; i < arr.size(); i++) {
        if (!seen[arr[i]]) {
            seen[arr[i]] = true;
            result.push_back(arr[i]);
        }
    }

    return result;
}
int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];   
    }

    std::vector<int> result = removeDuplicates1(arr);

    for(auto num : result) {
        std::cout << num << " ";
    }
    return 0;
}