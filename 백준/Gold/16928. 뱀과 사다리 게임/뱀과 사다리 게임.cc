#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

deque<int> d;
int N, N2;
int move_[101] = {};
int map[101] = {};
int dp[101] = {};
void bfs(int a) {
	for (int i = 1; i <= 6 && a + i <= 100; i++) {
		if (dp[a] + 1 < dp[a + i]) {
			if (move_[a + i] != 0) {
				int current = move_[a + i];
				if (dp[a] + 1 < dp[current]) {
					dp[current] = dp[a] + 1;
					d.push_back(current);
				}
			}
			else {
				dp[a + i] = dp[a] + 1;
				d.push_back(a + i);
			}
		}
	}
}
int main() {
	cin >> N >> N2;
	for (int i = 0; i < N + N2; i++) {
		int temp,b;
		cin >> temp;
		cin >> b;
		move_[temp] = b;
	}
	fill(dp, dp + 101, 1e9 + 10);
	dp[1] = 0;
	d.push_back(1);
	while (d.size() != 0) {
		int temp = d[0];
		d.pop_front();
		bfs(temp);
	}
	cout << dp[100] << '\n';
}