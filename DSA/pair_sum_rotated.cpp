// User function Template for C++

class Solution {
  public:
    bool pairInSortedRotated(vector<int>& arr, int target) {
        // code here
        int largest = 0;
        int i = 0;
        while(arr[i] <= arr[i + 1] && i < arr.size() - 1){
            i++;
        }
        largest = i;
        int smallest = (i + 1);
        int count = 0;
        while(count <= arr.size()){
            if(smallest > arr.size() - 1){
                smallest = 0;
            }
            if(largest < 0){
                largest = arr.size() - 1;
            }
            int newsum = arr[largest] + arr[smallest];
            if(newsum == target && smallest != largest){
                return true;
            }
            else if(newsum < target){
                smallest++;
            }
            else{
                largest--;
            }
            count++;
        }
        return false;
        
    }
};