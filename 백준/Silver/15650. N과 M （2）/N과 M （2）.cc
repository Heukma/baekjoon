#include <iostream>
#include <deque>
#include <cmath>
#include <utility>
#include <string>
using namespace std;

deque <int> d;
int N, M;
void solve(int n, int count) {
	if (count == 0) {
		for (int i = 0; i < d.size(); i++) {
			cout << d[i] << ' ';
		}
		cout << '\n';
		return;
	}
	
	for (int i = n; i <= N - count + 1; i++) {
		d.push_back(i);
		solve(i + 1, count - 1);
		d.pop_back();
	}
}
int main() {
	cin >> N >> M;

	// M이 2일때,
	solve(1, M);
}