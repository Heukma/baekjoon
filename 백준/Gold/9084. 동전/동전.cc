#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int N;
void solve() {
	int n;
	deque <int> d;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		d.push_back(temp);
	}
	int ending;
	cin >> ending;
	vector <int> dp(ending + 1, 0);
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = d[i]; j <= ending; j++) {
			dp[j] += dp[j - d[i]];
		}
	}
	cout << dp[ending] << '\n';
}
int main() {
	cin >> N;
	while (N--) {
		solve();
	}
}