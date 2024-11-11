#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int map[51][51] = {};
void printmap(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
}
bool isvalid(int a, int b){
    return a>=0 && a<N && b>=0 && b< M;
}
bool mat(int a,int b, int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(isvalid(i+a,j+b)){
                if(map[i+a][j+b]){
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    return true;
}

int solution(vector<int> mats, vector<vector<string>> park) {
    N = park.size();
    M = park[0].size();
    cout << N << ' '<<M <<'\n';
    for(int i=0;i<park.size();i++){
        for(int j=0;j<park[i].size();j++){
            if(park[i][j]!="-1"){
                map[i][j] = 1;
            }
        }
    }
    
    sort(mats.begin(),mats.end(),greater<>());
    for(int i=0;i<mats.size();i++){
        for(int y =0;y<N;y++){
            for(int x =0;x<M;x++){
                if(map[y][x] == 0){
                    if(mat(y,x,mats[i])){
                        
                        return mats[i];
                    }
                }
            }
        }
    }
    return -1;
}