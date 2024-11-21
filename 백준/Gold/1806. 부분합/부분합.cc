#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <cmath>
#include <string>

using namespace std;
int N, M;
int ans = 1e9 + 10;
int num[100001] = {};
int dp_front[100001] = {};
int dp_back[100001] = {};
int start_point = 0;
int end_point = 0;
void printdp() {
	for (int i = 0; i < N; i++) {
		cout << dp_front[i] << ' ';
	}
	cout << '\n';
	for (int i = 0; i < N; i++) {
		cout << dp_back[i] << ' ';
	}
	cout << '\n';
}
bool solve(int start, int end, int current) {
	// 왼쪽 한칸 이동.
	if (current >= M) {
		ans = min(ans, end - start + 1);
		start++;
		start_point = start;
	}
	// 우측 한칸 이동.
	else {
		end++;
		end_point = end;
	}

	if (start > end) return false;
	if (end > N - 1 || start > N - 1) return false;
	return true;
}

int solve_sum(int start, int end) {
	return dp_front[end] - dp_front[start] + num[start];
}
int main() {
	cin >> N >> M;
	int ind;
	
	for (int i = 0; i < N; i++) {
		cin >> ind;
		num[i] = ind;
	}

	dp_front[0] = num[0];
	for (int i = 1; i < N; i++) {
		dp_front[i] += num[i] + dp_front[i - 1];
	}

	//printdp();

	if (solve_sum(0, N-1) >= M) {
		bool flag = true;
		while (flag) {
			flag = solve(start_point, end_point, solve_sum(start_point, end_point));
		}
	}
	if (ans == 1e9 + 10) {
		cout << '0';
	}
	else {
		cout << ans;
	}
}