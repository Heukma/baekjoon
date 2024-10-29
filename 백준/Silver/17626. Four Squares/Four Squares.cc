#include <iostream>
#include <deque>

using namespace std;
int N;
int sq[250];
int dp[50001];
bool isvalid(int a) {
	return a <= 50000;
}
int main() {
	int indx = 0;
	for (int i = 1; i * i <= 50000; i++) {
		sq[i] = i * i;
		indx = i;
	}

	cin >> N;
	fill(dp, dp + 50001, 1e9 + 10);
	dp[0] = 0;
	for (int i = 0; i <= 50000; i++) {
		for (int j = 0; j <= indx; j++) {
			if(isvalid(i + sq[j])) {
				if (dp[i+sq[j]] > dp[i]+1) {
					dp[i + sq[j]] = dp[i] + 1;
				}
			}
		}
	}
	cout << dp[N];
	return 0;
}