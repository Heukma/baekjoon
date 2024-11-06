#include <iostream>

using namespace std;

int map[501][501] = {};
int N, M;
int ret = 0;
bool isvalid(int a, int b) {
	return a >= 0 && a < N && b >= 0 && b < M;
}
void solve(int a, int b) {
	if (isvalid(a + 3, b)) {
		ret = max(ret, map[a][b] + map[a + 1][b] + map[a + 2][b] + map[a + 3][b]);
	}
	if (isvalid(a, b + 3)) {
		ret = max(ret, map[a][b] + map[a][b + 1] + map[a][b + 2] + map[a][b + 3]);
	}

	if (isvalid(a+1, b +1)) {
		ret = max(ret, map[a][b] + map[a+1][b + 1] + map[a][b + 1] + map[a + 1][b]);
	} 

	if (isvalid(a + 1, b + 2)) {
		ret = max(ret, map[a][b] + map[a + 1][b] + map[a + 1][b + 1] + map[a + 1][b + 2]);
		ret = max(ret, map[a][b] + map[a + 1][b] + map[a][b + 1] + map[a][b + 2]);
		ret = max(ret, map[a][b] + map[a + 1][b + 2] + map[a][b + 1] + map[a][b + 2]);
		ret = max(ret, map[a][b + 2] + map[a + 1][b] + map[a + 1][b + 1] + map[a + 1][b + 2]);

		ret = max(ret, map[a][b] + map[a][b + 1] + map[a + 1][b + 1] + map[a + 1][b + 2]);
		ret = max(ret, map[a + 1][b] + map[a + 1][b + 1] + map[a][b + 1] + map[a][b + 2]);

		ret = max(ret, map[a + 1][b] + map[a + 1][b + 1] + map[a + 1][b + 2] + map[a][b + 1]);
		ret = max(ret, map[a + 1][b + 1] + map[a][b + 1] + map[a][b + 2] + map[a][b]);
	}

	if (isvalid(a + 2, b + 1)) {
		ret = max(ret, map[a][b] + map[a + 1][b] + map[a][b + 1] + map[a + 2][b]);
		ret = max(ret, map[a][b] + map[a + 1][b + 1] + map[a + 2][b + 1] + map[a][b + 1]);
		ret = max(ret, map[a][b] + map[a + 1][b] + map[a + 2][b + 1] + map[a + 2][b]);
		ret = max(ret, map[a + 2][b] + map[a + 1][b + 1] + map[a + 2][b + 1] + map[a][b + 1]);

		ret = max(ret, map[a][b] + map[a + 1][b + 1] + map[a + 1][b] + map[a + 2][b + 1]);
		ret = max(ret, map[a + 1][b] + map[a + 1][b + 1] + map[a][b + 1] + map[a + 2][b]);

		ret = max(ret, map[a + 1][b] + map[a + 1][b + 1] + map[a + 2][b + 1] + map[a][b + 1]);
		ret = max(ret, map[a + 1][b + 1] + map[a + 1][b] + map[a + 2][b] + map[a][b]);
	}

}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			solve(i,j);
		}
	}
	cout << ret;
}