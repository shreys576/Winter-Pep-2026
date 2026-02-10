#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n,0));
        int topRow = 0;
        int leftColumn = 0;
        int bottomRow = n - 1;
        int rightColumn = n - 1;
        int index = 1;
        while(topRow <= bottomRow && leftColumn <= rightColumn){
            for(int i = leftColumn; i <= rightColumn; i++){
                matrix[topRow][i] = index;
                index++;
            }
            topRow++;
            for(int i =topRow; i <= bottomRow; i++){
                matrix[i][rightColumn] = index;
                index++;
            }
            rightColumn--;
            if(topRow <= bottomRow){
                for(int i = rightColumn; i >= leftColumn; i--){
                    matrix[bottomRow][i] = index;
                    index++;
                }
                bottomRow--;
            }
            if(leftColumn <= rightColumn){
                for(int i = bottomRow; i >= topRow; i--){
                    matrix[i][leftColumn] = index;
                    index++;
                }
                leftColumn++;
            }
        }
        return matrix;
    }
};

int main(){
    Solution s;
    // Sample input
    int n = 3; // expected matrix:
    // 1 2 3
    // 8 9 4
    // 7 6 5

    vector<vector<int>> mat = s.generateMatrix(n);
    for(const auto &row : mat){
        for(size_t j = 0; j < row.size(); ++j){
            cout << row[j] << (j + 1 == row.size() ? '\n' : ' ');
        }
    }

    // To use custom input from stdin, uncomment below:
    // int n; if(cin >> n){ auto m = s.generateMatrix(n); for(auto &r:m){ for(size_t j=0;j<r.size();++j) cout<<r[j]<<(j+1==r.size()? '\n':' ');} }

    return 0;
}
