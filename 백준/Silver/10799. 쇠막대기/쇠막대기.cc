#include <iostream>
#include <deque>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

string t;
deque <int> d;
long long ans =0;
int main(){
    cin >> t;
    for(int i=0;i<t.size();i++){
        char temp;
        temp = t[i];
        if(temp == '('){
            d.push_back(i);
        }
        else{
            if(d.back() == i-1){
                d.pop_back();
                ans += d.size();
                // cout << d.size() << '\n';
            }
            else{
                d.pop_back();
                ans ++;
            }
        }
    }
    cout << ans ;
}