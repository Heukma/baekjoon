#include <iostream>
#include <vector>
using namespace std;

vector <int> d;
int N, M;
long long ans = 1e18 + 1; // ★ 수정된 부분 (충분히 큰 초기값 설정)
long long left_point = 0;
long long right_point = 1e18 + 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    d.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> d[i];
    }

    while (left_point <= right_point) {
        long long point = (left_point + right_point) / 2;
        long long tempans = 0;
        
        for (int i = 0; i < N; i++) {
            tempans += (point / d[i]);
            if(tempans >= M) break; // 오버플로우 방지 최적화
        }

        if (tempans >= M) {
            ans = point;
            right_point = point - 1;
        }
        else {
            left_point = point + 1;
        }
    }

    cout << ans;
}
