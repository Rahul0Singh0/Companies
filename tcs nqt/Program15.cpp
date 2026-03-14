// Find all Symmetric Pairs in the array of pairs
/*
Problem Statement: Given an array of pairs, find all the symmetric pairs in the array.
Example 1:
Input:
 (1,2),(2,1),(3,4),(4,5),(5,4)
Output:
 (2,1) (5,4)
Explanation:
 Since (1,2) and (2,1) are symmetric pairs and (4,5) and (5,4) are symmetric pairs.

Example 2:
Input:
 (1,5),(2,3),(4,2),(5,1),(2,4)
Output:
 (2,4) (5,1)
Explanation:
 Since (1,5) and (2,4) are symmetric pairs and (5,1) and (4,2) are symmetric pairs.
*/

#include <bits/stdc++.h>

void findSymmetricPairs(std::vector <std::pair <int, int>>& pairs) {
    for (int i = 0; i < pairs.size(); i++) {
        for (int j = i+1; j < pairs.size(); j++) {
            if (pairs[i].first == pairs[j].second && pairs[i].second == pairs[j].first) {
                std::cout << "(" << pairs[i].first << ", " << pairs[i].second << ")" << std::endl;
                break;
            }
        }
    }
}

int main() {
    int n; 
    std::cin >> n;
    std::vector <std::pair <int, int>> pairs;

    for (int i = 0; i < n; i++) {
        int n1, n2;
        std::cin >> n1 >> n2;
        // pairs.push_back({n1, n2}); // method 1
        pairs.push_back(std::make_pair(n1, n2)); // method 2
        // pairs.emplace_back(n1, n2); // method 3
    }

    // Bruteforce
    // findSymmetricPairs(pairs);
    // for (std::pair <int, int> p : pairs) {
    //     std::cout << "(" << p.first << ", " << p.second << ")" << std::endl;
    // }

    // Optimal - using map
    std::unordered_map <int, int> mp;

    for (std::pair <int, int> p : pairs) {
        int first = p.first;
        int second = p.second;

        // Already exist
        if (mp.find(second) != mp.end() && mp[second] == first) {
            std::cout << "(" << p.first << ", " << p.second << ")" << std::endl;
        } else {
            mp[first] = second;
        }
    }

    return 0;
}