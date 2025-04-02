#include <iostream>
#include <deque>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int map[500][500] = {};
int N;
long long ans = 0;
bool isvalid(int a , int b){
    return a>=0 && a<N && b>=0 && b<N;
}
void printmap(){
    cout << "=== printing map ===\n";
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
}
void left(int a, int b){
    int cursand = map[a][b];
    map[a][b] = 0;
    int usedsand = 0;
    int ra[10] = {-1,1,1,-1,0,2,-2,1,-1,0};
    int rb[10] = {-1,-1,0,0,-2,0,0,1,1,-1};
    double rc[10] = {0.1,0.1,0.07,0.07,0.05,0.02,0.02,0.01,0.01};
    // 10 10 7 7 5 2 2 1 1 a
    for(int i=0;i<10;i++){
        int tempa = a+ra[i];
        int tempb = b+rb[i];
        if(i == 9){
            // cout <<"Usedsand: "<< usedsand << '\n';
            if(isvalid(tempa,tempb)){
                int sand = cursand - usedsand;
                map[tempa][tempb] += sand;
                usedsand += sand;
            }
            else{
                int sand = cursand - usedsand;
                ans += sand;
                usedsand += sand;
            }
            break;
        }
        if(isvalid(tempa,tempb)){
            int sand = cursand * rc[i];
            map[tempa][tempb] += sand;
            usedsand += sand;
        }
        else{
            int sand = cursand * rc[i];
            ans += sand;
            usedsand += sand;
        }
    }

}
void right(int a, int b){
    int cursand = map[a][b];
    map[a][b] = 0;
    int usedsand = 0;
    int ra[10] = {-1,1,1,-1,0,2,-2,1,-1,0};
    int rb[10] = {1,1,0,0,2,0,0,-1,-1,1};
    double rc[10] = {0.1,0.1,0.07,0.07,0.05,0.02,0.02,0.01,0.01};
    // 10 10 7 7 5 2 2 1 1 a
    for(int i=0;i<10;i++){
        int tempa = a+ra[i];
        int tempb = b+rb[i];
        if(i == 9){
            if(isvalid(tempa,tempb)){
                int sand = cursand - usedsand;
                map[tempa][tempb] += sand;
                usedsand += sand;
            }
            else{
                int sand = cursand - usedsand;
                ans += sand;
                usedsand += sand;
            }
            break;
        }
        if(isvalid(tempa,tempb)){
            int sand = cursand * rc[i];
            map[tempa][tempb] += sand;
            usedsand += sand;
        }
        else{
            int sand = cursand * rc[i];
            ans += sand;
            usedsand += sand;
        }
    }
}
void up(int a, int b){
    int cursand = map[a][b];
    map[a][b] = 0;
    int usedsand = 0;
    int ra[10] = {-1,-1,0,0,-2,0,0,1,1,-1};
    int rb[10] = {-1,1,1,-1,0,2,-2,1,-1,0};
    double rc[10] = {0.1,0.1,0.07,0.07,0.05,0.02,0.02,0.01,0.01};
    // 10 10 7 7 5 2 2 1 1 a
    for(int i=0;i<10;i++){
        int tempa = a+ra[i];
        int tempb = b+rb[i];
        if(i == 9){
            if(isvalid(tempa,tempb)){
                int sand = cursand - usedsand;
                map[tempa][tempb] += sand;
                usedsand += sand;
            }
            else{
                int sand = cursand - usedsand;
                ans += sand;
                usedsand += sand;
            }
            break;
        }
        if(isvalid(tempa,tempb)){
            int sand = cursand * rc[i];
            map[tempa][tempb] += sand;
            usedsand += sand;
        }
        else{
            int sand = cursand * rc[i];
            ans += sand;
            usedsand += sand;
        }
    }
}
void down(int a, int b){
    int cursand = map[a][b];
    map[a][b] = 0;
    int usedsand = 0;
    int ra[10] = {1,1,0,0,2,0,0,-1,-1,1};
    int rb[10] = {-1,1,1,-1,0,2,-2,1,-1,0};
    double rc[10] = {0.1,0.1,0.07,0.07,0.05,0.02,0.02,0.01,0.01};
    // 10 10 7 7 5 2 2 1 1 a
    for(int i=0;i<10;i++){
        int tempa = a+ra[i];
        int tempb = b+rb[i];
        if(i == 9){
            // cout <<"used sand: " << usedsand << '\n';
            if(isvalid(tempa,tempb)){
                int sand = cursand - usedsand;
                map[tempa][tempb] += sand;
                usedsand += sand;
            }
            else{
                int sand = cursand - usedsand;
                ans += sand;
                usedsand += sand;
            }
            break;
        }
        if(isvalid(tempa,tempb)){
            int sand = cursand * rc[i];
            map[tempa][tempb] += sand;
            usedsand += sand;
        }
        else{
            int sand = cursand * rc[i];
            ans += sand;
            usedsand += sand;
        }
    }
}
int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> map[i][j];
        }
    }
    int x = N/2;
    int y = N/2;
    for(int i=1;i<=N-2;i+=2){
        for(int j=1;j<=i;j++){
            // left 
            y--;
            left(x,y);
        }
        for(int j=1;j<=i;j++){
            // down
            x++;
            down(x,y);
        }
        for(int j=0;j<=i;j++){
            // right 
            y++;
            right(x,y);
        }
        for(int j=0;j<=i;j++){
            // up
            x--;
            up(x,y);
        }
    }
    for(int j=1;j<=N-1;j++){
        // left 
        y--;
        left(x,y);
    }
    cout << ans ;
}