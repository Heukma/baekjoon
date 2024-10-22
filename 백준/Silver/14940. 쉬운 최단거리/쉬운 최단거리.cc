#include <iostream>
#include <deque>

using namespace std;

deque <pair<int, int> > d;
int N, M;
int map[1001][1001] = {};
int visited[1001][1001] = {};
int ra[4] = { 1,-1,0,0 };
int rb[4] = { 0,0,1,-1 };
bool isvalid(int a, int b) {
	return a >= 0 && a < N && b >= 0 && b < M;
}
void bfs(int a, int b) {
	for (int i = 0; i < 4; i++) {
		int tempa = a + ra[i];
		int tempb = b + rb[i];
		if (isvalid(tempa, tempb)) {
			if (map[tempa][tempb] == 1) {
				if (visited[tempa][tempb] == 0) {
					visited[tempa][tempb] = visited[a][b] + 1;
					d.push_back({ tempa,tempb });
				}
			}
		}
	}
}
void printvisited() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j] == 0) {
				if (map[i][j] == 0) {
					cout << visited[i][j] << ' ';
				}
				else {
					cout << -1 << ' ';
				}
			}
			else {
				cout << visited[i][j] - 1 << ' ';
			}
		}
		cout << '\n';
	}
}
int main() {
	int starta, startb;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				starta = i;
				startb = j;
			}
		}
	}
	visited[starta][startb] = 1;
	d.push_back({ starta,startb });
	
	while (d.size() != 0) {
		int a = d[0].first;
		int b = d[0].second;
		d.pop_front();
		bfs(a, b);
	}
	printvisited();
}