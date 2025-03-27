#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
vector <int> v;
int ans = 2*(1e9+10);
int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    int left = 0;
    int right =1;
    while(left<right && right<N){
        int temp = v[right] - v[left];
        if(temp >= M){
            ans = min(temp,ans);
            if(left+1 == right){
                right++;
            }
            else{
                left ++;
            }
        }
        else{
            right++;
        }
    }
    cout << ans;
}