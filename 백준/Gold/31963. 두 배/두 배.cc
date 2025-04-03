#include <iostream>
#include <deque>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int N;
long long rec = 0;
long long ans = 0;
vector<int> vi;
long long solve() {
    long long ret = 0;
    
    vector<int> multiply_cnt(vi.size(), 0);
    
    for (int i = 1 ; i < vi.size() ; ++i) {
        multiply_cnt[i] = max((int)ceil(log2((double)vi[i - 1]/ (double)vi[i]) + (double)multiply_cnt[i - 1]), 0);
        
        ret += multiply_cnt[i];
    }
    
    return ret;
}
int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        long long temp;
        cin >> temp;
        vi.push_back(temp);
    }

    cout << solve();
}