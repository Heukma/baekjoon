#include <iostream>
#include <deque>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;
map<int, int> mA,mB;
map<int, int>::iterator it;
deque <int> d;
int T;
int A[1001] = {};
int B[1001] = {};
int N,M;
long long ans =0;
long long dpA[1001] = {};
long long dpB[1001] = {};

void make_combination(int length, int index){
    if(length == 0){
        int i = d[0];
        int j = d[1];
        long long temp = dpA[j] - dpA[i] + A[i];
        mA[temp] ++; 
        return ;
    }
    for(int i=index;i<=N;i++){
        d.push_back(i);

        make_combination(length-1,i);
        
        d.pop_back();
    }
}
void make_combinationb(int length, int index){
    if(length == 0){
        int i = d[0];
        int j = d[1];
        long long temp = dpB[j] - dpB[i] + B[i];
        mB[temp] ++; 
        return ;
    }
    for(int i=index;i<=M;i++){
        d.push_back(i);
        make_combinationb(length-1,i);
        d.pop_back();
    }
}
int main(){
    cin >> T;
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> A[i];
        dpA[i] = dpA[i-1] + A[i];
    }
    make_combination(2,1);
    cin >> M;
    for(int i=1;i<=M;i++){
        cin >> B[i];
        dpB[i] = dpB[i-1] + B[i];
    }
    make_combinationb(2,1);
    for(it = mA.begin(); it!=mA.end();it++){
        // cout << it->first << ' ' << it->second <<'\n';
        ans += (long long)mB[T - it->first] * it->second;
    }
    cout << ans ;
}