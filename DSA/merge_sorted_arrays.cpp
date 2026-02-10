#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         int i = m - 1;
//         int j = n - 1;
//         int k = (m + n) - 1;
//         while(j > = 0){
//             if(i >= 0 && nums1[i] > num2[j]){
//                 nums1[k] = nums1[i];
//                 i--;
//                 k--;
//             }
//             else{
//                 nums1[k] = nums2[j];
//                 j--;
//                 k--;
//             }
//         }
//     }
// };



void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;
        int k = 0;
        while(i < m){
            if(j < n && nums2[j] < nums1[i]){
                nums1[k] = nums2[j];
                k++;
                j++;
            }
            else{
                nums1[k] = nums1[i];
                i++;
                k++;
            }
        }
    }

void print(vector<int> arr){
    for(int i : arr){
        cout << i << " ";
    }
    cout << endl;
}


int main(){

    vector<int> nums1 = {1,2,3,0,0,0};
    int m = 3;
    vector<int> nums2 = {2,5,6};
    int n = 3;
    merge(nums1, m, nums2, n);
    print(nums1);

}