#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>
#include <vector>
#include <utility>

using namespace std;
int N, L;
vector <pair<int, int>> v;
int ans = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> L;
	
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	int last_ = -1;
	for (int i = 0; i < v.size(); i++) {
		int a = v[i].first;
		int b = v[i].second;
		if (last_ > a) {
			a = last_;
		}
		int size = b - a;
		int tempans = 1;
		if (size > 0) {
			while (tempans * L < size) {
				tempans++;
			}
			last_ = a + tempans * L;
			ans += tempans;
		}		
	}

	cout << ans;
	return 0;
}