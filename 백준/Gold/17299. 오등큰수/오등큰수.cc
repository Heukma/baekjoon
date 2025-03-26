#include <iostream>
#include <algorithm>
#include <deque>
#include <cmath>
#include <utility>

using namespace std;

vector<int> v(1000000,0);
vector<int> A(1000000,0);
vector<int> ans(1000000,-1);
deque <pair<int,int> > d;
deque <pair<int,int> > tempd;
int N;
void printA(){
    cout << "printing A \n";
    for(int i=0;i<N;i++){
        cout << A[i] << ' ';
    }
    cout << '\n';
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> A[i];
        v[A[i]] ++;
    }
    // printA();
    for(int i=0;i<N;i++){
        // cout << i << "번째: " << v[A[i]] <<'\n';
        while(d.size()!=0){
            int index = d.back().first;
            int num = d.back().second;
            d.pop_back();
            if(num < v[A[i]]){
                ans[index] = A[i];
            }
            else{
                d.push_back(make_pair(index,num));
                break;
            }
        };
        d.push_back(make_pair(i,v[A[i]]));
    }
    for(int i=0;i<N;i++){
        cout << ans[i] << ' ';
    }
    return 0;
}