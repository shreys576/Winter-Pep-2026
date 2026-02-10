#include <bits/stdc++.h>
using namespace std;

// LeetCode 3379 - Transformed Array
// Provided Solution completed with a runnable main() and sample input

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        for(int i = 0; i < (int)nums.size(); i++){
            int index = nums[i];
            if(index > 0){
                int findex = index + i;
                if(findex >= (int)nums.size()){
                    findex = findex % nums.size();
                }
                result[i] = nums[findex];
            }
            else{
                index = abs(index);
                int findex = i - index;
                if(findex < 0){
                    do{
                        findex += nums.size();
                    }
                    while(findex < 0);
                }
                if(findex >= (int)nums.size()){
                    findex = findex % nums.size();
                }
                result[i] = nums[findex];

            }
        }
        return result;
    }
};

void print_vec(const vector<int>& v){
    cout << "[";
    for(size_t i=0;i<v.size();++i){
        cout << v[i];
        if(i+1<v.size()) cout << ", ";
    }
    cout << "]\n";
}

int main(){
    // Sample input: demonstrate positive and negative shifts
    vector<int> nums = {2, -1, 1, 2, -3};
    cout << "Input nums: ";
    print_vec(nums);

    Solution sol;
    vector<int> res = sol.constructTransformedArray(nums);

    cout << "Transformed: ";
    print_vec(res);

    return 0;
}
