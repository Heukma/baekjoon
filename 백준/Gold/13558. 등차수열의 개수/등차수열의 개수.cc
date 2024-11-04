#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>
#include <vector>
using namespace std;
int N;
long long g[100001] = {};
long long gleft[30001] = {};
long long gright[30001] = {};
void printg() {
	for (int i = 0; i < N; i++) {
		cout << g[i] << ' ';
	}
	cout << '\n';
}
bool issq(int a, int b, int c) {
	if (c - b == b - a) {
		return true;
	}
	return false;
}
bool isvalid(int a, int b) {
	return a - b >= 0 && a + b <= 30000;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	long long ans = 0;
	for (int i = 0; i < N; i++) {
		cin >> g[i];
		gright[g[i]]++;
	}
	gright[g[0]]--;
	long long mx = *max_element(g, g + N);
	for (int i = 1; i < N - 1; i++) {
		gright[g[i]]--;
		gleft[g[i - 1]]++;
		ans += gleft[g[i]] * gright[g[i]];
		for (int diff = 1; 1 <= g[i] - diff && g[i] + diff <= mx; diff++) {
			ans += gleft[g[i] + diff] * gright[g[i] - diff];
			ans += gleft[g[i] - diff] * gright[g[i] + diff];
		}
	}

	cout << ans;
}