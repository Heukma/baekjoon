#include <iostream>
#include <deque>

using namespace std;

int N, M;
int map[101][101] = {};
int door[101][101] = {};
deque <pair<int, int>> d;
int ra[4] = { 1,-1,0,0 };
int rb[4] = { 0,0,1,-1 };

void printmap() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}

}
void printdoor() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}

}
bool isvalid(int a, int b) {
	return a >= 0 && a < N && b >= 0 && b < M;
}
void bfs(int a, int b) {
	for (int i = 0; i < 4; i++) {
		int tempa = a + ra[i];
		int tempb = b + rb[i];
		if (isvalid(tempa, tempb)) {
			if (door[a][b] + map[tempa][tempb] < door[tempa][tempb]) {
				door[tempa][tempb] = door[a][b] + map[tempa][tempb];
				d.push_back({ tempa, tempb });
			}
		}
	}
}
int main() {
	cin >> M >> N;
	char temp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> temp;
			map[i][j] = temp - '0';
		}
	}
	for (int i = 0; i < N; i++) {
		fill(door[i], door[i] + M, 1e9 + 10);
	}
	//printdoor();
	door[0][0] = 0;
	d.push_back({ 0, 0 });
	while (d.size() != 0) {
		int a = d[0].first;
		int b = d[0].second;
		d.pop_front();
		bfs(a,b);
	}
	cout << door[N - 1][M - 1];
}