#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <utility>
using namespace std;
deque <pair<int, int>> d;
int dp[1000] = {};
int N, C;
int ans = 0;
int max_end = 0;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp, temp2;
		cin >> temp >> temp2;
		max_end = max(max_end, temp2);
		d.push_back({ temp,temp2 });
	}
	sort(d.begin(), d.end());
	for (int i = 0; i < N; i++) {
		int temp = d[i].first;
		int temp2 = d[i].second;
		dp[temp2]++;
		//cout << "fisrt: " << temp << "second: " << temp2 << " dp: " << dp[temp2] << '\n';
		ans = max(ans, dp[temp2]);
		for (int num = temp2 + 1; num <= max_end; num++) {
			if (dp[num] < dp[temp2]) {
				//cout << "num: " << num << '\n';
				dp[num] = dp[temp2];
			}
		}
	}

	cout << N - ans;
	return 0;
}