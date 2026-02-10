#include<bits/stdc++.h>
using namespace std;

void SpiralPrintClockWise(int arr[4][4]){
    int topRow = 0, leftColumn = 0;
    int bottomRow = 3, rightColumn = 3;
    while(topRow < bottomRow && leftColumn < rightColumn){
        for(int i = leftColumn; i <= rightColumn; i ++){
            cout << arr[topRow][i] << " ";
        }
        topRow++;
        for(int i = topRow; i <= bottomRow; i++){
            cout << arr[i][rightColumn] << " ";
        }
        rightColumn--;
        for(int i = rightColumn; i >= leftColumn; i--){
            cout << arr[bottomRow][i] << " ";
        }
        bottomRow--;
        for(int i = bottomRow; i >= topRow; i--){
            cout << arr[i][leftColumn] << " ";
        }
        leftColumn++;
    } 
}

void SpiralPrintCounterClockwise(int arr[4][4]){
    int topRow, leftColumn = 0, bottomRow, rightColumn = 3;
    while(topRow < bottomRow && leftColumn < rightColumn){
        for(int i = rightColumn; i >= leftColumn; i--){
            cout << arr[topRow][i];
        }
        topRow++;
        for(int i = topRow; i <= bottomRow; i++){
            cout << arr[i][leftColumn] << " ";
        }
        leftColumn++;
        for(int i = leftColumn; i <= rightColumn; i++){
            cout << arr[bottomRow][i];
        }
        bottomRow--;
        for(int i = bottomRow; i >= topRow; i--){
            cout << arr[i][rightColumn] << " ";
        }
        rightColumn--;
    }
}


int main(){

    int arr[4][4] = {1,7,14,6,11,15,5,10,2,4,16,3,9,13,8,12};
    SpiralPrintClockWise(arr);
    cout << endl;
    SpiralPrintCounterClockwise(arr);


}