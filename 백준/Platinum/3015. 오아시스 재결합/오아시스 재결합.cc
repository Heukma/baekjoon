#include <iostream>
#include <deque>
#include <vector>
using namespace std;
deque <pair<int,int>> d;
int N;
long long ans = 0;
int num = 1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for(int i=0;i<N;i++){
        int temp;
        cin >> temp;
        num = 1;
        int count = 1;
        while(d.size()!=0){
            int t = d.back().first;
            int c = d.back().second;
            if(temp > t){
                // 현재 사람이 stack의 사람보다 키가 크다.
                d.pop_back();
                ans += c;
            }
            else if(temp == t){
                d.pop_back();
                ans +=c;
                count += c; 
            }
            else{
                ans++;
                break;
            }
        }
        d.push_back(make_pair(temp,count));
    }
    cout << ans;
}