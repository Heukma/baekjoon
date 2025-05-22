#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;
int N;
int map[129][129] = {};
int blue =0;
int white =0;
void check(int a, int b, int aa, int bb){
    int what = map[a][b];
    int flag = 1;
    for(int i=a;i<aa;i++){
        for(int j=b;j<bb;j++){
            if(what != map[i][j]){
                flag = 0;
                break;
            }
        }
    }
    if(!flag && a+1 != aa){
        check(a,b,(aa-a)/2+a,(bb-b)/2+b);
        check(a,(bb-b)/2+b,(aa-a)/2+a,bb);
        check((aa-a)/2+a,b,aa,(bb-b)/2+b);
        check((aa-a)/2+a,(bb-b)/2+b,aa,bb);
    }
    else{
        // cout << a << ' ' << aa << ' ' << b <<' ' <<bb << '\n';
        if(what == 1) blue++;
        else white++;
    }
}
int main(){
    cin >>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> map[i][j];
        }
    }
    check(0,0,N,N);
    cout << white << '\n' << blue;
}