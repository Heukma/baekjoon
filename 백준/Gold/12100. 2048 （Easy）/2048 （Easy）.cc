#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>
#include <string>
#include <queue>
#include <utility>

using namespace std;
int N;
int ans = 0;
vector<vector<int> > map(21,vector<int>(21,0));
vector<vector<int> > visited(21,vector<int>(21,0));
void reset(){
    N = 0;
    ans = 0;
    map.assign(21,vector<int>(21,0));
    visited.assign(21,vector<int>(21,0));
}

void input_(){
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> map[i][j];
        }
    }
}

void printmap(vector<vector<int> > tempmap){
    cout << "printing map \n";
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << tempmap[i][j] <<' ';
        }
        cout << '\n';
    }
}
int maxvalue(vector<vector<int> > tempmap){
    int m = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            m = max(m,tempmap[i][j]);
        }
    }
    return m;
}

void move(int index, vector<vector<int> > tempmap){
    vector<vector<int> > tmap = tempmap;
    if(index == 0){
        ans = max(ans, maxvalue(tempmap));
        return;
    }
    //up 위로 이동.
    tempmap = tmap;
    for(int j=0;j<N;j++){
        deque <int> tempd;
        for(int i=0;i<N;i++){
            if(tempmap[i][j]){
                tempd.push_back(tempmap[i][j]);
            }
        }
        for(int i=0;i<N;i++){
            if(tempd.size()!=0){
                int now = tempd[0];
                tempd.pop_front();
                if(tempd.size()!=0){
                    int next = tempd[0];
                    if(now == next){
                        now *= 2;
                        tempd.pop_front();
                    }
                }
                tempmap[i][j] = now;
            }
            else{
                tempmap[i][j] = 0;
            }
        }
    }
    move(index - 1, tempmap);

    //down 아래로 이동.
    tempmap = tmap;
    for(int j=0;j<N;j++){
        deque <int> tempd;
        for(int i=N-1;i!=-1;i--){
            if(tempmap[i][j]){
                tempd.push_back(tempmap[i][j]);
            }
        }
        for(int i=N-1;i!=-1;i--){
            if(tempd.size()!=0){
                int now = tempd[0];
                tempd.pop_front();
                if(tempd.size()!=0){
                    int next = tempd[0];
                    if(now == next){
                        now *= 2;
                        tempd.pop_front();
                    }
                }
                tempmap[i][j] = now;
            }
            else{
                tempmap[i][j] = 0;
            }
        }
    }
    move(index - 1, tempmap);

    //left 왼쪽으로 이동.
    tempmap = tmap;
    for(int i=0;i<N;i++){
        deque <int> tempd;
        for(int j=0;j<N;j++){
            if(tempmap[i][j]){
                tempd.push_back(tempmap[i][j]);
            }
        }
        for(int j=0;j<N;j++){
            if(tempd.size()!=0){
                int now = tempd[0];
                tempd.pop_front();
                if(tempd.size()!=0){
                    int next = tempd[0];
                    if(now == next){
                        now *= 2;
                        tempd.pop_front();
                    }
                }
                tempmap[i][j] = now;
            }
            else{
                tempmap[i][j] = 0;
            }
        }
    }
    move(index - 1, tempmap);

    //right 오른쪽으로 이동.
    tempmap = tmap;
    for(int i=0;i<N;i++){
        deque <int> tempd;
        for(int j=N-1;j!=-1;j--){
            if(tempmap[i][j]){
                tempd.push_back(tempmap[i][j]);
            }
        }
        for(int j=N-1;j!=-1;j--){
            if(tempd.size()!=0){
                int now = tempd[0];
                tempd.pop_front();
                if(tempd.size()!=0){
                    int next = tempd[0];
                    if(now == next){
                        now *= 2;
                        tempd.pop_front();
                    }
                }
                tempmap[i][j] = now;
            }
            else{
                tempmap[i][j] = 0;
            }
        }
    }
    move(index - 1, tempmap);

}
int main(){
    reset();
    input_();
    move(5,map);
    cout << ans;
}