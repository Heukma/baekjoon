#include <iostream>
#include <deque>
#include <utility>
#include <cmath>

using namespace std;
deque <pair <int, int> > d;
int N, M;
char rmap[1001][1001] = {};
int map[1001][1001] = {};
int zero_[1001][1001] = {1,};
int one_[1001][1001] = {};
int ra[4] = { 1,-1,0,0 };
int rb[4] = { 0,0,-1,1 };
bool isvalid(int a, int b) {
	return a >= 0 && a < N && b >= 0 && b < M;
}
void bfs(int a, int b) {
	for (int i = 0; i < 4; i++) {
		int tempa = a + ra[i];
		int tempb = b + rb[i];

		if (zero_[a][b] != 0) {
			//벽을 부수지 않고 올 수 있음.
			
			if (isvalid(tempa, tempb)) {
				if (map[tempa][tempb] == 0) {
					if (!zero_[tempa][tempb]) {
						zero_[tempa][tempb] = zero_[a][b] + 1;
						d.push_back({ tempa,tempb });
					}
				}
				else {
					if (!one_[tempa][tempb]) {
						one_[tempa][tempb] = zero_[a][b] + 1;
						d.push_back({ tempa,tempb });
					}
				}
			}
		}
		if (one_[a][b] != 0) {
			// 벽을 부수고 올 수 도 있음.
			if (isvalid(tempa, tempb)) {
				if (map[tempa][tempb] == 0) {
					if (!one_[tempa][tempb]) {
						one_[tempa][tempb] = one_[a][b] + 1;
						d.push_back({ tempa,tempb });
					}
				}
			}
		}
	}
}
void printone() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << one_[i][j] << ' ';
		}
		cout << '\n';
	}
}
void printzero() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << zero_[i][j] << ' ';
		}
		cout << '\n';
	}
}
void printmap() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> rmap[i][j];
			map[i][j] = rmap[i][j] - 48;
		}
	}
	d.push_back({ 0,0 });
	while (d.size() != 0) {
		int a = d[0].first;
		int b = d[0].second;
		d.pop_front();
		bfs(a, b);
	}
	//printmap();
	//printzero();
	//printone();
	if (one_[N - 1][M - 1] == 0 && zero_[N - 1][M - 1] == 0) {
		cout << "-1";
	}
	else if (one_[N - 1][M - 1] == 0) {
		cout << zero_[N - 1][M - 1];
	}
	else if (zero_[N - 1][M - 1] == 0){
		cout << one_[N - 1][M - 1];
	}
	else {
		cout << min(one_[N - 1][M - 1], zero_[N - 1][M - 1]);
	}
}