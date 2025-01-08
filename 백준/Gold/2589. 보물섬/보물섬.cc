#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

deque <pair<int,int>> d;
int map[51][51] = {};
int visited[51][51] = {};
int ra[4] = { 1,-1,0,0 };
int rb[4] = { 0,0,-1,1 };
int N, M;
int Max_num = 0;
bool isvalid(int a, int b) {
	return a >= 0 && a < N && b >= 0 && b < M;
}
void reset_visited() {
	for (int i = 0; i < N; i++) {
		fill(visited[i], visited[i] + M, 0);
	}
}
void bfs(int a ,int b) {
	for (int i = 0; i < 4; i++) {
		int tempa = a + ra[i];
		int tempb = b + rb[i];
		if (isvalid(tempa, tempb)) {
			if (map[tempa][tempb] == 1) {
				if (visited[tempa][tempb] == 0) {
					visited[tempa][tempb] = visited[a][b] + 1;
					Max_num = max(Max_num, visited[tempa][tempb]);
					d.push_back({ tempa,tempb });
				}
			}
		}
	}
}
void max_route(int a, int b) {
	d.push_back({ a,b });
	visited[a][b] = 1;
	while (d.size() != 0) {
		int ta = d[0].first;
		int tb = d[0].second;
		d.pop_front();
		bfs(ta, tb);
	}
	reset_visited();
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
		char temp;
		for (int j = 0; j < M;j++) {
			cin >> temp;
			if (temp == 'L') {
				map[i][j] = 1;
			}
		}
	}
	//printmap();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1) {
				max_route(i,j);
			}
		}
	}
	cout << Max_num -1 ;
}