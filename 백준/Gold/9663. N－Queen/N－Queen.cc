#include <iostream>
#include <vector>
using namespace std;

int N, ans = 0;
vector<bool> col, leftDiag, rightDiag;

void placeQueen(int row) {
    if (row == N) {
        ans++; 
        return;
    }

    for (int c = 0; c < N; c++) {
        if (!col[c] && !leftDiag[row - c + N - 1] && !rightDiag[row + c]) {
            
            col[c] = true;
            leftDiag[row - c + N - 1] = true;
            rightDiag[row + c] = true;

            placeQueen(row + 1); 

            
            col[c] = false;
            leftDiag[row - c + N - 1] = false;
            rightDiag[row + c] = false;
        }
    }
}

int main() {
    cin >> N;

    
    col.resize(N, false);
    leftDiag.resize(2 * N - 1, false);
    rightDiag.resize(2 * N - 1, false);

    
    placeQueen(0);

    cout << ans << endl;

    return 0;
}
