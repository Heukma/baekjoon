#include <iostream>
#include <deque>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;
long long L,N,K;
deque <pair<long long, long long>> d;
deque <long long> ans;
set<long long> v;
int ra[2] = {1,-1};
bool isvalid(long long a){
    if(v.count(a) == false){
        return a>=0 && a<=L;
    }
    return 0;
}
void bfs(long long index, long long light){
    for(int i=0;i<2;i++){
        long long tempa = index + ra[i];
        if(isvalid(tempa)){
            d.push_back(make_pair(tempa,light+1));
            v.insert(tempa);
        }
    }
}
int main(){
    cin >> L;
    cin >> N >> K;
    for(int i=0;i<N;i++){
        long long temp;
        cin >> temp;
        d.push_back(make_pair(temp,0));
        v.insert(temp);
        ans.push_back(0);
    }

    while(K--){
        long long index = d[0].first;
        long long light = d[0].second;
        cout << light << '\n';
        d.pop_front();
        bfs(index,light);
    }
    

}