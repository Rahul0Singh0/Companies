/*
You are required to implement the following Function 

def LargeSmallSum(arr)

The function accepts an integers arr of size ’length’ as its arguments you are 
required to return the sum of second largest element from the even positions and 
second smallest from the odd position of given ‘arr’

Assumption:
    All array elements are unique
    Treat the 0th position as even

NOTE:
   Return 0 if array is empty
   Return 0, if array length is 3 or less than 3

Example
 Input
   arr:3 2 1 7 5 4

 Output
   7

Explanation:
    Second largest among even position elements(1 3 5) is 3
    Second smallest among odd position element is 4
    Thus output is 3+4 = 7

    Sample Input
       arr: 1 8 0 2 3 5 6

    Sample Output
       8
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Time : O(N)
int LargeSmallSum(int *arr, int n) {
    if(n <= 3) return 0;
    int sec_largest = INT_MIN, largest = INT_MIN; // even place
    int sec_smallest = INT_MAX, smallest = INT_MAX; // odd place
    for(int i = 0; i < n; i++) {
        if(i % 2) { // odd
            if(arr[i] < smallest) sec_smallest = smallest ,smallest = arr[i];
            else if(arr[i] < sec_smallest) sec_smallest = arr[i];
        } else { // even
            if(arr[i] > largest) sec_largest = largest, largest = arr[i];
            else if(arr[i] > sec_largest) sec_largest = arr[i];
        }
    }
    return sec_largest + sec_smallest;
}

// Time: O(n*log(n))

int main() {
    int *arr = new int;
    int n; cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    cout<<"\n"<<LargeSmallSum(arr, n);
    return 0;
}