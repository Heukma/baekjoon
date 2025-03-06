#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int N;
int M;
vector <long long> dp;
vector <long long> mod;
long long ans = 0;
int main() {
	cin >> N >> M;
	dp.resize(N + 1, 0);
	mod.resize(M, 0);
	for (int i = 1; i < N + 1; i++) {
		long long temp;
		cin >> temp;
		dp[i] = dp[i - 1] + temp;
		if (dp[i] % M == 0) {
			ans += mod[dp[i] % M]+1;
			mod[dp[i] % M]++;
		}
		else {
			ans += mod[dp[i] % M];
			mod[dp[i] % M]++;
		}
	}

	cout << ans;
}
