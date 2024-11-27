#include <iostream>
#include <deque>
#include <algorithm>
#include <cmath>
#include <utility>

using namespace std;

int N, M;
int ice[301][301] = {};
int tempice[301][301] = {};
int ra[4] = { 1,-1,0,0 };
int rb[4] = { 0,0,-1,1 };
int visited[301][301] = {};
deque <pair<int, int>> d;
bool stop() {
	bool flag = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (ice[i][j] != 0) {
				flag = true;
				break;
			}
		}
	}

	return flag;
}
bool isvalid(int a, int b) {
	return a >= 0 && a < N && b >= 0 && b < M;
}
void melt() {
	for (int i = 1; i < N-1; i++) {
		for (int j = 1; j < M-1; j++) {
			int flag = 0;
			for (int dir = 0; dir < 4; dir++) {
				int tempa = i + ra[dir];
				int tempb = j + rb[dir];
				if (ice[tempa][tempb] == 0) {
					flag++;
				}
			}
			tempice[i][j] = max(0, ice[i][j] - flag);
		}
	}
	for (int i = 1; i < N - 1; i++) {
		for (int j = 1; j < M - 1; j++) {
			ice[i][j] = tempice[i][j];
		}
	}
}
void bfs(int a, int b) {
	for (int i = 0; i < 4; i++) {
		int tempa = a + ra[i];
		int tempb = b + rb[i];
		if (isvalid(tempa, tempb)) {
			if (ice[tempa][tempb] != 0) {
				if (visited[tempa][tempb] == 0) {
					visited[tempa][tempb] = 1;
					d.push_back({ tempa,tempb });
				}
			}
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> ice[i][j];
		}
	}
	for (int year = 0;;year++) {
		if (!stop()) break;
		melt();
		for (int i = 0; i < N; i++) {
			fill(visited[i], visited[i] + M, 0);
		}
		int count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				//cout << "i, j : " << i <<" " << j <<" ice : "<<ice[i][j]<<" visited: " <<visited[i][j] << "\n";
				if (visited[i][j] == 0) {
					if (ice[i][j] == 0) {
						visited[i][j] = 1;
					}
					else {
						d.push_back({ i,j });
						count++;
						visited[i][j] = 1;
						while (d.size() != 0) {
							int a = d[0].first;
							int b = d[0].second;
							d.pop_front();
							bfs(a, b);
						}
					}
				}
			}

		}
		if (count >= 2) {
			cout << year + 1;
			return 0;
		}
	}
	cout << 0;
	return 0;
}