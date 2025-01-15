#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>
#include <vector>
#include <utility>

using namespace std;
int N, M;
int map[1000][1000] = {};
int dp[1000][1000] = {};
int ans = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char t;
			cin >> t;

			map[i][j] = t -'0';
		}
	}
	//printmap();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1) {
				if (i == 0 || j == 0) {
					dp[i][j] = 1; 
				}
				else {
					dp[i][j] = min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] }) + 1;
				}
				ans = max(ans, dp[i][j]);
			}
		}
	}

	cout << pow(ans, 2);
	return 0;
}