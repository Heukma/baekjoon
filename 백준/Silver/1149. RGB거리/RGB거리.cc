#include <iostream>
#include <cmath>

using namespace std;
int N;
int color[1001][3] = {};
int ans[1001][3] = {};
int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<3;j++){
            cin >> color[i][j];
        }
    }

    ans[0][0] = color[0][0];
    ans[0][1] = color[0][1];
    ans[0][2] = color[0][2];

    for(int i=1;i<N;i++){
        for(int j=0;j<3;j++){
            if(j == 0){
                ans[i][j] += min(ans[i-1][1], ans[i-1][2]) + color[i][j];
            }
            if(j == 1){
                ans[i][j] += min(ans[i-1][0], ans[i-1][2]) + color[i][j];
            }
            if(j == 2){
                ans[i][j] += min(ans[i-1][0], ans[i-1][1]) + color[i][j];
            }
        }
    }
    cout << min(min(ans[N-1][0],ans[N-1][1]),ans[N-1][2]);
}