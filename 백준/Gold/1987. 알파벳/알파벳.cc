#include <iostream>
#include <deque>
#include <algorithm>
#include <utility>
#include <cstring>
#include <cmath>

using namespace std;
int N,M;
char tempmap[21][21] = {};
int map[21][21] = {};
int ra[4] = { 1,-1,0,0 };
int rb[4] = { 0,0,-1,1 };
int ans = 0;
bool isvalid(int a, int b) {
	return a >= 0 && a < N && b >= 0 && b < M;
}
void dfs(int a, int b, int visited[], int c) {
	ans = max(ans, c);
	int temp_visited[26];
	copy(visited, visited + 26, temp_visited); 
	temp_visited[map[a][b]] = 1;
	for (int i = 0; i < 4; i++) {
		int tempa = a + ra[i];
		int tempb = b + rb[i];
		if (isvalid(tempa,tempb)) {
			if (!temp_visited[map[tempa][tempb]]) {
				//cout << "Tempa: " << tempa << ", Tempb: " << tempb <<", Map: "<<map[tempa][tempb] << '\n';
				dfs(tempa, tempb, temp_visited, c+1);
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tempmap[i][j];
			map[i][j] = tempmap[i][j] - 'A';
		}
	}
	int visited[26] = {};
	dfs(0, 0, visited, 1);

	cout << ans;
}
