#include <cstring>
#include <iostream>
#include <deque>
#include <utility>

using namespace std;
int N, M;

deque <pair<int, int> > d;
int map[501][501] = {};
int visited[501][501] = {};
int ra[4] = { 1,-1,0,0 };
int rb[4] = { 0,0,1,-1 };
bool isvalid(int a, int b) {
	return a >= 0 && a < N && b >= 0 && b < M;
}
int solve(int a, int b) {
	if (a == N - 1 && b == M - 1) {
		return 1;
	}
	if (visited[a][b] != -1) return visited[a][b];
	//방문한적 있으면 visited 값 리넡

	visited[a][b] = 0;

	for (int i = 0; i < 4; i++) {
		int tempa = a + ra[i];
		int tempb = b + rb[i];
		if (isvalid(tempa, tempb)) {
			if (map[a][b] > map[tempa][tempb]) {
				visited[a][b] += solve(tempa, tempb);
			}
		}
	}
	return visited[a][b];
}
int main() {
	cin >> N >> M;

	memset(visited, -1, sizeof(visited));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	int ret = solve(0, 0);
	cout << ret;
	return 0;
}