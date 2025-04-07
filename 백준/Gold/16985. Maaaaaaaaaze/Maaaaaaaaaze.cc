#include <iostream>
#include <deque>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
// int map[5][5][5] = {};
vector<vector<vector<int> > > map(5,vector<vector<int> >(5,vector<int>(5)));
vector<vector<vector<int> > > tempmap(5,vector<vector<int> >(5,vector<int>(5)));
vector<vector<vector<int> > > finalmap(5,vector<vector<int> >(5,vector<int>(5)));
vector<int> per = {0,1,2,3,4};
int ra[6] = {1,-1,0,0,0,0};
int rb[6] = {0,0,1,-1,0,0};
int rc[6] = {0,0,0,0,1,-1};
int visited[5][5][5] = {};
struct xyz {
    int a,b,c;
};
deque<xyz> d;
int ans = 1e9+7;
//debug
bool isvalid(int a, int b ,int c){
    return a>=0 && a<5 && b>=0 && b<5 && c>=0 && c<5;
}
void printtempmap(int index){
    cout << "printmap index: " << index << " \n";
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout << tempmap[index][i][j] << ' ';
        }
        cout << '\n';
    }
}
void printfinalmap(int index){
    cout << "printmap index: " << index << " \n";
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout << finalmap[index][i][j] << ' ';
        }
        cout << '\n';
    }
}
//debug
void input_(){
    for(int index=0;index<5;index++){
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                cin >> map[index][i][j];
            }
        }
    }
    
}

void resetvisited(){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            for(int ij=0;ij<5;ij++){
                visited[i][j][ij]= 0;
            }
        }
    }
}
void bfs(int a, int b, int c){
    for(int i=0;i<6;i++){
        int tempa = a + ra[i];
        int tempb = b + rb[i];
        int tempc = c + rc[i];
        if(isvalid(tempa,tempb,tempc)){
            if(finalmap[tempa][tempb][tempc] == 1){
                if(visited[tempa][tempb][tempc] ==0){
                    visited[tempa][tempb][tempc] = visited[a][b][c]+1;
                    xyz temp;
                    temp.a = tempa;
                    temp.b = tempb;
                    temp.c = tempc;
                    d.push_back(temp);
                }
            }
        }
    }
}
void move(){
    if(finalmap[0][0][0] == 0) return;
    xyz first;
    first.a = 0;
    first.b = 0;
    first.c = 0;
    visited[0][0][0] = 1;

    d.push_back(first);
    while(d.size()!=0){
        int tempa = d[0].a;
        int tempb = d[0].b;
        int tempc = d[0].c;
        d.pop_front();
        bfs(tempa,tempb,tempc);
    }
    
}
void permutation(){
    sort(per.begin(),per.end());
    do{
        int t = 0;
        for(auto i : per){
            finalmap[t] = tempmap[i];
            t++;
        }
        resetvisited();
        move();
        if(visited[4][4][4]){
            ans = min(ans,visited[4][4][4]);
        }
    }while(next_permutation(per.begin(),per.end()));
}
void rotate_map(int time, const vector<vector<int>>& v,int index){
    tempmap[index] = v;
    while(time --){
        vector<vector<int>> rmap(5,vector<int>(5));
        rmap = tempmap[index];
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                tempmap[index][i][j] = rmap[4-j][i];
            }
        }
    }
}
void make_map(){
    for(int i1=0;i1<4;i1++){
        for(int i2=0;i2<4;i2++){
            for(int i3=0;i3<4;i3++){
                for(int i4=0;i4<4;i4++){
                    for(int i5=0;i5<4;i5++){
                        rotate_map(i1,map[0],0);
                        rotate_map(i2,map[1],1);
                        rotate_map(i3,map[2],2);
                        rotate_map(i4,map[3],3);
                        rotate_map(i5,map[4],4);
                        permutation();
                    }
                }
            }
        }
    }
}
int main(){
    input_();
    make_map();

    if(ans == 1e9+7){
        cout << -1;
        return 0;
    }
    cout << ans - 1 << '\n';
    return 0;
}