#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> fin;
        if(matrix.empty() || matrix[0].empty()) return fin;
        int topRow = 0;
        int bottomRow = matrix.size() - 1;
        int leftColumn = 0;
        int rightColumn = matrix[0].size() - 1;

        while(topRow <= bottomRow && leftColumn <= rightColumn){
            for(int i = leftColumn; i <= rightColumn; i++){
                fin.push_back(matrix[topRow][i]);
            }
            topRow++;
            for(int i =topRow; i <= bottomRow; i++){
                fin.push_back(matrix[i][rightColumn]);
            }
            rightColumn--;
            if(topRow <= bottomRow){
                for(int i = rightColumn; i >= leftColumn; i--){
                    fin.push_back(matrix[bottomRow][i]);
                }
                bottomRow--;
            }
            if(leftColumn <= rightColumn){
                for(int i = bottomRow; i >= topRow; i--){
                    fin.push_back(matrix[i][leftColumn]);
                }
                leftColumn++;
            }
        }
        return fin;
    }
};

int main(){
    Solution s;
    // Sample matrix (you can modify this sample to test other cases)
    // Sample 1 (3x3): expected output -> 1 2 3 6 9 8 7 4 5
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Uncomment below to read custom input from stdin:
    // int m, n; if(cin >> m >> n){ matrix.assign(m, vector<int>(n)); for(int i=0;i<m;i++) for(int j=0;j<n;j++) cin >> matrix[i][j]; }

    vector<int> ans = s.spiralOrder(matrix);
    for(size_t i = 0; i < ans.size(); ++i){
        cout << ans[i] << (i + 1 == ans.size() ? '\n' : ' ');
    }
    return 0;
}
