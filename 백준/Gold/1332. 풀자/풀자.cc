#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

struct T{
    int max;
    int min;
    int n;
    int index;
};

int N, V;
int v[50];
queue<T> d;
unordered_set<int> visited; 

int main(){
    cin >> N >> V;
    for(int i=0; i<N; i++){
        cin >> v[i];
    }

    T start;
    start.max = v[0];
    start.min = v[0];
    start.n = 1;
    start.index = 0;
    d.push(start);

    visited.insert(0 * 1000000 + start.max * 1000 + start.min); 

    int ans = -1;
    while(!d.empty()){
        T temp = d.front();
        d.pop();

        if(temp.max - temp.min >= V){
            ans = temp.n;
            break;
        }

        if(temp.index + 1 < N){
            T v1;
            v1.index = temp.index + 1;
            v1.max = max(v[temp.index + 1], temp.max);
            v1.min = min(v[temp.index + 1], temp.min);
            v1.n = temp.n + 1;
            int state = v1.index * 1000000 + v1.max * 1000 + v1.min;

            if(visited.find(state) == visited.end()){
                visited.insert(state);
                d.push(v1);
            }
        }
        
        if(temp.index + 2 < N){
            T v1;
            v1.index = temp.index + 2;
            v1.max = max(v[temp.index + 2], temp.max);
            v1.min = min(v[temp.index + 2], temp.min);
            v1.n = temp.n + 1;
            int state = v1.index * 1000000 + v1.max * 1000 + v1.min;

            if(visited.find(state) == visited.end()){
                visited.insert(state);
                d.push(v1);
            }
        }
    }

    cout << (ans == -1 ? N : ans);
}
