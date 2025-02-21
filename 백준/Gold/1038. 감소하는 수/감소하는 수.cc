#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
deque <long long> d1,d2;

void make_dec(){
    while(!d2.empty()){
        
        int dsize = d2.size();
        
        for(int i=0;i<dsize;i++) {
            if (d2.empty()) break; 
            // cout << d2[0] << '\n';
            int curnum = d2[0] % 10 ;
            // cout << curnum << "\n";
            for(int j = curnum - 1; j >=0; j --){
                long long newNum = d2[0] * 10 + j;
                d2.push_back(newNum);
                d1.push_back(newNum);
            }
            
            d2.pop_front();
        }

    }
    
    sort(d1.begin(),d1.end());
}
int N;
int main(){
    cin >> N;
    if(N==0){
        cout << 0;
        return 0;
    }
    for(int i=1;i<10;i++){
        d1.push_back(i);
        d2.push_back(i);
    }
    make_dec();

    // for(int i=0;i<d1.size();i++){
    //     cout << d1[i] << '\n';
    // }
    // cout << d1.size() << '\n';
    if (N >= 1023) {  
        cout << -1;
    } else {
        cout << d1[N - 1]; 
    }
    
}