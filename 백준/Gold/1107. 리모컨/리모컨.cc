#include <iostream>
#include <deque>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M;
int remote[10] = {};
bool valid(int a) {
	do {
		if (remote[a % 10] == 1) {
			return false;
		}
		a /= 10;
	} while (a > 0);

	return true;
}

int ans(int a) {
	if (a / 100000) {
		return 6;
	}
	else if (a / 10000) {
		return 5;
	}
	else if (a / 1000) {
		return 4;
	}
	else if (a / 100) {
		return 3;
	}
	else if (a / 10) {
		return 2;
	}
	return 1;
}
int main() {
	cin >> N >> M;
	int ret = 1e9 + 10;
	for (int i = 0; i < M; i++) {
		int temp;
		cin >> temp;
		remote[temp] = 1;
	}

	int count = 0;

	ret = min(ret, abs(N - 100));
	if (valid(N)) {
		ret = min(ret, ans(N));
	}
	if (valid(N)) {
		ret = min(ret, ans(N));
	}
	count = 0;
	for (int i = 1; i <= N; i++) {
		if (valid(N - i)) {
			ret = min(ret, ans(N - i) + i);
			break;
		}
	}
	for (int i = 1; i <= 500000; i++) {
		if (valid(N + i)) {
			ret = min(ret, ans(N + i) + i);
			break;
		}
	}

	cout << ret;
	return 0;
}