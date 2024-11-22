#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <cmath>
#include <string>
#include <unordered_map>
#include <cmath>
#include <map>

using namespace std;
vector <int> v,v2;
int N, d, k, c;
map <int, int> m;
int begin_point = 0, end_point;
int ans = 0;

void solve() {
	m[v[begin_point]]--;
	if (m[v[begin_point]] == 0) {
		m.erase(v[begin_point]);
	}
	begin_point++;
	end_point++;

	m[v[end_point]]++;
	
	int a = m.size();
	if (m.find(c) == m.end()) {
		a++;
	}
	ans = max(ans, a);
}

int main() {
	cin >> N >> d >> k >> c;
	end_point = k - 1;
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	for (int i = 0; i < N; i++) {
		temp = v[i];
		v.push_back(temp);
	}

	// 원순열은 2번 연속해서 수열을 만듬;

	// 연속된 k개의 
	for (int i = 0; i < k; i++) {
		m[v[i]]++;
	}
	for (int i = 1; i < v.size() - k + 1; i++) {
		solve();
	}
	cout << ans;
}
