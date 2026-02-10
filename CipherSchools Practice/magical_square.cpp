// #include<bits/stdc++.h>
// using namespace std;

// bool isSquare(int num){
//     int i = 1;
//     while(i*i <= num){
//         if(i*i == num) return true;
//         i++;
//     }
//     return false;
// }

// int CountPerfectSquares(int L, int R){
//     int count = 0;
//     int loop = L;
//     while(loop <= R){
//         if(isSquare(loop)){
//             count++;
//         }
//         loop++;
//     }
//     return count;
// }

// int main(){

//     cout << CountPerfectSquares(9,25);

// }

#include <bits/stdc++.h>
using namespace std;

int CountPerfectSquares(int L, int R) {
    if (L > R) return 0;

    int low = ceil(sqrt(L));
    int high = floor(sqrt(R));

    if (low > high) return 0;
    return high - low + 1;
}

int main() {
    cout << CountPerfectSquares(9, 25);
    return 0;
}
