#include <iostream>
#include <deque>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int map[21][21] = {};
deque <int> d;
int ans =1e9+10;
void score(){
    int team1 = 0;
    int team2 = 0;
    deque <int> left;
    for(int i=0;i<N;i++){
        if(find(d.begin(),d.end(),i) == d.end()){
            left.push_back(i);
        }
        
    }
    for(int i=0;i<d.size();i++){
        for(int j=i+1;j<d.size();j++){
            // cout << d[i] << ' ' << d[j] << '\n';
            team1 += map[d[i]][d[j]] + map[d[j]][d[i]];
        }
    }
    for(int i=0;i<left.size();i++){
        for(int j=i+1;j<left.size();j++){
            // cout << left[i] << ' ' << left[j] << '\n';
            team2 += map[left[i]][left[j]] + map[left[j]][left[i]];
        }
    }
    // cout << team1 << ' ' << team2 << '\n';
    ans = min(ans, abs(team1 - team2));
}
void make_combination(int length,int index){
    if(length == 0){
        score();
    }
    for(int i=index;i<N;i++){
        d.push_back(i);
        make_combination(length-1,i+1);
        d.pop_back();
    }
}
int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> map[i][j];
        }
    }
    make_combination(N/2,0);
    cout << ans;
}