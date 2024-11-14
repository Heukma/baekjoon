#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <cstring>
using namespace std;
int N;
int dp[1001] = {};
int main() {
	cin >> N;
	fill(dp, dp+1001, 1);
	int ans = 0;

	vector <int> sequence(N,0);
	for (int i = 0; i < N; i++) {
		cin >> sequence[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (sequence[j] > sequence[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = max(ans, dp[i]);
		/*cout << i << ": " << dp[i] << '\n';*/
	}

	cout << ans;
}