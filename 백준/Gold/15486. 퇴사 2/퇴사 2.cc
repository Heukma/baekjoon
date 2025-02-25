#include <iostream>
#include <deque>
#include <algorithm>
#include <cmath>
using namespace std;
int N;
deque <pair<int, int> > d;
int dp[1500001] = { };
long long ans = 0;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp, temp2;
		cin >> temp >> temp2;
		d.push_back({temp, temp2});
	}
	for (int i = 0; i < N; i++) {
		int a = d[i].first;
		int b = d[i].second;
		if (i != 0) {
			dp[i] = max(dp[i], dp[i - 1]);
		}
		if (i + a <= N) {
			dp[i + a] = max(dp[i] + b, dp[i + a]);
			if (dp[i + a] > ans) {
				ans = dp[i + a];
			}
		}
	}
	cout << ans;
}