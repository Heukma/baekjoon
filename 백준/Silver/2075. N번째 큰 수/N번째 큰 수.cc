#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
priority_queue <pair<int,int> > pq;
int map[1501][1501] = {};
int index_[1501] = {};
int N;
int count = 0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> map[i][j];
        }
    }

    for(int i=0;i<N;i++){
        pq.push({map[N-1][i], i});
        index_[i] = N - 1;
    }
    int tempN = N - 1;
    while(tempN--){
        int a, b;
        a = pq.top().first;
        b = pq.top().second;
        pq.pop();
        pq.push({map[index_[b]-1][b],b});
        index_[b]--;
    }
    cout << pq.top().first;
    return 0;
}