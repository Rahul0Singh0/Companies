/*
Example 1:
Input: N = 5, array[] = {1,2,3,4,5}
Output: 3
Explanation: Average is the sum of all the elements divided by number of elements.Therefore (1+2+3+4+5)/5 = 3.


Example 2:
Input:  N=6, array[] = {1,2,1,1,5,1}
Output: 1.8
Explanation: Average is the sum of all the elements divided by number of elements.Therefore (1+2+1+1+5+1)/6 = 1.8
*/

#include <bits/stdc++.h>
int main() {
    int n;
    std::cin>>n;
    std::vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        std::cin>>arr[i];
    }

    double sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    std::cout << std::fixed; // Use fixed-point notation
    std::cout << std::setprecision(1); // Set the number of digits after the decimal point to 1
    std::cout << (float)((float)sum / (float)n);

    return 0;
}