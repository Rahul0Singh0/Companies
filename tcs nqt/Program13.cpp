#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void insertAtBeginning(vector<int>& arr, int x) {
        arr.insert(arr.begin(), x);
    }
    void insertAtPosition(vector<int>& arr, int pos, int x) {
        arr.insert(arr.begin() + pos, x);
    }
    void insertAtEnd(vector<int>& arr, int x) {
        arr.push_back(x);
    }
};

int main() {
    vector<int> arr = {1, 2, 4, 5};
    int pos = 2, x = 3;

    Solution obj;
    obj.insertAtBeginning(arr, 0);
    obj.insertAtPosition(arr, pos, x);
    obj.insertAtEnd(arr, 10);


    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
