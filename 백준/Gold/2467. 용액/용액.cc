#include <iostream>
#include <deque>
#include <algorithm>
#include <cmath>
using namespace std;
int N;
deque <int> d;
long long a,b;
long long ans =  3e9+10;
int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        long long temp;
        cin >> temp;
        d.push_back(temp);
    }
    sort(d.begin(),d.end());
    
    int left_p = 0;
    int right_p = N-1 ;
    while(left_p < right_p){
        if(abs(d[left_p] + d[right_p]) < abs(ans)){
            ans = d[left_p] + d[right_p];
            a = d[left_p];
            b = d[right_p];
        }
        if(d[left_p] + d[right_p] < 0){
            left_p ++;
        }
        else{
            right_p--;
        }
    }
    
    cout << a << ' ' << b;
}