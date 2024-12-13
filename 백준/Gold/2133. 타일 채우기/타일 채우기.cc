#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long dp[16] = {};
int N;
int main() {
	dp[0] = 3;
	dp[1] = 11;
	for (int i = 2; i < 16; i++) {
		dp[i] +=dp[i - 1] * 3 + 2;
		for (int j = 2; i - j >= 0;j++) {
			dp[i] += dp[i - j] * 2;
		}
	}
	cin >> N;
	if (N % 2 == 0) {
		cout << dp[N / 2 - 1];
	}
	else {
		cout << 0;
	}
}