#include <iostream>
#include <deque>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int map[500][500] = {};
int N, M;
long long ans = 0;

int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> map[i][j];
        }
    }

    for(int j=0;j<N;j++){
        int debt = 0;
        int balance = 0;
        int curhight = map[0][j];
        int flag = true;
        for(int i=0;i<N;i++){
            if(curhight == map[i][j]){
                
               if(debt) debt --; 
               else balance++;
            }
            else{
                if(curhight - map[i][j]==1){
                    if(debt){
                        flag = false;
                        break;
                    }
                    else{
                        curhight = map[i][j];
                        debt = M - 1;
                        balance = 0;
                    }
                }
                else if(curhight - map[i][j]==-1){
                    if(balance>=M){
                        balance = 1;
                        curhight = map[i][j];
                    }
                    else{
                        flag = false;
                        break;
                    }
                }
                else{
                    flag = false;
                    break;
                }
            }
        }
        if(flag) {
            if(!debt) ans ++;
        }
    }
    for(int i=0;i<N;i++){
        int debt = 0;
        int curhight = map[i][0];
        int balance = 0;
        int flag = true;
        // cout << "New\n";
        for(int j=0;j<N;j++){
            if(curhight == map[i][j]){
                // cout << "debt : " << debt <<" balance: " << balance << '\n';
               if(debt) debt --; 
               else balance++;
            }
            else{
                if(curhight - map[i][j]==1){
                    if(debt){
                        flag = false;
                        break;
                    }
                    else{
                        curhight = map[i][j];
                        debt = M-1;
                        balance = 0;
                    }
                }
                else if(curhight - map[i][j]==-1){
                    if(balance>=M){
                        balance = 1;
                        curhight = map[i][j];
                    }
                    else{
                        flag = false;
                        break;
                    }
                }
                else{
                    flag = false;
                    break;
                }
            }
        }
        if(flag) {
            if(!debt) ans ++;
        }
    }

    cout << ans ;
}