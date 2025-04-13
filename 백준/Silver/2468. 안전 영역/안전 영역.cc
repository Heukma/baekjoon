#include <iostream>
#include <deque>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int N;
int rain;
int map[101][101] = {};
int visited[101][101] = {};
int ra[4] = {1,-1,0,0};
int rb[4] = {0,0,1,-1};
int ret = -1;
struct xy {
    int a, b;
};
deque <xy> d;
void resetvisited() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = 0;
        }
    }
}
bool isvalid(int a, int b) {
    return a >= 0 && a < N && b >= 0 && b < N;
}
void bfs(int a, int b) {
    for (int i = 0; i < 4; i++){
        int tempa = a + ra[i];
        int tempb = b + rb[i];
        if (isvalid(tempa, tempb)) {
            if (!visited[tempa][tempb]) {
                if (map[tempa][tempb] > rain) {
                    visited[tempa][tempb] = 1;
                    d.push_back({ tempa,tempb });
                }
            }
        }
    }
}
void searchblock() {
    resetvisited();
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] > rain) {
                if (!visited[i][j]) {
                    ans++;
                    d.push_back({ i,j });
                    visited[i][j] = 1;
                    while (d.size() != 0) {
                        int a = d[0].a;
                        int b = d[0].b;
                        d.pop_front();
                        bfs(a, b);
                    }
                }
            }
        }
    }
    //cout << "rain: " << rain <<' '<< ans << '\n';
    ret = max(ret, ans);
}
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {

            cin >> map[i][j];
            
        }
    }

    for (int i = 0; i <= 100; i++) {
        rain = i;
        searchblock();
    }

    cout << ret;
}
