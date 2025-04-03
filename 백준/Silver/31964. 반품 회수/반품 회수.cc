#include <iostream>
#include <deque>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int N;
int curtime = 0;
int last = 0;
struct xy {
    int dis,time;
};
int main(){
    cin>> N;
    deque <xy> d(N);
    for(int i =0;i<N;i++){
        int temp;
        cin >> temp;
        d[i].dis = temp;
    }
    for(int i=0;i<N;i++){
        int temp;
        cin >> temp;
        d[i].time = temp;
    }
    while(d.size()!=0){
        xy temp = d.back();
        curtime += abs(temp.dis - last);
        last = temp.dis;
        if(curtime < temp.time){
            curtime = temp.time;
        }
        // cout <<"curtime: " << curtime << '\n';
        d.pop_back();
    }
    curtime += last;
    cout << curtime;
}