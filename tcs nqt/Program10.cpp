/*
Median of the AP Series

first arrange the series in ascending order

Example 1:
Input:
 [2,4,1,3,5]
Output:
 3

Example 2:
Input:
 [2,5,1,7]
Output:
 3.5
*/

#include<bits/stdc++.h>
int main() {
    int n;
    std::cin>>n;
    std::vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::sort(arr.begin(), arr.end());
    if(n%2 == 0) { // even case
        int firstMiddle = n/2 - 1;
        int secondMiddle = n/2;
        std::cout << std::fixed;
        std::cout << std::setprecision(1);
        std::cout << (double)((double)arr[firstMiddle] + (double)arr[secondMiddle]) / 2;
    } else { // odd case
        std::cout << arr[n/2];
    }
    return 0;
}