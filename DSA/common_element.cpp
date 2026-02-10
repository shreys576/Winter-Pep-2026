class Solution {
  public:
    // Function to find common elements in three arrays.
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                               vector<int> &arr3) {
        // Code Here
        set<int> fin;
        int i =0;
        int j = 0;
        int k = 0;
        while(i < arr1.size() && j < arr2.size() && k < arr3.size()){
            if(arr1[i] == arr2[j] && arr1[i] == arr3[k]){
                fin.insert(arr1[i]);
                i++;
                j++;
                k++;
            }
            else if(arr1[i] < arr2[j]){
                i++;
            }
            else if(arr2[j] < arr3[k]){
                j++;
            }
            else if(arr3[k] < arr1[i]){
                k++;
            }
        }
        return vector<int> n(fin.begin(), fin.end());
    }
};