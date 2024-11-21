#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <cmath>
#include <string>
#include <unordered_map>

using namespace std;

vector<int> v, v2;

int N, K;
int num[200001] = {};
int sum[200001] = {};
int start_point = 0;
int end_point = 0;
long long ans = 0;
unordered_map <int, int> map;

int main() {
	cin >> N >> K;
	int temp = 0;
	cin >> temp;
	num[0] = temp;
	sum[0] = temp;
	for (int i = 1; i < N; i++) {
		cin >> temp;
		num[i] = temp;
		sum[i] = sum[i - 1] + temp;
	}
	map[0] = 1;

	for (int i = 0; i < N; i++) {
		if (map[sum[i] - K] > 0) {
			ans += map[sum[i] - K];
		}
		map[sum[i]]++;
	}
	cout << ans;
}
