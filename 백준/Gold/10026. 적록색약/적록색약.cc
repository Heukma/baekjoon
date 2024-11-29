#include <iostream>
#include <deque>
#include <algorithm>
#include <cmath>
#include <utility>

using namespace std;

int N;
int map[101][101] = {};
int map2[101][101] = {};
int visited[101][101] = {};
int ra[4] = { 1,-1,0,0 };
int rb[4] = { 0,0,-1,1 };
deque<pair<int, int>> d;
void printmap() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}
bool isvalid(int a, int b) {
	return a >= 0 && a < N && b >= 0 && b < N;
}
void bfs(int a, int b) {
	for (int i = 0; i < 4; i++) {
		int tempa = a + ra[i];
		int tempb = b + rb[i];
		if (isvalid(tempa, tempb)) {
			if (visited[tempa][tempb] == 0) {
				if (map[tempa][tempb] == map[a][b]) {
					d.push_back({ tempa,tempb });
					visited[tempa][tempb] = 1;
				}
			}
		}
	}
}
void bfs_(int a, int b) {
	for (int i = 0; i < 4; i++) {
		int tempa = a + ra[i];
		int tempb = b + rb[i];
		if (isvalid(tempa, tempb)) {
			if (visited[tempa][tempb] == 0) {
				if (map2[tempa][tempb] == map2[a][b]) {
					d.push_back({ tempa,tempb });
					visited[tempa][tempb] = 1;
				}
			}
		}
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char temp;
			cin >> temp;
			map[i][j] = temp - 'A';
			map2[i][j] = temp - 'A';
			if (map2[i][j] == 6) {
				map2[i][j] = 17;
			}
		}
	}

	int counta = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == 0) {
				counta++;
				d.push_back({ i,j });
				while (d.size() != 0) {
					int a = d[0].first;
					int b = d[0].second;
					d.pop_front();

					bfs(a, b);
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		fill(visited[i], visited[i] + N, 0);
	}
	int countb = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == 0) {
				countb++;
				d.push_back({ i,j });
				while (d.size() != 0) {
					int a = d[0].first;
					int b = d[0].second;
					d.pop_front();

					bfs_(a, b);
				}
			}
		}
	}

	cout << counta << ' ' << countb << '\n';
}