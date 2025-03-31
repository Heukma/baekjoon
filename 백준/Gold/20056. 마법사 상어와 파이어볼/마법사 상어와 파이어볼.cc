#include <iostream>
#include <deque>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
struct fireball{
    int a,b;
    int m;
    int s;
    int dir;
};
vector <vector<vector<fireball>>> map(51,vector<vector<fireball>>(51));
int N, M, K;
int ra[8] = {-1,-1, 0, 1, 1, 1, 0,-1};
int rb[8] = {0 , 1, 1, 1, 0,-1,-1,-1};

vector <fireball> v;
void input_(){
    cin >> N >> M >> K;
    for(int i=0;i<M;i++){
        fireball tf;
        cin >> tf.a >> tf.b;
        tf.a --; tf.b --;
        cin >> tf.m;
        cin >> tf.s;
        cin >> tf.dir;
        v.push_back(tf);
    }
}
void isvalid(int& a, int& b){
    if(a<0){
        a+=N;
    }
    if(a>=N){
        a-=N;
    }
    if(b<0){
        b+=N;
    }
    if(b>=N){
        b-=N;
    }
}
long long ans(){
    long long ans = 0;
    // cout << "=========\n";
    for(int i=0;i<v.size();i++){
        // cout << v[i].a << ' ' << v[i].b << ' '<<v[i].m << ' '<<v[i].s << ' '<<v[i].dir << '\n';
        ans += v[i].m;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input_();
    for(int turn =0; turn< K; turn ++){
        // cout << v.size() << '\n';
        for(int i=0;i<v.size();i++){
            int tempa = v[i].a;
            int tempb = v[i].b;
        
            // for(int j=0;j<v[i].s;j++){
            //     tempa +=  ra[v[i].dir];
            //     tempb +=  rb[v[i].dir];
            //     isvalid(tempa,tempb);
            // }
            tempa = (tempa + ra[v[i].dir] * v[i].s % N + N) % N;
            tempb = (tempb + rb[v[i].dir] * v[i].s % N + N) % N;
            v[i].a = tempa;
            v[i].b = tempb;
            // cout <<"temp: " <<tempa << ' ' << tempb << '\n';
            map[tempa][tempb].push_back(v[i]);
        }
        // ans();
        v.clear();
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(map[i][j].size() >=2){
                    fireball tf;
                    tf.a = i;
                    tf.b = j;
                    tf.m = 0;
                    tf.s = 0;
                    tf.dir = map[i][j][0].dir;
                    for(int index=0;index<map[i][j].size();index++){
                        tf.m += map[i][j][index].m;
                        tf.s += map[i][j][index].s;
                        // cout << tf.dir << '\n';
                        if(!(tf.dir % 2 == map[i][j][index].dir % 2 && tf.dir != -1)){
                            tf.dir = -1;
                        }
                    }
                    if(tf.m>4){
                        tf.m /=5;
                        tf.s /= map[i][j].size();
                        // cout << tf.dir << '\n';
                        if(tf.dir != -1){
                            tf.dir = 0;
                            v.push_back(tf);
                            tf.dir = 2;
                            v.push_back(tf);
                            tf.dir = 4;
                            v.push_back(tf);
                            tf.dir = 6;
                            v.push_back(tf);
                        }
                        else{
                            tf.dir = 1;
                            v.push_back(tf);
                            tf.dir = 3;
                            v.push_back(tf);
                            tf.dir = 5;
                            v.push_back(tf);
                            tf.dir = 7;
                            v.push_back(tf);
                        }
                    }
                }
                else if(map[i][j].size()){
                    v.push_back(map[i][j][0]);
                }
                map[i][j].clear();
            }
        }
    }

    cout << ans();
}