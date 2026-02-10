class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> fin;
        int s = 0;
        int e = nums.size() - 1;
        while(s <= e){
            int mid = (s+e)/2;
            if(nums[mid] == target){
                s = mid;
                e = mid;
                while(nums[s] == nums[s - 1]){
                    s --;
                }
                while(nums[e] == nums[e + 1]){
                    e++;
                }
                fin.push_back(s);
                fin.push_back(e);
            }
            else if(nums[mid] < target){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        if(fin.size() > 0){
            return fin;
        }
        else{
            return {-1, -1};
        }
    }
};