/**
 * Given two array and truck size: 
 * 1. Number of boxes[i]         =   [1,2,3]
 * 2. Number of units per box[i] =   [3,2,1]
 * 3. Truck size                 =   4
 * the maximum number of boxes that can be put on the truck. 
 * You can choose any boxes to put on the truck as long as the number of boxes 
 * does not exceed truckSize.
 * 
 * Return the maximum total number of units that can be put on the truck.
 * Output of given above example: 8
 * 
 * This problem is greedy problem
 * 
 * Input: boxTypes = [[5,10],[2,5],[4,7],[3,9]], truckSize = 10
 * Output: 91
 */
#include<iostream>
#include<algorithm>
using namespace std;
struct Pair{
    int u;
    int b;
};
class Solution {
public:
    // Greedy Problem
    static bool cmp(Pair a, Pair b) {
        return (a.u) > (b.u);
    }
    int fun(int *Boxes, int *Units, int truckSize, int n) {
        Pair *p = new Pair[n];
        for(int i = 0; i < n; i++) {
            p[i].b = Boxes[i];
            p[i].u = Units[i]; 
        }
        sort(p, p+n, cmp);
        // for(int i = 0; i < n; i++) {
        //     cout<<p[i].b<<" "<<p[i].u<<endl;
        // }
        int mx_profit = 0;
        for(int i = 0; i < n; i++) {
            if(p[i].b <= truckSize) {
                mx_profit += (p[i].b * p[i].u);
                truckSize -= p[i].b;
            } 
            else {
                mx_profit += (truckSize*p[i].u);
                truckSize = 0;
            }
            if(truckSize == 0) break;
        }
        return mx_profit;
    }
};
int main() {
    int n;
    cin>>n;
    int Boxes[n]; // No.of Boxes
    int Units[n]; // No. of units of each box
    for(int i = 0; i < n; i++) cin>>Boxes[i];
    for(int i = 0; i < n; i++) cin>>Units[i];
    int truckSize;
    cin>>truckSize;
    Solution s;
    cout<<s.fun(Boxes,Units,truckSize,n);
    return 0;
}