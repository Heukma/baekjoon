#include <string>
#include <vector>
#include <iostream>
using namespace std;
int map[51][51] = {};
int ra[4] = {1,-1,0,0}; // 남, 북
int rb[4] = {0,0,1,-1};  // 동, 서
int N,M;
bool isvalid(int a,int b){
    return a>=0 && a<N && b>=0 && b<M;
}
pair <int, int> move(int dir, int size, int a, int b){
    int flag = 1;
    for(int i=0;i<size;i++){
        a = a + ra[dir];
        b = b + rb[dir];
        if(isvalid(a,b)){
            if(map[a][b] != 88){
                
            }
            else{
                return {-1,-1};
            }
        }
        else{  
            return {-1,-1};
        }
    }
    return {a,b};
}
vector<int> solution(vector<string> park, vector<string> routes) {
    N = park.size();
    M = park[0].length();
    int sa;
    int sb;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            map[i][j] = park[i][j];
            if(map[i][j] == 83) {
                sa = i;
                sb = j;
            }
        }
    }
    // cout << N << M;
    for(int i=0;i<routes.size();i++){
        string temp = routes[i];
        char dir = temp[0];
        int dirint = -1;
        if(dir == 'E') dirint = 2;
        if(dir == 'W') dirint = 3;
        if(dir == 'N') dirint = 1;
        if(dir == 'S') dirint = 0;
        
        char much = temp[2];
        int cost = much -'0';
        pair <int, int> tempi = move(dirint,cost,sa,sb);
        
        if(tempi.first != -1){
            sa = tempi.first;
            sb = tempi.second;
        }
    }
    
    vector<int> answer;
    answer.push_back(sa);
    answer.push_back(sb);
    return answer;
}