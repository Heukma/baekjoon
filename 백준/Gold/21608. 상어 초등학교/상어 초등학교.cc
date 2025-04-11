#include <iostream>
#include <deque>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <set>

using namespace std;
set <int> lovetable[401] = {};
int classmap[21][21] = {};
int ra[4] = {1,-1,0,0};
int rb[4] = {0,0,1,-1};
int N;
bool isvalid(int a, int b){
    return a>=0 && a<N && b>=0 && b<N;
}
void selectseat(int index){
    int left=-1, love=0;
    int a,b;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(classmap[i][j]) {
                continue;
            }
            int le=0;
            int lo=0;
            for(int ij=0;ij<4;ij++){
                int tempa = i+ra[ij];
                int tempb = j+rb[ij];
                if(isvalid(tempa,tempb)){
                    if(classmap[tempa][tempb]){
                        if(lovetable[index].count(classmap[tempa][tempb])){
                            lo++;
                        }
                    }
                    else{
                        le++;
                    }
                }
            }
            if(lo>love){
                love = lo;
                left = le;
                a = i;
                b = j;
            }
            else if(lo == love && le > left){
                love = lo;
                left = le;
                a = i;
                b = j;
            }
        }
    }
    // cout <<"a,b: "<< a << " " << b << '\n';
    classmap[a][b] = index;
}  
int ans(){
    int ret = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int ans = 0;
            for(int ij=0;ij<4;ij++){
                int tempa = i+ra[ij];
                int tempb = j+rb[ij];
                if(isvalid(tempa,tempb)){
                    if(classmap[tempa][tempb]){
                        if(lovetable[classmap[i][j]].count(classmap[tempa][tempb])){
                            ans++;
                        }
                    }
                }
            }
            if(ans ==1){
                ret ++;
            }
            if(ans ==2){
                ret +=10;
            }
            if(ans ==3){
                ret +=100;
            }
            if(ans ==4){
                ret +=1000;
            }
        }
    }
    return ret;
} 
void printmap(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << classmap[i][j] << ' ';
        }
        cout << '\n';
    }
}
int main(){
    cin >> N;
    // printmap();
    for(int i=0;i<N*N;i++){
        int index;
        cin >> index;
        for(int j=0;j<4;j++){
            int temp;
            cin >> temp;
            lovetable[index].insert(temp);
        }

        selectseat(index);
    }
    // printmap();
    cout << ans();
}