#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int N, S;
vector <int> v;
deque <int> ans;
void solve(int count) {
	if (count <= 0) {
		for (int i = 0; i < v.size(); i++) {
			ans.push_back(v[i]);
		}
		return;
	}
	int max_num = -1;
	int max_index = -1;
	for (int i = 0; i <= count; i++) {
		if (i >= v.size()) break;
		if (v[i] > max_num) {
			max_num = v[i];
			max_index = i;
		}
	}
	if (max_num == -1) solve(0);
	else {
		v.erase(v.begin() + max_index);
		ans.push_back(max_num);
		solve(count - max_index);
	}
}
int main() {
	cin >> N;
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		v.push_back(temp);
	}

	cin >> S;
	solve(S);

	for (int i = 0; i < N; i++) {
		cout << ans[i] << ' ';
	}
	return 0;
}