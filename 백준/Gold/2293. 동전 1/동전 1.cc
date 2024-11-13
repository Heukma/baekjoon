#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int N, K;
int dp[100001] = {};

vector <int> d;
bool isvalid(int a) {
	return a >= 0 && a < 100001;
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		d.push_back(temp);
	}
	sort(d.begin(), d.end(), greater<>());

	dp[0] = 1;
	for (int i = 0; i < d.size(); i++) {
		for (int j = d[i]; j <= K; j++) {
			dp[j] += dp[j - d[i]];
		}
	}
	cout << dp[K];
}