#include <iostream>

using namespace std;

int N;
int dp[16] = {};
bool isvalid(int a) {
	return a >= 0 && a <= N;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tempd, tempcost;
		cin >> tempd >> tempcost;
		for (int j = 0;; j++) {
			if (isvalid(tempd + i + j)) {
				dp[tempd + i + j] = max(dp[tempd + i + j], dp[i] + tempcost);
			}
			else {
				break;
			}
		}
	}
	cout << dp[N];
}