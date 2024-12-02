#include <iostream>
#include <deque>
#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>

using namespace std;
int C, N;
vector <pair<int, int>> v;
int dp[2001] = {};
int main() {
	cin >> C >> N;

	for (int i = 0; i < N; i++) {
		int cost, ppl;
		cin >> cost >> ppl;
		v.push_back({ cost,ppl });

		for (int i = C; i !=-1; i--) {
			int index = i - ppl;
			if (index <= 0) {
				index = 0;
			}
			if (i == C) {
				if (dp[index] == 0) {
					dp[index] = cost;
				}
				else {
					dp[index] = min(dp[index], cost);
				}
			}
			else if (dp[i]) {
				if (dp[index] == 0) {
					dp[index] = dp[i] + cost;
				}
				else {
					dp[index] = min(dp[index], dp[i] + cost);
				}
			}
		}
	}
	cout << dp[0];
}