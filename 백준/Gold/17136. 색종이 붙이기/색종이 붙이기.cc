#include <iostream>
#include <deque>
#include <vector>
#include <utility>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int map[11][11] = {};
int ans = 1e9 + 7;
int count1 =0;
bool isvalid(int a, int b){
    return a>=0 && a<10 && b>=0 && b<10;
}
bool isdone(int visited[11][11]){
    int flag = 1;
    for(int i=0;i<11;i++){
        for(int j=0;j<11;j++){
            if(visited[i][j]){
                flag = 0;
                break;
            }
        }
        if(flag == 0) break;
    }
    return flag;
}
void printmap(int visited[11][11]){
    cout << "---map---\n";
    for(int i=0;i<11;i++){
        for(int j=0;j<11;j++){
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }
}
void solve(int a, int b,int c1, int c2, int c3, int c4, int c5, int visited[11][11]){
    // printmap(visited);
    if(c1 > 5 ||c2 > 5 ||c3 > 5 ||c4 > 5 ||c5 > 5 ){
        return;
    }
    if(isdone(visited)){
        ans = min(ans,c1+c2+c3+c4+c5);
        return;
    }
    for(int i=a;i<10;i++){
        for(int j = (i == a ? b : 0); j < 10; j++){
            if(visited[i][j]){
                // cout << "--\n";
                // cout << a << ' ' << b << '\n';
                // cout << i << ' ' << j << '\n';
                // cout << "--\n";
                visited[i][j] = 0;
                solve(i,j,c1+1,c2,c3,c4,c5,visited);
                visited[i][j] = 1;
                
                int flag = 1;
                //2
                for(int ii = i; ii<i+2;ii++){
                    for(int jj=j; jj<j+2;jj++){
                        if(!isvalid(ii,jj) || visited[ii][jj]== 0){
                            flag = 0;
                            break;
                        }
                    }
                    if(flag ==0) break;
                }
                
                if(flag) {
                    for(int ii = i; ii<i+2;ii++){
                        for(int jj=j; jj<j+2;jj++){
                            visited[ii][jj] = 0;
                        }
                    }

                    solve(i,j,c1,c2+1,c3,c4,c5,visited);

                    for(int ii = i; ii<i+2;ii++){
                        for(int jj=j; jj<j+2;jj++){
                            visited[ii][jj] = 1;
                        }
                    }
                
                }
                
                //3 
                for(int ii = i; ii<i+3;ii++){
                    for(int jj=j; jj<j+3;jj++){
                        if(!isvalid(ii,jj)||visited[ii][jj]== 0){
                            flag = 0;
                            break;
                        }
                    }
                    if(flag ==0) break;
                }
                if(flag) {
                    for(int ii = i; ii<i+3;ii++){
                        for(int jj=j; jj<j+3;jj++){
                            visited[ii][jj] = 0;
                        }
                    }
                    solve(i,j,c1,c2,c3+1,c4,c5,visited);
                    for(int ii = i; ii<i+3;ii++){
                        for(int jj=j; jj<j+3;jj++){
                            visited[ii][jj] = 1;
                        }
                    }
                
                }

                //4
                for(int ii = i; ii<i+4;ii++){
                    for(int jj=j; jj<j+4;jj++){
                        if(!isvalid(ii,jj)||visited[ii][jj]== 0){
                            flag = 0;
                            break;
                        }
                    }
                    if(flag ==0) break;
                }
                if(flag) {
                    
                    for(int ii = i; ii<i+4;ii++){
                        for(int jj=j; jj<j+4;jj++){
                            visited[ii][jj] = 0;
                        }
                    }
                    solve(i,j,c1,c2,c3,c4+1,c5,visited);
                    
                    for(int ii = i; ii<i+4;ii++){
                        for(int jj=j; jj<j+4;jj++){
                            visited[ii][jj] = 1;
                        }
                    }
                
                }

                //5
                for(int ii = i; ii<i+5;ii++){
                    for(int jj=j; jj<j+5;jj++){
                        if(!isvalid(ii,jj)||visited[ii][jj]== 0){
                            flag = 0;
                            break;
                        }
                    }
                    if(flag ==0) break;
                }
                if(flag) {

                    for(int ii = i; ii<i+5;ii++){
                        for(int jj=j; jj<j+5;jj++){
                            visited[ii][jj] = 0;
                        }
                    }
                    solve(i,j,c1,c2,c3,c4,c5+1,visited);
                    
                    for(int ii = i; ii<i+5;ii++){
                        for(int jj=j; jj<j+5;jj++){
                            visited[ii][jj] = 1;
                        }
                    }
                }



                return ;
            }
        }
    }
}
int main(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cin >> map[i][j];
            if(map[i][j]) count1 ++;
        }
    }
    solve(0,0,0,0,0,0,0,map);
    
    if(ans == 1e9+7){
        cout << -1;
    }
    else{
        cout << ans;
    }
    return 0;
}