/**
 * 23/09/2024 assessment date
 * Given image (Square Matrix), info of rotational degree(integer),  info of vertical_flip
 *  and horizontal_flip in boolean form
 * perform following operations:
 *   1. Rotate by 90 degree, 180 degree, or 270 degree clockwise
 *   2. Flip image vertically if vertical_flip = 1(true)
 *   3. Flip image horizontally if horizontal_flip = 1(true)
 * 
 * return binary matrix representing the final image after performing all three operations.
 * 
 * Example: n = 3, rotatio = 270, vertical_flip = 0, horizontal_flip = 1
 *          image = [[1,0,0],[0,1,1],[0,0,1]]
 *          result = [[1,1,0],[0,1,0],[0,0,1]]
 * 
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void rotation90(vector<vector<int>>& image) {
        // bruteforce: time: O(n*n), space: O(n*n)
        int n = image.size(); // given image is square
        // vector<vector<int>> ans(n, vector<int>(n));
        // for(int i = 0; i < n; i++) {
        //     for(int j = 0 ; j < n; j++) {
        //         ans[j][n-i-1] = image[i][j];
        //     }
        // }
        // image = ans;

        // Optimize solution reduce space O(n*n) to space constant
        // step 1 transpose original image
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                swap(image[i][j], image[j][i]);
            }
        }
        // step 2 reverse each row of tranposed matrix
        for(int i = 0; i < n; i++) {
            reverse(image[i].begin(), image[i].end());
            // two pointer
            // int ii = 0, j = n-1;
            // while(ii <= j) {
            //     swap(image[i][ii], image[i][j]);
            //     ii++;
            //     j--;
            // }
        }
    }

    void rotation180(vector<vector<int>>& image) {
        // bruteforce
        // int n = image.size();
        // vector<vector<int>> ans(n, vector<int>(n));
        // for(int i =0; i < n; i++) {
        //     for(int j = 0; j < n; j++) {
        //         ans[n-1-i][n-1-j] = image[i][j];
        //     }
        // }
        // image = ans;

        // optimized solution by using optimized 90 degree solution
        rotation90(image);
        rotation90(image);
    }

    void rotation270(vector<vector<int>>& image) {
        // Bruteforce
        // int n = image.size();
        // vector<vector<int>> ans(n, vector<int>(n));
        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < n; j++) {
        //         ans[n-1-j][i] = image[i][j];
        //     }
        // }
        // image = ans;

        // optimized solution by using 90 degree optimized solution
        // rotation90(image);
        // rotation90(image);
        // rotation90(image);

        rotation180(image);
        rotation90(image);
    }
    vector<vector<int>> fun(vector<vector<int>>& image, int rotation, int vertical_flip, int horizontal_flip) {
        if(rotation == 90) {
            rotation90(image);
        }
        else if(rotation == 180) {
            rotation180(image);
        }
        else if(rotation == 270) {
            rotation270(image);
        }
        if(vertical_flip) {
            int n = image.size();
            vector<vector<int>> ans(n,vector<int>(n));
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    ans[n-1-i][j] = image[i][j];
                }
            }
            image = ans;
        }
        // To flip an image horizontally means that each row of the image is reversed.
        if(horizontal_flip) {
            int n = image.size();
            for(int i = 0; i < n; i++) {
                reverse(image[i].begin(), image[i].end());
            }
        }
        return image;
    }
    void display(vector<vector<int>>& image) {
        int n = image.size();
        for(int i =0; i < n; i++) {
            for(int j =0; j < n; j++) {
                cout<<image[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
};
int main() {
    int n,rotation,vertical_flip,horizotal_flip;
    cin>>n;
    vector<vector<int>> image(n, vector<int>(n));
    for(int i =0; i < n; i++) {
        for(int j =0; j < n; j++) {
            cin>>image[i][j];
        }
    }
    cin>>rotation;
    cin>>vertical_flip>>horizotal_flip;
    Solution s;
    vector<vector<int>> resultant_image = s.fun(image,rotation,vertical_flip,horizotal_flip);
    s.display(resultant_image);
}