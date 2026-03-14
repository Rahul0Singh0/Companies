/*
Problem Statement: Find all the repeating elements present in an array.
Arr[] = [1,1,2,3,4,4,5,2]
Output:
 1,2,4
Explanation:
 1,2 and 4 are the elements which are occurring more than once.
*/
#include <bits/stdc++.h>
//Better solution - by first sorting them
void findRepeatedElements(std::vector <int> nums) {
    std::sort(nums.begin(), nums.end());

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i-1] == nums[i]) {
            std::cout << nums[i-1] << " ";
        }
    }
    std::cout << std::endl;
}

// Optimal Solution 
void findRepeated(std::vector <int> nums) {
    std::unordered_map <int, int> freq;
    for (auto num : nums) {
        freq[num]++;
    }
    for (auto i : freq) {
        if (i.second > 1) {
            std::cout << i.first << " ";
        } 
    }
    std::cout << std::endl;
}
// Bruteforce
int main() {
    int n;
    std::cin >> n;
    std::vector <int> nums(n);
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }

    findRepeatedElements(nums);
    findRepeated(nums);

    // bruteforce solution
    int cnt = 0;
    std::vector <int> dup(n);
    for (int i = 0; i < n-1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] == nums[j]) {
                dup[cnt++] = nums[i];
            }
        }
    }

    for (int i = 0; i < cnt; i++) {
        if (i == 0 || dup[i] != dup[i-1]) {
            std::cout << dup[i] << " ";
        }
    }
    return 0;
}