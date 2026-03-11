/*
Example 1:
Input: int n = 6, arr[] = {10,5,10,15,10,5};
Output: 10  3
        5  2
        15  1
*/


// Bruteforce solution 
#include <bits/stdc++.h>
// Optimized solution
void freqCount(std::vector<int>& arr, int n) {
    std::unordered_map<int, int> freq;

    for(int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    for(auto x : freq) {
        std::cout << x.first << " " << x.second << std::endl;
    }
}
int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    
    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    
    // Time Complexity - O(N^2) and Space Complexity - O(N)
    std::vector<int> visited(n, false);

    for(int i = 0; i < n; i++) {
        int count = 1;
        if(visited[i] == true) {
            continue;
        } 
           
        for(int j = i+1; j < n; j++) {
            if(arr[i] == arr[j]) {
                visited[j] = true;
                count++;
            }
        }
        std::cout << arr[i] << " " << count << std::endl;    
    }

    std::cout << " --------------------------------------- " << std::endl;

    freqCount(arr, n);  // O(N) for time and space complexity

    return 0;
}